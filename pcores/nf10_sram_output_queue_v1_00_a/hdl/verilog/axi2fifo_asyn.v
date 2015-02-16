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
reg wfull, w_almost_full;
reg rempty, r_almost_empty;

wire [(TDATA_WIDTH*8+5+1)-1 : 0]    axi_din;
wire [(TDATA_WIDTH*8+5+1)-1 : 0]    buffer_dout;

wire [TDATA_WIDTH*8-1 : 0]  tdata_read;
reg [TDATA_WIDTH*8-1 : 0]   prev_tdata_read;
wire                        tlast_read;
reg                         prev_tlast_read;



wire [4:0]  tstrb_count;
wire [4:0]  tstrb_count_read;
reg [4:0]   prev_tstrb_count_read;
//*********

assign axi_din = {tdata,tstrb_count,tlast};
assign tdata_read = buffer_dout[];
assign tlast_read = buffer_dout[];
assign tstrb_count_read

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

    if(~w_almost_full /*|| ~wfull*/) begin
        tready = 1'b1;
        wren = 1'b1;
    end
    
    if(~r_almost_empty) begin
        rden = 1'b1; // more condition should be add later
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
    else if (wren) begin
        buffer_wren <= 1'b1;
    end
    else begin
        buffer_wren <= 1'b0;
    end
end

always @ * begin
    rden = 1'b0;
    
end

// read
always @ (posedge memclk) begin
    if (reset) begin
        prev_tdata_read <={(8*TDATA_WIDTH){1'b0}};
        pkg_state <= 3'd0
        buffer_rden <= 1'b0;
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
        buffer_rden <= next_buffer_rden;    
    end

end



buffer_axis_data buffer_data (
    .rst(reset),
    .wr_clk(clk),
    .rd_clk(memclk),
    .din(axi_din),
    .wr_en(buffer_wren),
    .rd_en(buffer_rden),
    .dout(buffer_dout),
    .full(wfull),
    .almost_full(w_almost_full),
    .empty(rempty),
    .almost_empty(r_almost_empty),
    .valid(dout_valid)
    );
    
endmodule
