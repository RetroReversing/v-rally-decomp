#define I(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define SH(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define P(p,o) (*(void **)((u8 *)(p)+(o)))
void func_8004C7F0(void *);
void func_8004D31C();
void *func_800592AC(s8);
void *func_800592D0(s32);
void func_8005937C(s32, u8);
void func_8005BB5C();
void func_8005BC60();
void func_80069974(u8, void *);
void func_8007EE9C(void *);
void func_80081540(void *);
void func_8008A0D8(void *, s32, s32);
extern void *D_800A1468;
extern void D_800A5F7C;
extern void D_800A5F8C;
extern u8 D_800C02AE[];
extern void *D_800C3508;
extern void *D_800C35A0;
extern void *D_800D0658;
void func_8007A29C(void)
{
  int __repair_literal;
  void *sp14;
  void *sp24;
  void *sp1C;
  void *sp2C;
  void *temp_s2;
  void *var_s0;
  void *new_var4;
  void *new_var2;
  int new_var;
  void *var_s2;
  s16 var_v0;
  void *temp_a1;
  s8 temp_v0;
  s8 temp_v0_4;
  s8 var_fp;
  s8 var_s4;
  u16 var_s5;
  u8 *temp_s6;
  u8 *temp_v0_3;
  u8 temp_a0;
  u8 temp_s7;
  u8 temp_v1;
  void *temp_s0;
  void *temp_v0_2;
  void *temp_v0_5;
  void *new_var3;
  func_8004D31C();
  var_fp = 0;
  func_8005BC60();
  func_8005BB5C();
  B(D_800A1468, 0x22B) = (u8) B(D_800A1468, 0x228);
  new_var2 = D_800A1468;
  temp_v1 = B(D_800C35A0 + (B(D_800C35A0 + ((s8) B(new_var2, 0x228)), 0x32) * 0x28), 0x4F);
  B(D_800A1468, 0x237) = temp_v1;
  new_var = temp_v1 & 0xFF;
  B(D_800A1468, 0x238) = (u8) H((new_var * 0x2C4) + D_800D0658, 0x14);
  sp24 = new_var2 + 0x23D;
  sp1C = P(D_800C3508, 0x10) + (SH(D_800C3508, 0x2) * 0x14);
  func_80081540(&D_800A5F7C);
  sp14 = D_800D0658;
  sp2C = new_var2 + 0x241;
  B(new_var2, 0x23E) = 8;
  B(new_var2, 0x243) = 0xC;
  B(new_var2, 0x23D) = 4;
  B(new_var2, 0x23F) = 4;
  B(new_var2, 0x240) = 4;
  B(new_var2, 0x241) = 0;
  B(new_var2, 0x242) = 4;
  B(new_var2, 0x244) = 0x10;
  do
  {
    temp_v0_2 = func_800592AC(var_fp);
    var_s0 = P(temp_v0_2, 0x28);
    var_s4 = 0;
    temp_v0_3 = sp24 + var_fp;
    temp_s7 = *temp_v0_3;
    var_s5 = H(var_s0, 0x8);
    var_s2 = NULL;
    __repair_literal = 0;
    if (((s32) temp_s7) > __repair_literal)
    {
      temp_s6 = sp2C + var_fp;
      do
      {
        B(var_s0, 0x22) = (s8) ((*temp_s6) + var_s4);
        if (!(H(((((s8) (*temp_s6)) + var_s4) * 0x2C4) + sp14, 0x10) & 8))
        {
          H(var_s0, 0x8) = var_s5;
          var_s5 += 0x14;
          var_s2 = var_s0;
          var_s0 = P(var_s0, 0x0);
        }
        else
        {
          if (var_s2 == NULL)
          {
            temp_s2 = var_s0;
            var_s0 = P(var_s0, 0x0);
            var_s2 = NULL;
            P(temp_v0_2, 0x28) = var_s0;
            func_8007EE9C(temp_s2);
          }
          else
          {
            P(var_s2, 0) = P(var_s0, 0x0);
            func_8007EE9C(var_s0);
            var_s0 = P(var_s2, 0);
          }
          *temp_v0_3 -= 1;
          B(temp_v0_2, 0x4C) = (u8) (B(temp_v0_2, 0x4C) - 1);
        }
        temp_s7 = var_s4 + 1;
        temp_v0_4 = temp_s7;
        var_s4 = temp_v0_4;
      }
      while (temp_v0_4 < ((s32) temp_s7));
    }
    if (B(sp24 + var_fp, 0) == 0)
    {
      ;
      B(func_800592AC(var_fp), 0x41) = 0;
      func_8008A0D8(D_800C3508, (B((SH(D_800C3508, 0x2) * 0x14) + P(D_800C3508, 0x10), 0xD) + var_fp) & 0xFFFF, 0);
      if (B(new_var2, 0x238) == var_fp)
      {
        temp_s0 = D_800C35A0;
        new_var4 = temp_s0;
        H(D_800C35A0 + (B(new_var4 + ((s8) B(new_var2, 0x228)), 0x32) * 0x28), 0x4E) = 4;
        B(new_var2, 0x238) = (u8) H(D_800D0658, 0xB24);
      }
    }
    func_8005937C(B(sp1C, 0xD) + var_fp, B(sp24 + var_fp, 0));
    temp_v0 = var_fp + 1;
    var_fp = temp_v0;
  }
  while (temp_v0 < 4);
  temp_a1 = P(D_800C3508, 0x10);
  temp_a0 = B(new_var3, 0x238);
  var_s4 = 0;
  temp_v0_5 = (SH(D_800C3508, 0x2) * 0x14) + temp_a1;
  B(temp_v0_5, 0xE) = (s8) (B(temp_v0_5, 0xD) + temp_a0);
  func_80069974(temp_a0, temp_a1);
  B(new_var2, 0x2BD) = 1;
  func_8004C7F0(&(*((void *) 0x800a5f7c)));
  temp_s0 = func_800592D0(0x38);
  var_v0 = 0x98;
  if (((s8) B(new_var2, 0x228)) == var_s4)
  {
    var_v0 = 3;
  }
  B(temp_s0, 0x4) = var_v0;
}
