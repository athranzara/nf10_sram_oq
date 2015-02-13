module AxiToFifo
#(
///////////////////////////////////////////////////////////////////////////////
// Parameter Definitions
///////////////////////////////////////////////////////////////////////////////
                    // Width of TID signals.
                    // Range: >= 1.
    parameter integer TID_WIDTH             = 4, 
                    // Width of AXI data bus in bytes
    parameter integer TDATA_WIDTH           = 32,
                    // Width of CROPPED FIFO data in bits
    parameter integer CROPPED_DATA_WIDTH    = 24,

                    // Width of TUSER in bits
    parameter integer TUSER_WIDTH           = 128,

    parameter integer TDEST_WIDTH           = 4,
    parameter integer NUM_QUEUES            = 5,
    parameter integer QUEUE_ID_WIDTH        = 3,
    parameter integer MEM_ADDR_WIDTH        = 19,
    parameter integer MEM_NUM_WORDS         = 524288,
    parameter integer QUEUE_SIZE            = MEM_NUM_WORDS/NUM_QUEUES,
    parameter integer MEM_WORD_BYTES_LOG2   = 3
)
(
    input                                   clk,
    input                                   reset,
    input                                   tvalid,
    output reg                              tready,
    input [((8*TDATA_WIDTH) - 1):0]         tdata,
    input [(TDATA_WIDTH-1):0]               tstrb,
    input                                   tlast,
    input [(TUSER_WIDTH-1):0]               tuser,
    input                                   memclk,
    input                                   memreset,
    input                                   rden,
    output                                  rempty,
    output                                  r_almost_empty,
    output                                  dout_valid,
    output [(8*CROPPED_DATA_WIDTH+10)-1:0]  dout,
    input                                   cal_done,
    input                                   output_inc,
    output reg [31:0]                       input_fifo_cnt
);

wire wfull, w_almost_full;
reg [(QUEUE_ID_WIDTH-1):0]                  latched_queue_id;
reg [(QUEUE_ID_WIDTH-1):0]                  next_latched_queue_id;
reg [(MEM_ADDR_WIDTH-1):0]                  mem_usage;
reg [(MEM_ADDR_WIDTH-1):0]                  next_mem_usage;
reg [(MEM_ADDR_WIDTH-1):0]                  prev_mem_usage;

reg mem_full;
reg next_packet_start;
reg packet_start;
reg next_allow_packet;
reg allow_packet;
reg next_dout_valid;
reg rden_prev;
reg [31:0] next_input_fifo_cnt;
reg wren;


always @(posedge clk)
begin
    if(reset)
    begin
        mem_usage <= QUEUE_SIZE-1;
        prev_mem_usage <= QUEUE_SIZE-1;
        packet_start <= 1'b1;
        allow_packet <= 1'b0;
    end
    else
    begin
        mem_usage <= next_mem_usage;
        prev_mem_usage <= mem_usage;
        packet_start <= next_packet_start;
        allow_packet <= next_allow_packet;
    end
end

always @(posedge clk)
begin
    if(reset)
        input_fifo_cnt <= 32'b0;
    else
        input_fifo_cnt <= next_input_fifo_cnt;
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


reg [2:0] pkg_state;
    
always @(*)
begin
    /*configure the register here*/
    tready = 1'b0;
    wren = 1'b0;
    
    next_packet_start = packet_start;
    next_input_fifo_cnt = input_fifo_cnt;
    next_allow_packet = allow_packet;
    
    if (~w_almost_full && cal_done && (pkg_state != 3'd4))
    begin
        tready = 1'b1;
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
    
    if (wren && ~output_inc)
        next_mem_usage = mem_usage-1;
    else if(~wren && output_inc)
        next_mem_usage = mem_usage+1;
    else
        next_mem_usage = mem_usage;
end




//////////////////////////////////////////////////////////////////////////////////    



reg [(8*CROPPED_DATA_WIDTH+10) -1 : 0]         fifo_data;
reg [(8*CROPPED_DATA_WIDTH+10) -1 : 0]         next_fifo_data;
reg [(8*TDATA_WIDTH) - 1 : 0]           prev_tdata;
reg [TDATA_WIDTH - 1 : 0]               prev_tstrb;
reg                 prev_tlast;
reg [2:0]           next_pkg_state;
wire [4:0]          tstrb_count;
reg                 prev_tstrb_count;
reg                 wren_fifo;
reg                 next_wren_fifo;


assign tstrb_count[4] = tstrb[16];
assign tstrb_count[3] = (tstrb[8] && ~tstrb[16]) || tstrb[24];
assign tstrb_count[2] = (tstrb[4] && ~tstrb[8]) || (tstrb[12] && ~tstrb[16]) || (tstrb[20] && ~tstrb[24]) || (tstrb[28]);
assign tstrb_count[1] = (^{tstrb[2],tstrb[4],tstrb[6],tstrb[8],tstrb[10],tstrb[12],tstrb[14],tstrb[16],tstrb[18],tstrb[20],tstrb[22],tstrb[24],tstrb[26],tstrb[28],tstrb[30]});
assign tstrb_count[0] = ~(^tstrb);
    
always @(posedge clk)
begin
    if(reset) begin
        prev_tdata <= {(8*TDATA_WIDTH){1'b0}};
        prev_tstrb <= {(TDATA_WIDTH){1'b0}};
        pkg_state <= 3'b0;
        prev_tlast <= 1'b0;
        fifo_data <= 0;
        wren_fifo <= 0;
    end
    else begin
        if(wren) begin
            prev_tdata <= tdata;
            prev_tlast <= tlast;
            prev_tstrb <= tstrb;
        end
        else begin
            prev_tdata <= prev_tdata;
            prev_tlast <= prev_tlast;
            prev_tstrb <= prev_tstrb;
        end
        pkg_state <= next_pkg_state;
        fifo_data <= next_fifo_data;
        wren_fifo <= next_wren_fifo;
    end

        /* Need A register (wren) here that record when should change the pkg buffering state*/

end


always @(*)
begin
    case(pkg_state)
        0: next_fifo_data = {tuser, prev_tstrb_count, pkg_state, tlast, wren};
        1: next_fifo_data = {tdata[191:0], prev_tstrb_count, pkg_state, tlast, wren};
        2: next_fifo_data = {tdata[127:0], prev_tdata[255:192], prev_tstrb_count, pkg_state, tlast, wren};
        3: next_fifo_data = {tdata[63:0], prev_tdata[255:128], prev_tstrb_count, pkg_state, tlast, wren};
        4: next_fifo_data = {prev_tdata[255:64], prev_tstrb_count, pkg_state, 1'b0, wren};
    endcase
    
    next_wren_fifo = 1'b0;
    
    if (wren || (pkg_state == 3'd4)) begin
        if (pkg_state == 3'd4) begin
        next_pkg_state = 3'd0;
        end
        else begin
        next_pkg_state = pkg_state + 3'd1;
        end
        
        next_wren_fifo = 1'b1;
    end
    else if (prev_tlast && ( (pkg_state == 3'd1) || (pkg_state == 3'd2) || (pkg_state == 3'd3))) begin
        next_pkg_state = 3'd0;
        next_wren_fifo = 1'b1;
    end
    else
        next_pkg_state = pkg_state;
end

// AXI state machine 
always @(*) begin
    


end


async_fifo fifo(reset, clk, memclk, fifo_data, wren_fifo, rden, dout, wfull, w_almost_full, rempty, r_almost_empty, dout_valid);




endmodule
