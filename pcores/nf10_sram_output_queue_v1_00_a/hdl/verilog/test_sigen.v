// This module is used for axi stream signal generation

module test_sigen #(
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
/* master axi stream interface */
    output reg                          tvalid,
    input                               tready,
    output reg [8*TDATA_WIDTH-1:0]      tdata,
    output reg [8*TSTRB_WIDTH-1:0]      tstrb,
    output reg [8*TUSER_WIDTH-1:0]      tuser,
    output reg                          tlast
    );
    
localparam INIT = 0;
localparam LOAD = 1;
localparam TRSM = 2;
localparam PAUS = 3;
localparam PACKET_LEN =10;
localparam PAUS_INTVAL=5;

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
reg [1:0] pattern_num;
reg [8*TUSER_WIDTH-1:0] tuser_temp;
reg [10:0] paus_intval;
reg load_done;
reg trsm_done;
reg paus_done;
reg sigen_done;

reg [7:0]   i;




always @ (posedge clk) begin
    if (reset) begin
        state <= 2'd0;
        pattern_num <=2'd0;
    end
    else begin
        state <= next_state;

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
tlast = 1'b0;
next_state = state;

next_tdata = tdata;
next_tuser = tuser;
next_tstrb = tstrb;
next_tvalid = tvalid;
next_tlast = tlast;
next_i = i;


    if (state == TRSM)
        tvalid = 1'b1;

    case (state)
    INIT:
    begin
        tdata = {(8*TDATA_WIDTH){1'b0}};
        tstrb = {(8*TSTRB_WIDTH){1'b0}};
        tuser = {(8*TUSER_WIDTH){1'b0}};
        next_i = 8'b0;
        if (tdata == {(8*TDATA_WIDTH){1'b0}})
            next_state = LOAD;
    end
    
    LOAD:
    begin
        next_tdata = tdata_temp;
        next_tstrb = {(8*TSTRB_WIDTH){1'b1}};
        if ((tdata == tdata_temp) && (tstrb == 32'hffffffff))
            next_state = TRSM;
    end
    
    TRSM:
    begin
        if (tready) begin
            if (i == (PACKET_LEN - 1)) begin
                next_tstrb = 32'h0000ffff;
                next_tlast = 1'b1;
            end
            else begin
                next_tdata = tdata + 1'b1;
                next_i = i + 1'b1;
            end
        end
    end
    
    PAUS:
    begin
        if (pattern_num == 2'd3) begin
        
        end
    
        if (sigen_done) begin
            if(paus_done)
                next_state = PAUS;
        end
        else if (paus_done) begin
            next_state = INIT;
        end
    end
    endcase

end


    
    PAUS:
    begin
        if (pattern_num == 2'd3) begin
            sigen_done <= 1'b1;
        end
        
        tdata <= {(8*TDATA_WIDTH){1'b0}};
        tstrb <= {(8*TSTRB_WIDTH){1'b0}};
        tuser <= {(8*TUSER_WIDTH){1'b0}};
        tlast <= 1'b0;
        
        insert interval here
        
        if (paus_intval == PAUS_INTVAL) begin
            paus_intval <= 11'b0;
            paus_done = 1'b1;
            pattern_num = pattern_num + 1'b1;
        end
        else begin
            paus_intval <= paus_intval + 1'b1;
        end
        
    end
    
    
    endcase

end






//always @ (posedge clk) begin

//    case (state)
//    INIT:
//    begin
//        tdata <= {(8*TDATA_WIDTH){1'b0}};
//        tstrb <= {(8*TSTRB_WIDTH){1'b0}};
//        tuser <= {(8*TUSER_WIDTH){1'b0}};
//        tlast <= 1'b0;
//        i <= 8'b0;
//        paus_intval <= 11'b0;
//        trsm_done <= 1'b0;
//        load_done <= 1'b0;
//        paus_done <= 1'b0;
//    end
//    
//    LOAD:
//    begin
//        tdata <= tdata_temp;
//        tstrb <= {(8*TSTRB_WIDTH){1'b1}};
//        
//        if ((tdata == tdata_temp) && (tstrb == 32'hffffffff)) begin
//            load_done <= 1'b1;
//        end
//    end
//    
//    TRSM:
//    begin
//        if (tready) begin
//            if (i == (PACKET_LEN - 1)) begin
//                tstrb <= 32'h0000ffff;
//                trsm_done <= 1'b1;
//                tlast <= 1'b1;
//                tdata <= tdata + 1'b1;
//            end
//            else begin
//                tdata <= tdata + 1'b1;
//                i <= i + 1'b1;
//            end
//        end
//    end
//    
//    PAUS:
//    begin
//        if (pattern_num == 2'd3) begin
//            sigen_done <= 1'b1;
//        end
//        
//        tdata <= {(8*TDATA_WIDTH){1'b0}};
//        tstrb <= {(8*TSTRB_WIDTH){1'b0}};
//        tuser <= {(8*TUSER_WIDTH){1'b0}};
//        tlast <= 1'b0;
//        
//        insert interval here
//        
//        if (paus_intval == PAUS_INTVAL) begin
//            paus_intval <= 11'b0;
//            paus_done = 1'b1;
//            pattern_num = pattern_num + 1'b1;
//        end
//        else begin
//            paus_intval <= paus_intval + 1'b1;
//        end
//        
//    end
//    
//    
//    endcase

//end

endmodule
