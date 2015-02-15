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
	
	Axi2Fifo A2F (
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

    reg [7:0]   i;
    reg [255:0] tdata1;
    reg [255:0] tdata2;
    reg         packet_num;
    reg [1:0]   axis_state,next_axis_state;
    
    localparam PACKET_LEN = 16;
    localparam GETREADY = 0;
    localparam TRANSMISSION = 1;

/* axis simulator*/
always @ * begin
    if (reset) begin
        axis_state = 0;
        next_axis_state = 0;
    end
    else begin
        axis_state = next_axis_state;
    end

end

always @ * begin
        tlast = 1'b0;
        tstrb = tstrb;
        if (i == PACKET_LEN) begin
            tlast = 1'b1;
            tstrb = 32'h000fffff;
        end

end

always @ (posedge clk) begin
    case (axis_state)
    GETREADY:       begin
                        if (~reset) begin
                            if (packet_num == 0) begin
                                tdata <= tdata1;
                                tuser <= {tuser_para1,tuser_para2,tuser_para3};
                                tvalid <= 1'b1;
                                tstrb <= 32'hffffffff;
                                packet_num <= 1;
                                i = 0;
                            end
                            else if (packet_num == 1) begin
                                tstrb <= 32'hffffffff;
                                tdata <= tdata2;
                                tuser <= {tuser_para1,tuser_para2_2,tuser_para3};
                                tvalid <= 1'b1;
                                packet_num <=0;
                                i = 0;
                            end
                            next_axis_state <= TRANSMISSION;
                        end

                    end
    
    TRANSMISSION:   begin
                        if (tready) begin
                            if (tlast) begin
                                next_axis_state <= GETREADY;

                            end
                            else begin
                            tdata = tdata + 256'd1;
                            i = i + 1;
                            end
                        end
                    end
                    
    default:        begin
                    tvalid <= 0;
                    tdata <= 256'bz;
                    tuser <= 128'bz;
                    tstrb <= 32'bz;
                    /*pause*/
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
