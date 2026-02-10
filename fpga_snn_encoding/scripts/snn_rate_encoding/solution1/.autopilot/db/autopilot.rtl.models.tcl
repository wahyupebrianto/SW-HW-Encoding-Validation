set SynModuleInfo {
  {SRCNAME rate_encoding MODELNAME rate_encoding RTLNAME rate_encoding IS_TOP 1
    SUBMODULES {
      {MODELNAME rate_encoding_fmul_32ns_32ns_32_4_max_dsp_1 RTLNAME rate_encoding_fmul_32ns_32ns_32_4_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME rate_encoding_uitofp_32ns_32_6_no_dsp_1 RTLNAME rate_encoding_uitofp_32ns_32_6_no_dsp_1 BINDTYPE op TYPE uitofp IMPL auto LATENCY 5 ALLOW_PRAGMA 1}
      {MODELNAME rate_encoding_fcmp_32ns_32ns_1_2_no_dsp_1 RTLNAME rate_encoding_fcmp_32ns_32ns_1_2_no_dsp_1 BINDTYPE op TYPE fcmp IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME rate_encoding_mul_5ns_11ns_15_1_1 RTLNAME rate_encoding_mul_5ns_11ns_15_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME rate_encoding_gmem_m_axi RTLNAME rate_encoding_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME rate_encoding_control_s_axi RTLNAME rate_encoding_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME rate_encoding_flow_control_loop_delay_pipe RTLNAME rate_encoding_flow_control_loop_delay_pipe BINDTYPE interface TYPE internal_upc_flow_control INSTNAME rate_encoding_flow_control_loop_delay_pipe_U}
    }
  }
}
