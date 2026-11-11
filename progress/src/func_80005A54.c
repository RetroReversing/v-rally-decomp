extern signed char D_800AE865;
s32 func_8007F798();
extern volatile unsigned char D_8009B5B0;
extern char gOrderState[];
extern char gStreamState[];

/* One-time setup: stores the two buffers in the stream state, clears their +0x14 flag byte
 * and sends message 6 to func_8007F798. Returns 1 on the first call, 0 after that. */
s32 func_80005A54(void *first, void *second)
{
  void **slot;
  s32 ret;
  char *state;
  int one;
  ret = 0;
  if (D_8009B5B0 == 0)
  {
    state = gStreamState;
    D_800AE865 = 1;
    *((void **) (state + 0x1030A)) = first;
    *((void **) (gStreamState + 0x3252)) = second;
    *((s8 *) (((char *) first) + 0x14)) = 0;
    slot = (void **) (gStreamState + 0x3252);
    *((s8 *) (((char *) (*slot)) + 0x14)) = 0;
    D_8009B5B0 = 1;
    func_8007F798(6, 0, *((void **) (gStreamState + 0x1030A)));
    one = 1;
    ret = one;
  }
  return ret;
}
