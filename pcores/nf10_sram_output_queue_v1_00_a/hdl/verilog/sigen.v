// This module is used for axi stream signal generation

module sigen #(
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

parameter integer MEM_WORD_BYTES_LOG2   = 3,
parameter integer PACKET_LEN = 10,
parameter integer PAUS_INTVAL = 1

)
(
    input                               clk,
    input                               reset,
/* master axi stream interface */
    output reg                          tvalid,
    input                               tready,
    output reg [8*TDATA_WIDTH-1:0]      tdata,
    output reg [8*TSTRB_WIDTH-1:0]      tstrb,
    output reg [8*TUSER_WIDTH-1:0]      tuser,
    output reg                          tlast
    );
    
localparam LOAD = 0;
localparam TRSM = 1;
localparam PAUS = 2;

localparam [95:0]   tuser_para1 = 96'b0;
localparam [7:0]    tuser_para2 = 8'b10101111;
localparam [23:0]   tuser_para3 = 24'b1;
localparam [7:0]    tuser_para2_2 = 8'b11101010;

localparam [8*TDATA_WIDTH-1:0] tdata0 = 50;
localparam [8*TDATA_WIDTH-1:0] tdata1 = 150;
localparam [8*TDATA_WIDTH-1:0] tdata2 = 250;
localparam [8*TDATA_WIDTH-1:0] tdata3 = 350;


reg [8*TDATA_WIDTH-1:0] tdata_temp;
reg [1:0] state, next_state;
reg [1:0] pattern_num, next_pattern_num;
reg [8*TUSER_WIDTH-1:0] tuser_temp;
reg [10:0] paus_intval, next_paus_intval;


reg [7:0]   i;
reg [7:0]   next_i;

reg [8*TDATA_WIDTH-1:0] next_tdata;
reg [8*TSTRB_WIDTH-1:0] next_tstrb;
reg [8*TUSER_WIDTH-1:0] next_tuser;

reg next_tlast;


always @ (posedge clk) begin
    if (reset) begin
        state <= 2'd0;
        pattern_num <=2'd0;
        tdata = {(8*TDATA_WIDTH){1'b0}};
        tstrb = {(8*TSTRB_WIDTH){1'b0}};
        tuser = {(8*TUSER_WIDTH){1'b0}};
        tlast = 1'b0;
        paus_intval = 11'b0;
    end
    else begin
        state <= next_state;
        i <= next_i;
        tdata <= next_tdata;
        tstrb <= next_tstrb;
        tuser <= next_tuser;
        tlast <= next_tlast;
        pattern_num <= next_pattern_num;
        paus_intval <= next_paus_intval;
    end
end

always @ * begin

tdata_temp = {(8*TDATA_WIDTH){1'b0}};

    case (pattern_num)
        2'd0:
        begin
            tdata_temp = tdata0;
            tuser_temp = {tuser_para1,tuser_para2,tuser_para3};
        end
        
        2'd1:
        begin
            tdata_temp = tdata1;
            tuser_temp = {tuser_para1,tuser_para2_2,tuser_para3};
        end
        
        2'd2:
        begin
            tdata_temp = tdata2;
            tuser_temp = {tuser_para1,tuser_para2,tuser_para3};
        end
        
        2'd3:
        begin
            tdata_temp = tdata3;
            tuser_temp = {tuser_para1,tuser_para2_2,tuser_para3};
        end
    endcase

end


always @ (*) begin
tvalid = 1'b0;
next_state = state;

next_tdata = tdata;
next_tuser = tuser;
next_tstrb = tstrb;
next_tlast = tlast;
next_i = i;

next_paus_intval = paus_intval;

next_pattern_num = pattern_num;


    if (state == TRSM)
        tvalid = 1'b1;

    case (state)

    LOAD:
    begin
        next_i = 8'b0;
        next_paus_intval = 11'b0;
        next_tdata = tdata_temp;
        next_tuser = tuser_temp;
        next_tstrb = {(8*TSTRB_WIDTH){1'b1}};
        next_pattern_num = pattern_num + 1'b1;
        next_state = TRSM;
        next_tlast = 1'b0;
    end

    TRSM:
    begin
        if (tready) begin
            next_tuser = {(8*TUSER_WIDTH){1'b0}};
            if (i == (PACKET_LEN)) begin
                next_state = PAUS;
            end
            else begin
                next_tdata = tdata + 1'b1;
                next_i = i + 1'b1;
                if (i == (PACKET_LEN -1 )) begin
                    next_tstrb = 32'h0000ffff;
                    next_tlast = 1'b1;
                end
                else begin
                    next_tdata = tdata + 1'b1;
                    next_i = i + 1'b1;
                end
            end
        end
    end

    PAUS:
    begin
        if (paus_intval == PAUS_INTVAL) begin
            next_paus_intval = 11'b0;
            if (pattern_num == 2'd4) begin
                next_state = PAUS;
            end
            else begin
                next_state = LOAD;
            end
        end
        else begin
            next_paus_intval = paus_intval + 1'b1;
        end
        
    end
    
    endcase

end




endmodule
