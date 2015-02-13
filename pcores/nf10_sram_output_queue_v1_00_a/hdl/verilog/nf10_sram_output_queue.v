//----------------------------------------------------------------------------
// Filename:          nf10_sram_output_queues
// Version:           1.00.a
// Description:       Example Axi Streaming core (Verilog).
// Date:              Thu Dec 11 11:54:41 2014 (by Create and Import Peripheral Wizard)
// Verilog Standard:  Verilog-2001
//----------------------------------------------------------------------------
// Naming Conventions:
//   active low signals:                    "*_n"
//   clock signals:                         "clk", "clk_div#", "clk_#x"
//   reset signals:                         "rst", "rst_n"
//   generics:                              "C_*"
//   user defined types:                    "*_TYPE"
//   state machine next state:              "*_ns"
//   state machine current state:           "*_cs"
//   combinatorial signals:                 "*_com"
//   pipelined or register delay signals:   "*_d#"
//   counter signals:                       "*cnt*"
//   clock enable signals:                  "*_ce"
//   internal version of output port:       "*_i"
//   device pins:                           "*_pin"
//   ports:                                 "- Names begin with Uppercase"
//   processes:                             "*_PROCESS"
//   component instantiations:              "<ENTITY_>I_<#|FUNC>"
//----------------------------------------------------------------------------

