module Axi2Fifo_buffer#(
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

reg rden;
reg rden_prev;
reg wren;

reg packet_start;
reg next_packet_start;
reg allow_packet;
reg next_allow_packet;

wire wfull;
wire w_almost_full;
wire rempty;
wire r_almost_empty;
reg [31:0] input_fifo_cnt;
reg [31:0] next_input_fifo_cnt;

reg [(MEM_ADDR_WIDTH-1):0]        mem_usage;
reg [(MEM_ADDR_WIDTH-1):0]        next_mem_usage;
reg [(MEM_ADDR_WIDTH-1):0]        prev_mem_usage;

reg [(8*CROPPED_DATA_WIDTH+10)-1:0]     fifo_data;
reg [(8*CROPPED_DATA_WIDTH+10)-1:0]     next_fifo_data;

wire [(8*TDATA_WIDTH)-1:0]              buffer_tdata;
wire [4:0]                              buffer_tstrb_count;
wire                                    buffer_tlast;

reg [(8*TDATA_WIDTH)-1:0]               buffer_prev_tdata;
reg [4:0]                               buffer_prev_tstrb_count;
reg buffer_prev_tlast;

reg [2:0]                               pkg_state;
reg [2:0]                               next_pkg_state;

reg wren_fifo;
reg next_wren_fifo;
reg [4:0] next_output_queue;

wire [4:0] tstrb_count;

assign tstrb_count[4] = tstrb[16];
assign tstrb_count[3] = (tstrb[8] && ~tstrb[16]) || tstrb[24];
assign tstrb_count[2] = (tstrb[4] && ~tstrb[8]) || (tstrb[12] && ~tstrb[16]) || (tstrb[20] && ~tstrb[24]) || (tstrb[28]);
assign tstrb_count[1] = (^{tstrb[2],tstrb[4],tstrb[6],tstrb[8],tstrb[10],tstrb[12],tstrb[14],tstrb[16],tstrb[18],tstrb[20],tstrb[22],tstrb[24],tstrb[26],tstrb[28],tstrb[30]});
assign tstrb_count[0] = ~(^tstrb);

wire [(8*TDATA_WIDTH+5+1)-1:0]  axi_din;
wire [(8*TDATA_WIDTH+5+1)-1:0]  buffer_dout;

assign axi_din = {tdata,tstrb_count,tlast};

assign  buffer_tdata = buffer_dout[(8*TDATA_WIDTH+5+1)-1:(5+1)];
assign  buffer_tstrb_count = buffer_dout[5:1];
assign  buffer_tlast = buffer_dout[0];

always @(posedge clk)
begin
    if(reset)
    begin
        mem_usage <= QUEUE_SIZE-1;
        prev_mem_usage <= QUEUE_SIZE-1;
        packet_start <= 1'b1;
        allow_packet <= 1'b0;
        input_fifo_cnt <= 32'b0;
    end
    else
    begin
        mem_usage <= next_mem_usage;
        prev_mem_usage <= mem_usage;
        packet_start <= next_packet_start;
        allow_packet <= next_allow_packet;
        input_fifo_cnt <= next_input_fifo_cnt;
    end
end

always @(posedge memclk)
begin
    if(memreset)
    begin
        rden_prev <= 1'b0;
    end
    else
    begin
        rden_prev <= rden;
    end
end

localparam DST_POS = 24;
always @(*)
begin
    /*configure the register here*/
    tready = 1'b0;
    wren = 1'b0;
    rden =1'b0;
    
    next_packet_start = packet_start;
    next_input_fifo_cnt = input_fifo_cnt;
    next_allow_packet = allow_packet;
    
    
    
    if (~r_almost_empty && output_enable && dout_valid) begin
        rden = 1;
    end

    
    if (~w_almost_full)
    begin
        if (!(pkg_state == 3'd0 && next_pkg_state == 3'd1))
            tready = 1'b1 ;

        if(tvalid)
        begin
            next_input_fifo_cnt = input_fifo_cnt + 1;
            
            if(allow_packet)
                wren = 1'b1;
            if(tlast)
                next_packet_start = 1'b1;
            else
                next_packet_start = 1'b0;
            if(packet_start)
            begin
                /**/
                next_output_queue = tuser[DST_POS] |
                (tuser[DST_POS + 2] << 1) |
                (tuser[DST_POS + 4] << 2) |
                (tuser[DST_POS + 6] << 3) | 
                ((tuser[DST_POS + 1] | tuser[DST_POS + 3] | tuser[DST_POS + 5] | tuser[DST_POS + 7]) << 4);
                
                if(prev_mem_usage > (tuser[15:MEM_WORD_BYTES_LOG2]))
                begin
                    wren = 1'b1;
                    next_allow_packet = 1'b1;
                end
                else
                    next_allow_packet = 1'b0;
            end
        end
    end
    
    if(wren && ~output_enable)
        next_mem_usage = mem_usage -1;
    else if (~wren && output_enable)
        next_mem_usage = mem_usage +1;
    else
        next_mem_usage = mem_usage;
end

always @(posedge clk) begin
    if(reset) begin
        buffer_prev_tdata <={(8*TDATA_WIDTH){1'b0}};
        pkg_state <= 3'd0;
        buffer_prev_tlast <= 1'b0;
        fifo_data <= 0;
        rden_fifo <= 0;
    end
    else begin
        if(rden) begin
            buffer_prev_tdata <= buffer_tdata;
            buffer_prev_tlast <= buffer_tlast;
            buffer_prev_tstrb_count <= buffer_tstrb_count;
        end
        else begin
            buffer_prev_tdata <= buffer_prev_tdata;
            buffer_prev_tlast <= buffer_prev_tlast;
            buffer_prev_tstrb_count <= buffer_prev_tstrb_count;
        end
        pkg_state <= next_pkg_state;
        fifo_data <= next_fifo_data;
        rden_fifo <= next_rden_fifo;
    end
end




































async_fifo_buffer buffer(
    .rst(reset),
    .wr_clk(clk),
    .rd_clk(memclk),
    .din(axi_din),
    .wr_en(rden_fifo),
    .rd_en(rden),
    .dout(buffer_dout),
    .full(wfull),
    .almost_full(w_almost_full),
    .empty(rempty),
    .almost_empty(r_almost_empty),
    .valid(dout_valid)
    );
    
endmodule
