typedef char *va_list7F;
typedef struct 
{
  s32 a;
  s32 b;
} Hdr7F12C;
typedef struct 
{
  s32 pad[3];
  s32 (*fn)(void *, s32, s32, s32);
} Cls7F12C;
extern s32 gHeapBusy;
extern void *gHeapCallerRa;
extern Cls7F12C *D_800C5BB0[];
extern void *gHeapBlocks[];
extern void (*heapPanicFn)(void *);
extern void (*heapReentryFn)(void *);

/* Allocator-style entry point, same shape as func_8007EBF4 but with two extra
   varargs words passed to the class's fn. The handle is resolved to a block and
   class; if both exist the class fn runs on the block, and its result goes to *ret.
   Guarded against reentry. */
s32 func_8007F12C(u32 handle, s32 *ret, s32 arg2, ...)
{
  va_list7F ap;
  s32 arg_a;
  int new_var4;
  s32 arg_b;
  s32 class_idx;
  s32 *pidx = &class_idx;
  Cls7F12C **new_var2;
  int new_var3;
  Hdr7F12C *block;
  Cls7F12C *cls;
  s32 *new_var;
  if (gHeapBusy == 1)
  {
    heapReentryFn(((char *) gHeapCallerRa) - 4);
  }
  gHeapBusy = 1;
  {
    void *u;
    do
    {
      gHeapCallerRa = __builtin_mips_live_return_address();
    }
    while (0);
  }
 do { ap = (va_list7F) __builtin_next_arg(arg2); ap = (char *) ((((int) ap) + 3) & (-4)); new_var4 = 1; arg_a = *((s32 *) ap); ap += 4; ap = (char *) ((((int) ap) + 3) & (-4)); new_var = (s32 *) ap; arg_b = *new_var; if (!(handle & 0xFFFF0000)) { block = gHeapBlocks[handle]; class_idx = handle; } else { block = (Hdr7F12C *) handle; class_idx = new_var4; } if (new_var3 = block == 0) { heapPanicFn(((char *) gHeapCallerRa) - 4); block = 0; } else { block--; } } while (0);
  if (block != 0)
  {
    new_var2 = D_800C5BB0;
    cls = new_var2[class_idx];
    if (cls != 0)
    {
      *ret = cls->fn(block + 1, arg2, arg_a, arg_b);
    }
  }
  gHeapBusy = 0;
  return 0;
}
