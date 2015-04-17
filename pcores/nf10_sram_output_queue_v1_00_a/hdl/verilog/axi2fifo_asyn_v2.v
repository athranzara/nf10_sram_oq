module Axi2Fifo_asyn_v2 #(
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
    output reg [NUM_QUEUES-1:0]             oq,
/* Other inputs*/
    input                               memfull
    );

//*******
reg wren_axi, wren_tuser;
reg rden_axis, rden_tuser;
// rden has impact on the next memclk
// while prev_rden indicate the impact of the current rden

wire wfull, w_almost_full, wfull_tuser, w_almost_full_tuser;
wire rempty, r_almost_empty, rempty_tuser, r_almost_empty_tuser;

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


wire [TUSER_WIDTH*8-1:0] tuser_read;



wire [4:0]  tstrb_count;
wire [4:0]  tstrb_count_read;
reg [4:0]   prev_tstrb_count_read;




localparam DST_POS = 24;
localparam IDLE = 0;
localparam WR_PKT = 1;
localparam DROP = 2;

reg wr_state, next_wr_state;

reg fst_wd, next_fst_wd;

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


// write

always @ (posedge clk) begin
    if (reset) begin
        wr_state <= 1'b0;
        fst_wd <= 1'b0;
    end
    else begin
        wr_state <= next_wr_state;
        fst_wd <= next_fst_wd;
    end
end

always @ * begin
    wren_axi = 1'b0;
    wren_tuser = 1'b0;
    tready = 1'b0;
    next_wr_state = wr_state;
    next_fst_wd = fst_wd;

// stay idle, no drops here.
    case (wr_state)
    IDLE:
        begin
            if (tvalid) begin
                if (~w_almost_full && ~w_almost_full_tuser) begin
                    next_wr_state = WR_PKT;
                    next_fst_wd = 1'b1;
                end
                else begin
                    next_wr_state = IDLE;
                end
            end
        end
        
    WR_PKT:
        begin

            if (tvalid) begin
                if (~w_almost_full && ~w_almost_full_tuser) begin
                    next_fst_wd = 1'b0;
                    wren_axi = 1'b1;
                    tready = 1'b1;
                    
                    if (fst_wd) begin
                        wren_tuser = 1'b1;
                    end
                
                    if (tlast) begin
                        next_wr_state = IDLE;
                    end
                end
                
            end
        end
        
    endcase

end


/////////////////////////////////////////////////////////////////
//// Asyn fifo for AXIS
/////////////////////////////////////////////////////////////////
// do not have dout_valid
// this fifo will not output valid number until the first rden.
/////////////////////////////////////////////////////////////////

fallthrough_small_async_fifo #(
    .WIDTH(262),
    .MAX_DEPTH_BITS(4)
    )
    
    buffer_data 
    (
     .din(axi_din),     // Data in
     .wr_en(wren_axi),   // Write enable

     .rd_en(rden_axis),   // Read the next word

     .dout(buffer_dout),    // Data out
     .full(wfull),
     .nearly_full(w_almost_full),
     .empty(rempty),
     .nearly_empty(r_almost_empty),

     .reset(reset),
     .rd_clk(memclk),
     .wr_clk(clk)
     );


fallthrough_small_async_fifo #(
    .WIDTH(128),
    .MAX_DEPTH_BITS(3)
)
    tuser_buffer
    (
    .din(tuser),     // Data in
    .wr_en(wren_tuser),   // Write enable

    .rd_en(rden_tuser),   // Read the next word

    .dout(tuser_read),    // Data out
    .full(wfull_tuser),
    .nearly_full(w_almost_full_tuser),
    .empty(rempty_tuser),
    .nearly_empty(r_almost_empty_tuser),

    .reset(reset),
    .rd_clk(memclk),
    .wr_clk(clk)
    );
/////////////////////////////////////////////////////////////////
//// END of Asyn fifo for AXIS
/////////////////////////////////////////////////////////////////


// read when it is almost_empty for asyn_fifos.

// read state machine
// if 

localparam RD_PKT = 1;
localparam RD_DROP = 2;

reg [1:0] rd_state, next_rd_state;
reg     buffer_dout_valid;


