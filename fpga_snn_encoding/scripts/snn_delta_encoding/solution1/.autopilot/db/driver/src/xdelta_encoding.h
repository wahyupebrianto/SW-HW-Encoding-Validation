// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XDELTA_ENCODING_H
#define XDELTA_ENCODING_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xdelta_encoding_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XDelta_encoding_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XDelta_encoding;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XDelta_encoding_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XDelta_encoding_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XDelta_encoding_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XDelta_encoding_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XDelta_encoding_Initialize(XDelta_encoding *InstancePtr, UINTPTR BaseAddress);
XDelta_encoding_Config* XDelta_encoding_LookupConfig(UINTPTR BaseAddress);
#else
int XDelta_encoding_Initialize(XDelta_encoding *InstancePtr, u16 DeviceId);
XDelta_encoding_Config* XDelta_encoding_LookupConfig(u16 DeviceId);
#endif
int XDelta_encoding_CfgInitialize(XDelta_encoding *InstancePtr, XDelta_encoding_Config *ConfigPtr);
#else
int XDelta_encoding_Initialize(XDelta_encoding *InstancePtr, const char* InstanceName);
int XDelta_encoding_Release(XDelta_encoding *InstancePtr);
#endif

void XDelta_encoding_Start(XDelta_encoding *InstancePtr);
u32 XDelta_encoding_IsDone(XDelta_encoding *InstancePtr);
u32 XDelta_encoding_IsIdle(XDelta_encoding *InstancePtr);
u32 XDelta_encoding_IsReady(XDelta_encoding *InstancePtr);
void XDelta_encoding_EnableAutoRestart(XDelta_encoding *InstancePtr);
void XDelta_encoding_DisableAutoRestart(XDelta_encoding *InstancePtr);

void XDelta_encoding_Set_img(XDelta_encoding *InstancePtr, u64 Data);
u64 XDelta_encoding_Get_img(XDelta_encoding *InstancePtr);
void XDelta_encoding_Set_spikes(XDelta_encoding *InstancePtr, u64 Data);
u64 XDelta_encoding_Get_spikes(XDelta_encoding *InstancePtr);
void XDelta_encoding_Set_threshold(XDelta_encoding *InstancePtr, u32 Data);
u32 XDelta_encoding_Get_threshold(XDelta_encoding *InstancePtr);
void XDelta_encoding_Set_leak(XDelta_encoding *InstancePtr, u32 Data);
u32 XDelta_encoding_Get_leak(XDelta_encoding *InstancePtr);

void XDelta_encoding_InterruptGlobalEnable(XDelta_encoding *InstancePtr);
void XDelta_encoding_InterruptGlobalDisable(XDelta_encoding *InstancePtr);
void XDelta_encoding_InterruptEnable(XDelta_encoding *InstancePtr, u32 Mask);
void XDelta_encoding_InterruptDisable(XDelta_encoding *InstancePtr, u32 Mask);
void XDelta_encoding_InterruptClear(XDelta_encoding *InstancePtr, u32 Mask);
u32 XDelta_encoding_InterruptGetEnabled(XDelta_encoding *InstancePtr);
u32 XDelta_encoding_InterruptGetStatus(XDelta_encoding *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
