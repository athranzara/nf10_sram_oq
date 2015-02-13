module AxiFifoArbiter
#(
///////////////////////////////////////////////////////////////////////////////
// Parameter Definitions
///////////////////////////////////////////////////////////////////////////////
  // Width of AXI data bus in bytes
  parameter integer TDATA_WIDTH        = 24, /*croqped by previous module*/
  // Width of TUSER in bits
  parameter integer TUSER_WIDTH        = 128,
  parameter integer NUM_QUEUES         = 5,
  parameter integer QUEUE_ID_WIDTH     = 3
)
(
    input                               reset,
    input                               memclk,
    input [NUM_QUEUES-1:0]              oq,
    input                               din_valid,
    input  [((8*TDATA_WIDTH+10)-1):0]   din,
    output                              next_pkg_en,

    output reg [QUEUE_ID_WIDTH-1:0]     queue_id,
    output reg [((8*TDATA_WIDTH+10)-1):0]  dout,
    output reg                          dout_valid
);

reg [NUM_QUEUES-1:0]                oq_reg;
reg [QUEUE_ID_WIDTH-1:0]            oq_rra;

reg                                 rra_last;

reg pkg_start, next_pkg_start;
reg pkg_last;

reg read_done;
reg oq_changed;
reg rd_oq_ready;

always @ * begin
    rd_oq_ready = 1'b1;
    
    if (reset) begin
        rd_oq_ready = 1'b0;
    end
    else if (pkg_valid && ~rra_last) begin
        rd_oq_ready = 1'b0;
    end
end

reg [4:0] prev_oq;

always @ (posedge memclk) begin
    if (reset) begin
        prev_oq <= oq;
    end
    else begin
        prev_oq <= oq;
    end
end

always @ (posedge memclk) begin
    if (prev_oq !== oq) begin
        oq_reg <= oq;
        read_done <= 1'b1;
    end
    else begin
        read_done <= 1'b0;
    end
end

//always @ (oq) begin
//    oq_changed = 1'b0;
//    if(~reset) begin
//        if (read_done) begin
//            oq_changed = 1'b0;
//        end
//        else begin
//            oq_changed = 1'b1;
//        end
//    end  
//end

reg pkg_valid;
reg prev_read_done;

always @ (posedge memclk) begin
    if (reset) begin
        prev_read_done <= 1'b0;
    end
    else prev_read_done <= read_done;
end

always @ (posedge memclk) begin
    if (reset) begin
        oq_reg <= 5'b0;
        read_done <=1'b0;
        pkg_valid <= 1'b0;
    end
    else if (rd_oq_ready && din_valid) begin
        oq_reg <= oq;
        read_done <=1'b1;
        pkg_valid <=1'b1;
    end
    else begin
        read_done <= 1'b0; 
    end

    /* in what case read_done goes back to zero?*/
end

always @ (posedge memclk) begin
    if (reset) begin
        oq_rra <= 3'b0;
        rra_last <= 1'b0;
    end
    else if (pkg_valid) begin
        casex(oq_reg)
            5'bxxxx1:begin
                oq_rra <= 3'd0;
                if ((oq & 5'b11110) == 5'b00000) begin
                    rra_last <= 1'b1;
                    oq_reg <= oq;
                end
                else begin
                    oq_reg <= oq_reg & 5'b11110;
                    rra_last <= 1'b0;
                end           
            end
            5'bxxx1x:begin
                oq_rra <= 3'd1;
                if ((oq_reg & 5'b11101) == 5'b00000) begin
                    rra_last <= 1'b1;
                    oq_reg <= oq;
                end
                else begin
                    oq_reg <= oq_reg & 5'b11101;
                    rra_last <= 1'b0;
                end
            end
            5'bxx1xx:begin
                oq_rra <= 3'd2;
                if ((oq_reg & 5'b11011) == 5'b00000) begin
                    rra_last <= 1'b1;
                    oq_reg <= oq;
                end
                else begin
                    oq_reg <= oq_reg & 5'b11011;
                    rra_last <= 1'b0;
                end
            end
            5'bx1xxx:begin
                oq_rra <= 3'd3;
                if ((oq_reg & 5'b10111) == 5'b00000) begin
                    rra_last <= 1'b1;
                    oq_reg <= oq;
                end
                else begin
                    oq_reg <= oq_reg & 5'b10111;
                    rra_last <= 1'b0;
                end
            end
            5'b1xxxx:begin
                oq_rra <= 3'd4;
                rra_last = 1'b1;
                oq_reg <= oq;
            end
            default:begin
                oq_rra <= 3'dz;
                oq_reg <= oq;
            end
        endcase
    end

end

assign next_pkg_en = rra_last;






endmodule
