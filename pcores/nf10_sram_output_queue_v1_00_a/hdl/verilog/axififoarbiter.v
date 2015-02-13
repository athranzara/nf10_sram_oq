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
reg                                 rra_last;



reg [2:0] state;
reg [2:0] prev_state;
reg [2:0] next_state;
reg fetch_done;
reg prev_fetch_done;

always @ (posedge memclk) begin
    if (reset) begin
        state <= 3'd0;
        prev_state <= 3'd0;
    end
    else begin
        state <= next_state;
        prev_state <= state;
    end

end


always @ (oq or reset or fetch_done) begin
    next_state = 3'd0;
    if (reset) begin
        next_state = 3'd0;
    end
    else begin
        if (state == 3'd0) begin
            if (~fetch_done)
                next_state = 3'd1;
            else
                next_state = 3'd0;
        end
        else if (state == 3'd2) begin
            if (fetch_done || ~prev_fetch_done)
                next_state = 3'd1;
            else 
                next_state = 3'd2;
        end
        else if (prev_state == 3'd1) begin
            if (fetch_done)
                next_state = 3'd2;
            else 
                next_state = 3'd2;
        end
    end
end


always @ (posedge memclk) begin
    if (reset) begin
        prev_fetch_done <= 1'b0;
    end
    else begin
        prev_fetch_done <= fetch_done;
    end
end

always @ (posedge memclk) begin
    case (state)
        0:  begin
                fetch_done <=0;
                oq_reg <= 5'b0;
                rra_last <= 1'b0;
            end
        
        1:  begin
                if (din_valid) begin
                    oq_reg <= oq;
                    fetch_done <= 1'b1;
                end
            end

        
        2:  begin
                fetch_done <= 1'b0;
                if (din_valid) begin
                    casex(oq_reg)
                        5'bxxxx1:begin
                            queue_id <= 3'd0;
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
                            queue_id <= 3'd1;
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
                            queue_id <= 3'd2;
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
                            queue_id <= 3'd3;
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
                            queue_id <= 3'd4;
                            rra_last <= 1'b1;
                            oq_reg <= oq;
                        end
                        default:begin
                            queue_id <= 3'dz;
                            oq_reg <= oq;
                        end
                    endcase
                end
                
            end
    endcase
end

always @ * begin
    dout_valid = 1'b0;
    dout = 202'b0;
    if ( (state == 3'd2) && ~ fetch_done && (next_state !== 3'd1))
        dout_valid = 1'b1;
    if (dout_valid)
        dout = din;
end


assign next_pkg_en = rra_last;






endmodule
