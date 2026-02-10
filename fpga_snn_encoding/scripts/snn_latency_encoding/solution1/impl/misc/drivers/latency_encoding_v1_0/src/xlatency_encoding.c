// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xlatency_encoding.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XLatency_encoding_CfgInitialize(XLatency_encoding *InstancePtr, XLatency_encoding_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XLatency_encoding_Start(XLatency_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_AP_CTRL) & 0x80;
    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XLatency_encoding_IsDone(XLatency_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XLatency_encoding_IsIdle(XLatency_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XLatency_encoding_IsReady(XLatency_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XLatency_encoding_EnableAutoRestart(XLatency_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XLatency_encoding_DisableAutoRestart(XLatency_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_AP_CTRL, 0);
}

void XLatency_encoding_Set_img(XLatency_encoding *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IMG_DATA, (u32)(Data));
    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IMG_DATA + 4, (u32)(Data >> 32));
}

u64 XLatency_encoding_Get_img(XLatency_encoding *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IMG_DATA);
    Data += (u64)XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IMG_DATA + 4) << 32;
    return Data;
}

void XLatency_encoding_Set_spikes(XLatency_encoding *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_SPIKES_DATA, (u32)(Data));
    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_SPIKES_DATA + 4, (u32)(Data >> 32));
}

u64 XLatency_encoding_Get_spikes(XLatency_encoding *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_SPIKES_DATA);
    Data += (u64)XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_SPIKES_DATA + 4) << 32;
    return Data;
}

void XLatency_encoding_Set_seed(XLatency_encoding *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_SEED_DATA, Data);
}

u32 XLatency_encoding_Get_seed(XLatency_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_SEED_DATA);
    return Data;
}

void XLatency_encoding_InterruptGlobalEnable(XLatency_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_GIE, 1);
}

void XLatency_encoding_InterruptGlobalDisable(XLatency_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_GIE, 0);
}

void XLatency_encoding_InterruptEnable(XLatency_encoding *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IER);
    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IER, Register | Mask);
}

void XLatency_encoding_InterruptDisable(XLatency_encoding *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IER);
    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IER, Register & (~Mask));
}

void XLatency_encoding_InterruptClear(XLatency_encoding *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLatency_encoding_WriteReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_ISR, Mask);
}

u32 XLatency_encoding_InterruptGetEnabled(XLatency_encoding *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_IER);
}

u32 XLatency_encoding_InterruptGetStatus(XLatency_encoding *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XLatency_encoding_ReadReg(InstancePtr->Control_BaseAddress, XLATENCY_ENCODING_CONTROL_ADDR_ISR);
}

