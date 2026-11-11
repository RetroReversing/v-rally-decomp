extern char gOrderState[];
extern void *gOrderPrevHook;
s32 order_alloc_records(s32);
void func_8001BD44(void);
/* Sets up the order record block in gOrderState: two record buffers of 300 entries
   each, and installs func_8001BD44 as the hook, keeping the previous hook in the state. */
void func_8001BDA0(void)
{
  s32 *block = (s32 *) (gOrderState + 0x87D8);
  s32 buf;
  block[0] = order_alloc_records(0x12C);
  buf = order_alloc_records(0x12C);
  block[2] = block[0];
  *((s32 *) (gOrderState + 0x6D9C)) = (s32)gOrderPrevHook;
  block[4] = 0;
  block[5] = 0x12C;
  block[1] = buf;
  block[3] = buf;
  gOrderPrevHook = func_8001BD44;
}
