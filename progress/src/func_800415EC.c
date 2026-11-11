extern char D_800A4C94[];
extern char D_800A4CA0[];
extern char D_800A4CAC[];
extern char gStreamState[];
extern int D_800C355C;
s32 text_load_and_parse();
s32 func_80050DD4();
void *poolAlloc();
s32 memset();

/* Resets the stream state block, then allocates and zeroes one buffer of
 * 0x2C4 bytes per entry for the ten entries that have a nonzero count. */
void func_800415EC(void)
{
  u32 idx;
  char *slots;
  slots = gStreamState + 0x10332;
  memset(slots, 0, 0x7C);
  text_load_and_parse(D_800A4C94, D_800A4CA0);
  for (idx = 0; idx < 10; idx++)
  {
    if ((*((u16 *) ((slots + 0x3E) + (idx * 2)))) != 0)
    {
      *((void **) ((slots + 0x54) + (idx * 4))) = poolAlloc(1, (*((u16 *) ((slots + 0x3E) + (idx * 2)))) * 0x2C4);
      memset(*((void **) ((slots + 0x54) + (idx * 4))), 0, (*((u16 *) ((slots + 0x3E) + (idx * 2)))) * 0x2C4);
    }
  }

  text_load_and_parse(D_800A4C94, D_800A4CAC);
  D_800C355C = 0;
  func_80050DD4();
}
