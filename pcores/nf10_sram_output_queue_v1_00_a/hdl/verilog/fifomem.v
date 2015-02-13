module FifoMen
#(
///////////////////////////////////////////////////////////////////////////////
// Parameter Definitions
///////////////////////////////////////////////////////////////////////////////
  // Width of AXI data bus in bytes
  parameter integer TDATA_WIDTH         = 32,
  parameter integer TUSER_WIDTH         = 128,
  parameter integer NUM_QUEUES          = 5,
  parameter integer QUEUE_ID_WIDTH      = 3,
  parameter integer NUM_MEM_INPUTS      = 6,
  parameter integer NUM_MEM_CHIPS       = 3,
  parameter integer MEM_WIDTH           = 36,
  parameter integer MEM_ADDR_WIDTH      = 19,
  parameter integer MEM_NUM_WORDS       = 524288,
  parameter integer QUEUE_SIZE          = MEM_NUM_WORDS/NUM_QUEUES
)
(
    input                                   clk,
    input                                   reset,
    input  [(QUEUE_ID_WIDTH-1):0]           read_queue_id,
    output reg [(QUEUE_ID_WIDTH-1):0]       read_data_queue_id,
    input                                   read_data_ready,
    output reg [((8*TDATA_WIDTH+10)-1):0]   read_data,
    output                                  read_data_valid,
    output reg [(NUM_QUEUES-1):0]           read_empty,
    output reg                              read_burst_state,


    input [(QUEUE_ID_WIDTH-1):0]            write_queue_id,
    input [((8*TDATA_WIDTH+10)-1):0]        write_data,
    input                                   write_data_valid, /*need data valid indicator from previous module*/
    output reg [(NUM_QUEUES-1):0]           write_full,
    output reg                              next_write_burst_state,

    input                                   sram_read_full,
    input                                   sram_write_full,
    output reg [(MEM_WIDTH*NUM_MEM_INPUTS-1):0]     dout,
    output reg [(MEM_ADDR_WIDTH-1):0]               dout_addr,
    output reg                                      dout_burst_ready,
    input  [(MEM_WIDTH*NUM_MEM_INPUTS-1):0]         din,
    input  [(NUM_MEM_CHIPS-1):0]                    din_valid,
    output reg [(MEM_ADDR_WIDTH-1):0]               din_addr,
    output reg                                      din_ready,
    
    // Misc, might be assigned by simulation
    input [MEM_ADDR_WIDTH-1:0]              q0_addr_low,
    input [MEM_ADDR_WIDTH-1:0]              q0_addr_high,
    input [MEM_ADDR_WIDTH-1:0]              q1_addr_low,
    input [MEM_ADDR_WIDTH-1:0]              q1_addr_high,
    input [MEM_ADDR_WIDTH-1:0]              q2_addr_low,
    input [MEM_ADDR_WIDTH-1:0]              q2_addr_high,
    input [MEM_ADDR_WIDTH-1:0]              q3_addr_low,
    input [MEM_ADDR_WIDTH-1:0]              q3_addr_high,
    input [MEM_ADDR_WIDTH-1:0]              q4_addr_low,
    input [MEM_ADDR_WIDTH-1:0]              q4_addr_high,
    
    input									q0_enable,
    input                                   q2_enable,
    input                                   q3_enable,
    input                                   q4_enable,
    input                                   q5_enable
);

    function integer log2;
        input integer number;
        begin
            log2=0;
            while(2**log2<number) begin
                log2=log2+1;
            end
        end
    endfunction
    
    localparam MEM_ADDR_WIDTH_QUE = log2(MEM_NUM_WORDS/NUM_QUEUES);
    localparam MAX_MEM_NUM_WORDS_QUE = 104857;
    

// target queue number is 5
reg [MEM_ADDR_WIDTH-1:0]        q0_wr_addr;
reg [MEM_ADDR_WIDTH-1:0]        q0_rd_addr;
reg [MEM_ADDR_WIDTH-1:0]        q1_wr_addr;
reg [MEM_ADDR_WIDTH-1:0]        q1_rd_addr;
reg [MEM_ADDR_WIDTH-1:0]        q2_wr_addr;
reg [MEM_ADDR_WIDTH-1:0]        q2_rd_addr;
reg [MEM_ADDR_WIDTH-1:0]        q3_wr_addr;
reg [MEM_ADDR_WIDTH-1:0]        q3_rd_addr;
reg [MEM_ADDR_WIDTH-1:0]        q4_wr_addr;
reg [MEM_ADDR_WIDTH-1:0]        q4_rd_addr;

