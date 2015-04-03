`timescale 1ns / 1ps

module Axi2Mem_tb;

    // Inputs
	reg clk;
	reg reset;
	reg memclk;
	reg memreset;
	reg tvalid;
	reg [255:0] tdata;
	reg [31:0] tstrb;
	reg [127:0] tuser;
	reg tlast;

	// Outputs
	wire tready;
	wire [201:0] dout;
	wire [201:0] dout_mem;
	wire dout_valid;
	wire dout_valid_mem;
	wire [4:0] oq;
	wire [2:0] queue_id;
	wire output_enable;
	
	Axi2Fifo_asyn A2F (
		.clk(clk), 
		.reset(reset), 
		.memclk(memclk), 
		.memreset(memreset), 
		.tvalid(tvalid), 
		.tready(tready), 
		.tdata(tdata), 
		.tstrb(tstrb), 
		.tuser(tuser), 
		.tlast(tlast), 
		.dout(dout), 
		.dout_valid(dout_valid), 
		.output_enable(output_enable),
		.oq(oq)
	);
	
	AxiFifoArbiter AFA (
	    .reset(reset),
	    .memclk(memclk),
	    .oq(oq),
	    .din_valid(dout_valid),
	    .din(dout),
	    .next_pkg_en(output_enable),
	    .queue_id(queue_id),
	    .dout(dout_mem),
	    .dout_valid(dout_valid_mem)
	);
	
	
localparam [95:0]   tuser_para1 = 96'b0;
localparam [7:0]    tuser_para2 = 8'b10101111;
localparam [23:0]   tuser_para3 = 24'b1;
localparam [7:0]    tuser_para2_2 = 8'b11101010;

reg [7:0]   i,next_i;
reg [255:0] tdata1;
reg [255:0] tdata2;
reg         packet_num;
reg         next_packet_num;
reg [1:0]   axis_state,next_axis_state;

localparam PACKET_LEN =30;
localparam GETREADY = 0;
localparam TRANSMISSION = 1;

reg [255:0] next_tdata;
reg [127:0] next_tuser;
reg [31:0]  next_tstrb;
reg         next_tvalid;
reg         next_tlast;

/* axis simulator*/
always @ (posedge clk) begin
    if (reset) begin
        axis_state <= 0;
        tdata <= {256{1'b0}};
        tuser <= {128{1'b0}};
        tstrb <= {32{1'b0}};
        tvalid<= 1'b0;
        tlast <= 1'b0;
        packet_num = 1'b0;
        i <= 0;
    end
    else begin
        axis_state <= next_axis_state;
        tdata <= next_tdata;
        tuser <= next_tuser;
        tstrb <= next_tstrb;
        tvalid<= next_tvalid;
        tlast <=next_tlast;
        packet_num <= next_packet_num;
        if (tlast) begin
            i = 0;
        end
        else if (tready) begin
            i <= next_i;
        end

    end
end

always @ * begin
next_axis_state = axis_state;
next_tdata = tdata;
next_tuser = tuser;
next_tstrb = tstrb;
next_tvalid = tvalid;
next_tlast = tlast;
next_packet_num = packet_num;

    case (axis_state)
    GETREADY:
    begin
        if (~reset) begin
            case (packet_num)
                1'b0:
                begin
                    next_tdata = tdata1;
                    next_tuser = {tuser_para1,tuser_para2,tuser_para3};
                    next_tvalid = 1'b1;
                    next_tstrb = 32'hffffffff;
                    next_packet_num = 1'b1;
                end
                
                1'b1:
                begin
                    next_tstrb = 32'hffffffff;
                    next_tdata = tdata2;
                    next_tuser = {tuser_para1,tuser_para2_2,tuser_para3};
                    next_tvalid = 1'b1;
                    next_packet_num = 1'b0;
                end
            endcase
            next_axis_state = TRANSMISSION;
            next_tvalid = 1'b1;
        end
    end
    
    TRANSMISSION:
    begin
        if (tready) begin
            if (i == (PACKET_LEN-1)) begin
                next_tlast = 1'b1;
            end
            else begin
                next_tlast = 1'b0;
            end
            
            if (tlast) begin
                next_axis_state = GETREADY;
                next_tvalid = 1'b0;
                next_i = 0;
                next_tdata = 0;
            end
            else begin
                next_tdata = tdata + 256'd1;
                next_i = i + 1;
            end
        end
        
        

    end
    
    endcase

end

/* end of axis simulator*/

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		memclk = 0;
		memreset = 1;
		tvalid = 0;
		tdata = 0;
		tdata1 = 50;
		tdata2 = 200;
		tstrb = 0;
		tuser = 0;
		i = 0;
		packet_num = 0;

		// Wait 100 ns for global reset to finish
		#10;
        reset = 1'b0;
        memreset = 1'b0;
		// Add stimulus here

	end
	

    
    always #3.125   begin
        clk = ~clk;         // 160MHz
    end
    

    always #2 begin
        memclk = ~memclk;   // 250MHz
    end
    
    reg [127:0] read_tuser = 0;
    reg [255:0] read_tdata = 0;
    reg [4:0] read_tstrb = 0;
    reg [3:0] read_pkg_state =0;
    reg read_tlast = 0;
    reg [2:0] read_queue_id = 0;
    

    always @ (posedge memclk) begin
        if(dout_valid_mem) begin
            read_pkg_state <= dout_mem[4:2];
            read_queue_id <= queue_id;
            case (dout[4:2])
            3'd0:   begin
                        read_tuser <= dout_mem[137:10];
                        read_tstrb <= dout_mem[9:5];
                        read_tlast <= dout_mem[1];
                    end
            3'd1:   begin
                        read_tdata <= dout_mem[201:10];
                        read_tstrb <= dout_mem[9:5];
                        read_tlast <= dout_mem[1];
                    end
            3'd2:   begin
                        read_tdata <= dout_mem[201:74];
                        read_tstrb <= dout_mem[9:5];
                        read_tlast <= dout_mem[1];
                    end
            3'd3:   begin
                        read_tdata <= dout_mem[201:138];
                        read_tstrb <= dout_mem[9:5];
                        read_tlast <= dout_mem[1];
                    end
            3'd4:   begin
                        read_tdata <= dout_mem[201:10];
                        read_tstrb <= dout_mem[9:5];
                        read_tlast <= dout_mem[1];
                    end
            endcase
        end
    end
    
    
endmodule
