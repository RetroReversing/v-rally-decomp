extern u8 *D_800C35A0;
extern s32 D_800A123C;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern void func_8007C694(void);
extern void func_8007EA64(s32, s32, s32 *, s32 *);
extern s32 func_80084BF0(s32);
extern s32 func_80084DD4(s32);
void func_800516BC(void)
{
  s32 a0;
  s32 s0;
  s32 s1;
  s32 v0;
  int new_var4;
  s32 v1;
  s32 *a2;
  s32 new_var;
  u16 *new_var5;
  s32 *a3;
  u8 new_var3;
  s32 *new_var2;
  s32 *t0;
  s32 ta0;
  s32 ta1;
  s0 = 0;
  if ((*((u16 *) (D_800C35A0 + 0x1E))) != 7)
  {
    return;
  }
  s1 = (new_var = func_80084BF0(0));
  v0 = func_80084DD4(1);
  if (v0 != 0)
  {
    s0 = func_80084BF0(1);
  }
  func_8007C694();
  if (((*(new_var5 = (u16 *) (((u8 *) D_800C35A0) + 0x2C))) & 0x20) == 0)
  {
    a0 = 0;
    if ((s0 & 0x1000) == 0)
    {
      if ((s1 & 0x1000) == 0)
      {
        v0 = D_800A123C;
        D_800A123C = v0 + 1;
        if (v0 != 0x8CA)
        {
          v1 = *((u16 *) (D_800AE850 + 0x2414));
          v0 = (*((u16 *) (D_800AE850 + 0x2416))) - 0x64;
          if (v0 != v1)
          {
            goto done;
          }
        }
      }
    }
    a0 = 1;
  }
  else
  {
    a0 = 0;
    if ((s1 & 0x1000) == 0)
    {
      v0 = D_800A123C;
      D_800A123C = v0 + 1;
      v1 = 0x19;
      if (v0 != v1)
      {
        goto done;
      }
    }
    a0 = 1;
  }
  done:
  if (a0 == 0)
  {
    return;
  }

  a3 = (s32 *) D_800C35A0;
  {
    extern s32 D_800C8214[];
    a2 = D_800C8214;
  }
  t0 = a2 + 0x3C;
  D_800A123C = 0;
  do
  {
    ta0 = a2[2];
    ta1 = a2[3];
    new_var4 = 0;
    ((s32 *) D_800C35A0)[new_var4] = a2[new_var4];
    ((s32 *) D_800C35A0)[1] = a2[1];
    ((s32 *) D_800C35A0)[2] = ta0;
    a3[3] = ta1;
    a3 += 4;
  }
  while (a2 != t0);
  new_var2 = a3;
  *a3 = *a2;
  D_800C02AE[0x7E72] = 0;
  *((s16 *) (((u8 *) D_800C35A0) + 0xE)) = 1;
  s0 = ta0;
  func_8007EA64(s0, ta1, a2, new_var2);
  a2 += 4;
  *((s16 *) (((u8 *) D_800C35A0) + 0x12)) = (s16) D_800C02AE[0x38F2];
  new_var3 = (v0 = D_800C02AE[0x38F0]);
  *((s32 *) (D_800AE850 + 0x8030)) = 5;
  new_var = new_var4;
  *((u16 *) (((u8 *) D_800C35A0) + 0x1E)) = new_var;
  *((s16 *) (((u8 *) D_800C35A0) + 0xE)) = (s16) v0;
}
