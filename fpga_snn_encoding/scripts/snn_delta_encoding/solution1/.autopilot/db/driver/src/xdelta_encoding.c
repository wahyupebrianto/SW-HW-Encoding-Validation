// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xdelta_encoding.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XDelta_encoding_CfgInitialize(XDelta_encoding *InstancePtr, XDelta_encoding_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XDelta_encoding_Start(XDelta_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_AP_CTRL) & 0x80;
    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XDelta_encoding_IsDone(XDelta_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XDelta_encoding_IsIdle(XDelta_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XDelta_encoding_IsReady(XDelta_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XDelta_encoding_EnableAutoRestart(XDelta_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XDelta_encoding_DisableAutoRestart(XDelta_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_AP_CTRL, 0);
}

void XDelta_encoding_Set_img(XDelta_encoding *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IMG_DATA, (u32)(Data));
    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IMG_DATA + 4, (u32)(Data >> 32));
}

u64 XDelta_encoding_Get_img(XDelta_encoding *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IMG_DATA);
    Data += (u64)XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IMG_DATA + 4) << 32;
    return Data;
}

void XDelta_encoding_Set_spikes(XDelta_encoding *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_SPIKES_DATA, (u32)(Data));
    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_SPIKES_DATA + 4, (u32)(Data >> 32));
}

u64 XDelta_encoding_Get_spikes(XDelta_encoding *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_SPIKES_DATA);
    Data += (u64)XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_SPIKES_DATA + 4) << 32;
    return Data;
}

void XDelta_encoding_Set_threshold(XDelta_encoding *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_THRESHOLD_DATA, Data);
}

u32 XDelta_encoding_Get_threshold(XDelta_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_THRESHOLD_DATA);
    return Data;
}

void XDelta_encoding_Set_leak(XDelta_encoding *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_LEAK_DATA, Data);
}

u32 XDelta_encoding_Get_leak(XDelta_encoding *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_LEAK_DATA);
    return Data;
}

void XDelta_encoding_InterruptGlobalEnable(XDelta_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_GIE, 1);
}

void XDelta_encoding_InterruptGlobalDisable(XDelta_encoding *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_GIE, 0);
}

void XDelta_encoding_InterruptEnable(XDelta_encoding *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IER);
    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IER, Register | Mask);
}

void XDelta_encoding_InterruptDisable(XDelta_encoding *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IER);
    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IER, Register & (~Mask));
}

void XDelta_encoding_InterruptClear(XDelta_encoding *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDelta_encoding_WriteReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_ISR, Mask);
}

u32 XDelta_encoding_InterruptGetEnabled(XDelta_encoding *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_IER);
}

u32 XDelta_encoding_InterruptGetStatus(XDelta_encoding *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XDelta_encoding_ReadReg(InstancePtr->Control_BaseAddress, XDELTA_ENCODING_CONTROL_ADDR_ISR);
}

