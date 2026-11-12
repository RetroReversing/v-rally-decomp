extern unsigned char D_800ADFE1;
extern unsigned char gCurCount;
extern int D_800ADFE8;
extern char gGameState[];
extern char stream_state[];

/* Returns 1 unless the stream at obj has finished its last block and stream_state's
   entry reports idle (its 16-bit field at +0x1E is zero); the flag is then 0 or 1. */
s32 func_800464B0(void *obj)
{
  s16 remaining;
  s16 *sub_count;
  s32 result;
  char *state;

  sub_count = &(*((s16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) obj) + 0x8C)))) + 0x28)))) + 8)));
  result = 1;
  if ((((D_800ADFE1 != 0) && ((*(*((s32 **) (((char *) obj) + 0x70)))) == (gCurCount - 1))) && (((remaining = *sub_count, (((u32) remaining) < ((u32) (D_800ADFE8 - 1))) == 0)) || (remaining <= 0))) && (!((*((s32 *) (((char *) obj) + 0x14))) & 0x100)))
  {
    result = (*((u16 *) (((char *) (*((void **) (state = stream_state + 0x32F2)))) + 0x1E))) == 0;
  }
  return result;
}
