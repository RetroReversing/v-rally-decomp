extern s32 gHeapBusy;
extern s32 gHeapCallerRa;
extern s32 *D_800C5BB0[];
extern s32 gHeapBlocks[];
extern void (*heapPanicFn)(s32), (*heapReentryFn)(s32);
extern void (*D_800C808C)(s32, s32);

/* Allocator entry point. The first argument is either a pool index (below 0x10000,
   looked up in gHeapBlocks) or a pool pointer. The allocation goes through the pool's
   handler in D_800C5BB0, and the pool id is written just before the block. Sets
   gHeapBusy while it runs, to catch re-entry. Returns the block, or 0 on failure. */
s32 poolAlloc(s32 pool_arg, s32 size_arg, ...)
{
 volatile s32 pool_id;
 s32 extra_arg;
 s32 pool_ptr;
 s32 block;
 s32 result = 0;
 if (gHeapBusy == 1) heapReentryFn(gHeapCallerRa - 4);
 gHeapBusy = 1;
 { s32 u; do { gHeapCallerRa = (s32)__builtin_mips_live_return_address(); } while (0); }
 extra_arg = ((s32 *)(((s32)__builtin_next_arg(size_arg) + 3) & ~3))[0];
 if (!(pool_arg & 0xFFFF0000)) { pool_ptr = gHeapBlocks[pool_arg]; pool_id = pool_arg; } else { pool_ptr = pool_arg; pool_id = 1; }
 if (pool_ptr == 0) { heapPanicFn(gHeapCallerRa - 4); block = 0; } else block = pool_ptr - 8;
 if (block) {
  result = ((s32 (*)(s32, s32, s32))*(s32 *)D_800C5BB0[pool_id])(block + 8, size_arg, extra_arg);
  if (result) *(s32 *)(result - 8) = pool_id;
  else D_800C808C(pool_arg, gHeapCallerRa - 4);
 }
 gHeapBusy = 0;
 return result;
}
