extern char gOrderState[];
extern void *gOrderPrevHook;
s32 order_alloc_records(s32);
void func_8001BD44(void);
/* Sets up the order record block in gOrderState: two record buffers of 300 entries
   each, and installs func_8001BD44 as the hook, keeping the previous hook in the state. */
void order_records_init(void)
{
  s32 *records = (s32 *) (gOrderState + 0x87D8);
  s32 second_buf;
  records[0] = order_alloc_records(0x12C);
  second_buf = order_alloc_records(0x12C);
  records[2] = records[0];
  *((void **) (gOrderState + 0x6D9C)) = gOrderPrevHook;
  records[4] = 0;
  records[5] = 0x12C;
  records[1] = second_buf;
  records[3] = second_buf;
  gOrderPrevHook = func_8001BD44;
}
