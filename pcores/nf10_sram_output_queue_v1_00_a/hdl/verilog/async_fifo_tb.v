`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:10:53 01/25/2015
// Design Name:   async_fifo
// Module Name:   /local/scratch/jz377/Dropbox/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/devl/projnav/async_fifo_tb.v
// Project Name:  nf10_sram_output_queue
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: async_fifo
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module async_fifo_tb;

	// Inputs
	reg rst;
	reg wr_clk;
	reg rd_clk;
	reg [201:0] din;
	reg wr_en;
	reg rd_en;

	// Outputs
	wire [201:0] dout;
	wire full;
	wire almost_full;
	wire empty;
	wire almost_empty;
	wire valid;

	// Instantiate the Unit Under Test (UUT)
	async_fifo uut (
		.rst(rst), 
		.wr_clk(wr_clk), 
		.rd_clk(rd_clk), 
		.din(din), 
		.wr_en(wr_en), 
		.rd_en(rd_en), 
		.dout(dout), 
		.full(full), 
		.almost_full(almost_full), 
		.empty(empty), 
		.almost_empty(almost_empty), 
		.valid(valid)
	);
	
	always @ (posedge wr_clk) begin
	    if (wr_en == 1'b1)
	        din = din + 1'd1;
	end
	
	always @* begin
	    wr_en = 0;
	    rd_en = 0;
	    if (almost_full != 1'b1)
	        wr_en = 1;
	    if (almost_empty != 1'b1)
	        rd_en = 1;
	end

	initial begin
		// Initialize Inputs
		rst = 0;
		wr_clk = 0;
		rd_clk = 0;
		din = 0;
		wr_en = 0;
		rd_en = 0;
		din = 202'd1;

		// Wait 100 ns for global reset to finish
		#100;

        
		// Add stimulus here
        

	end
	
    always #3.125   begin
        wr_clk = ~wr_clk;         // 160MHz
    end
    

    always #2       rd_clk = ~rd_clk;   // 250MHz
      
endmodule

