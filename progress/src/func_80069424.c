extern s32 D_8009B974;
extern s32 D_800A1634;
#ifdef PORT
extern u8 *gRecords;
#else
extern s32 gRecords;
#endif
extern s32 contClearEntryWords();
extern s32 func_800852FC(s32, s32 *, s32);

/* For the first two records in gRecords: takes the record's 32-bit value at +0x68,
   maps each of its eight 4-bit nibbles through the table at D_800A1634 into an
   8-byte stride of D_8009B974 (one word per nibble), then passes each record
   on to contClearEntryWords and func_800852FC. */
void func_80069424(void)
{
  #ifdef PORT
  u8 *recordAddr;
#else
  int recordAddr;
#endif
  s8 i;
  s8 idx;
  #ifdef PORT
  u8 *base;
#else
  s32 base;
#endif
  #ifdef PORT
  u8 *charBase;
#else
  s32 charBase;
#endif
  s32 value;
  s8 j;
  u32 bits;
  s32 outIndex;
  i = 0;
  charBase = gRecords + 0x32;
  do
  {
    idx = i;
    base = gRecords;
    value = *((u8 *) (charBase + idx));
    recordAddr = base + (value * 0x28);
    bits = *((u32 *) (recordAddr + 0x68));
    j = 0;
    do
    {
      outIndex = j << 24;
      *((s32 *) (((char *) (&D_8009B974)) + (outIndex >> 21))) = *((s32 *) (((char *) (&D_800A1634)) + ((bits & 0xF) * 4)));
      bits >>= 4;
      j = (s8) (j + 1);
    }
    while (j < 8);
    contClearEntryWords(i & 0xFF);
    func_800852FC(i & 0xFF, &D_8009B974, 0xC);
    i = (s8) (i + 1);
  }
  while (i < 2);
}
