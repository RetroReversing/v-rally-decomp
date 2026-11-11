s32 select_reset_text();
s32 func_8005C198();
s32 heapFreeBlock();
extern void *gSelectState;
extern s32 gSelectBuffer;
extern char gStreamState[];
extern s32 func_8007A29C;
extern s32 func_8007A9A8;
extern s32 func_8007AA94;

/* Select-screen setup: frees the saved block in gSelectBuffer if there is one, runs the setup
 * chain select_reset_text, installs three state handlers in the select state (+0x288, +0x28C,
 * +0x290) and stores the last record index (count at record block +0xF, minus one) at +0x228.
 * Returns 0. */
s32 func_80065F9C(int arg0, s32 arg1)
{
  char *state;
  char *count;
  func_8005C198();
  if (gSelectBuffer != 0)
  {
    heapFreeBlock(gSelectBuffer);
    gSelectBuffer = 0;
  }
  select_reset_text(arg0, arg1);
  state = (char *) gSelectState;
  count = ((char *) (*((void **) (gStreamState + 0x32F2)))) + 0xF;
  *((s32 **) (((char *) gSelectState) + 0x288)) = &func_8007A29C;
  count += 0;
  *((s32 **) (((char *) gSelectState) + 0x28C)) = &func_8007A9A8;
  *((s32 **) (state + 0x290)) = &func_8007AA94;
  *((s8 *) (((char *) gSelectState) + 0x228)) = (s8) ((*((u8 *) count)) - 1);
  return 0;
}
