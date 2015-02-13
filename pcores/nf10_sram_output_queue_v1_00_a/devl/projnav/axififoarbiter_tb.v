`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:23:59 02/03/2015
// Design Name:   AxiFifoArbiter
// Module Name:   /local/scratch/jz377/Dropbox/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/devl/projnav/axififoarbiter_tb.v
// Project Name:  nf10_sram_output_queue
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: AxiFifoArbiter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module axififoarbiter_tb;

	// Inputs
	reg reset;
	reg memclk;
	reg [4:0] oq;
	reg din_valid;
	reg [201:0] din;

	// Outputs
	wire next_pkg_en;
	wire [2:0] queue_id;
	wire [201:0] dout;
	wire dout_valid;

	// Instantiate the Unit Under Test (UUT)
	AxiFifoArbiter uut (
		.reset(reset), 
		.memclk(memclk), 
		.oq(oq), 
		.din_valid(din_valid), 
		.din(din), 
		.next_pkg_en(next_pkg_en), 
		.queue_id(queue_id), 
		.dout(dout), 
		.dout_valid(dout_valid)
	);
	
	localparam din0 = 202'd1;
	localparam din1 = 202'd101;
	localparam oq0 = 5'b01011;
	localparam oq1 = 5'b11001;
	
	
	reg [20:0] i = 0;

    always @ (posedge memclk) begin
        if (next_pkg_en) begin
            din = din + 1;
            din_valid = 1;
            i = i + 1;
        end
        if (i == 30) begin
        din = din1;
        oq = oq1;
        end
    end

	initial begin
		// Initialize Inputs
		reset = 1;
		memclk = 0;
		oq = 0;
		din_valid = 0;
		din = din0;
		
		#30
		reset = 0;
		din_valid = 1;
		oq = oq0;


//        #48
//        oq = 5'b11001;
//        din = 202'd10;
//        din_valid = 1;
//        
//        #300
//        oq = 5'b01011;
//        din = 202'd20;
//        din_valid = 1; 
        
        
		// Add stimulus here

	end
	
    always #2       memclk = ~memclk;   // 250MHz
      
endmodule

