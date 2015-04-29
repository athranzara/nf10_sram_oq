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

reg output_enable;

always @ (posedge memclk) begin
    if (reset) begin
        ctrl_state = 1'b0;
    end
    else begin
        ctrl_state = next_ctrl_state;
    end
end


reg ctrl_state, next_ctrl_state;

//always @ * begin
//output_enable = 1'b0;
//next_ctrl_state = ctrl_state;

//if (dout_valid)
//    output_enable = 1'b1;

////// delayed output_enable perform better
////    case (ctrl_state)
////    0:
////        begin
////            if (dout_valid) begin
////                next_ctrl_state = 1'b1;
////            end
////        end
////    
////    
////    1:
////        begin
////            if (dout_valid) begin
////                output_enable = 1'b1;
////            end
////            else begin
////                next_ctrl_state = 1'b0;
////            end
////        end
////    endcase
//    
//end


//template test for current module









// fifo to axi template

reg wr_f2a;
reg rd_f2a;
reg wfull_f2a, w_almost_full_f2a;
reg rempty_f2a, r_almost_empty_f2a;

reg [201:0] dout_pkg;

//// write from mememry to fifo
//always @ (posedge memclk) begin
//    if (reset) begin
//        
//    end

//end

always @ * begin
    wr_f2a = 1'b0;
    // output_enable template
    output_enable = 1'b0;
    
    
    if (dout_valid && ~w_almost_full_f2a) begin
        wr_f2a = 1'b0;
        // output_enable template
        output_enable = 1'b1;
    end
end


//

fallthrough_small_async_fifo #(
    .WIDTH(202),
    .MAX_DEPTH_BITS(4)
    )
    
    fifo2axi 
    (
     .din(dout),     // Data in
     .wr_en(wr_f2a),   // Write enable

     .rd_en(rd_f2a),   // Read the next word

     .dout(dout_pkg),    // Data out
     .full(wfull_f2a),
     .nearly_full(w_almost_full_f2a),
     .empty(rempty_f2a),
     .nearly_empty(r_almost_empty_f2a),

     .reset(reset),
     .rd_clk(memclk),
     .wr_clk(clk)
     );
//

// read from f2a
always @ (posedge clk) begin
    if (reset) begin
    
    end
    else begin
    
    end
end

always @ * begin
rd_f2a = 1'b0;
    case 
    
    endcase

end

// axi simulator

reg s_axi_state,nxt_s_axi_state;
reg s_axi_tready;

always @ (posedge clk) begin
    if (reset) begin
        s_axi_state = 1'b0;
    end
    else begin
        s_axi_state = nxt_s_axi_state;
    end

end

always @ * begin
nxt_s_axi_state = s_axi_state;
s_axi_tready = 1'b0;

    case (s_axi_state)
    0:
        begin
            if (~r_almost_empty_f2a)
                nxt_s_axi_state = 1'b1;
        end
    1:
        begin
            if (r_almost_empty_f2a) begin
                nxt_s_axi_state = 1'b0;
            end
            else
                s_axi_tready = 1'b1;
        end
    endcase

end


// read test
// generate input instant
    
    reg [127:0] test_tuser=0;
    reg [255:0] test_tdata1=0;
    reg [255:0] test_tdata2=0;
    reg [255:0] test_tdata_cur=0;
    reg [255:0] test_tdata_prev=0;
    reg [4:0]   test_tstrb=0;
    reg [3:0]   test_pkg_state=0;
    reg         test_tlast=0;
    reg [2:0] test_queue_id=0;
    



always @ * begin

    test_pkg_state = dout[4:2];
    case (dout[4:2])
    3'd0:   begin
                test_tuser = dout[137:10];
                test_tstrb = dout[9:5];
                test_tlast = dout[1];
            end
    3'd1:   begin
                test_tdata1 = dout[201:10];
                test_tdata2 = 0;
                test_tstrb = dout[9:5];
                test_tlast = dout[1];
            end
    3'd2:   begin
                test_tdata1 = dout[201:74];
                test_tdata2 = dout[73:10];
                test_tstrb = dout[9:5];
                test_tlast = dout[1];
            end
    3'd3:   begin
                test_tdata1 = dout[201:138];
                test_tdata2 = dout[137:10];
                test_tstrb = dout[9:5];
                test_tlast = dout[1];
            end
    3'd4:   begin
                test_tdata1 = dout[201:10];
                test_tstrb = dout[9:5];
                test_tlast = dout[1];
            end
    endcase


end




endmodule
