; ModuleID = 'E:/1_Research/Neuromorphic/NEUROMORPHIC/First_research/fpga_snn_encoding/scripts/snn_delta_encoding/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: noinline
define void @apatb_delta_encoding_ir(float* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="784" "maxi" %img, [784 x i8]* noalias nocapture nonnull "fpga.decayed.dim.hint"="25" "maxi" %spikes, float %threshold, float %leak) local_unnamed_addr #0 {
entry:
  %img_copy = alloca [784 x float], align 512
  %malloccall = tail call i8* @malloc(i64 19600)
  %spikes_copy = bitcast i8* %malloccall to [25 x [784 x i8]]*
  %0 = bitcast float* %img to [784 x float]*
  %1 = bitcast [784 x i8]* %spikes to [25 x [784 x i8]]*
  call fastcc void @copy_in([784 x float]* nonnull %0, [784 x float]* nonnull align 512 %img_copy, [25 x [784 x i8]]* nonnull %1, [25 x [784 x i8]]* %spikes_copy)
  call void @apatb_delta_encoding_hw([784 x float]* %img_copy, [25 x [784 x i8]]* %spikes_copy, float %threshold, float %leak)
  call void @copy_back([784 x float]* %0, [784 x float]* %img_copy, [25 x [784 x i8]]* %1, [25 x [784 x i8]]* %spikes_copy)
  tail call void @free(i8* %malloccall)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_in([784 x float]* noalias readonly, [784 x float]* noalias align 512, [25 x [784 x i8]]* noalias readonly, [25 x [784 x i8]]* noalias) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a784f32([784 x float]* align 512 %1, [784 x float]* %0)
  call fastcc void @onebyonecpy_hls.p0a25a784i8([25 x [784 x i8]]* %3, [25 x [784 x i8]]* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0a784f32([784 x float]* noalias align 512 %dst, [784 x float]* noalias readonly %src) unnamed_addr #2 {
entry:
  %0 = icmp eq [784 x float]* %dst, null
  %1 = icmp eq [784 x float]* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @arraycpy_hls.p0a784f32([784 x float]* nonnull %dst, [784 x float]* nonnull %src, i64 784)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a784f32([784 x float]* %dst, [784 x float]* readonly %src, i64 %num) local_unnamed_addr #3 {
entry:
  %0 = icmp eq [784 x float]* %src, null
  %1 = icmp eq [784 x float]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [784 x float], [784 x float]* %dst, i64 0, i64 %for.loop.idx2
  %src.addr = getelementptr [784 x float], [784 x float]* %src, i64 0, i64 %for.loop.idx2
  %3 = load float, float* %src.addr, align 4
  store float %3, float* %dst.addr, align 4
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0a25a784i8([25 x [784 x i8]]* noalias %dst, [25 x [784 x i8]]* noalias readonly %src) unnamed_addr #2 {
entry:
  %0 = icmp eq [25 x [784 x i8]]* %dst, null
  %1 = icmp eq [25 x [784 x i8]]* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @arraycpy_hls.p0a25a784i8([25 x [784 x i8]]* nonnull %dst, [25 x [784 x i8]]* nonnull %src, i64 25)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a25a784i8([25 x [784 x i8]]* %dst, [25 x [784 x i8]]* readonly %src, i64 %num) local_unnamed_addr #3 {
entry:
  %0 = icmp eq [25 x [784 x i8]]* %src, null
  %1 = icmp eq [25 x [784 x i8]]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [25 x [784 x i8]], [25 x [784 x i8]]* %dst, i64 0, i64 %for.loop.idx2
  %src.addr = getelementptr [25 x [784 x i8]], [25 x [784 x i8]]* %src, i64 0, i64 %for.loop.idx2
  call void @arraycpy_hls.p0a784i8([784 x i8]* %dst.addr, [784 x i8]* %src.addr, i64 784)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a784i8([784 x i8]* %dst, [784 x i8]* readonly %src, i64 %num) local_unnamed_addr #3 {
entry:
  %0 = icmp eq [784 x i8]* %src, null
  %1 = icmp eq [784 x i8]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [784 x i8], [784 x i8]* %dst, i64 0, i64 %for.loop.idx2
  %src.addr = getelementptr [784 x i8], [784 x i8]* %src, i64 0, i64 %for.loop.idx2
  %3 = load i8, i8* %src.addr, align 1
  store i8 %3, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_out([784 x float]* noalias, [784 x float]* noalias readonly align 512, [25 x [784 x i8]]* noalias, [25 x [784 x i8]]* noalias readonly) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a784f32([784 x float]* %0, [784 x float]* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0a25a784i8([25 x [784 x i8]]* %2, [25 x [784 x i8]]* %3)
  ret void
}

declare void @free(i8*) local_unnamed_addr

declare void @apatb_delta_encoding_hw([784 x float]*, [25 x [784 x i8]]*, float, float)

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_back([784 x float]* noalias, [784 x float]* noalias readonly align 512, [25 x [784 x i8]]* noalias, [25 x [784 x i8]]* noalias readonly) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a25a784i8([25 x [784 x i8]]* %2, [25 x [784 x i8]]* %3)
  ret void
}

define void @delta_encoding_hw_stub_wrapper([784 x float]*, [25 x [784 x i8]]*, float, float) #5 {
entry:
  call void @copy_out([784 x float]* null, [784 x float]* %0, [25 x [784 x i8]]* null, [25 x [784 x i8]]* %1)
  %4 = bitcast [784 x float]* %0 to float*
  %5 = bitcast [25 x [784 x i8]]* %1 to [784 x i8]*
  call void @delta_encoding_hw_stub(float* %4, [784 x i8]* %5, float %2, float %3)
  call void @copy_in([784 x float]* null, [784 x float]* %0, [25 x [784 x i8]]* null, [25 x [784 x i8]]* %1)
  ret void
}

declare void @delta_encoding_hw_stub(float* noalias nocapture nonnull readonly, [784 x i8]* noalias nocapture nonnull, float, float)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="arraycpy_hls" }
attributes #4 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
