project new /local/scratch/jz377/Dropbox/nf10_sram_oq/pcores/nf10_sram_output_queue_v1_00_a/devl/projnav/nf10_sram_output_queue.xise;
project set family virtex5;
project set device xc5vtx240t;
project set package ff1759;
project set speed -2;
project set top_level_module_type HDL;
project set synthesis_tool "XST (VHDL/Verilog)";
lib_vhdl new nf10_sram_output_queue_v1_00_a;
xfile add /local/scratch/jz377/Dropbox/nf10_sram_oq//pcores/nf10_sram_output_queue_v1_00_a/hdl/verilog/nf10_sram_output_queue.v;
project close;
