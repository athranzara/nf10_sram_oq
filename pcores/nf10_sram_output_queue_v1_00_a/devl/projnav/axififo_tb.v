`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:48:14 01/25/2015
// Design Name:   AxiToFifo
// Module Name:   /local/scratch/jz377/Dropbox/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/devl/projnav/axififo_tb.v
// Project Name:  nf10_sram_output_queue
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: AxiToFifo
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module axififo_tb;

	// Inputs
	reg clk;
	reg reset;
	reg tvalid;
	reg [255:0] tdata;
	reg [31:0] tstrb;
	reg tlast;
	reg [127:0] tuser;
	reg memclk;
	reg memreset;
	reg rden;
	reg cal_done;
	reg output_inc;

	// Outputs
	wire tready;
	wire rempty;
	wire r_almost_empty;
	wire dout_valid;
	wire [201:0] dout;
	wire [31:0] input_fifo_cnt;

	// Instantiate the Unit Under Test (UUT)
	AxiToFifo uut (
		.clk(clk), 
		.reset(reset), 
		.tvalid(tvalid), 
		.tready(tready), 
		.tdata(tdata), 
		.tstrb(tstrb), 
		.tlast(tlast), 
		.tuser(tuser), 
		.memclk(memclk), 
		.memreset(memreset), 
		.rden(rden), 
		.rempty(rempty), 
		.r_almost_empty(r_almost_empty), 
		.dout_valid(dout_valid), 
		.dout(dout), 
		.cal_done(cal_done), 
		.output_inc(output_inc), 
		.input_fifo_cnt(input_fifo_cnt)
	);

    always @ (posedge clk) begin
    if ((reset != 1'b1) || (memreset != 1'b1)) begin
    tstrb = 32'hffffffff;
    tdata = tdata + 256'd1;
    tvalid = 1'b1;
    tuser = 128'b0;
    end

    
    
    end

	initial begin
		// Initialize Inputs
		clk = 0;
		tvalid = 0;
		tdata = 0;
		tstrb = 0;
		tlast = 0;
		tuser = 0;
		memclk = 0;
		rden = 0;
		cal_done = 1;
		output_inc = 0;
		
		reset = 1'b1;
		memreset = 1'b1;

		// Wait 100 ns for global reset to finish
		#100;
        reset = 0;
        memreset = 0;
        rden = 1;
		// Add stimulus here

	end
	
    always #3.125   clk = ~clk;         // 160MHz
    always #2       memclk = ~memclk;   // 250MHz
      
endmodule

