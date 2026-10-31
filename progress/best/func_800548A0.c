extern char *D_800C35A0;
extern char *D_800D0634;
extern u16 D_800D061E;
extern s32 D_800C3B80;
extern s8 D_800C3B84;
extern s8 D_800C3B85;
extern s8 D_800C3B8B;
extern s8 D_800C3B8C;
extern s8 D_800C3B8A;
extern char D_800C02AE[];
s32 func_800535F4(void *);
s32 func_80098180(void *, void *);
s32 func_80098290();
void func_800548A0(void)
{
  char *__repair_addr;
  s32 sp10[8];
  s16 sp30[4];
  u8 sp3F;
  s32 *sp44;
  char *s7;
  char *fp;
  s32 *s5;
  s32 s0;
  int s3;
  s32 s4;
  u8 a3;
  s32 s1;
  s32 s2;
  s32 a2;
  s32 v0;
  s32 v1;
  s32 temp_v1_2;
  s32 temp_v0;
  s32 temp_s0_2;
  s32 var_s1_2;
  s32 var_s2;
  void *temp_a0;
  s32 *temp_s0_3;
  sp3F = 0;
  sp44 = sp10;
  do
  {
    s0 = sp3F << 2;
    func_80098290(&sp30, D_800C35A0 + ((sp3F * 0x28) + 0x44));
    s7 = D_800D0634;
    v1 = s0 + ((s32) sp44);
    *((s32 *) v1) = 0;
    *((s32 *) (v1 + 0x10)) = 0;
    s3 = 1;
    a3 = 0;
    if (D_800D061E == 0)
    {
      goto outer_done;
    }
    s5 = (s32 *) v1;
    fp = s7 + 0x14;
    do
    {
      v0 = *((u16 *) fp);
      v0 = ((u32) v0) > 0U;
      v0 = s3 & v0;
      s3 = 0;
      if (v0 == 0)
      {
        goto row_advance;
      }
      s4 = 0;
      do
      {
        a2 = 1;
        s1 = 0;
        temp_s0_2 = s4 & 0xFF;
    s2 = (temp_s0_2) << 6;
        v0 = 0;
        inner_loop:
        temp_v1_2 = v0 * 0x10;

        temp_a0 = (s7 + temp_v1_2) + s2;
        if ((*((u8 *) (((char *) temp_a0) + 0x38))) != 1)
        {
          s1 += 1;
          goto inner_continue;
        }
        temp_v0 = func_80098180(&sp30, (((char *) temp_a0) + 0x2C) + 6);
        if (temp_v0 == 0)
        {
          *s5 += *((s32 *) (((char *) temp_a0) + 0x2C));
          s3 = 1;
          s5[4] += *((u8 *) (((char *) temp_a0) + 0x36));
        }
        else
        {
          s1 += 1;
          inner_continue:
          v0 = s1 & 0xFF;

          if (a2 & (((u32) (s1 & 0xFF)) < 3U))
          {
            goto inner_loop;
          }
        }
        s4 += 1;
        v0 = s4 & 0xFF;
      }
      while (s3 & (v0 < ((u32) (*((u16 *) fp)))));
      row_advance:
      fp += 0x2C4;

      s7 += 0x2C4;
      a3 += 1;
    }
    while (s3 & (((u32) (a3 & 0xFF)) < ((u32) D_800D061E)));
    outer_done:
    var_s2 = 1;

    if (s3 & 0xFF)
    {
      var_s1_2 = 0;
      do
      {
        temp_s0_2 = (var_s1_2 & 0xFF) * 0x10;
        var_s1_2 += 1;
        if (func_80098180(&sp30, (D_800C02AE + 0x38A8) + temp_s0_2) == 0)
        {
          var_s2 &= -((*((s32 *) ((D_800C02AE + 0x38A2) + temp_s0_2))) != sp44[sp3F]);
        }
      }
      while (((u32) (var_s1_2 & 0xFF)) < 3U);
      if (var_s2 & 0xFF)
      {
        temp_s0_3 = &sp44[sp3F];
        temp_a0 = D_800C35A0 + sp3F;
        D_800C3B8B = 0;
        D_800C3B80 = *temp_s0_3;
        __repair_addr = (char *) ((D_800C35A0 + (((u8 *) temp_a0)[0x32] * 0x28)) + 0x4E);
        D_800C3B84 = (s8) (*((u16 *) __repair_addr));
        D_800C3B85 = (s8) (*((u16 *) (D_800C35A0 + 0x16)));
        func_80098290((D_800C02AE + 0x38D2) + (var_s1_2 = 6), D_800C35A0 + ((((u8 *) temp_a0)[0x32] * 0x28) + 0x44), D_800C35A0);
        D_800C3B8C = 1;
        s3 = 0x38D2;
        D_800C3B8A = (s8) (temp_s0_3[4] / 50);
        func_800535F4((D_800C02AE + s3) - 0x30);
      }
    }
    sp3F += 1;
  }
  while (sp3F < 4U);
}
