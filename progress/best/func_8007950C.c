typedef struct { char name[4]; u32 first, second, third; u8 flag, pad17, icon, pad19[5]; } ScoreRow;
extern ScoreRow D_800C7F90[5];
extern s32 D_800C8328;
void *func_80006008();
void func_80006014();
void func_80006298();
void func_800068C0();
int func_80006CF8();
void func_800072F4();
void func_8000C22C();
void func_8000C244(s32,s32,s32,s16,void*,s32);
int func_8000C9B0(void *, void *, int, float, int);
void func_8000CC04(void *, s32, s32, int, void *, int, float, float, int, int);
void func_80052E94();
char *func_80057918();
void func_80073108(s32,s16,s16,s32,u8);
void func_8007347C();
int func_80099DF8(void *, void *, ...);
extern char D_800A1798[];
extern u8 D_800A17E9;
extern u8 D_800A17EA;
extern char D_800A5EB8[];
extern char D_800A5ED8[];
extern char D_800A5EE0[];
extern char D_800A5EEC[];
extern char D_800A5EF4[];
extern char D_800A5EFC[];
extern char D_800A5F04[];
extern char D_800A5F0C[];
extern char D_800A5F14[];
extern char D_800A5F18[];
extern char D_800A5F2C[];
extern char D_800A5F44[];
extern char D_800A5F54[];
extern char D_800C02AE[];
void func_8007950C(s32 arg0)
{
  char sp40[0x78];
  char spB8[0x18];
  char spD0[0x18];
  char spE8[0x18];
  struct { char text[0x18];    } tail;
  s32 *var_a1_3;
  s32 *var_a1_4;
  s32 *var_a2_2;
  s32 *var_a3_2;
  u16 left_local;
  s32 var_a1_2;
  s32 var_a2;
  s32 right_local;
  s32 var_a3;
  s32 temp_s0_4;
  s32 temp_s0_5;
  s32 temp_s1;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 temp_s4;
  u16 var_s7;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_s0;
  u32 *new_var;
  s32 temp_s0_2;
  int new_var2;
  s32 temp_s1_2;
  s32 temp_s1_3;
  s32 temp_s2;
  u16 temp_s3;
  s32 temp_v1_2;
  u16 var_fp;
  s32 var_s4;
  u32 temp_s0_3;
  u32 temp_v0_2;
  void *temp_s1_4;
  void *temp_v0;
  temp_v0 = func_80006008(arg0);
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
  func_80006014(arg0, temp_v0 + 8);
  temp_s0 = func_80006CF8(arg0, 0) & 0xFFFF;
  func_800068C0(arg0, temp_s0, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
  func_800072F4(arg0, temp_s0, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  func_80006298(arg0);
  {
  char *nm;
  if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 2)
    nm = func_80057918(D_800C8328, 0x1CD);
  else if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 3)
    nm = func_80057918(D_800C8328, 0x1CE);
  else if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 4)
    nm = func_80057918(D_800C8328, 0x1CF);
  else
    nm = func_80057918(D_800C8328, 0x1D0);
  var_s7 = 0x5A;
  func_80099DF8(&tail.text, &D_800A5F14, nm);
  }
  func_8000C22C(*((s32 *) (D_800C02AE + 0x7F5E)), 0xFF, 0xFF, 0xFF, 0xFF);
  func_80099DF8(&sp40, &D_800A5EB8);
  temp_s0_2 = (D_800A17EA + D_800A17E9) + func_8000C9B0(D_800C02AE + 0x7F5E, &sp40, 1, 1.0f, 1);
  temp_v0_2 = ((u32) (temp_s0_2 & 0xFFFF)) >> 1;
  temp_s2 = temp_v0_2 + 0xA0;
  temp_s1 = 0xA0 - temp_v0_2;
  func_8000C22C(*((s32 *) (D_800C02AE + 0x7F5E)), 0xDC, 0xDC, 0x80, 0xFF);
  func_8007347C(arg0, (temp_s1 - 7) & 0xFFFF, 0x46, (temp_s0_2 + 0xD) & 0xFFFF, 0x11);
  var_fp = 0;
  left_local = temp_s1;
  func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16)temp_s1, 0x48, func_80057918(D_800C8328, 0xCF), 1);
  func_8000C22C(*((s32 *) (D_800C02AE + 0x7F5E)), 0xFF, 0xFF, 0xFF, 0xFF);
  right_local = (u32)(-temp_s2) << 16;
  do
  {
    var_s4 = (u16) left_local;

    if ((var_fp & 0xFFFF) == 4)
    {
      var_s4 = 0x25;
      temp_s2_2 = var_s7 + 0x19;
      var_s7 = temp_s2_2 + 0x12;
      func_80099DF8(&sp40, &D_800A5F44, &tail.text, func_80057918(D_800C8328, 0xD2));
      temp_s1_2 = func_8000C9B0(D_800C02AE + 0x7F5E, &sp40, 1, 1.0f, 1);
      temp_s3 = temp_s1_2;
      func_8000C22C(*((s32 *) (D_800C02AE + 0x7F5E)), 0xDC, 0xDC, 0x80, 0xFF);
      temp_s0_3 = ((u32) (temp_s3 & 0xFFFF)) >> 1;
      new_var2 = 0x7F5E;
      func_8007347C(arg0, (0x97 - temp_s0_3) & 0xFFFF, (temp_s2_2 + (-2)) & 0xFFFF, (temp_s1_2 + 0xF) & 0xFFFF, 0x11);
      func_8000C244(*((s32 *) (D_800C02AE + new_var2)), arg0, 0xA0 - temp_s0_3, temp_s2_2, sp40, 1);
      func_8000C22C(*((s32 *) (D_800C02AE + 0x7F5E)), 0xFF, 0xFF, 0xFF, 0xFF);

      goto row_color_done;
    }
    new_var = &D_800C7F90[(var_fp & 0xFFFF)].first;

    if ((*new_var) == D_800C7F90[4].first)
    {
      func_8000C22C(*((s32 *) (D_800C02AE + 0x7F5E)), 0xDC, 0xDC, 0x10, 0xFF);

    }
row_color_done:
    temp_a0 = D_800C7F90[(var_fp & 0xFFFF)].first;
    if (temp_a0 != 0)
    {
      func_80052E94(temp_a0, &spB8);

    }
    else
    {
      func_80099DF8(&spB8, &D_800A5EE0);

    }
    temp_a0_2 = D_800C7F90[(var_fp & 0xFFFF)].second;
    if (D_800C7F90[(var_fp & 0xFFFF)].second != 0)
    {
      func_80052E94(temp_a0_2, &spD0);

    }
    else
    {
      func_80099DF8(&spD0, &D_800A5EE0);

    }
    temp_v1_2 = D_800C7F90[(var_fp & 0xFFFF)].third;
    if (temp_v1_2 != 0)
    {
      if ((*((u16 *) (D_800C02AE + 0x7FB6))) != 0)
      {
        func_80099DF8(&spE8, &D_800A5EEC, (s32 *) (((u32) (temp_v1_2 * 0x9F00)) >> 0x10));

      }
      else
      {
        func_80099DF8(&spE8, &D_800A5EF4, (s32 *) (temp_v1_2 & 0xFFFF));

      }
    }
    else
    {
      if ((*((u16 *) (D_800C02AE + 0x7FB6))) != 0)
      {
        var_a1_3 = &D_800A5EFC;
        func_80099DF8(&spE8, var_a1_3); }
      else
      {
        var_a1_3 = &D_800A5F04;
        func_80099DF8(&spE8, var_a1_3);
      }

    }
    if ((var_fp & 0xFFFF) != 4)
    {
      func_80099DF8(&sp40, &D_800A5F0C, (var_fp & 0xFFFF) + 1, D_800C7F90[(var_fp & 0xFFFF)].name);

    }
    else
    {
      func_80099DF8(&sp40, &D_800A5F14, D_800C7F90[4].name);

    }
    if ((var_fp & 0xFFFF) != 4)
    {
      func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16) var_s4, var_s7, sp40, 1);
    }
    temp_s0_4 = var_s4 + D_800A17E9;
    temp_s4 = var_s7 - 1;
    if ((((u32) (temp_s0_4 & 0xFFFF)) < 0x141U) & ((var_fp & 0xFFFF) != 4))
    {
      func_80073108(arg0, temp_s0_4, temp_s4, *((s32 *) (D_800C02AE - (-0x103B2))), (s32) D_800C7F90[(var_fp & 0xFFFF)].icon);
    }
    temp_s2_3 = temp_s4 + 1;
    var_s7 = temp_s2_3;
    temp_s0_5 = temp_s0_4 + D_800A17EA;
    if ((var_fp & 0xFFFF) == 0) goto zero_row;
    if ((var_fp & 0xFFFF) != 4) goto normal_row;
    {
        temp_s3 = ((D_800A17E9 + 0xFFF1) + D_800A17EA) + func_8000C9B0(D_800C02AE + 0x7F5E, &D_800A5F18, 1, 1.0f, 1);
        temp_s1_3 = (s32)(0x140 - (temp_s3 & 0xFFFF)) / 2;
        temp_s3 = temp_s1_3;
        temp_s3 = temp_s3 & 0xFFFF;
        func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, temp_s3, temp_s2_3, sp40, 1);
        if (((u32) (temp_s0_5 & 0xFFFF)) < 0x141U)
        {
          func_80073108(arg0, (s16) (temp_s1_3 + (D_800A17E9 + 0xFFF1)), temp_s4, *((s32 *) (D_800C02AE + 0x103B2)), (s32) D_800C7F90[4].icon);
        }
        func_80099DF8(sp40, &D_800A5ED8, &spB8, &spE8);
        func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, ((temp_s3 - 0xF) + D_800A17E9) + D_800A17EA, temp_s2_3, sp40, 1);
        var_s7 += 0xF;
      goto row_done;
    }