//----------------------------------------
// Module Section
//----------------------------------------
module nf10_sram_output_queues 
#(
  parameter C_FAMILY              = "virtex5",
  parameter C_S_AXI_DATA_WIDTH    = 32,          
  parameter C_S_AXI_ADDR_WIDTH    = 32,          
  parameter C_USE_WSTRB           = 0,
  parameter C_DPHASE_TIMEOUT      = 0,
  parameter C_BASEADDR            = 32'hFFFFFFFF,
  parameter C_HIGHADDR            = 32'h00000000,
  parameter C_S_AXI_ACLK_FREQ_HZ  = 100,
  parameter C_M_AXIS_DATA_WIDTH	  = 256,
  parameter C_S_AXIS_DATA_WIDTH	  = 256,
  parameter C_M_AXIS_TUSER_WIDTH  = 128,
  parameter C_S_AXIS_TUSER_WIDTH  = 128,
  parameter NUM_QUEUES=5,
  
  // Width of AXI data bus in bytes
  parameter integer TDATA_WIDTH        = C_M_AXIS_DATA_WIDTH/8,
  parameter integer CROPPED_TDATA_WIDTH        = (((C_M_AXIS_DATA_WIDTH/8) > 24) ? 24 : (C_M_AXIS_DATA_WIDTH/8)),
  // Width of TUSER in bits
  parameter integer TUSER_WIDTH        = C_M_AXIS_TUSER_WIDTH,
  parameter integer QUEUE_ID_WIDTH     = 3,
  parameter integer NUM_MEM_CHIPS      = 3,
  parameter integer NUM_MEM_INPUTS     = 6,
  parameter integer MEM_WIDTH          = 36,
  parameter integer MEM_ADDR_WIDTH     = 19,
  parameter integer MEM_CQ_WIDTH       = 1,
  parameter integer MEM_CLK_WIDTH      = 1,
  parameter integer MEM_BW_WIDTH       = 4,
  parameter integer TID_WIDTH          = 4, 
  parameter integer TDEST_WIDTH        = 4,
  parameter integer NUM_MEMORY_CHIPS   = 3
)
(
//  // Slave AXI Ports
//  input      [C_S_AXI_ADDR_WIDTH-1 : 0]     S_AXI_AWADDR,
//  input                                     S_AXI_AWVALID,
//  input      [C_S_AXI_DATA_WIDTH-1 : 0]     S_AXI_WDATA,
//  input      [C_S_AXI_DATA_WIDTH/8-1 : 0]   S_AXI_WSTRB,
//  input                                     S_AXI_WVALID,
//  input                                     S_AXI_BREADY,
//  input      [C_S_AXI_ADDR_WIDTH-1 : 0]     S_AXI_ARADDR,
//  input                                     S_AXI_ARVALID,
//  input                                     S_AXI_RREADY,
//  output                                    S_AXI_ARREADY,
//  output     [C_S_AXI_DATA_WIDTH-1 : 0]     S_AXI_RDATA,
//  output     [1 : 0]                        S_AXI_RRESP,
//  output                                    S_AXI_RVALID,
//  output                                    S_AXI_WREADY,
//  output     [1 :0]                         S_AXI_BRESP,
//  output                                    S_AXI_BVALID,
//  output                                    S_AXI_AWREADY,


    input                           aclk,
    input                           aresetn,
    input                           memclk,
    input                           memclk_270,
    input                           memclk_200,
	 
	 // memory interface
    input [(MEM_WIDTH)-1:0]			qdr_q_0,
    input [MEM_CQ_WIDTH-1:0]		qdr_cq_0,
    input [MEM_CQ_WIDTH-1:0]		qdr_cq_n_0,
    output [MEM_CLK_WIDTH-1:0]		qdr_c_0,
    output [MEM_CLK_WIDTH-1:0]		qdr_c_n_0,
    output  						qdr_dll_off_n_0,
    output [MEM_CLK_WIDTH-1:0]		qdr_k_0,
    output [MEM_CLK_WIDTH-1:0]		qdr_k_n_0,
    output [MEM_ADDR_WIDTH-1:0]		qdr_sa_0,
    output [(MEM_BW_WIDTH)-1:0]		qdr_bw_n_0,
    output             				qdr_w_n_0,
    output [(MEM_WIDTH)-1:0]		qdr_d_0,
    output             				qdr_r_n_0,

    input [(MEM_WIDTH)-1:0] 		qdr_q_1,
    input [MEM_CQ_WIDTH-1:0]    	qdr_cq_1,
    input [MEM_CQ_WIDTH-1:0]    	qdr_cq_n_1,
    output [MEM_CLK_WIDTH-1:0]  	qdr_c_1,
    output [MEM_CLK_WIDTH-1:0]  	qdr_c_n_1,
    output             				qdr_dll_off_n_1,
    output [MEM_CLK_WIDTH-1:0]  	qdr_k_1,
    output [MEM_CLK_WIDTH-1:0]  	qdr_k_n_1,
    output [MEM_ADDR_WIDTH-1:0] 	qdr_sa_1,
    output [(MEM_BW_WIDTH)-1:0]		qdr_bw_n_1,
    output             				qdr_w_n_1,
    output [(MEM_WIDTH)-1:0]		qdr_d_1,
    output							qdr_r_n_1,

    input [(MEM_WIDTH)-1:0]  		qdr_q_2,
    input [MEM_CQ_WIDTH-1:0]    	qdr_cq_2,
    input [MEM_CQ_WIDTH-1:0]    	qdr_cq_n_2,
    output [MEM_CLK_WIDTH-1:0]  	qdr_c_2,
    output [MEM_CLK_WIDTH-1:0]  	qdr_c_n_2,
    output             				qdr_dll_off_n_2,
    output [MEM_CLK_WIDTH-1:0]  	qdr_k_2,
    output [MEM_CLK_WIDTH-1:0]  	qdr_k_n_2,
    output [MEM_ADDR_WIDTH-1:0] 	qdr_sa_2,
    output [(MEM_BW_WIDTH)-1:0]  qdr_bw_n_2,
    output             				qdr_w_n_2,
    output [(MEM_WIDTH)-1:0]  	qdr_d_2,
    output             				qdr_r_n_2,

    /*synthesis syn_keep = 1 */(* S = "TRUE" *)
//    input  [MASTERBANK_PIN_WIDTH-1:0]  masterbank_sel_pin,

    input		locked,

    output [(MEM_WIDTH*NUM_MEM_INPUTS-1):0] debug_mem_controller_dout,
    output [(MEM_ADDR_WIDTH-1):0]  debug_mem_controller_dout_addr,
    output debug_mem_controller_dout_ready,
    output [NUM_MEM_CHIPS-1:0] debug_calibration,
    output [63:0] mem_dbg,
    output [63:0] fifo_dbg,

  // Slave Stream Ports (interface to data path)
	input [C_S_AXIS_DATA_WIDTH - 1:0] s_axis_tdata,
	input [((C_S_AXIS_DATA_WIDTH / 8)) - 1:0] s_axis_tstrb,
	input [C_S_AXIS_TUSER_WIDTH-1:0] s_axis_tuser,
	input s_axis_tvalid,
	output s_axis_tready,
	input s_axis_tlast,

  // Master Stream Ports (interface to TX queues)
	output [C_M_AXIS_DATA_WIDTH - 1:0] m_axis_tdata_0,
	output [((C_M_AXIS_DATA_WIDTH / 8)) - 1:0] m_axis_tstrb_0,
	output [C_M_AXIS_TUSER_WIDTH-1:0] m_axis_tuser_0,
	output  m_axis_tvalid_0,
	input m_axis_tready_0,
	output  m_axis_tlast_0,

	output [C_M_AXIS_DATA_WIDTH - 1:0] m_axis_tdata_1,
	output [((C_M_AXIS_DATA_WIDTH / 8)) - 1:0] m_axis_tstrb_1,
	output [C_M_AXIS_TUSER_WIDTH-1:0] m_axis_tuser_1,
	output  m_axis_tvalid_1,
	input m_axis_tready_1,
	output  m_axis_tlast_1,

	output [C_M_AXIS_DATA_WIDTH - 1:0] m_axis_tdata_2,
	output [((C_M_AXIS_DATA_WIDTH / 8)) - 1:0] m_axis_tstrb_2,
	output [C_M_AXIS_TUSER_WIDTH-1:0] m_axis_tuser_2,
	output  m_axis_tvalid_2,
	input m_axis_tready_2,
	output  m_axis_tlast_2,

	output [C_M_AXIS_DATA_WIDTH - 1:0] m_axis_tdata_3,
	output [((C_M_AXIS_DATA_WIDTH / 8)) - 1:0] m_axis_tstrb_3,
	output [C_M_AXIS_TUSER_WIDTH-1:0] m_axis_tuser_3,
	output  m_axis_tvalid_3,
	input m_axis_tready_3,
	output  m_axis_tlast_3,

	output [C_M_AXIS_DATA_WIDTH - 1:0] m_axis_tdata_4,
	output [((C_M_AXIS_DATA_WIDTH / 8)) - 1:0] m_axis_tstrb_4,
	output [C_M_AXIS_TUSER_WIDTH-1:0] m_axis_tuser_4,
	output  m_axis_tvalid_4,
	input m_axis_tready_4,
	output  m_axis_tlast_4,

 // misc
	input axi_aclk,
	input axi_resetn
);

function integer log2;
	input integer number;
	begin
		log2=0;
		while(2**log2<number) 
			begin
				log2=log2+1;
			end
	end
endfunction

//AxiToFifo #()
//axi_to_fifo();
//
//FifoMem#()
//fifomem();




endmodule 