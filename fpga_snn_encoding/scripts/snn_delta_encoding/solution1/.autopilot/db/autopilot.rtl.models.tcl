set SynModuleInfo {
  {SRCNAME delta_encoding_Pipeline_INIT_LOOP MODELNAME delta_encoding_Pipeline_INIT_LOOP RTLNAME delta_encoding_delta_encoding_Pipeline_INIT_LOOP
    SUBMODULES {
      {MODELNAME delta_encoding_flow_control_loop_pipe_sequential_init RTLNAME delta_encoding_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME delta_encoding_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME delta_encoding_Pipeline_TIME_LOOP_PIXEL_LOOP MODELNAME delta_encoding_Pipeline_TIME_LOOP_PIXEL_LOOP RTLNAME delta_encoding_delta_encoding_Pipeline_TIME_LOOP_PIXEL_LOOP
    SUBMODULES {
      {MODELNAME delta_encoding_faddfsub_32ns_32ns_32_5_full_dsp_1 RTLNAME delta_encoding_faddfsub_32ns_32ns_32_5_full_dsp_1 BINDTYPE op TYPE fadd IMPL fulldsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME delta_encoding_fmul_32ns_32ns_32_4_max_dsp_1 RTLNAME delta_encoding_fmul_32ns_32ns_32_4_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME delta_encoding_fcmp_32ns_32ns_1_2_no_dsp_1 RTLNAME delta_encoding_fcmp_32ns_32ns_1_2_no_dsp_1 BINDTYPE op TYPE fcmp IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME delta_encoding_sparsemux_17_3_32_1_1 RTLNAME delta_encoding_sparsemux_17_3_32_1_1 BINDTYPE op TYPE sparsemux IMPL auto}
      {MODELNAME delta_encoding_mul_5ns_11ns_15_1_1 RTLNAME delta_encoding_mul_5ns_11ns_15_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME delta_encoding MODELNAME delta_encoding RTLNAME delta_encoding IS_TOP 1
    SUBMODULES {
      {MODELNAME delta_encoding_integrator_RAM_AUTO_1R1W RTLNAME delta_encoding_integrator_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME delta_encoding_gmem_m_axi RTLNAME delta_encoding_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME delta_encoding_control_s_axi RTLNAME delta_encoding_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
