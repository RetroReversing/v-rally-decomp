typedef struct { u32 id, second, duration, a,b,c; } MenuRow;
extern MenuRow D_800C7F94[];
void *func_80006008(void *);
void func_80006014(void *, void *);
void func_80006298(void *);
void func_800068C0();
int func_80006B4C();
void func_800072F4();
void func_8000C22C();
void func_8000C244();
int func_8000C9B0(void *, void *, int, float, int);
void func_8000CC04(void *, void *, s16, s16, void *, int, float, float, int, int);
void func_80052E94();
char *func_80057918();
void func_80073108();
void func_80073320();
void func_8007347C();
int func_80099DF8(void *, void *, ...);
extern char D_800A1798[];
extern u8 D_800A17E8;
extern u8 D_800A17EA;
extern char D_800A5D70[];
extern char D_800A5D7C[];
extern char D_800A5D84[];
extern char D_800A5D8C[];
extern char D_800A5D9C[];
extern char D_800A5DC8[];
extern char D_800A5DE8[];
extern char D_800A5DF0[];
extern char D_800A5DF4[];
extern char D_800A5DFC[];
extern char D_800A5E0C[];
extern char D_800A5E10[];
extern char D_800A73E0[];
extern char D_800C02AE[];
void func_800754D4(void *arg0, void *arg1)
{
  char sp40[0x78];
  char spB8[0x18];
  char spD0[0x18];
  char spE8[24];
  u16 sp106;
  void *sp114;
  s32 *temp_s5_2;
  s32 var_a2;
  u16 temp_s0_5;
  u16 temp_s1_6;
  s16 temp_s1_7;
  s16 temp_s1_8;
  s16 temp_s1_9;
  s32 temp_a0;
  s32 temp_s0;
  s32 temp_s0_11;
  s32 temp_s0_12;
  s32 temp_s0_13;
  s32 temp_s0_2;
  
  s32 temp_s0_6;
  s32 temp_s0_7;
  s32 temp_s1;
  s32 temp_s1_2;
  s32 temp_s1_3;
  u16 temp_s1_4;
  s32 temp_s3;
  s32 temp_s3_2;
  s32 temp_s5;
  s32 temp_v0_3;
  s32 var_a1;
  u16 var_s0;
  s32 var_s7;
  s32 var_v0;
  s32 var_v0_3;
  s32 var_v0_4;
  int new_var;
  s32 var_v1;
  u32 temp_a2;
  u32 temp_a2_2;
  u32 temp_s0_10;
  u32 temp_s0_4;
  u32 temp_s0_8;
  u32 temp_s1_5;
  u32 temp_v1;
  u32 temp_v1_2;
  u32 var_a2_2;
  u32 var_v0_2;
  void *temp_s3_3;
  void *temp_v0;
  void *temp_v0_2;
  temp_v0 = func_80006008(arg1);
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
  func_80006014(arg1, temp_v0 + 8);
  temp_s0 = func_80006B4C(arg1, 0);
  if ((*((u16 *) ((*((char **) (D_800C02AE + 0x32F2))) + 0x12))) == 1)
  {
    func_800068C0(arg1, temp_s0 & 65535, 32, 0, 0, 288, 0, 0, 288, 240, 0, 32, 240, 0);
  }
  else
  {
    func_800068C0(arg1, temp_s0 & 65535, 0, 0, 0, 320, 0, 0, 320, 240, 0, 0, 240, 0);
  }
  func_800072F4(arg1, temp_s0 & 0xFFFF, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  func_80006298(arg1);
  func_80099DF8(&sp40, &D_800A5DC8);
  temp_v0_2 = arg0 + 0x40;
  sp106 = 0x28;
  var_s7 = 0;
  sp114 = temp_v0_2;
  temp_s3 = func_8000C9B0(temp_v0_2, &sp40, 1, 1.0f, 1);
  temp_s1 = 0xA0 - (((u32) (temp_s3 & 0xFFFF)) >> 1);
  temp_s0_2 = func_8000C9B0(sp114, D_800C02AE + 0x7CE2, 1, 1.0f, 1);
  temp_s0 = (D_800A17EA + temp_s0_2) + func_8000C9B0(sp114, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD0), 1, 1.0f, 1);
  temp_s1_2 = (temp_s1 - 7) & 0xFFFF;
  temp_s3_2 = (unsigned short) (temp_s3 + 0xD);
  func_8007347C(arg1, temp_s1_2, 0x17, temp_s3_2, 0x11);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x80, 0xFF);
  temp_s0_4 = ((u32) (temp_s0 & 0xFFFF)) >> 1;
  temp_s5 = temp_s0_4 & 0xFFFF;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, 0xA0 - temp_s5, 0x19, D_800C02AE + 0x7CE2, 1);
  func_80073108(arg1, (s16) (func_8000C9B0(sp114, D_800C02AE + 0x7CE2, 1, 1.0f, 1) - (temp_s0_4 - 0xA0)), 0x18, *((s32 *) (D_800C02AE + 0x103B2)), (s32) (*((u8 *) (D_800C02AE + 0x7CF4))));
  temp_s0_5 = ((func_8000C9B0(sp114, D_800C02AE + 0x7CE2, 1, 1.0f, 1) + 0xA0) - temp_s5) + D_800A17EA;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s0_5, 0x19, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD0), 1);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
  temp_s5_2 = (D_800C02AE + 0x7CE2) + 0x60;
  temp_s0_6 = func_8000C9B0(sp114, temp_s5_2, 1, 1.0f, 1);
  temp_s0_7 = (D_800A17EA + temp_s0_6) + func_8000C9B0(sp114, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD0), 1, 1.0f, 1);
  func_8007347C(arg1, temp_s1_2, 0x8F, temp_s3_2, 0x11);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x80, 0xFF);
  temp_s0_8 = ((u32) (temp_s0_7 & 0xFFFF)) >> 1;
  temp_s1_3 = temp_s0_8 & 0xFFFF;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, 0xA0 - temp_s1_3, 0x91, temp_s5_2, 1);
  func_80073108(arg1, (s16) (func_8000C9B0(sp114, D_800C02AE + 0x7CE2, 1, 1.0f, 1) - (temp_s0_8 - 0xA0)), 0x90, *((s32 *) (D_800C02AE + 0x103B2)), (s32) (*((u8 *) (D_800C02AE + 0x7D54))));
  temp_s0_5 = ((func_8000C9B0(sp114, D_800C02AE + 0x7CE2, 1, 1.0f, 1) + 0xA0) - temp_s1_3) + D_800A17EA;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s0_5, 0x91, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD0), 1);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
  do
  {
    temp_s1_4 = var_s7 & 0xFFFF;

    if (temp_s1_4 == 6)
    {
      temp_v0_3 = func_8000C9B0(arg0 + 0x40, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD1), 1, 1.0f, 1);
      temp_s0_10 = ((u32) (temp_v0_3 & 0xFFFF)) >> 1;
      func_8007347C(arg1, (0x97 - temp_s0_10) & 0xFFFF, 0x67, (temp_v0_3 + 0xF) & 0xFFFF, 0x11);
      func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x80, 0xFF);
      sp106 = 0x78;
      func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, 0xA0 - temp_s0_10, 0x69, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD1), 1);
      func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
  
    }
    temp_s0_11 = temp_s1_4 * 24;

    if (((D_800C7F94[temp_s1_4].id) == (*((s32 *) (D_800C02AE + 0x7D76)))) & (temp_s1_4 != 6))
    {
      func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x10, 0xFF);
    }
    func_80052E94(D_800C7F94[temp_s1_4].id, &spB8);
    func_80052E94(D_800C7F94[temp_s1_4].second, &spD0);
    if ((*((u16 *) ((*((char **) (D_800C02AE + 0x32F2))) + 0x50))) != 0)
    {
      temp_v1 = D_800C7F94[temp_s1_4].duration;
      if (temp_v1 >= 0x12DU)
      {
        func_80099DF8(&spE8, &D_800A5DE8);
        var_v1 = var_s7 & 0xFFFF;
      }
      else
      {
        var_a2 = 0x10;
        func_80099DF8(&spE8, &D_800A5D7C, ((u32) (temp_v1 * 0x9F00)) >> var_a2);
        var_v1 = var_s7 & 0xFFFF;
      }
      var_v0_2 = ((u32) ((D_800C7F94[var_v1].duration) * 0x27C)) >> 0xA;
    }
    else
    {
      temp_a2 = D_800C7F94[temp_s1_4].duration;
      if (temp_a2 >= 0x12DU)
      {
        func_80099DF8(&spE8, &D_800A5DF4);
        var_v0_3 = var_s7 & 0xFFFF;
      }
      else
      {
        func_80099DF8(&spE8, &D_800A5D84, temp_a2 & 0xFFFF);
        var_v0_3 = var_s7 & 0xFFFF;
      }
      var_v0_2 = D_800C7F94[var_v0_3].duration;
    }
    temp_v0_2 = (void *)&spE8;
    if (var_v0_2 < 0x64U)
    {
      func_80099DF8(&sp40, &D_800A5DF0, (u32) (temp_v0_2));
 do { } while (0);
      func_80099DF8(temp_v0_2, &D_800A5D9C, (u32) (&sp40));
    }
    temp_v1_2 = var_s7 & 0xFFFF;
    temp_a0 = temp_v1_2 < 3U;
    if (temp_v1_2 != 6)
    {
      if (temp_a0 != 0)
      {
        if (((s32) temp_v1_2) >= ((*((u8 *) (D_800A73E0 + 0x6C00))) - 1))
        {
          if (temp_a0 == 0)
          {
            goto block_23;
          }
          goto block_27;
        }
        goto block_24;
      }
      block_23:
      if (((s32) (temp_v1_2 - 3)) < ((*((u8 *) (D_800A73E0 + 0x6C00))) - 1))
      {
        block_24:
        temp_a2_2 = var_s7 & 0xFFFF;

        if (temp_a2_2 < 3U)
        {
          func_80099DF8(&sp40, &D_800A5DFC, temp_a2_2 + 1, &spB8, &spD0, temp_v0_2);
        }
        else
        {
          if (arg1 || sp114)
          {
            func_80099DF8(&sp40, &D_800A5DFC, temp_a2_2 - 2, &spB8, &spD0, temp_v0_2);
          }
          else
          {
            func_80099DF8(&sp40, &D_800A5DFC, temp_a2_2 - 2, &spB8, &spD0, temp_v0_2);
          }
        }
        var_s0 = var_s7 & 0xFFFF;
        goto formatted;
      }

      block_27:
      if ((*((u8 *) (D_800A73E0 + 0x6C00))) == 0)
      {
        temp_s1_5 = var_s7 & 0xFFFF;

        if ((D_800C7F94[temp_s1_5].id) == 0)
        {
          func_80099DF8(&spB8, &D_800A5D70);
          func_80099DF8(&spD0, &D_800A5D70);
          func_80099DF8(temp_v0_2, &D_800A5D8C);
  
        }
        if (temp_s1_5 < 3U)
        {
          func_80099DF8(&sp40, &D_800A5DFC, temp_s1_5 + 1, &spB8, &spD0, temp_v0_2);
        }
        else
        {
          func_80099DF8(&sp40, &D_800A5DFC, temp_s1_5 - 2, &spB8, &spD0, temp_v0_2);
        }


        var_s0 = var_s7 & 0xFFFF;
      }
      else
      {
        func_80099DF8(&sp40, &D_800A5E0C);
        goto block_36;
      }

    }
    else
    {
      func_80099DF8(&sp40, &D_800A5E10, (u32) (D_800C02AE + 0x7D72), &spB8, temp_v0_2);
      block_36:
      var_s0 = var_s7 & 0xFFFF;

      func_80099DF8(temp_v0_2, &D_800A5E0C);
    }
    formatted:
    if ((D_800C7F94[var_s0].id) != 0)
    {
      func_8000CC04(sp114, arg1, (s16) (0xA0 - (((u32) (func_8000C9B0(sp114, &sp40, 1, 1.0f, 1) & 0xFFFF)) >> 1)), (s16) sp106, &sp40, 1, 1.0f, 1.0f, 0, 1);
    }
    sp106 += 0xF;
    func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
    if (var_s0 == 2)
    {
      sp106 = 0xA0;
    }
  }
  while (((u32) (++var_s7 & 0xFFFF)) < 7U);
  temp_s3_3 = arg0 + 0x40;
  temp_s0_12 = func_8000C9B0(temp_s3_3, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD3), 1, 1.0f, 1);
  temp_s0_13 = ((D_800A17E8 + temp_s0_12) + (D_800A17E8 + 5)) + func_8000C9B0(temp_s3_3, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD7), 1, 1.0f, 1);
  temp_s1_6 = 0x11D - temp_s0_13;
  func_80073320(arg1, temp_s1_6 & 0xFFFF, 0xDC, temp_s0_13 & 0xFFFF, 0x11);
  func_80073108(arg1, temp_s1_6, 0xDC, *((s32 *) (D_800C02AE + 0x103B6)), 2);
  temp_s1_7 = temp_s1_6 + D_800A17E8;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s1_7, 0xDE, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD3), 1);
  temp_s1_8 = temp_s1_7 + func_8000C9B0(temp_s3_3, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD3), 1, 1.0f, 1);
  func_80073108(arg1, temp_s1_8, 0xDC, *((s32 *) (D_800C02AE + 0x103B6)), 0);
  temp_s1_9 = temp_s1_8 + D_800A17E8;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s1_9, 0xDE, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), 0xD7), 1);
}
