`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:51:19 04/02/2015
// Design Name:   test_siggen
// Module Name:   /local/scratch/jz377/git_repo/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/devl/projnav/siggen_testfix.v
// Project Name:  nf10_sram_output_queue
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: test_siggen
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sigen_testfix;

	// Inputs
	reg clk;
	reg reset;
	reg memclk;
	reg memreset;
	reg tready;

	// Outputs
	wire tvalid;
	wire [255:0] tdata;
	wire [31:0] tstrb;
	wire [127:0] tuser;
	wire tlast;

	// Instantiate the Unit Under Test (UUT)
	test_sigen uut (
		.clk(clk), 
		.reset(reset), 
		.memclk(memclk), 
		.memreset(memreset), 
		.tvalid(tvalid), 
		.tready(tready), 
		.tdata(tdata), 
		.tstrb(tstrb), 
		.tuser(tuser), 
		.tlast(tlast)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		memclk = 0;
		memreset = 1;
		tready = 0;

		// Wait 100 ns for global reset to finish
		#10;
        
		// Add stimulus here
		reset = 0;
		memreset = 0;
		
		#100
		tready = 1;

	end

    always #3.125   begin
        clk = ~clk;         // 160MHz
    end


    always #2 begin
        memclk = ~memclk;   // 250MHz
    end
    
endmodule

