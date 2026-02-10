set moduleName delta_encoding_Pipeline_INIT_LOOP
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {delta_encoding_Pipeline_INIT_LOOP}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
dict set ap_memory_interface_dict integrator_7 { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
dict set ap_memory_interface_dict integrator_6 { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
dict set ap_memory_interface_dict integrator_5 { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
dict set ap_memory_interface_dict integrator_4 { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
dict set ap_memory_interface_dict integrator_3 { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
dict set ap_memory_interface_dict integrator_2 { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
dict set ap_memory_interface_dict integrator_1 { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
dict set ap_memory_interface_dict integrator { MEM_WIDTH 32 MEM_SIZE 392 MASTER_TYPE BRAM_CTRL MEM_ADDRESS_MODE WORD_ADDRESS PACKAGE_IO port READ_LATENCY 0 }
set C_modelArgList {
	{ integrator_7 float 32 regular {array 98 { 0 3 } 0 1 }  }
	{ integrator_6 float 32 regular {array 98 { 0 3 } 0 1 }  }
	{ integrator_5 float 32 regular {array 98 { 0 3 } 0 1 }  }
	{ integrator_4 float 32 regular {array 98 { 0 3 } 0 1 }  }
	{ integrator_3 float 32 regular {array 98 { 0 3 } 0 1 }  }
	{ integrator_2 float 32 regular {array 98 { 0 3 } 0 1 }  }
	{ integrator_1 float 32 regular {array 98 { 0 3 } 0 1 }  }
	{ integrator float 32 regular {array 98 { 0 3 } 0 1 }  }
}
set hasAXIMCache 0
set hasAXIML2Cache 0
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "integrator_7", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "integrator_6", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "integrator_5", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "integrator_4", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "integrator_3", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "integrator_2", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "integrator_1", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "integrator", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 38
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ integrator_7_address0 sc_out sc_lv 7 signal 0 } 
	{ integrator_7_ce0 sc_out sc_logic 1 signal 0 } 
	{ integrator_7_we0 sc_out sc_logic 1 signal 0 } 
	{ integrator_7_d0 sc_out sc_lv 32 signal 0 } 
	{ integrator_6_address0 sc_out sc_lv 7 signal 1 } 
	{ integrator_6_ce0 sc_out sc_logic 1 signal 1 } 
	{ integrator_6_we0 sc_out sc_logic 1 signal 1 } 
	{ integrator_6_d0 sc_out sc_lv 32 signal 1 } 
	{ integrator_5_address0 sc_out sc_lv 7 signal 2 } 
	{ integrator_5_ce0 sc_out sc_logic 1 signal 2 } 
	{ integrator_5_we0 sc_out sc_logic 1 signal 2 } 
	{ integrator_5_d0 sc_out sc_lv 32 signal 2 } 
	{ integrator_4_address0 sc_out sc_lv 7 signal 3 } 
	{ integrator_4_ce0 sc_out sc_logic 1 signal 3 } 
	{ integrator_4_we0 sc_out sc_logic 1 signal 3 } 
	{ integrator_4_d0 sc_out sc_lv 32 signal 3 } 
	{ integrator_3_address0 sc_out sc_lv 7 signal 4 } 
	{ integrator_3_ce0 sc_out sc_logic 1 signal 4 } 
	{ integrator_3_we0 sc_out sc_logic 1 signal 4 } 
	{ integrator_3_d0 sc_out sc_lv 32 signal 4 } 
	{ integrator_2_address0 sc_out sc_lv 7 signal 5 } 
	{ integrator_2_ce0 sc_out sc_logic 1 signal 5 } 
	{ integrator_2_we0 sc_out sc_logic 1 signal 5 } 
	{ integrator_2_d0 sc_out sc_lv 32 signal 5 } 
	{ integrator_1_address0 sc_out sc_lv 7 signal 6 } 
	{ integrator_1_ce0 sc_out sc_logic 1 signal 6 } 
	{ integrator_1_we0 sc_out sc_logic 1 signal 6 } 
	{ integrator_1_d0 sc_out sc_lv 32 signal 6 } 
	{ integrator_address0 sc_out sc_lv 7 signal 7 } 
	{ integrator_ce0 sc_out sc_logic 1 signal 7 } 
	{ integrator_we0 sc_out sc_logic 1 signal 7 } 
	{ integrator_d0 sc_out sc_lv 32 signal 7 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "integrator_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator_7", "role": "address0" }} , 
 	{ "name": "integrator_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_7", "role": "ce0" }} , 
 	{ "name": "integrator_7_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_7", "role": "we0" }} , 
 	{ "name": "integrator_7_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator_7", "role": "d0" }} , 
 	{ "name": "integrator_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator_6", "role": "address0" }} , 
 	{ "name": "integrator_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_6", "role": "ce0" }} , 
 	{ "name": "integrator_6_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_6", "role": "we0" }} , 
 	{ "name": "integrator_6_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator_6", "role": "d0" }} , 
 	{ "name": "integrator_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator_5", "role": "address0" }} , 
 	{ "name": "integrator_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_5", "role": "ce0" }} , 
 	{ "name": "integrator_5_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_5", "role": "we0" }} , 
 	{ "name": "integrator_5_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator_5", "role": "d0" }} , 
 	{ "name": "integrator_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator_4", "role": "address0" }} , 
 	{ "name": "integrator_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_4", "role": "ce0" }} , 
 	{ "name": "integrator_4_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_4", "role": "we0" }} , 
 	{ "name": "integrator_4_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator_4", "role": "d0" }} , 
 	{ "name": "integrator_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator_3", "role": "address0" }} , 
 	{ "name": "integrator_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_3", "role": "ce0" }} , 
 	{ "name": "integrator_3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_3", "role": "we0" }} , 
 	{ "name": "integrator_3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator_3", "role": "d0" }} , 
 	{ "name": "integrator_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator_2", "role": "address0" }} , 
 	{ "name": "integrator_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_2", "role": "ce0" }} , 
 	{ "name": "integrator_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_2", "role": "we0" }} , 
 	{ "name": "integrator_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator_2", "role": "d0" }} , 
 	{ "name": "integrator_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator_1", "role": "address0" }} , 
 	{ "name": "integrator_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_1", "role": "ce0" }} , 
 	{ "name": "integrator_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator_1", "role": "we0" }} , 
 	{ "name": "integrator_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator_1", "role": "d0" }} , 
 	{ "name": "integrator_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "integrator", "role": "address0" }} , 
 	{ "name": "integrator_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator", "role": "ce0" }} , 
 	{ "name": "integrator_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "integrator", "role": "we0" }} , 
 	{ "name": "integrator_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "integrator", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "delta_encoding_Pipeline_INIT_LOOP",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "786", "EstimateLatencyMax" : "786",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "integrator_7", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "integrator_6", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "integrator_5", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "integrator_4", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "integrator_3", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "integrator_2", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "integrator_1", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "integrator", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "INIT_LOOP", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_state1", "FirstStateIter" : "", "FirstStateBlock" : "ap_ST_fsm_state1_blk", "LastState" : "ap_ST_fsm_state1", "LastStateIter" : "", "LastStateBlock" : "ap_ST_fsm_state1_blk", "QuitState" : "ap_ST_fsm_state1", "QuitStateIter" : "", "QuitStateBlock" : "ap_ST_fsm_state1_blk", "OneDepthLoop" : "1", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	delta_encoding_Pipeline_INIT_LOOP {
		integrator_7 {Type O LastRead -1 FirstWrite 0}
		integrator_6 {Type O LastRead -1 FirstWrite 0}
		integrator_5 {Type O LastRead -1 FirstWrite 0}
		integrator_4 {Type O LastRead -1 FirstWrite 0}
		integrator_3 {Type O LastRead -1 FirstWrite 0}
		integrator_2 {Type O LastRead -1 FirstWrite 0}
		integrator_1 {Type O LastRead -1 FirstWrite 0}
		integrator {Type O LastRead -1 FirstWrite 0}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "786", "Max" : "786"}
	, {"Name" : "Interval", "Min" : "786", "Max" : "786"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	integrator_7 { ap_memory {  { integrator_7_address0 mem_address 1 7 }  { integrator_7_ce0 mem_ce 1 1 }  { integrator_7_we0 mem_we 1 1 }  { integrator_7_d0 mem_din 1 32 } } }
	integrator_6 { ap_memory {  { integrator_6_address0 mem_address 1 7 }  { integrator_6_ce0 mem_ce 1 1 }  { integrator_6_we0 mem_we 1 1 }  { integrator_6_d0 mem_din 1 32 } } }
	integrator_5 { ap_memory {  { integrator_5_address0 mem_address 1 7 }  { integrator_5_ce0 mem_ce 1 1 }  { integrator_5_we0 mem_we 1 1 }  { integrator_5_d0 mem_din 1 32 } } }
	integrator_4 { ap_memory {  { integrator_4_address0 mem_address 1 7 }  { integrator_4_ce0 mem_ce 1 1 }  { integrator_4_we0 mem_we 1 1 }  { integrator_4_d0 mem_din 1 32 } } }
	integrator_3 { ap_memory {  { integrator_3_address0 mem_address 1 7 }  { integrator_3_ce0 mem_ce 1 1 }  { integrator_3_we0 mem_we 1 1 }  { integrator_3_d0 mem_din 1 32 } } }
	integrator_2 { ap_memory {  { integrator_2_address0 mem_address 1 7 }  { integrator_2_ce0 mem_ce 1 1 }  { integrator_2_we0 mem_we 1 1 }  { integrator_2_d0 mem_din 1 32 } } }
	integrator_1 { ap_memory {  { integrator_1_address0 mem_address 1 7 }  { integrator_1_ce0 mem_ce 1 1 }  { integrator_1_we0 mem_we 1 1 }  { integrator_1_d0 mem_din 1 32 } } }
	integrator { ap_memory {  { integrator_address0 mem_address 1 7 }  { integrator_ce0 mem_ce 1 1 }  { integrator_we0 mem_we 1 1 }  { integrator_d0 mem_din 1 32 } } }
}
