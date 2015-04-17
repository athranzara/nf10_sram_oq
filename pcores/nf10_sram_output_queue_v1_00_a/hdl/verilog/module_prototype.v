module module_prototype;

// inputs
    reg clk;
    reg reset;
    reg memclk;
    reg memreset;
    reg memfull;
    
// template output
    wire [201:0] dout;
    wire dout_valid;
    


//sigen wires
    wire sig_tvalid;
    wire [255:0]    sig_tdata;
    wire [127:0]    sig_tuser;
    wire [31:0]     sig_tstrb;
    wire            sig_tlast;
    wire [4:0]      oq;

//axi2fifo_asyn_v2 wire
    wire a2a_tready;
    
sigen #(
.PACKET_LEN(50)
) 
sigen (
    .clk(clk),
    .reset(reset),
    .tvalid(sig_tvalid),
    .tready(a2a_tready),
    .tdata(sig_tdata),
    .tstrb(sig_tstrb),
    .tuser(sig_tuser),
    .tlast(sig_tlast)
);



Axi2Fifo_asyn_v2 a2f(
    .clk(clk), 
    .reset(reset), 
    .memclk(memclk), 
    .memreset(memreset), 
    .tvalid(sig_tvalid), 
    .tready(a2a_tready), 
    .tdata(sig_tdata), 
    .tstrb(sig_tstrb), 
    .tuser(sig_tuser), 
    .tlast(sig_tlast), 
    .dout(dout), 
    .dout_valid(dout_valid), 
    .output_enable(output_enable),
    .oq(oq),
    .memfull(memfull)

);


initial begin
    // Initialize Inputs
    clk = 0;
    reset = 1;
    memclk = 0;
    memreset = 1;
    memfull = 0;

    // Wait 100 ns for global reset to finish
    #20;
    
    // Add stimulus here
    reset = 0;
    memreset = 0;


end

always #3.125   begin
    clk = ~clk;         // 160MHz
end

always #2 begin
    memclk = ~memclk;   // 250MHz
end


//template test inputs for current module

reg output_enable, nxt_output_enable;

always @ (posedge memclk) begin
    if (reset) begin
        output_enable <= 1'b0;
    end
    else begin
        output_enable <=nxt_output_enable;
    end
end


always @ * begin
nxt_output_enable = output_enable;
    if (dout_valid) begin
        nxt_output_enable = 1'b1;
    end
end
//template test for current module

endmodule
