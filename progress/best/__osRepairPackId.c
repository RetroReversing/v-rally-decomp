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
s32 func_800937B0(void);
s32 __osContRamRead(s32, s32, s32, u8 *);
s32 func_80096A10(s32, s32, u16, u8 *, s32);
static inline static u16 inline_fn(u16 *arg0)
{
  return *arg0;
}

s32 __osRepairPackId(S_osPfsInitPak_arg1 *p, void *q, void *r)
{
  u8 a[0x20];
  u8 b[0x20];
  u8 *new_var2;
  u16 new_var;
  s32 bank;
  s32 n;
  s32 v;
  s16 keys[4];
  *((s32 *) r) = -1;
  *(((s32 *) r) - -1) = func_800937B0();
  {
    s32 t0;
    s32 t1;
    t0 = ((s32 *) q)[2];
    t1 = ((s32 *) q)[3];
    ((s32 *) r)[2] = t0;
    ((s32 *) r)[3] = t1;
    t0 = ((s32 *) q)[4];
    t1 = ((s32 *) q)[5];
    ((s32 *) r)[4] = t0;
    ((s32 *) r)[5] = t1;
  }
  bank = 0;
  if (p->unk_65 && (v = __osPfsSelectBank(p, 0)))
  {
    return v;
  }
  do
  {
    if (v = __osPfsSelectBank(p, bank & 0xFF))
    {
      return v;
    }
    if (v = __osContRamRead(p->unk_04, p->unk_08, 0, a))
    {
      return v;
    }
    a[0] = (u8) (bank | 0x80);
    for (n = 1; n < 0x20; n++)
    {
      a[n] = (u8) (~a[n]);
    }

    if (v = func_80096A10(p->unk_04, p->unk_08, 0, a, 0))
    {
      return v;
    }
    if (v = __osContRamRead(p->unk_04, p->unk_08, 0, b))
    {
      return v;
    }
    n = 0;
    while (n < 0x20)
    {
      if (b[n] != a[n])
      {
        break;
      }
      n++;
    }

    if (n == 0x20)
    {
      if (bank > 0)
      {
        if (v = __osPfsSelectBank(p, 0))
        {
          return v;
        }
        if (v = __osContRamRead(p->unk_04, p->unk_08, 0, a))
        {
          return v;
        }
        if (a[0] != 0x80)
        {
          break;
        }
      }
      bank++;
    }
    if (bank >= 0x3E)
    {
      break;
    }
  }
  while (1);
  if (p->unk_65 && (v = __osPfsSelectBank(p, 0)))
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
    tv0 = ((u16 *) q)[0xC];
    a2p = (u16 *) (((u8 *) r) + 0x1E);
    a0p = (u16 *) r;
    tv1 = (u16) (bank > 0);
    ((u8 *) r)[0x1A] = (u8) bank;
    tv0 = (u16) (tv0 & 0xFFFE);
    tv1 = (u16) (tv1 | tv0);
    ((u16 *) r)[0xC] = tv1;
    new_var = (u16) ((u8 *) q)[0x1B];
    tv0 = new_var;
    a1p = (u16 *) (((u8 *) r) + 0x1C);
    a3p = a1p;
    *((u16 *) (((u8 *) r) + 0x1E)) = 0;
    *a1p = 0;
    ((u8 *) r)[0x1B] = (u8) tv0;
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
    if (v = func_80096A10(p->unk_04, p->unk_08, (u16) keys[n], (u8 *) r, 1))
    {
      return v;
    }
  }

  if (v = __osContRamRead(p->unk_04, p->unk_08, 1, a))
  {
    return v;
  }
  for (n = 0; n < 0x20; n++)
  {
    if (a[n] != ((u8 *) r)[n])
    {
      return 10;
    }
  }

  return 0;
}
