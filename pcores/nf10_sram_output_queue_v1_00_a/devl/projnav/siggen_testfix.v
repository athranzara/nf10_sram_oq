

module sigen_testfix;

	// Inputs
	reg clk;
	reg reset;

	reg tready;

	// Outputs
	wire tvalid;
	wire [255:0] tdata;
	wire [31:0] tstrb;
	wire [127:0] tuser;
	wire tlast;

	// Instantiate the Unit Under Test (UUT)
	sigen uut (
		.clk(clk), 
		.reset(reset), 
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
		tready = 0;

		// Wait 100 ns for global reset to finish
		#10;
        
		// Add stimulus here
		reset = 0;
		
		#100
		tready = 1;

	end

    always #3.125   begin
        clk = ~clk;         // 160MHz
    end

    
endmodule

