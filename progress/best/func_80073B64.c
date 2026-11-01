#define CFG(o) (*(u16 *)(*(char **)(D_800C02AE+0x32F2)+(o)))
void *func_80006008(void *);
void func_80006014(void *, void *);
void func_80006298(void *);
void func_800068C0();
int func_80006CF8();
void func_800072F4();
void func_8000C22C();
void func_8000C244(void *, void *, s16, s16, void *, int);
int func_8000C9B0(void *, void *, int, float, int);
void func_8000CC04(void *, void *, s16, s16, void *, int, float, float, int, int);
void func_80052E94();
char *func_80057918();
void func_80073108(void *, s16, s16, void *, int);
void func_80073320();
void func_8007347C();
int func_80099DF8(void *, void *, ...);
void func_800735D0(void *, s16);
extern char D_800A1798[];
extern u8 D_800A17E8;
extern u8 D_800A17E9;
extern u8 D_800A17EA;
extern char D_800A5D50[];
extern char D_800A5D70[];
extern char D_800A5D7C[];
extern char D_800A5D84[];
extern char D_800A5D8C[];
extern char D_800A5D94[];
extern char D_800A5D9C[];
extern char D_800A5DA0[];
extern char D_800A5DB4[];
extern char D_800A5DBC[];
extern char D_800C02AE[];
extern char D_800D0634[];
extern char D_800C8200[];
extern char D_800C8210[];
extern char D_800C8220[];
extern char D_800C8230[];

