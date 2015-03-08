`timescale 1ns / 1ps

module axi2fifo_asyn_tb;

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
	reg output_enable;

	// Outputs
	wire tready;
	wire [201:0] dout;
	wire dout_valid;
	wire [4:0] oq;

	// Instantiate the Unit Under Test (UUT)
	Axi2Fifo_asyn uut (
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

localparam PACKET_LEN = 20;
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
		output_enable = 0;
		i = 0;
		packet_num = 0;

		// Wait 100 ns for global reset to finish
		#20;
        reset = 1'b0;
        memreset = 1'b0;
		// Add stimulus here
		output_enable = 1'b1;


	end
	
    always #3.125   begin
        clk = ~clk;         // 160MHz
    end
    

    always #2 begin
        memclk = ~memclk;   // 250MHz
    end
    
// simulatre arbitor behavior

always @ (posedge memclk) begin
    
end
    
    
      
endmodule

