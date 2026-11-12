s32 select_reset_text();
s32 select_arm_if_clear();
s32 heapFreeBlock();
extern void *gSelectState;
extern s32 gSelectBuffer;
extern char stream_state[];
extern s32 func_8007A29C;
extern s32 func_8007A9A8;
extern s32 func_8007AA94;

/* Resets the select screen: frees the cached block at gSelectBuffer, sets up the select state,
   installs the three select callbacks in gSelectState and stores the stream count minus one
   at +0x228. */
s32 func_80063104(int arg0, s32 arg1)
{
  char *sel;
  char *count_ptr;
  select_arm_if_clear();
  if (gSelectBuffer != 0)
  {
    heapFreeBlock(gSelectBuffer);
    gSelectBuffer = 0;
  }
  select_reset_text(arg0, arg1);
  sel = (char *) gSelectState;
  count_ptr = ((char *) (*((void **) (stream_state + 0x32F2)))) + 0xF;
  *((s32 **) (((char *) gSelectState) + 0x288)) = &func_8007A29C;
  count_ptr += 0;
  *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_8007A9A8;
  *((s32 **) (sel + 0x290)) = &func_8007AA94;
  *((s8 *) (((char *) gSelectState) + 0x228)) = (s8) ((*((u8 *) count_ptr)) - 1);
  return 0;
}
