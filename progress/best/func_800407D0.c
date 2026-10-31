#define I(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define P(p,o) ((o)==0x32F2 ? D_800C35A0 : (*(u8 **)((u8 *)(p)+(o))))
extern u8 *D_800C35A0;
u64 osGetTime(void);
void func_80053C28(u8, s32, s32, u32);
u32 func_80098090();
void func_800980C4(u32);
void func_80099DF8(s32 *, void *, void *, s32);
extern void D_800A4C20;
extern void D_800A4C28;
extern u8 D_800C02AE[];
void func_800407D0(void)
{
  s32 sp10[4];
  s32 sp20;
  s32 pad[4];
  s32 temp_s0;
  s32 *var_s4;
  u8 *temp_s3;
  s16 new_var3;
  s32 var_a0;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_s1;
  s32 var_s2;
  s32 var_s2_2;
  s32 var_v1_3;
  u16 *temp_fp;
  u16 *var_a0_2;
  volatile unsigned int new_var2;
  u16 *var_a0_3;
  u32 temp_s2;
  u32 temp_s6;
  u16 temp_v1;
  u32 temp_hi;
  u32 temp_hi_2;
  u32 temp_s0_2;
  int new_var4;
  u32 temp_s0_3;
  s32 *new_var;
  u32 var_v1;
  u32 var_v1_2;
  void *temp_a1;
  {
    extern u16 D_800D0630;
    temp_s6 = D_800D0630;
  }
  temp_s2 = H(P(D_800C02AE, 0x32F2), 0xE);
  temp_fp = (u16 *) (P(D_800C02AE, 0x32F2) + 0x3A);
  temp_s3 = D_800C02AE + 0x10332;
  func_800980C4((u32) osGetTime());
  if (temp_s6 != 0)
  {
    var_s1 = 0;
    if (temp_s2 != 0)
    {
      do
      {
        temp_s0 = var_s1 & 0xFFFF;
        temp_a1 = P(D_800C02AE, 0x32F2) + temp_s0;
        temp_fp[temp_s0] = H(P(D_800C02AE, 0x32F2) + (B(temp_a1, 0x32) * 0x28), 0x4E);
        if (B(P(D_800C02AE, 0x32F2) + (B(temp_a1, 0x32) * 0x28), 0x44) == 0)
        {
          func_80099DF8(&sp20, &D_800A4C20, &D_800A4C28, temp_s0 + 1);
          I((B(P(D_800C02AE, 0x32F2) + temp_s0, 0x32) * 0x28) + P(D_800C02AE, 0x32F2), 0x44) = sp20;
        }
        var_s1 += 1;
      }
      while (((u32) (var_s1 & 0xFFFF)) < temp_s2);
    }
    if (H(P(D_800C02AE, 0x32F2), 0x1E) != 0)
    {
      new_var4 = 0xFFFF;
      temp_s3 = P(temp_s3, 0x78);
      var_s1 = 0;
      if (temp_s2 != 0)
      {
        var_a0 = 0 & 0xFFFF;
        do
        {
          var_s1 += 1;
          new_var2 = var_s1;
          (&sp10[0])[var_a0] = (s32) H((H(P(D_800C02AE, 0x32F2) + (B(P(D_800C02AE, 0x32F2) + var_a0, 0x32) * 0x28), 0x4E) * 0x2C4) + temp_s3, 0x14);
          var_a0 = new_var2 & 0xFFFF;
        }
        while (((u32) (var_s1 & new_var4)) < temp_s2);
      }
      var_s1 = temp_s2;
      if (var_s1 < 4U)
      {
        var_s4 = &sp10[0];
        do
        {
          temp_v1 = H(P(D_800C02AE, 0x32F2), 0xE);
          switch (temp_v1)
          {
            case 1:
              if (sp10[0] == 2)
            {
              sp10[0] = 0;
            }
              var_s2 = 0;
              temp_s0_2 = var_s1 & 0xFFFF;
              do
            {
              temp_hi = func_80098090() % temp_s6;
              new_var = var_s4;
              var_a2 = 1;
              if (H((temp_hi * 0x2C4) + temp_s3, 0x14) == (*new_var))
              {
                var_v1 = 0;
                if (temp_s0_2 != 0)
                {
                  var_a0_2 = temp_fp;
                  do
                  {
                    var_v1 += 1;
                    var_a2 &= -((*var_a0_2) != temp_hi);
                    var_a0_2 += 1;
                  }
                  while (var_v1 < temp_s0_2);
                }
                if ((var_a2 != 0) && (!(H((temp_hi * 0x2C4) + temp_s3, 0x10) & 8)))
                {
                  temp_fp[temp_s0_2] = (s16) temp_hi;
                  var_s2 = 1;
                  func_80053C28(B(P(D_800C02AE, 0x32F2) + temp_s0_2, 0x32), temp_hi & 0xFF, var_a2, temp_s0_2);
                }
              }
            }
            while (var_s2 == 0);
              var_s1 += 1;
              break;

            case 2:
              if (sp10[0] == temp_v1)
            {
              sp10[0] = 0;
            }
              if (sp10[1] == temp_v1)
            {
              sp10[1] = 0;
            }
              var_s2_2 = 0;
              temp_s0_3 = var_s1 & 0xFFFF;
              do
            {
              temp_hi_2 = func_80098090() % temp_s6;
              var_a2_2 = 1;
              if (H((temp_hi_2 * 0x2C4) + temp_s3, 0x14) == (*var_s4))
              {
                new_var3 = (s16) temp_hi_2;
                var_v1_2 = 0;
                if (temp_s0_3 != 0)
                {
                  var_a0_3 = temp_fp;
                  do
                  {
                    var_v1_2 += 1;
                    var_a2_2 &= -((*var_a0_3) != temp_hi_2);
                    var_a0_3 += 1;
                  }
                  while (var_v1_2 < temp_s0_3);
                }
                if ((var_a2_2 != 0) && (!(H((temp_hi_2 * 0x2C4) + temp_s3, 0x10) & 8)))
                {
                  var_s2_2 = 1;
                  temp_fp[temp_s0_3] = new_var3;
                  var_s4 += 1;
                  func_80053C28(B(P(D_800C02AE, 0x32F2) + temp_s0_3, 0x32), temp_hi_2 & 0xFF, var_a2_2, temp_s0_3);
                }
              }
            }
            while (var_s2_2 == 0);

            case 3:

            default:
              var_s1 += 1;
              break;

          }

        }
        while (((u32) (var_s1 & new_var4)) < 4U);
      }
      var_s1 = 0;
      var_v1_3 = 0 & new_var4;
      do
      {
        var_s1 += 1;
        H(P(D_800C02AE, 0x32F2) + (B(P(D_800C02AE, 0x32F2) + var_v1_3, 0x32) * 0x28), 0x4E) = (u16) H((var_v1_3 * 2) + P(D_800C02AE, 0x32F2), 0x3A);
        var_v1_3 = var_s1 & 0xFFFF;
      }
      while (((u32) (var_s1 & new_var4)) < 4U);
    }
  }
}