always @ (posedge memclk) begin
    if (reset) begin
        rd_state <= 2'b0;
        prev_tdata_read <={(8*TDATA_WIDTH){1'b0}};
        pkg_state <= 3'd0;
        prev_tlast_read <= 1'b0;
    end
    else begin
        if (rden_axis) begin
            prev_tdata_read <= tdata_read;
            prev_tlast_read <= tlast_read;
            prev_tstrb_count_read <= tstrb_count_read;
        end
        else begin
            prev_tdata_read <= prev_tdata_read;
            
            prev_tstrb_count_read <= prev_tstrb_count_read;
        end
        
        pkg_state <= next_pkg_state;

        rd_state <= next_rd_state;
    end
end

localparam INIT = 0;

always @ * begin
rden_axis = 1'b0;
rden_tuser = 1'b0;
buffer_dout_valid = 1'b0;
next_rd_state = rd_state;
oq = {(NUM_QUEUES){1'b0}};
next_pkg_state = pkg_state;

    case (rd_state) // condition that goes back to rd_state is (~remtpy && ~rempty_tuser)
                    // In this state, all AXIS data will load ready.
    INIT:/*two different possibility for packet start read*/
        begin
        
            if (~tlast_read) begin /* first arrival packet*/
                if (~memfull) begin
                    next_rd_state = RD_PKT;
                end
                else begin
                    next_rd_state = RD_DROP;
                end
            end
            else begin /* the following arrival packet*/
                if (~r_almost_empty && ~r_almost_empty_tuser) begin
                    rden_axis = 1'b1;
                    rden_tuser = 1'b1;
                        if (~memfull) begin
                            next_rd_state = RD_PKT;
                        end
                        else begin
                            next_rd_state = RD_DROP;
                        end
                end
            end
            
        end

        
    RD_PKT: // whenever the tdata buffer has two sets of data 
        begin
            oq = tuser_read[DST_POS] | (tuser_read[DST_POS + 2] << 1) | (tuser_read[DST_POS + 4] << 2) | (tuser_read[DST_POS + 6] << 3) | ((tuser_read[DST_POS + 1] | tuser_read[DST_POS + 3] | tuser_read[DST_POS + 5] | tuser_read[DST_POS + 7]) << 4);
            
            if (~r_almost_empty) begin
            buffer_dout_valid = 1'b1;
            
                case(pkg_state)
                3'd0:   begin
                            if (output_enable) begin
                                    next_pkg_state = 3'd1;
                            end
                        end
                        
                3'd1:   begin /* prev_tlast_read not possible in package 1*/
                            if (output_enable) begin
            //                    if (prev_tlast_read) begin
            //                        next_pkg_state = 3'd0;
            //                    end
            //                    else begin
                                    next_pkg_state = 3'd2;
            //                    end
                            end
                        end
                3'd2:   begin
                            if (output_enable) begin
                                if (prev_tlast_read) begin
                                    next_pkg_state = 3'd0;
                                end
                                else begin
                                    next_pkg_state = 3'd3;
                                end
                            end
                        end
                
                3'd3:   begin
                            if (output_enable) begin
                                if (prev_tlast_read) begin
                                    next_pkg_state = 3'd0;
                                end
                                else begin
                                    next_pkg_state = 3'd4;
                                end
                            end
                        end
                
                3'd4:   begin
                            if (output_enable) begin
                                if (prev_tlast_read) begin
                                    next_pkg_state = 3'd0;
                                end
                                else begin
                                    next_pkg_state = 3'd1;
                                end
                            end
                        end
                default:    next_pkg_state = 3'd0;

                endcase
            
            
            end

        end
    
    RD_DROP:
        begin
            if (r_almost_empty) begin
                rden_axis = 1'b1;
            end
        end
    endcase
    
    
    
    case (pkg_state)
    0: dout_data = {tuser_read, prev_tstrb_count_read, pkg_state, 1'b0, /*rden*/1'b0};
    1: dout_data = {tdata_read[191:0], prev_tstrb_count_read, pkg_state, tlast_read, 1'b0};
    2: dout_data = {tdata_read[127:0], prev_tdata_read[255:192], prev_tstrb_count_read, pkg_state, tlast_read, 1'b0};
    3: dout_data = {tdata_read[63:0], prev_tdata_read[255:128], prev_tstrb_count_read, pkg_state, tlast_read, 1'b0};
    4: dout_data = {prev_tdata_read[255:64], prev_tstrb_count_read, pkg_state, 1'b0, 1'b0};
    default: dout_data = {(8*TDATA_WIDTH+5+1){1'b0}};
    endcase

end

assign dout_valid = buffer_dout_valid;


//// counter for test

//localparam COUNTER = 1;

//reg [7:0] cnt;

//always @ (posedge memclk) begin
//    if (memreset) begin
//        cnt <= 8'd0;
//    end
//    else begin
//        if (cnt == COUNTER) begin
//            cnt <= cnt;
//        end
//        else begin
//            cnt <= cnt + 1'b1;
//        end
//        
//    end
//    
//end



//// read control for test
//always @ (*) begin
//rden_axis = 1'b0;
//rden_tuser = 1'b0;

//if (cnt == COUNTER) begin
//    if (~r_almost_empty) begin
//        rden_axis = 1'b1;
//    end
//    
//    if (~r_almost_empty_tuser) begin
//        if (tlast_read)
//            rden_tuser = 1'b1;
//    end
//end


//    
//end

//test 


endmodule
