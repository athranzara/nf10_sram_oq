// This module attempt to achieve 40 Gb/s however, the output reading is not correct
// Further debuging is requried.


module Axi2Fifo_asyn #(
///////////////////////////////////////////////////////////////////////////////
// Parameter Definitions
///////////////////////////////////////////////////////////////////////////////

/* parameters in bytes */
parameter integer TDATA_WIDTH           = 32,
parameter integer TSTRB_WIDTH           = TDATA_WIDTH/8,
parameter integer TUSER_WIDTH           = 16,
parameter integer CROPPED_DATA_WIDTH    = 24,

parameter integer NUM_QUEUES            = 5,
parameter integer QUEUE_ID_WIDTH        = 3,
parameter integer MEM_ADDR_WIDTH        = 19,
parameter integer MEM_NUM_WORDS         = 524288,
parameter integer QUEUE_SIZE            = MEM_NUM_WORDS/5,

parameter integer MEM_WORD_BYTES_LOG2   = 3
)
(
    input                               clk,
    input                               reset,
    input                               memclk,
    input                               memreset,
/* slave axi stream interface */
    input                               tvalid,
    output reg                          tready,
    input [8*TDATA_WIDTH-1:0]           tdata,
    input [8*TSTRB_WIDTH-1:0]           tstrb,
    input [8*TUSER_WIDTH-1:0]           tuser,
    input                               tlast,
/* master data stream */
    output [(8*CROPPED_DATA_WIDTH+10)-1:0]  dout, //datawidth to fifo2Mem might need to change
    output                              dout_valid,
    input                               output_enable,
    output reg [NUM_QUEUES-1:0]         oq
    );
    
//*******
reg wren;
reg rden;

reg buffer_wren;
reg buffer_rden;
reg next_buffer_rden;
wire wfull, w_almost_full;
wire rempty, r_almost_empty;

reg [2:0]   pkg_state;
reg [2:0]   next_pkg_state;

reg [(8*CROPPED_DATA_WIDTH+10)-1:0]  dout_data;
reg [(8*CROPPED_DATA_WIDTH+10)-1:0]  next_dout_data;

wire [(TDATA_WIDTH*8+5+1)-1 : 0]    axi_din;
wire [(TDATA_WIDTH*8+5+1)-1 : 0]    buffer_dout;

wire [TDATA_WIDTH*8-1 : 0]  tdata_read;
reg [TDATA_WIDTH*8-1 : 0]   prev_tdata_read;
wire                        tlast_read;
reg                         prev_tlast_read;



wire [4:0]  tstrb_count;
wire [4:0]  tstrb_count_read;
reg [4:0]   prev_tstrb_count_read;

wire     buffer_dout_valid;

//*********

assign axi_din = {tdata,tstrb_count,tlast};
assign tdata_read = buffer_dout[((TDATA_WIDTH*8+5+1)-1) : ((TDATA_WIDTH*8+5+1) - (8*TDATA_WIDTH))];
assign tlast_read = buffer_dout[0];
assign tstrb_count_read = buffer_dout[(1+5)-1 : 1];

assign tstrb_count[4] = tstrb[16];
assign tstrb_count[3] = (tstrb[8] && ~tstrb[16]) || tstrb[24];
assign tstrb_count[2] = (tstrb[4] && ~tstrb[8]) || (tstrb[12] && ~tstrb[16]) || (tstrb[20] && ~tstrb[24]) || (tstrb[28]);
assign tstrb_count[1] = (^{tstrb[2],tstrb[4],tstrb[6],tstrb[8],tstrb[10],tstrb[12],tstrb[14],tstrb[16],tstrb[18],tstrb[20],tstrb[22],tstrb[24],tstrb[26],tstrb[28],tstrb[30]});
assign tstrb_count[0] = ~(^tstrb);

// combinational logical interface


always @ * begin
    tready = 1'b0;
    wren = 1'b0;
    rden = 1'b0;
    

    if(~w_almost_full ) begin
        if (buffer_wren) begin
            tready = 1'b1;
        end        
        wren = 1'b1;
    end    
    
    if(~r_almost_empty) begin    
        if ((pkg_state != 3'd4) && (pkg_state != 3'd0)) begin
            if (output_enable) begin
                rden = 1'b1;
            end
        end                         
    end
end

// asynchrounos buffer
// in which condition to write axi to the buffer?


// link





// write

always @ (posedge clk) begin
    if (reset) begin
        buffer_wren <= 1'b0;
    end
    else begin
        if (wren) begin
            buffer_wren <= 1'b1;
        end
        else begin
            buffer_wren <= 1'b0;
        end
    end
end

reg read_pkg_start;
reg next_read_pkg_start;

// read
always @ (posedge memclk) begin
    if (reset) begin
        read_pkg_start <= 1'b1;
        
    end
    else begin
        read_pkg_start <= next_read_pkg_start;
    end
end

always @ (*) begin
    next_read_pkg_start = read_pkg_start;
    
    if (dout_valid) begin
        if (tlast_read) begin
            next_read_pkg_start = 1'b1;
        end
        else begin
            next_read_pkg_start = 1'b0;
        end
    end
end

// need package start indicator for reading side

//reg [261:0] buffer_dout_syn;
//reg         dout_valid_syn; 

