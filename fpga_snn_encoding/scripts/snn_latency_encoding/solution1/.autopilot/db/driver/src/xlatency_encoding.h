// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.1 (64-bit)
// Tool Version Limit: 2024.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XLATENCY_ENCODING_H
#define XLATENCY_ENCODING_H

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
#include "xlatency_encoding_hw.h"

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
} XLatency_encoding_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XLatency_encoding;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XLatency_encoding_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XLatency_encoding_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XLatency_encoding_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XLatency_encoding_ReadReg(BaseAddress, RegOffset) \
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
int XLatency_encoding_Initialize(XLatency_encoding *InstancePtr, UINTPTR BaseAddress);
XLatency_encoding_Config* XLatency_encoding_LookupConfig(UINTPTR BaseAddress);
#else
int XLatency_encoding_Initialize(XLatency_encoding *InstancePtr, u16 DeviceId);
XLatency_encoding_Config* XLatency_encoding_LookupConfig(u16 DeviceId);
#endif
int XLatency_encoding_CfgInitialize(XLatency_encoding *InstancePtr, XLatency_encoding_Config *ConfigPtr);
#else
int XLatency_encoding_Initialize(XLatency_encoding *InstancePtr, const char* InstanceName);
int XLatency_encoding_Release(XLatency_encoding *InstancePtr);
#endif

void XLatency_encoding_Start(XLatency_encoding *InstancePtr);
u32 XLatency_encoding_IsDone(XLatency_encoding *InstancePtr);
u32 XLatency_encoding_IsIdle(XLatency_encoding *InstancePtr);
u32 XLatency_encoding_IsReady(XLatency_encoding *InstancePtr);
void XLatency_encoding_EnableAutoRestart(XLatency_encoding *InstancePtr);
void XLatency_encoding_DisableAutoRestart(XLatency_encoding *InstancePtr);

void XLatency_encoding_Set_img(XLatency_encoding *InstancePtr, u64 Data);
u64 XLatency_encoding_Get_img(XLatency_encoding *InstancePtr);
void XLatency_encoding_Set_spikes(XLatency_encoding *InstancePtr, u64 Data);
u64 XLatency_encoding_Get_spikes(XLatency_encoding *InstancePtr);
void XLatency_encoding_Set_seed(XLatency_encoding *InstancePtr, u32 Data);
u32 XLatency_encoding_Get_seed(XLatency_encoding *InstancePtr);

void XLatency_encoding_InterruptGlobalEnable(XLatency_encoding *InstancePtr);
void XLatency_encoding_InterruptGlobalDisable(XLatency_encoding *InstancePtr);
void XLatency_encoding_InterruptEnable(XLatency_encoding *InstancePtr, u32 Mask);
void XLatency_encoding_InterruptDisable(XLatency_encoding *InstancePtr, u32 Mask);
void XLatency_encoding_InterruptClear(XLatency_encoding *InstancePtr, u32 Mask);
u32 XLatency_encoding_InterruptGetEnabled(XLatency_encoding *InstancePtr);
u32 XLatency_encoding_InterruptGetStatus(XLatency_encoding *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