zero_row:
    func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16)temp_s0_5, temp_s2_3, spB8, 1);
    goto detail_row;
normal_row:
    func_80099DF8(&sp40, &D_800A5F2C, &spB8, &spD0);
    func_8000C244(*((s32 *) (D_800C02AE + 0x7F5E)), arg0, (s16)temp_s0_5, temp_s2_3, sp40, 1);
detail_row:
    func_8000CC04(D_800C02AE + 0x7F5E, arg0, right_local >> 0x10, temp_s2_3, &spE8, 1, 1.0f, 1.0f, 0, 1);
    var_s7 += 0xF;
row_done:
    var_fp += 1;
    func_8000C22C(*((s32 *) (D_800C02AE + 0x7F5E)), 0xFF, 0xFF, 0xFF, 0xFF);
  }
  while (((u32) (var_fp & 0xFFFF)) < 5U);
  temp_s1_4 = D_800C02AE + 0x7F62;
  func_8000C22C(*((s32 *) (D_800C02AE + 0x7F62)), 0xDC, 0xDC, 0x10, 0xFF);
  if (D_800C7F90[0].flag < 4U)
  {
    func_80099DF8(&sp40, &D_800A5ED8, func_80057918(D_800C8328, 0xD8), D_800C7F90[0].name);
    func_8000C244(*((s32 *) (D_800C02AE + 0x7F62)), arg0, 0xA0 - (((u32) (func_8000C9B0(temp_s1_4, &sp40, 1, 1.0f, 0) & 0xFFFF)) >> 1), 0x14, &sp40, 0);
  }
  var_s7 = 0x28;
  if ((*((s32 *) (D_800C02AE + 0x32AA))) == 2)
  {
    if ((*((u8 *) (D_800C02AE + 0x7F4F))) == 8)
      func_80099DF8(&sp40, &D_800A5ED8, func_80057918(D_800C8328, 0xD9), &tail.text);
    else
      func_80099DF8(&sp40, &D_800A5F54, func_80057918(D_800C8328, 0xD9), &tail.text);
  }
  else
    func_80099DF8(&sp40, &D_800A5F44, &tail.text, func_80057918(D_800C8328, 0xD9));
  temp_s3 = func_8000C9B0(temp_s1_4, &sp40, 1, 1.0f, 0);
  func_8000C244(*((s32 *) (D_800C02AE + 0x7F62)), arg0, 0xA0 - (((u32) (temp_s3 & 0xFFFF)) >> 1), var_s7, &sp40, 0);
  func_8000C22C(*((s32 *) (D_800C02AE + 0x7F62)), 0xFF, 0xFF, 0xFF, 0xFF);
}
