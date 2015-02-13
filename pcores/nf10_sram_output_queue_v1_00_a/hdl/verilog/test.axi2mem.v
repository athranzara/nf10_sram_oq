module Axi2Mem;

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
	
	Axi2Fifo uut (
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

