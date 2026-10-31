extern int D_800B5C60;
extern int D_800D05D8;
extern float D_800C6CF8;
extern int D_800C8328;
extern void *D_800C35A0;
s32 func_8004240C();
s32 func_80047B54();
s32 func_8004CF7C(s32, s32, s32, s32, f32, s32, s32);
char *func_80057918();
void *func_800592D0();
s32 func_80059618();
s32 func_800596F4();
s32 func_8005A6BC();
s32 func_8005A6E0();
s32 func_80097E30();
s32 func_80099DF8();
extern u8 D_800A14D5;
extern u8 D_800A1548;
extern char D_800A5418[];
extern char D_800A541C[];
extern char D_800A5428[];
extern char D_800A5434[];
extern f64 D_800A5438;
extern f64 D_800A5440;
extern f64 D_800A5448;
extern char D_800AE850[];
extern char D_800C02AE[];
static inline static static u8 inline_fn(void *arg0)
{
  return *((u8 *) (((char *) arg0) + 0xC));
}

static inline static u8 *inline_fn2(char *arg0)
{
  return (u8 *) arg0;
}

void func_8005D0B0(void)
{
  char sp20[16];
  char sp30[8];
  int new_var;
  char sp38[16];
  s32 new_var5;
  char *new_var7;
  char (*new_var4)[16];
  char sp_pad[8];
  s32 *var_a1;
  f64 temp_fv1;
  f64 var_fv1;
  char *new_var3;
  u32 temp_a1;
  u8 *new_var2;
  s32 var_a2;
  u32 var_hi;
  char *new_var8;
  int new_var6;
  u8 var_a2_2;
  u8 *cfg;
  void *temp_s1;
  void *temp_s1_2;
  void *temp_v1;
  func_80097E30(&sp20, 0, 0x10);
  D_800B5C60 = 0;
  if (D_800A1548 != 0)
  {
    func_80047B54(func_8004240C(0), 0, 0, 0);
    D_800A1548 -= 1;
  }
  func_8004CF7C(D_800D05D8, 0, 0x68, 0x4A, D_800C6CF8, 0, 0xFF);
  temp_s1 = func_800592D0(0);
  new_var8 = (char *) temp_s1;
  new_var4 = &sp38;
  func_80059618(temp_s1, *inline_fn2((0, ((char *) temp_s1) + 0xB)), inline_fn(temp_s1), *((u8 *) (((char *) temp_s1) + 0xD)), 0xFF);
  {
    u16 v0u;
    u16 v1u;
    s32 v0s;
    s32 tbl;
    u8 b37;
    cfg = (u8 *) D_800C35A0;
    v0u = *((u16 *) (cfg + 0x1E));
    v1u = *((u16 *) (cfg + 0x20));
    v0s = ((s32) v0u) << 2;
    tbl = *((s32 *) ((D_800C02AE + 0x10386) + v0s));
    v0s = ((s32) v1u) * 0x2C4;
    v1u = *((u16 *) (new_var2 = cfg + 0x22));
    v0s = v0s + tbl;
    v0s = v0s + (((s32) v1u) << 6);
    b37 = *((u8 *) (v0s + 0x37));
    func_80099DF8(&sp20, &D_800A5418, func_80057918(*((s32 *) (D_800C02AE + 0x807A)), b37 + 0x1E4));
  }
  func_800596F4(temp_s1, *((s16 *) (((char *) temp_s1) + 6)), *((s16 *) (new_var8 + 8)), &sp20);
  func_80097E30(&sp38, 0, 0xA);
  temp_s1 = func_800592D0(2);
  new_var5 = *((s32 *) ((D_800C02AE + 0x10386) + ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) * 4)));
  new_var = ((*((u16 *) (((char *) D_800C35A0) + 0x20))) * 0x2C4) + new_var5;
  temp_v1 = ((*((u16 *) (((char *) D_800C35A0) + 0x22))) * 4) + new_var;
  new_var7 = (char *) temp_v1;
  temp_a1 = *((s32 *) (new_var7 + 0x22C));
  if ((*((u16 *) (((char *) D_800C35A0) + 0x50))) == 0)
  {
    var_a2 = ((u32) temp_a1) / 1000;
    new_var6 = ((u32) temp_a1) % 1000;
    var_hi = ((u32) new_var6) / 100;
    var_a1 = (s32 *) (&D_800A541C);
  }
  else
  {
    var_fv1 = (f64) temp_a1;
    if (temp_a1 < 0)
    {
      var_fv1 += D_800A5438;
    }
    temp_fv1 = var_fv1 * D_800A5440;
    if (!(D_800A5448 <= temp_fv1))
    {
      temp_a1 = (s32) temp_fv1;
    }
    else
    {
      temp_a1 = (s32) (temp_fv1 - D_800A5448);
      temp_a1 = temp_a1 | 0x80000000;
    }
    var_a2 = temp_a1 / 1000;
    var_hi = (temp_a1 % 1000) / 100;
    var_a1 = (s32 *) (&D_800A5428);
  }
  func_80099DF8(new_var4, var_a1, var_a2 & 0xFFFF, var_hi & 0xFFFF);
  new_var3 = ((char *) temp_s1) + 0xC;
  func_80059618(temp_s1, *((u8 *) (((char *) temp_s1) + 0xB)), *inline_fn2(new_var3), *inline_fn2(((char *) temp_s1) + 0xD), (s32) (*((u8 *) (((char *) temp_s1) + (((0xE & 0xFFu) & 0xFFu) & 0xFFu)))));
  func_800596F4(temp_s1, *((s16 *) (((char *) temp_s1) + 6)), *((s16 *) (((char *) temp_s1) + 8)), &sp38);
  if (D_800A14D5 != 0)
  {
    func_8005A6BC(0xD);
    temp_s1_2 = func_800592D0(0xE);
    func_80097E30(&sp30, 0, 0);
    func_80059618(temp_s1_2, *((u8 *) (((char *) temp_s1_2) + 0xB)), inline_fn(temp_s1_2), *inline_fn2(((char *) temp_s1_2) + 0xD), (s32) (*inline_fn2(((char *) temp_s1_2) + 0xE)));
    if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) == 0)
    {
      var_a2_2 = *((u8 *) (((char *) D_800C35A0) + 0x30));
      if (var_a2_2 == 0)
      {
        func_800596F4(temp_s1_2, *((s16 *) (((char *) temp_s1_2) + 6)), *((s16 *) (((char *) temp_s1_2) + 8)), func_80057918(D_800C8328, 0x174));
        return;
      }
      goto block_18;
    }
    ;
    block_18:
    func_80099DF8(&sp30, &D_800A5434, 3, 0);

    func_800596F4(temp_s1_2, *((s16 *) (((char *) temp_s1_2) + 6)), *((s16 *) (((char *) temp_s1_2) + 8)), &sp30);
    return;
  }
  func_8005A6E0(0xD);
}
