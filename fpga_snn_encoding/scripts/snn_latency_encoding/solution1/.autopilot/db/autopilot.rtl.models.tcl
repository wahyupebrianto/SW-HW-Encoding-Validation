set SynModuleInfo {
  {SRCNAME latency_encoding_Pipeline_INIT_T_INIT_I MODELNAME latency_encoding_Pipeline_INIT_T_INIT_I RTLNAME latency_encoding_latency_encoding_Pipeline_INIT_T_INIT_I
    SUBMODULES {
      {MODELNAME latency_encoding_mul_5ns_11ns_15_1_1 RTLNAME latency_encoding_mul_5ns_11ns_15_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_flow_control_loop_pipe_sequential_init RTLNAME latency_encoding_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME latency_encoding_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME latency_encoding_Pipeline_PIXEL_LOOP MODELNAME latency_encoding_Pipeline_PIXEL_LOOP RTLNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP
    SUBMODULES {
      {MODELNAME latency_encoding_faddfsub_32ns_32ns_32_5_full_dsp_1 RTLNAME latency_encoding_faddfsub_32ns_32ns_32_5_full_dsp_1 BINDTYPE op TYPE fsub IMPL fulldsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_fmul_32ns_32ns_32_4_max_dsp_1 RTLNAME latency_encoding_fmul_32ns_32ns_32_4_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_uitofp_32ns_32_6_no_dsp_1 RTLNAME latency_encoding_uitofp_32ns_32_6_no_dsp_1 BINDTYPE op TYPE uitofp IMPL auto LATENCY 5 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_fcmp_32ns_32ns_1_2_no_dsp_1 RTLNAME latency_encoding_fcmp_32ns_32ns_1_2_no_dsp_1 BINDTYPE op TYPE fcmp IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_fsqrt_32ns_32ns_32_16_no_dsp_1 RTLNAME latency_encoding_fsqrt_32ns_32ns_32_16_no_dsp_1 BINDTYPE op TYPE fsqrt IMPL fabric LATENCY 15 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_flog_32ns_32ns_32_13_full_dsp_1 RTLNAME latency_encoding_flog_32ns_32ns_32_13_full_dsp_1 BINDTYPE op TYPE flog IMPL fulldsp LATENCY 12 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_mul_23s_22ns_45_1_1 RTLNAME latency_encoding_mul_23s_22ns_45_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_mul_30s_29ns_58_2_1 RTLNAME latency_encoding_mul_30s_29ns_58_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_mul_80s_24ns_80_5_1 RTLNAME latency_encoding_mul_80s_24ns_80_5_1 BINDTYPE op TYPE mul IMPL auto LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_sparsemux_17_3_1_1_1 RTLNAME latency_encoding_sparsemux_17_3_1_1_1 BINDTYPE op TYPE sparsemux IMPL auto}
      {MODELNAME latency_encoding_sparsemux_33_4_1_1_1 RTLNAME latency_encoding_sparsemux_33_4_1_1_1 BINDTYPE op TYPE sparsemux IMPL auto}
      {MODELNAME latency_encoding_mul_15ns_15ns_30_1_1 RTLNAME latency_encoding_mul_15ns_15ns_30_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_mul_15ns_15s_30_1_1 RTLNAME latency_encoding_mul_15ns_15s_30_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_ref_4oPi_table_100_ROM_1P_LUTRAM_1R RTLNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_ref_4oPi_table_100_ROM_1P_LUTRAM_1R BINDTYPE storage TYPE rom_1p IMPL lutram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_second_order_float_sin_cos_K0_ROM_1P_LUTbkb RTLNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_second_order_float_sin_cos_K0_ROM_1P_LUTbkb BINDTYPE storage TYPE rom_1p IMPL lutram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_second_order_float_sin_cos_K1_ROM_1P_LUTcud RTLNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_second_order_float_sin_cos_K1_ROM_1P_LUTcud BINDTYPE storage TYPE rom_1p IMPL lutram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_second_order_float_sin_cos_K2_ROM_1P_LUTdEe RTLNAME latency_encoding_latency_encoding_Pipeline_PIXEL_LOOP_second_order_float_sin_cos_K2_ROM_1P_LUTdEe BINDTYPE storage TYPE rom_1p IMPL lutram LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME latency_encoding MODELNAME latency_encoding RTLNAME latency_encoding IS_TOP 1
    SUBMODULES {
      {MODELNAME latency_encoding_gmem_m_axi RTLNAME latency_encoding_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME latency_encoding_control_s_axi RTLNAME latency_encoding_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
