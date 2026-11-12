typedef struct S_osPfsInitPak_arg1
{
  s32 unk_00;
  s32 unk_04;
  s32 unk_08;
  u8 unk_0C[0x40];
  s32 unk_4C;
  s32 unk_50;
  s32 unk_54;
  s32 unk_58;
  s32 unk_5C;
  s32 unk_60;
  u8 unk_64;
  u8 unk_65;
} S_osPfsInitPak_arg1;
s32 __osPfsSelectBank(void *, s32);
u32 osGetCount(void);
s32 __osContRamRead(s32, s32, s32, u8 *);
s32 __osContRamWrite(s32, s32, u16, u8 *, s32);
static inline static u16 inline_fn(u16 *arg0)
{
  return *arg0;
}

/* Repairs a controller pak's ID block for the bank at pfs. Searches banks for a
 * free slot (0x80 marks it used, the 0x20-byte block is written inverted and
 * read back to verify), then rebuilds the block from the source record at src
 * and writes it four times to the key slots 1, 3, 4 and 6. dst receives the
 * block. Returns 0 on success or an error code. */
s32 __osRepairPackId(S_osPfsInitPak_arg1 *pfs, void *src, void *dst)
{
  u8 blockA[0x20];
  u8 blockB[0x20];
  u8 *new_var2;
  u16 new_var;
  s32 bank;
  s32 n;
  s32 v;
  s16 keys[4];
  *((s32 *) dst) = -1;
  *(((s32 *) dst) - -1) = osGetCount();
  {
    s32 t0;
    s32 t1;
    t0 = ((s32 *) src)[2];
    t1 = ((s32 *) src)[3];
    ((s32 *) dst)[2] = t0;
    ((s32 *) dst)[3] = t1;
    t0 = ((s32 *) src)[4];
    t1 = ((s32 *) src)[5];
    ((s32 *) dst)[4] = t0;
    ((s32 *) dst)[5] = t1;
  }
  bank = 0;
  if (pfs->unk_65 && (v = __osPfsSelectBank(pfs, 0)))
  {
    return v;
  }
  do
  {
    if (v = __osPfsSelectBank(pfs, bank & 0xFF))
    {
      return v;
    }
    if (v = __osContRamRead(pfs->unk_04, pfs->unk_08, 0, blockA))
    {
      return v;
    }
    blockA[0] = (u8) (bank | 0x80);
    for (n = 1; n < 0x20; n++)
    {
      blockA[n] = (u8) (~blockA[n]);
    }

    if (v = __osContRamWrite(pfs->unk_04, pfs->unk_08, 0, blockA, 0))
    {
      return v;
    }
    if (v = __osContRamRead(pfs->unk_04, pfs->unk_08, 0, blockB))
    {
      return v;
    }
    n = 0;
    while (n < 0x20)
    {
      if (blockB[n] != blockA[n])
      {
        break;
      }
      n++;
    }

    if (n != 0x20)
    {
      break;
    }
      if (bank > 0)
      {
        if (v = __osPfsSelectBank(pfs, 0))
        {
          return v;
        }
        if (v = __osContRamRead(pfs->unk_04, pfs->unk_08, 0, blockA))
        {
          return v;
        }
        if (blockA[0] != 0x80)
        {
          break;
        }
      }
      bank++;
    if (bank >= 0x3E)
    {
      break;
    }
  }
  while (1);
  if (pfs->unk_65 && (v = __osPfsSelectBank(pfs, 0)))
  {
    return v;
  }
  {
    u16 tv0;
    u16 tv1;
    u16 *a0p;
    u16 *a1p;
    u16 *a2p;
    u16 *a3p;
    u16 word;
    u16 acc;
    tv0 = ((u16 *) src)[0xC];
    a2p = (u16 *) (((u8 *) dst) + 0x1E);
    a0p = (u16 *) dst;
    tv1 = (u16) (bank > 0);
    ((u8 *) dst)[0x1A] = (u8) bank;
    tv0 = (u16) (tv0 & 0xFFFE);
    tv1 = (u16) (tv1 | tv0);
    ((u16 *) dst)[0xC] = tv1;
    new_var = (u16) ((u8 *) src)[0x1B];
    tv0 = new_var;
    a1p = (u16 *) (((u8 *) dst) + 0x1C);
    a3p = a1p;
    *((u16 *) (((u8 *) dst) + 0x1E)) = 0;
    *a1p = 0;
    ((u8 *) dst)[0x1B] = (u8) tv0;
    new_var2 = (u8 *) a3p;
    do
    {
      word = inline_fn(a0p);
      acc = inline_fn(a1p);
      acc += word;
      *a1p = acc;
      acc = inline_fn(a2p);
      a0p = (u16 *) (((u8 *) a0p) + 2);
      acc += (u16) (~word);
      *a2p = acc;
    }
    while (((u8 *) a0p) < new_var2);
  }
  keys[0] = 1;
  keys[1] = 3;
  keys[2] = 4;
  keys[3] = 6;
  for (n = 0; n < 4; n++)
  {
    if (v = __osContRamWrite(pfs->unk_04, pfs->unk_08, (u16) keys[n], (u8 *) dst, 1))
    {
      return v;
    }
  }

  if (v = __osContRamRead(pfs->unk_04, pfs->unk_08, 1, blockA))
  {
    return v;
  }
  for (n = 0; n < 0x20; n++)
  {
    if (blockA[n] != ((u8 *) dst)[n])
    {
      return 10;
    }
  }

  return 0;
}
