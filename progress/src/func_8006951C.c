s32 func_80068D9C();
extern void *gSelectState;
extern char D_800A167C[];
extern char D_800A1684[];
extern char gStreamState[];
static inline char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

/* Clears the 0x10 flag in the selected stream record and sets its 0x68 word
 * to 0x75834210, calls func_80068D9C(0x19, 0), then fills the two 8-entry
 * tables with the nibbles of 0x75834210, lowest nibble first. */
s32 func_8006951C(void)
{
  s32 idx;
  int recOff;
  s32 i;
  s8 nib;
  u32 order;
  void *rec;
  order = 0x75834210;
  recOff = (*((s8 *) (inline_fn(gSelectState) + 0x22A))) * 0x28;
  *((s32 *) (((char *) ((*((s32 *) (gStreamState + 0x32F2))) + recOff)) + 0x68)) = 0x75834210;
  rec = (*((s32 *) (gStreamState + 0x32F2))) + ((*((s8 *) (inline_fn(gSelectState) + 0x22A))) * 0x28);
  *((u8 *) (((char *) rec) + 0x48)) &= 0xEF;
  func_80068D9C(0x19, 0);
  i = 0;
  do
  {
    nib = order & 0xF;
    idx = i & 0xFF;
    i += 1;
    *(D_800A167C + idx) = nib;
    *(D_800A1684 + idx) = nib;
    order = order >> 4;
  }
  while (((u32) (i & 0xFF)) < 8U);
  return 0;
}
