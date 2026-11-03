extern u32 D_800C7F9C[];
extern char D_800C7F90[];
extern s32 D_800C8328;
extern s32 D_800D0660;
extern s32 D_800D0664;
void *func_80006008();
void func_80006014();
void func_80006298();
volatile unsigned long long func_800068C0();
int func_80006B4C();
void func_800072F4();
void func_8000C22C();
void func_8000C244();
int func_8000C9B0(void *, void *, int, float, int);
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
static inline static char *inline_fn(int arg0, s32 arg1)
{
  return (D_800C02AE + arg0) + (arg1 * 0x18);
}

static inline static static int inline_fn2(s16 arg0, u8 arg1)
{
  return arg0 + arg1;
}

void func_80074BF8(void *arg0, void *arg1)
{
  s32 * dp74;
char sp40[0x78];
  char spB8[0x18];
  char spD0[0x18];
  char spE8[0x18];
  char *text;
  u16 sp106;
  s32 *temp_s3;
  s32 sp10C;
  u16 temp_s0_5;
  s16 temp_s1_4;
  s16 temp_s1_5;
  s16 temp_s1_6;
  s32 temp_s0;
  s32 temp_s0_10;
  char (*new_var3)[];
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s0_7;
  s32 temp_s0_8;
  s32 temp_s0_9;
  s32 temp_s1;
  s32 temp_s1_2;
  u16 temp_s1_3;
  s32 temp_v0_2;
  s32 var_s6;
  s32 var_v0;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v1;
  u32 temp_a2;
  int new_var;
  u32 temp_s0_4;
  int new_var2;
  u32 temp_s0_6;
  u32 temp_v1;
  u32 var_v0_2;
  void *temp_s3_2;
  void *temp_s4;
  void *temp_v0;
  dp74=(s32 *)&D_800D0660;
temp_v0 = func_80006008(arg1);
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
  func_80006014(arg1, temp_v0 + 8);
  temp_s0 = func_80006B4C(arg1, 0) & 0xFFFF;
  func_800068C0(arg1, temp_s0, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
  func_800072F4(arg1, temp_s0, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  func_80006298(arg1);
  func_80099DF8(&sp40, &D_800A5DC8);
  temp_s4 = arg0 + 0x40;
  temp_s3 = D_800C7F90;
  temp_s1 = func_8000C9B0(temp_s4, &sp40, 1, 1.0f, 1);
  sp106 = 0x4B;
  text = spE8;
  temp_s0_2 = 0xA0 - (((u32) (temp_s1 & 0xFFFF)) >> 1);
  var_s6 = 0;
  text = (char *) (((u32) text) ^ ((u32) arg0));
  text = (char *) (((u32) text) ^ ((u32) arg0));
  text = (char *) (((u32) text) ^ ((u32) arg0));
  text = (char *) (((u32) text) ^ ((u32) arg0));
  text = (char *) (((u32) text) ^ ((u32) arg0));
  text = (char *) (((u32) text) ^ ((u32) arg0));
  sp10C = func_8000C9B0(temp_s4, temp_s3, 1, 1.0f, 1);
  new_var = 5;
  temp_s0_3 = func_8000C9B0(temp_s4, func_80057918(D_800C8328, 0xD0), 1, 1.0f, 1);
  temp_s0_3 += D_800A17EA + sp10C;
  func_8007347C(arg1, (temp_s0_2 - 7) & 0xFFFF, 0x3A, (temp_s1 + 0xD) & 0xFFFF, 0x11);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x80, 0xFF);
  temp_s0_4 = ((u32) (temp_s0_3 & 0xFFFF)) >> 1;
  temp_s1_2 = temp_s0_4 & 0xFFFF;
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, 0xA0 - temp_s1_2, 0x3C, temp_s3, 1);
  func_80073108(arg1, (s16) (func_8000C9B0(temp_s4, temp_s3, 1, 1.0f, 1) - (temp_s0_4 - 0xA0)), 0x3B, *((s32 *)dp74), (s32) (*((u8 *) (D_800C02AE + 0x7CF4))));
  func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, (func_8000C9B0(temp_s4, temp_s3, 1, 1.0f, 1) + (0xA0 - temp_s1_2)) + D_800A17EA, 0x3C, func_80057918(D_800C8328, 0xD0), 1);
  func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
  do
  {
    temp_s1_3 = var_s6 & 0xFFFF;
    new_var3 = &D_800A5DF0;
    if (temp_s1_3 == 6)
    {
      temp_v0_2 = func_8000C9B0(arg0 + 0x40, func_80057918(D_800C8328, 0xD1), 1, 1.0f, 1);
      temp_s0_6 = ((u32) (temp_v0_2 & 0xFFFF)) >> 1;
      func_8007347C(arg1, (0x97 - temp_s0_6) & 0xFFFF, 0xBC, (temp_v0_2 + 0xF) & 0xFFFF, 0x11);
      func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x80, 0xFF);
      sp106 = 0xCD;
      func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, 0xA0 - temp_s0_6, 0xBE, func_80057918(D_800C8328, 0xD1), 1);
      func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
      var_v0 = temp_s1_3 * 2;
    }
    temp_s0_7 = temp_s1_3 * 24;
    if (((*((u32 *) ((D_800C02AE + 0x7CE6) + temp_s0_7))) == (*((s32 *) (D_800C02AE + 0x7D76)))) & (temp_s1_3 != 6))
    {
      func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xDC, 0xDC, 0x10, 0xFF);
    }
    func_80052E94(*((u32 *) ((D_800C02AE + 0x7CE6) + temp_s0_7)), &spB8);
    func_80052E94(*((u32 *) ((D_800C02AE + 0x7CEA) + temp_s0_7)), &spD0);
    if ((*((u16 *) ((*((char **) (D_800C02AE + 0x32F2))) + 0x50))) != 0)
    {
      temp_v1 = *((u32 *) ((D_800C02AE + 0x7CEE) + temp_s0_7));
      if (temp_v1 >= 0x12DU)
      {
        func_80099DF8(spE8, &D_800A5DE8);
        var_v1 = 0xFFFF;
        var_v1 = var_s6 & var_v1;
      }
      else
      {
        func_80099DF8(spE8, &D_800A5D7C, ((u32) (temp_v1 * 0x9F00)) >> 0x10);
        var_v1 = var_s6 & 0xFFFF;
      }
      var_v0_2 = ((u32) ((*((u32 *) ((D_800C02AE + 0x7CEE) + (var_v1 * 0x18)))) * 0x27C)) >> 0xA;
    }
    else
    {
      temp_a2 = *((u32 *) ((D_800C02AE + 0x7CEE) + temp_s0_7));
      if (temp_a2 >= 0x12DU)
      {
        func_80099DF8(spE8, &D_800A5DF4);
        
      }
      else
      {
        func_80099DF8(spE8, &D_800A5D84, temp_a2 & 0xFFFF);
        
      }
      {s32 idx74;do {do {idx74=var_s6 & 0xFFFF;}while(0);}while(0);idx74=D_800C7F9C[idx74*6];var_v0_2=idx74;}
    }
    if (var_v0_2 < 0x64U)
    {
      func_80099DF8(&sp40, new_var3, (u32) text);
      func_80099DF8(text, &D_800A5D9C, (u32) (&sp40));
    }
    temp_s0_8 = var_s6 & 0xFFFF;
    if (temp_s0_8 != 6)
    {
      if (temp_s0_8 >= ((*((u8 *) (D_800A73E0 + 0x6C00))) - 1))
      {
        if ((*((u8 *) (D_800A73E0 + 0x6C00))) == 0)
        {
          if ((*((u32 *) ((D_800C02AE + 0x7CE6) + (temp_s0_8 * 0x18)))) == 0)
          {
            func_80099DF8(spB8, D_800A5D70);
            func_80099DF8(spD0, D_800A5D70);
            func_80099DF8(spE8, D_800A5D8C);
          }
        }
        else
        {
          goto e0c;
        }
      }
      func_80099DF8(sp40, D_800A5DFC, temp_s0_8 + 1, spB8, spD0, text);
      goto done;
      e0c:
      {
        char *f = D_800A5E0C;
        func_80099DF8(sp40, f);
        func_80099DF8(spE8, f);
      }

    }
    else
    {
      func_80099DF8(sp40, D_800A5E10, D_800C02AE + 0x7D72, spB8, text);
      func_80099DF8(text, D_800A5E0C);
    }
    done:
    var_v0_4 = var_s6 & 0xFFFF;

    if ((*((u32 *) inline_fn(0x7CE6, var_v0_4))) != 0)
    {
      func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, 0xA0 - (((u32) (func_8000C9B0(arg0 + 0x40, &sp40, 1, 1.0f, 1) & 0xFFFF)) >> 1), (s16) sp106, &sp40, 1);
    }
    func_8000C22C(*((s32 *) (((char *) arg0) + 0x40)), 0xFF, 0xFF, 0xFF, 0xFF);
    var_s6 += 1;
    sp106 += 0xF;
  }
  while (((u32) (var_s6 & 0xFFFF)) < 7U);
  temp_s3_2 = arg0 + 0x40;
  temp_s0_9 = func_8000C9B0(temp_s3_2, func_80057918(D_800C8328, 0xD3), 1, 1.0f, 1);
  temp_s0_10 = (((D_800A17E8 + temp_s0_9) + (D_800A17E8 + new_var)) + func_8000C9B0(temp_s3_2, func_80057918(D_800C8328, 0xD7), 1, 1.0f, 1)) + 0x10;
  {
    u16 xx = 0x140 - temp_s0_10;
    s32 *pp = &D_800D0664;
    func_80073320(arg1, xx & 0xFFFF, 0xDC, temp_s0_10 & 0xFFFF, 0x11);
    func_80073108(arg1, (s16) xx, 0xDC, *pp, 2);
    xx += D_800A17E8;
    func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, (s16) xx, 0xDE, func_80057918(D_800C8328, 0xD3), 1);
    xx += func_8000C9B0(temp_s3_2, func_80057918(D_800C8328, 0xD3), 1, 1.0f, 1);
    func_80073108(arg1, (s16) xx, 0xDC, *pp, 0);
    xx += D_800A17E8;
    func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), arg1, (s16) xx, 0xDE, func_80057918(D_800C8328, 0xD7), 1);
  }
}

