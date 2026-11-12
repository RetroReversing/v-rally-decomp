extern s32 gHeapBusy;
extern s32 gHeapCallerRa;
extern s32 *D_800C5BB0[];
extern s32 gHeapBlocks[];
extern void (*heapPanicFn)(s32), (*heapReentryFn)(s32);
extern void (*D_800C808C)(s32, s32);
/* Allocator entry point: takes a handle or a raw pointer in arg0, calls the
   chosen allocator's vtable slot 6 with the block size from the varargs, and
   returns the new block (or 0 after reporting failure). Guarded against reentry. */
s32 func_8007EBF4(s32 handle, s32 size, ...)
{
 volatile s32 handle_idx;
 s32 size_arg;
 s32 block;
 s32 base;
 s32 result = 0;
#ifdef PORT
 __builtin_va_list ap;
#endif
 if (gHeapBusy == 1) heapReentryFn(gHeapCallerRa - 4);
 gHeapBusy = 1;
#ifdef PORT
 gHeapCallerRa = 0;
 __builtin_va_start(ap, size);
 size_arg = __builtin_va_arg(ap, s32);
 __builtin_va_end(ap);
#else
 { s32 u; do { gHeapCallerRa = (s32)__builtin_mips_live_return_address(); } while (0); }
 size_arg = ((s32 *)(((s32)__builtin_next_arg(size) + 3) & ~3))[0];
#endif
 if (!(handle & 0xFFFF0000)) { block = gHeapBlocks[handle]; handle_idx = handle; } else { block = handle; handle_idx = 1; }
 if (block == 0) { heapPanicFn(gHeapCallerRa - 4); base = 0; } else base = block - 8;
 if (base) {
#ifdef PORT
  result = ((s32 (*)(s32, s32, s32))(unsigned long)(unsigned int)D_800C5BB0[handle_idx][6])(base + 8, size, size_arg);
#else
  result = ((s32 (*)(s32, s32, s32))D_800C5BB0[handle_idx][6])(base + 8, size, size_arg);
#endif
  if (result)
#ifdef PORT
    *(s32 *)(unsigned long)(unsigned int)(result - 8) = handle_idx;
#else
    *(s32 *)(result - 8) = handle_idx;
#endif
  else D_800C808C(handle, gHeapCallerRa - 4);
 }
 gHeapBusy = 0;
 return result;
}