//always @ (posedge memclk) begin
//    if (reset) begin
//        buffer_dout_syn <= {(262){1'b0}};
//        dout_valid_syn <= 1'b0;
//    end
//    else begin
//        if (buffer_dout_valid) begin
//            buffer_dout_syn <= buffer_dout;
//            dout_valid_syn <= 1'b1;
//        end
//        else begin
//            dout_valid_syn <= 1'b0;
//        end
//    end
//end


//
always @ (posedge memclk) begin
    if (reset) begin
        prev_tdata_read <={(8*TDATA_WIDTH){1'b0}};
        pkg_state <= 3'd0;
        prev_tlast_read <= 1'b0;
        dout_data <= {(8*TDATA_WIDTH+5+1){1'b0}};

//        buffer_rden <= 1'b0;
    end
    else begin
        if (rden) begin
            prev_tdata_read <= tdata_read;
            prev_tlast_read <= tlast_read;
            prev_tstrb_count_read <= tstrb_count_read;
        end
        else begin
            prev_tdata_read <= prev_tdata_read;
            prev_tlast_read <= prev_tlast_read;
            prev_tstrb_count_read <= prev_tstrb_count_read;
        end
        
        pkg_state <= next_pkg_state;
        dout_data <= next_dout_data;
//        buffer_rden <= next_buffer_rden;    
    end

end

//reg pkg_changed;


always @ (pkg_state or output_enable or dout_valid or read_pkg_start or prev_tlast_read) begin
//    next_buffer_rden = 1'b0; 

    next_pkg_state = pkg_state;
    
    case (pkg_state)
        0: next_dout_data = {tuser/*need buffering*/, prev_tstrb_count_read, pkg_state, tlast_read, rden};
        1: next_dout_data = {tdata_read[191:0], prev_tstrb_count_read, pkg_state, tlast_read, rden};
        2: next_dout_data = {tdata_read[127:0], prev_tdata_read[255:192], prev_tstrb_count_read, pkg_state, tlast_read, rden};
        3: next_dout_data = {tdata_read[63:0], prev_tdata_read[255:128], prev_tstrb_count_read, pkg_state, tlast_read, rden};
        4: next_dout_data = {prev_tdata_read[255:64], prev_tstrb_count_read, pkg_state, 1'b0, rden};
    endcase
    

// pkg not correct here.

        if (pkg_state == 3'd0) begin
            
            if (output_enable) begin
                if (dout_valid) begin
                    next_pkg_state = pkg_state + 3'd1;
                end
                else begin
                    next_pkg_state = pkg_state;
                end
            end
        end
        
        else if (pkg_state == 3'd4) begin
            if (output_enable) begin
                if (dout_valid) begin
                    if (~read_pkg_start) begin
                        next_pkg_state = 3'd1;

                    end
                    else begin
                        next_pkg_state = 3'd0;

                    end
                end
                else begin
                    next_pkg_state = pkg_state;
                end
            end
        end
        
        else if ( (pkg_state == 3'd1) || (pkg_state == 3'd2) || (pkg_state == 3'd3) ) begin
            if (output_enable) begin
                if (dout_valid) begin
                    if (prev_tlast_read) begin
                        next_pkg_state = 3'd0;
                    end
                    else begin
                        next_pkg_state = pkg_state + 3'd1;
                    end
                end
                else begin
                    next_pkg_state = pkg_state;
                end
            end   
        end
        
        else begin
            next_pkg_state = pkg_state;
        end
    
end


// read test
    
    reg [127:0] test_tuser=0;
    reg [255:0] test_tdata=0;
    reg [4:0]   test_tstrb=0;
    reg [3:0]   test_pkg_state=0;
    reg         test_tlast=0;
    reg [2:0] test_queue_id=0;
    

    always @ * begin
        if(dout_valid) begin
            test_pkg_state = dout_data[4:2];
            case (dout_data[4:2])
            3'd0:   begin
                        test_tuser = dout_data[137:10];
                        test_tstrb = dout_data[9:5];
                        test_tlast = dout_data[1];
                    end
            3'd1:   begin
                        test_tdata = dout_data[201:10];
                        test_tstrb = dout_data[9:5];
                        test_tlast = dout_data[1];
                    end
            3'd2:   begin
                        test_tdata = dout_data[201:74];
                        test_tstrb = dout_data[9:5];
                        test_tlast = dout_data[1];
                    end
            3'd3:   begin
                        test_tdata = dout_data[201:138];
                        test_tstrb = dout_data[9:5];
                        test_tlast = dout_data[1];
                    end
            3'd4:   begin
                        test_tdata = dout_data[201:10];
                        test_tstrb = dout_data[9:5];
                        test_tlast = dout_data[1];
                    end
            endcase
        end
    end

assign dout_valid = test;
reg test;
always @ (posedge memclk) begin
    test = 1'b1;
end

// do not have dout_valid
fallthrough_small_async_fifo #(
    .WIDTH(262),
    .MAX_DEPTH_BITS(3)
    )   
    
    buffer_data 
    (
     .din(axi_din),     // Data in
     .wr_en(buffer_wren),   // Write enable

     .rd_en(rden),   // Read the next word

     .dout(buffer_dout),    // Data out
     .full(wfull),
     .nearly_full(w_almost_full),
     .empty(rempty),
     .nearly_empty(r_almost_empty),

     .reset(reset),
     .rd_clk(memclk),
     .wr_clk(clk)
     );
     
     

    

endmodule
