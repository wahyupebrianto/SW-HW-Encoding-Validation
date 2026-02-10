// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xdelta_encoding.h"

extern XDelta_encoding_Config XDelta_encoding_ConfigTable[];

#ifdef SDT
XDelta_encoding_Config *XDelta_encoding_LookupConfig(UINTPTR BaseAddress) {
	XDelta_encoding_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XDelta_encoding_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XDelta_encoding_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XDelta_encoding_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XDelta_encoding_Initialize(XDelta_encoding *InstancePtr, UINTPTR BaseAddress) {
	XDelta_encoding_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XDelta_encoding_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XDelta_encoding_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XDelta_encoding_Config *XDelta_encoding_LookupConfig(u16 DeviceId) {
	XDelta_encoding_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XDELTA_ENCODING_NUM_INSTANCES; Index++) {
		if (XDelta_encoding_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XDelta_encoding_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XDelta_encoding_Initialize(XDelta_encoding *InstancePtr, u16 DeviceId) {
	XDelta_encoding_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XDelta_encoding_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XDelta_encoding_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

