// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xrate_encoding.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XRate_encoding_CfgInitialize(XRate_encoding *InstancePtr, XRate_encoding_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XRate_encoding_Start(XRate_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_AP_CTRL) & 0x80;
    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XRate_encoding_IsDone(XRate_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XRate_encoding_IsIdle(XRate_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XRate_encoding_IsReady(XRate_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XRate_encoding_EnableAutoRestart(XRate_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XRate_encoding_DisableAutoRestart(XRate_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_AP_CTRL, 0);
}

void XRate_encoding_Set_img(XRate_encoding *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IMG_DATA, (u32)(Data));
    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IMG_DATA + 4, (u32)(Data >> 32));
}

u64 XRate_encoding_Get_img(XRate_encoding *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IMG_DATA);
    Data += (u64)XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IMG_DATA + 4) << 32;
    return Data;
}

void XRate_encoding_Set_spikes(XRate_encoding *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_SPIKES_DATA, (u32)(Data));
    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_SPIKES_DATA + 4, (u32)(Data >> 32));
}

u64 XRate_encoding_Get_spikes(XRate_encoding *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_SPIKES_DATA);
    Data += (u64)XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_SPIKES_DATA + 4) << 32;
    return Data;
}

void XRate_encoding_Set_seed(XRate_encoding *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_SEED_DATA, Data);
}

u32 XRate_encoding_Get_seed(XRate_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_SEED_DATA);
    return Data;
}

void XRate_encoding_InterruptGlobalEnable(XRate_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_GIE, 1);
}

void XRate_encoding_InterruptGlobalDisable(XRate_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_GIE, 0);
}

void XRate_encoding_InterruptEnable(XRate_encoding *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IER);
    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IER, Register | Mask);
}

void XRate_encoding_InterruptDisable(XRate_encoding *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IER);
    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IER, Register & (~Mask));
}

void XRate_encoding_InterruptClear(XRate_encoding *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRate_encoding_WriteReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_ISR, Mask);
}

u32 XRate_encoding_InterruptGetEnabled(XRate_encoding *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_IER);
}

u32 XRate_encoding_InterruptGetStatus(XRate_encoding *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRate_encoding_ReadReg(InstancePtr->Control_BaseAddress, XRATE_ENCODING_CONTROL_ADDR_ISR);
}

