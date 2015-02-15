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


wire [4:0] tstrb_count;

assign tstrb_count[4] = tstrb[16];
assign tstrb_count[3] = (tstrb[8] && ~tstrb[16]) || tstrb[24];
assign tstrb_count[2] = (tstrb[4] && ~tstrb[8]) || (tstrb[12] && ~tstrb[16]) || (tstrb[20] && ~tstrb[24]) || (tstrb[28]);
assign tstrb_count[1] = (^{tstrb[2],tstrb[4],tstrb[6],tstrb[8],tstrb[10],tstrb[12],tstrb[14],tstrb[16],tstrb[18],tstrb[20],tstrb[22],tstrb[24],tstrb[26],tstrb[28],tstrb[30]});
assign tstrb_count[0] = ~(^tstrb);



async_fifo_buffer buffer(
    .rst(reset),
    .wr_clk(clk),
    .rd_clk(memclk),
    .din(axi_din),
    .wr_en(wren),
    .rd_en(rden),
    .dout(buffer_dout),
    .full(wfull),
    .almost_full(w_almost_full),
    .empty(rempty),
    .almost_empty(r_almost_empty),
    .valid(dout_valid)
    );
    
endmodule