reg [MEM_ADDR_WIDTH-1:0]        next_din_addr;

reg [MEM_ADDR_WIDTH-1:0]        read_addr       [(NUM_QUEUES-1):0];
reg [MEM_ADDR_WIDTH-1:0]        next_read_addr  [(NUM_QUEUES-1):0];
reg [MEM_ADDR_WIDTH-1:0]        write_addr      [(NUM_QUEUES-1):0];
reg [MEM_ADDR_WIDTH-1:0]        next_write_addr [(NUM_QUEUES-1):0];

reg                             mem_full        [(NUM_QUEUES-1):0];

reg [MEM_ADDR_WIDTH-1:0]        mem_usage       [(NUM_QUEUES-1):0];
reg [MEM_ADDR_WIDTH-1:0]        next_mem_usage  [(NUM_QUEUES-1):0];

reg                             next_din_ready;
reg                             dout_ready;
reg                             next_read_data_valid;

reg [(MEM_WIDTH*NUM_MEM_INPUTS-1):0]    next_dout;
reg [(MEM_ADDR_WIDTH-1):0]          next_dout_addr;
reg [(NUM_QUEUES-1):0]              next_write_full;

// define new circle for queue memory address
always @(*) begin
if (next_read_addr[0] == (q0_addr_high + 19'b1))
    next_read_addr[0] = q0_addr_low;

if (next_read_addr[1] == (q1_addr_high + 19'b1))
    next_read_addr[1] = q1_addr_low;
    
if (next_read_addr[2] == (q2_addr_high + 19'b1))
    next_read_addr[2] = q2_addr_low;
    
if (next_read_addr[3] == (q3_addr_high + 19'b1))
    next_read_addr[3] = q3_addr_low;

if (next_read_addr[4] == (q4_addr_high + 19'b1))
    next_read_addr[4] = q4_addr_low;

end



always @(posedge clk) begin
// more software reset function should be added here
    if(reset) begin
        read_addr[0] <= q0_addr_low;
        write_addr[0] <= q0_addr_low;
        mem_usage[0] <= {(MEM_ADDR_WIDTH-1){1'b0}};
        mem_full[0] <= 0;
        
        read_addr[1] <= q1_addr_low;
        write_addr[1] <= q1_addr_low;
        mem_usage[0] <= {(MEM_ADDR_WIDTH-1){1'b0}};
        mem_full[1] <= 0;
        
        read_addr[2] <= q2_addr_low;
        write_addr[2] <= q2_addr_low;
        mem_usage[0] <= {(MEM_ADDR_WIDTH-1){1'b0}};
        mem_full[2] <= 0;
        
        read_addr[3] <= q3_addr_low;
        write_addr[3] <= q3_addr_low;
        mem_usage[0] <= {(MEM_ADDR_WIDTH-1){1'b0}};
        mem_full[3] <= 0;
        
        read_addr[4] <= q4_addr_low;
        write_addr[4] <= q4_addr_low;
        mem_usage[0] <= {(MEM_ADDR_WIDTH-1){1'b0}};
        mem_full[4] <= 0;
        
        dout <= {(MEM_WIDTH*NUM_MEM_INPUTS){1'b0}};
        dout_addr <= {(MEM_ADDR_WIDTH){1'b0}};
        write_full <= {(NUM_QUEUES){1'b0}};
        din_addr <= {(MEM_ADDR_WIDTH){1'b0}};
        din_ready <= 1'b0;
    end
    else begin
        read_addr[0] <= next_read_addr[0];
        write_addr[0] <= next_write_addr[0];
        mem_usage[0] <= next_mem_usage[0];
        
        read_addr[1] <= next_read_addr[1];
        write_addr[1] <= next_write_addr[1];
        mem_usage[1] <= next_mem_usage[1];
        
        read_addr[2] <= next_read_addr[2];
        write_addr[2] <= next_write_addr[2];
        mem_usage[2] <= next_mem_usage[2];
        
        read_addr[3] <= next_read_addr[3];
        write_addr[3] <= next_write_addr[3];
        mem_usage[3] <= next_mem_usage[3];
        
        read_addr[4] <= next_read_addr[4];
        write_addr[4] <= next_write_addr[4];
        mem_usage[4] <= next_mem_usage[4];
        
        dout <= next_dout;
        dout_addr <= next_dout_addr;
        din_addr <= next_din_addr;
        din_ready <= next_din_ready;
        write_full <= next_write_full;
        
    end
end

always @(*) /*not all the combitional?*/
begin
    // some default assignment
    next_mem_usage[0] = mem_usage[0];
    next_mem_usage[1] = mem_usage[1];
    next_mem_usage[2] = mem_usage[2];
    next_mem_usage[3] = mem_usage[3];
    next_mem_usage[4] = mem_usage[4];
    //
    dout_ready = 1'b0;
    next_din_ready = 1'b0;
    next_din_addr = {(MEM_ADDR_WIDTH){1'b0}};
    next_dout_addr = {(MEM_ADDR_WIDTH){1'b0}};
    next_dout[(8*TDATA_WIDTH+10 - 1) : 0] = write_data;
    next_dout[(8*TDATA_WIDTH+10+QUEUE_ID_WIDTH - 1) : (8*TDATA_WIDTH+10)] = write_queue_id;
    next_dout[8*TDATA_WIDTH+10+QUEUE_ID_WIDTH] = write_data_valid;
        
    read_data = din[(8*TDATA_WIDTH+10)-1:0];
    read_data_queue_id = din[((8*TDATA_WIDTH+10+QUEUE_ID_WIDTH)-1):(8*TDATA_WIDTH+10)];
        
        

    if (read_data_ready) /*read empty*/
    begin
        case (read_queue_id)
        
        'd0:begin
                next_din_addr = read_addr[0];
                next_read_addr[1] = read_addr[1];
                next_read_addr[2] = read_addr[2];
                next_read_addr[3] = read_addr[3];
                next_read_addr[4] = read_addr[4];
                if(!read_empty[0]) begin
                    next_din_ready = 1'b1;
                    next_read_data_valid = 1'b1;
                    
                    next_read_addr[0][MEM_ADDR_WIDTH-1:0] = read_addr[0][(MEM_ADDR_WIDTH-1):0] + 1'b1;
                end
            end
            
        'd1:begin
                next_din_addr = read_addr[1];
                next_read_addr[0] = read_addr[0];
                next_read_addr[2] = read_addr[2];
                next_read_addr[3] = read_addr[3];
                next_read_addr[4] = read_addr[4];
                if(!read_empty[1]) begin
                    next_din_ready = 1'b1;
                    next_read_data_valid = 1'b1;
                    
                    next_read_addr[1][MEM_ADDR_WIDTH-1:0] = read_addr[1][(MEM_ADDR_WIDTH-1):0] + 1'b1;
                end
            end
            
        'd2:begin
                next_din_addr = read_addr[2];
                next_read_addr[1] = read_addr[1];
                next_read_addr[0] = read_addr[0];
                next_read_addr[3] = read_addr[3];
                next_read_addr[4] = read_addr[4];
                if(!read_empty[2]) begin
                    next_din_ready = 1'b1;
                    next_read_data_valid = 1'b1;
                    
                    next_read_addr[2][MEM_ADDR_WIDTH-1:0] = read_addr[2][(MEM_ADDR_WIDTH-1):0] + 1'b1;
                end
            end
            
        'd3:begin
                next_din_addr = read_addr[3];
                next_read_addr[1] = read_addr[1];
                next_read_addr[2] = read_addr[2];
                next_read_addr[0] = read_addr[0];
                next_read_addr[4] = read_addr[4];
                if(!read_empty[3]) begin
                    next_din_ready = 1'b1;
                    next_read_data_valid = 1'b1;
                    
                    next_read_addr[3][MEM_ADDR_WIDTH-1:0] = read_addr[3][(MEM_ADDR_WIDTH-1):0] + 1'b1;
                end
            end
            
        'd4:begin
                next_din_addr = read_addr[4];
                next_read_addr[1] = read_addr[1];
                next_read_addr[2] = read_addr[2];
                next_read_addr[3] = read_addr[3];
                next_read_addr[0] = read_addr[0];
                if(!read_empty[4]) begin
                    next_din_ready = 1'b1;
                    next_read_data_valid = 1'b1;
                    
                    next_read_addr[4][MEM_ADDR_WIDTH-1:0] = read_addr[4][(MEM_ADDR_WIDTH-1):0] + 1'b1;
                end
            end
            
        endcase
    end
        
    if (write_data_valid) begin
        case (write_queue_id)
        'd0:begin
                next_dout_addr = write_addr[0];
                next_write_addr[1] = write_addr[1];
                next_write_addr[2] = write_addr[2];
                next_write_addr[3] = write_addr[3];
                next_write_addr[4] = write_addr[4];
                    
                if(!write_full[0]) begin
                    next_write_addr[0][MEM_ADDR_WIDTH-1:0] = write_addr[0][MEM_ADDR_WIDTH-1:0] + 1'b1; 
                    dout_ready = 1'b1;
                end
                else begin
                    next_write_addr[0] = write_addr[0];
                    dout_ready = 1'b0;
                end
                    
            end
        'd1:begin
                next_dout_addr = write_addr[1];
                next_write_addr[0] = write_addr[0];
                next_write_addr[2] = write_addr[2];
                next_write_addr[3] = write_addr[3];
                next_write_addr[4] = write_addr[4];
                    
                if(!write_full[1]) begin
                    next_write_addr[1][MEM_ADDR_WIDTH-1:0] = write_addr[1][MEM_ADDR_WIDTH-1:0] + 1'b1; 
                    dout_ready = 1'b1;
                end
                else begin
                    next_write_addr[1] = write_addr[1];
                    dout_ready = 1'b0;
                end
                
            end
            
        'd2:begin
                next_dout_addr = write_addr[2];
                next_write_addr[1] = write_addr[1];
                next_write_addr[0] = write_addr[0];
                next_write_addr[3] = write_addr[3];
                next_write_addr[4] = write_addr[4];
                    
                if(!write_full[2]) begin
                    next_write_addr[2][MEM_ADDR_WIDTH-1:0] = write_addr[2][MEM_ADDR_WIDTH-1:0] + 1'b1; 
                    dout_ready = 1'b1;
                end
                else begin
                    next_write_addr[2] = write_addr[2];
                    dout_ready = 1'b0;
                end
                
            end
            
        'd3:begin
                next_dout_addr = write_addr[3];
                next_write_addr[1] = write_addr[1];
                next_write_addr[2] = write_addr[2];
                next_write_addr[0] = write_addr[0];
                next_write_addr[4] = write_addr[4];
                    
                if(!write_full[3]) begin
                    next_write_addr[3][MEM_ADDR_WIDTH-1:0] = write_addr[3][MEM_ADDR_WIDTH-1:0] + 1'b1; 
                    dout_ready = 1'b1;
                end
                else begin
                    next_write_addr[3] = write_addr[3];
                    dout_ready = 1'b0;
                end
            end
            
        'd4:begin
                next_dout_addr = write_addr[4];
                next_write_addr[1] = write_addr[1];
                next_write_addr[2] = write_addr[2];
                next_write_addr[3] = write_addr[3];
                next_write_addr[0] = write_addr[0];
                    
                if(!write_full[4]) begin
                    next_write_addr[4][MEM_ADDR_WIDTH-1:0] = write_addr[4][MEM_ADDR_WIDTH-1:0] + 1'b1; 
                    dout_ready = 1'b1;
                end
                else begin
                    next_write_addr[4] = write_addr[4];
                    dout_ready = 1'b0;
                end
            end
        default begin
                    next_write_addr[0] = write_addr[0];
                    next_write_addr[1] = write_addr[1];
                    next_write_addr[2] = write_addr[2];
                    next_write_addr[3] = write_addr[3];
                    next_write_addr[4] = write_addr[4];
                end
        endcase
    end
    
//    rw_same_queue = read_queue_id == write_queue_id;
//    if(next_din_ready && (~dout_ready || ~rw_same_queue)) //(din_ready & ~dout_ready)
//    begin
//        next_num_used[read_queue_id] = num_used[read_queue_id] - 1;
//    end
//    if(dout_ready && (~next_din_ready || ~rw_same_queue))//(dout_ready & ~din_ready)
//    begin
//        next_num_used[write_queue_id] = num_used[write_queue_id] + 1;
//    end

//    next_dout_burst_ready = /*~write_burst_state &&*/ dout_ready;
            
end


endmodule
