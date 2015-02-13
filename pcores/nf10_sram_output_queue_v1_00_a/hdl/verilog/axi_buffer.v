module axi_buffer #(
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



)(
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
/* master axi stream interface */
    output                              dout_valid,
    output [(8*(TDATA_WIDTH+TUSER_WIDTH)+5+1)-1:0]  dout
    );

wire [4:0] tstrb_count;
reg [4:0] prev_tstrb_count;

assign tstrb_count[4] = tstrb[16];
assign tstrb_count[3] = (tstrb[8] && ~tstrb[16]) || tstrb[24];
assign tstrb_count[2] = (tstrb[4] && ~tstrb[8]) || (tstrb[12] && ~tstrb[16]) || (tstrb[20] && ~tstrb[24]) || (tstrb[28]);
assign tstrb_count[1] = (^{tstrb[2],tstrb[4],tstrb[6],tstrb[8],tstrb[10],tstrb[12],tstrb[14],tstrb[16],tstrb[18],tstrb[20],tstrb[22],tstrb[24],tstrb[26],tstrb[28],tstrb[30]});
assign tstrb_count[0] = ~(^tstrb);

wire [(8*TDATA_WIDTH+5+1)-1:0]  axi_din;
wire [(8*TDATA_WIDTH+5+1)-1:0]  fifo_dout;

assign axi_din = {tdata,tstrb_count,tlast};

reg     buffer_wren;
reg     buffer_rden;
reg     buffer_full;
reg     buffer_almost_full;
reg     buffer_empty;
reg     buffer_almost_empty;
reg     buffer_valid;

always @ (posedge clk) begin
    if (reset) begin
    
    end
end

always @ * begin
    buffer_wren = 1'b0;
    buffer_rden = 1'b0;
    
    if (~buffer_almost_full) begin
        if (tvalid) begin
            buffer_wren = 1'b0;
        end
    end

end

async_fifo_buffer buffer(
    .rst(reset),
    .wr_clk(clk),
    .rd_clk(memclk),
    .din(axi_din),
    .wr_en(buffer_wren),
    .rd_en(buffer_rden),
    .dout(fifo_dout),
    .full(buffer_full),
    .almost_full(buffer_almost_full),
    .empty(buffer_empty),
    .almost_empty(buffer_almost_empty),
    .valid(buffer_valid)
    );


endmodule