void func_80073B64(void *raw0, void *arg1)
{
  void *arg0 = raw0;
  char sp40[0x78];
  char spB8[0x18];
  char spD0[0x18];
  char spE8[0x18];
  u16 slots[8];
#define sp106 (*(s16 *)&slots[3])
#define sp10E (slots[7])
  s32 sp114;
  char *sp11C;
  u16 loop_index;
  u16 start_x;
  u16 format_index;
  s32 entry_index;
  s32 tail_y;
  s32 var_a1_2;
  s32 var_a1_3;
  char *new_var2;
  s32 var_a1_4;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_a3;
  s32 temp_s0_2;
  u16 temp_s0_3;
  s16 temp_s0_4;
  u16 temp_s1_3;
  u16 temp_s1_4;
  s16 temp_s1_5;
  s32 temp_s1_6;
  s16 temp_s1_7;
  s16 temp_s1_8;
  s16 temp_s3;
  s32 temp_s4;
  u16 var_fp;
  s16 var_s0_2;
  s32 temp_a0;
  s32 temp_a0_2;
  u16 temp_a3;
  s32 temp_s0;
  s32 temp_s0_5;
  s32 temp_s1;
  s32 temp_s1_2;
  s32 temp_s2;
  s32 temp_s2_3;
  s32 temp_v1;
  s32 var_a1;
  s32 var_s0;
  s32 var_v0;
  s32 var_v0_2;
  float scale;
  u32 temp_s2_2;
  u32 temp_v0_2;
  void *temp_v0;
  void *var_s2;
  new_var2 = D_800C02AE + 0x32F2;
  do
  {
    temp_v0 = func_80006008(arg1);
    *((u32 *) temp_v0) = 0xDE000000;
    *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
    func_80006014(arg1, temp_v0 + 8);
    temp_s0 = func_80006CF8(arg1, 0);
    if ((CFG(0xE) == 2) && (CFG(0x12) == 1))
    {
      func_800068C0(arg1, temp_s0 & 0xffff, 32, 0, 0, 288, 0, 0, 288, 240, 0, 32, 240, 0);
    }
    else
    {
      func_800068C0(arg1, temp_s0 & 0xffff, 0, 0, 0, 320, 0, 0, 320, 240, 0, 0, 240, 0);
    }
    func_800072F4(arg1, temp_s0 & 0xFFFF, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  }
  while (0);
  func_80006298(arg1);
  func_80099DF8(&sp40, &D_800A5D50);
  sp10E = 0;
  temp_s1 = (D_800A17EA + D_800A17E9) + func_8000C9B0(arg0 + 0x40, &sp40, 1, 1.0f, 1);
  sp11C = sp40;
  temp_v0_2 = ((u32) (temp_s1 & 0xFFFF)) >> 1;
  temp_v0_2 += 0xA0;
  temp_s0_2 = 0x140 - temp_v0_2;
  func_800735D0(arg0, temp_s0_2);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x80, 0xFF);
  func_8007347C(arg1, (temp_s0_2 - 7) & 0xFFFF, 0x46, (unsigned short) (temp_s1 + 0xD), 0x11);
  var_fp = 0x5A;
  sp106 = temp_s0_2;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, (s16) (temp_s0_2 + 2), 0x48, func_80057918((*((s32 *)(D_800C8200 + 0x128))), 0xCF), 1);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
  sp114 = (u32)(-((s32) (temp_v0_2))) << 16;
  do
  {
    entry_index = sp10E;
    if (entry_index == 4)
    {
      var_v0 = entry_index * 2;
      if ((*((u16 *) ((*((char **) new_var2)) + 0x1E))) != 5)
      {
        temp_s1_2 = func_8000C9B0(arg0 + 0x40, func_80057918((*((s32 *)(D_800C8210 + 0x118))), 0xD1), 1, 1.0f, 1);
        temp_s2 = temp_s1_2;
        func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x80, 0xFF);
        temp_s2_2 = ((u32) (temp_s2 & 0xFFFF)) >> 1;
        temp_s0_3 = var_fp + 0x1B;
        func_8007347C(arg1, (0x97 - temp_s2_2) & 0xFFFF, (temp_s0_3 - 2) & 0xFFFF, (temp_s1_2 + 0xF) & 0xFFFF, 0x11);
        var_fp = temp_s0_3 + 0x12;
        func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, 0xA0 - temp_s2_2, temp_s0_3, func_80057918((*((s32 *)(D_800C8220 + 0x108))), 0xD1), 1);
        func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 255, 255, 255, 255);
        entry_index = sp10E;
        var_v0 = entry_index * 2;
      }
    }
    else
    {
      if (((*((u32 *) ((D_800C02AE + 0x7CE6) + (entry_index * 0x18)))) == (*((s32 *) (D_800C02AE + 0x7D46)))) && ((*((u16 *) ((*((char **) new_var2)) + 0x1E))) != 5))
      {
        func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 220, 220, 16, 255);
      }
      entry_index = sp10E;
      var_v0 = entry_index * 2;
    }
    start_x = sp106;
    temp_a0 = *((u32 *) ((D_800C02AE + 0x7CE6) + ((var_v0 + entry_index) * 8)));
    if (temp_a0 != 0)
    {
      func_80052E94(temp_a0, &spB8);
    }
    else
    {
      func_80099DF8(&spB8, &D_800A5D70);
    }
    temp_a0_2 = *((u32 *) ((D_800C02AE + 0x7CEA) + (sp10E * 0x18)));
    if (temp_a0_2 != 0)
    {
      func_80052E94(temp_a0_2, &spD0);
    }
    else
    {
      func_80099DF8(&spD0, &D_800A5D70);
    }
    temp_v1 = *((u32 *) ((D_800C02AE + 0x7CEE) + (sp10E * 0x18)));
    if (temp_v1 != 0)
    {
      if ((*((u16 *) ((*((char **) (D_800C02AE + 0x32F2))) + 0x50))) != 0)
      {
        func_80099DF8(&spE8, &D_800A5D7C, ((u32) (temp_v1 * 0x9F00)) >> 0x10);
      }
      else
      {
        func_80099DF8(&spE8, &D_800A5D84, temp_v1 & 0xFFFF);
      }
    }
    else
    {
      func_80099DF8(&spE8, &D_800A5D8C);
    }
    format_index = sp10E;
    if (format_index != 4)
    {
      func_80099DF8(&sp40, &D_800A5D94, format_index + 1, ((4 * format_index) * 6) + (D_800C02AE + 0x7CE2));
    }
    else
    {
      func_80099DF8(&sp40, &D_800A5D9C, (u32) (D_800C02AE + 0x7D42));
    }
    loop_index = sp10E;
    if (loop_index != 4)
    {
      func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, (s16) start_x, var_fp, sp11C, 1);
    }
    temp_s1_3 = start_x + D_800A17E9;
    temp_s3 = var_fp - 1;
    if ((((u32) (temp_s1_3 & 0xFFFF)) < 0x141U) & ((temp_s2 = loop_index) != 4))
    {
      func_80073108(arg1, temp_s1_3, temp_s3, *((s32 *) (D_800C02AE + 0x103B2)), (s32) (*((u8 *) ((D_800C02AE + 0x7CF4) + (temp_s2 * 0x18)))));
    }
    temp_s0_4 = temp_s3 + 1;
    temp_s1_4 = temp_s1_3 + D_800A17EA;
    if (loop_index != 0)
    {
      if (loop_index == 4)
      {
        if ((*((u16 *) ((*((char **) new_var2)) + 0x1E))) != 5)
        {
          temp_s2_3 = ((s32) (0x140 - (((D_800A17EA + (D_800A17E9 + 0xFFF1)) + func_8000C9B0(arg0 + 0x40, &D_800A5DA0, 1, 1.0f, 1)) & 0xFFFF))) / 2;
          temp_s4 = temp_s2_3 & 0xFFFF;
          func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s4, temp_s0_4, sp11C, 1);
          if (((u32) (temp_s1_4 & 0xFFFF)) < 0x141U)
          {
            func_80073108(arg1, (s16) (temp_s2_3 + (D_800A17E9 + 0xFFF1)), temp_s3, *((s32 *) (D_800C02AE + 0x103B2)), (s32) (*((u8 *) (D_800C02AE + 0x7D54))));
          }
          func_80099DF8(sp11C, &D_800A5DB4, (u32) (&spB8), &spE8);
          func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, ((temp_s4 - 0xF) + D_800A17E9) + D_800A17EA, temp_s0_4, sp11C, 1);
        }
      }
      else
      {
        func_80099DF8(&sp40, &D_800A5DBC, (u32) (&spB8), &spD0);
        var_s0 = temp_s0_4 << 0x10;
        goto block_41;
      }
    }
    else
    {
      var_s0 = temp_s0_4 << 0x10;
      block_41:
      temp_s0_5 = var_s0 >> 0x10;

      func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s1_4, (s16) temp_s0_5, sp11C, 1);
      func_8000CC04(arg0 + 0x40, arg1, sp114 >> 0x10, temp_s0_5, &spE8, 1, 1.0f, 1.0f, 0, 1);
    }
    sp10E += 1;
    func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
    var_fp = temp_s0_4 + 0xF;
  }
  while (sp10E < 5U);

  if (CFG(0x22) == ((*((u16 *) (((CFG(0x20) * 0x2c4) + (*((char **) (D_800D0634 + (CFG(0x1e) * 4))))) + 0x14))) - 1))
  {
    scale = 1.0f;
    var_s2 = arg0 + 0x40;
    var_v0_2 = func_8000C9B0(var_s2, func_80057918((*((s32 *)(D_800C8230 + 0xF8))), 0xD3), 1, scale, 1);
    var_a1_3 = 0xDF;
  }
  else
  {
    scale = 1.0f;
    var_s2 = arg0 + 0x40;
    var_v0_2 = func_8000C9B0(var_s2, func_80057918((*((s32 *)(D_800C8200 + 0x128))), 0xD3), 1, scale, 1);
    var_a1_3 = 0xD4;
  }
  temp_a3 = (((D_800A17E8 + var_v0_2) + (D_800A17E8 + 5)) + func_8000C9B0(var_s2, func_80057918((*((s32 *)(D_800C8210 + 0x118))), var_a1_3), 1, scale, 1)) + 0x10;
  temp_s1_5 = 0x140 - temp_a3;
  var_s0_2 = temp_s1_5;
  var_fp = 0xDC;
  if ((*((u16 *) ((*((char **) new_var2)) + 0xE))) == 2)
  {
    func_80073320(arg1, var_s0_2 & 0xFFFF, var_fp, (temp_a3 - 0x23) & 0xFFFF, 0x11);
    var_s0_2 = temp_s1_5 - 0xF;
  }
  else
  {
    func_80073320(arg1, var_s0_2 & 0xFFFF, var_fp, temp_a3 & 0xFFFF, 0x11);
  }
  func_80073108(arg1, var_s0_2, var_fp, *((s32 *) (D_800C02AE + 0x103B6)), 2);
  temp_s1_6 = var_s0_2 + D_800A17E8;
  tail_y = var_fp + 2;
  temp_s0_4 = tail_y;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s1_6, temp_s0_4, func_80057918((*((s32 *)(D_800C8220 + 0x108))), 0xD3), 1);
  temp_s1_7 = temp_s1_6 + func_8000C9B0(arg0 + 0x40, func_80057918((*((s32 *)(D_800C8230 + 0xF8))), 0xD3), 1, 1.0f, 1);
  func_80073108(arg1, temp_s1_7, (s16)(tail_y - 2), *((s32 *) (D_800C02AE + 0x103B6)), 0);
  temp_s1_8 = temp_s1_7 + D_800A17E8;
  if (CFG(0x22) == ((*((u16 *) (((CFG(0x20) * 0x2c4) + (*((char **) (D_800D0634 + (CFG(0x1e) * 4))))) + 0x14))) - 1))
  {
    var_a1_4 = 0xDF;
 do { func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s1_8, temp_s0_4, func_80057918((*((s32 *)(D_800C8200 + 0x128))), var_a1_4), 1); } while (0);
  }
  else
  {
    var_a1_4 = 0xD4;
    func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, temp_s1_8, temp_s0_4, func_80057918((*((s32 *)(D_800C8210 + 0x118))), var_a1_4), 1);
  }
}
