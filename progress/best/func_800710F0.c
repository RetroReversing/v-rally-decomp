#define sp18 packet.h
#define sp1A packet.b
s32 func_80052E94(s32, s16 *);
s16 *func_80057918(s32, u16);
void *func_800592D0(s32);
s32 func_80059618(void *, u8, u8, u8, s32);
s32 func_800596F4(void *, s16, s16, s16 *);
s32 func_80097E30(s16 *, s32, s32);
s32 func_800980D0(s16 *, s32 *);
s32 func_80099DF8(s16 *, s32 *, s32, void *);
extern s32 D_800A171C;
extern s32 D_800A5CFC;
extern s16 D_800A5D04;
extern s8 D_800A5D06;
extern s32 D_800A5D08;
extern s32 D_800C02AE;
void func_800710F0(void)
{
  char *__repair_addr;
  struct 
  {
    s16 h;
    s8 b;
    u8 rest[13];
  } packet;
  s16 *temp_s0;
  s32 temp_a2;
  unsigned short temp_a3;
  s32 temp_a3_2;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s1;
  s32 temp_s1_2;
  s32 temp_v0;
  s32 temp_v1;
  s32 var_a0;
  s32 var_a2;
  s32 var_s0;
  s32 var_s2;
  s32 *new_var;
  s32 var_s2_2;
  s32 var_s2_3;
  s32 var_s2_4;
  char *new_var2;
  s32 var_s6;
  void *temp_s0_4;
  void *temp_s3;
  void *temp_s3_2;
  void *temp_s3_3;
  void *temp_s3_4;
  void *temp_s3_5;
  void *temp_s4;
  void *temp_s4_2;
  void *var_a3;
  int new_var3;
  var_s6 = 0;
  temp_s3 = func_800592D0(0x13);
  var_s2 = 0;
  __repair_addr = (char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)));
  temp_s0 = func_80057918(*((s32 *) (((char *) (&D_800C02AE)) + 0x807A)), *((u16 *) (((u8 *) (&D_800A171C)) + ((*((u16 *) (((char *) __repair_addr) + 0x20))) * 2))));
  func_80059618(temp_s3, *((u8 *) (((char *) temp_s3) + 0xB)), *((u8 *) (((char *) temp_s3) + 0xC)), *((u8 *) (((char *) temp_s3) + 0xD)), (s32) (*((u8 *) (((char *) temp_s3) + 0xE))));
  new_var2 = ((char *) temp_s3) + 6;
  func_800596F4(temp_s3, *((s16 *) new_var2), *((s16 *) (((char *) temp_s3) + 8)), temp_s0);
  func_80097E30(&sp18, 0, 0xF);
  temp_s3_2 = func_800592D0(0x10);
  do
  {
    temp_s0_2 = var_s2 & 0xFF;
    temp_a2 = temp_s0_2 + 1;
    new_var = (temp_s0_2 * 0x10) + ((&D_800C02AE) + 0x34A2);
    var_s2 += 1;
    func_80099DF8(&sp18, &D_800A5CFC, temp_a2, (((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x20))) << 6) + new_var) + 6);
    func_800596F4(temp_s3_2, *((s16 *) (((char *) temp_s3_2) + 6)), (s16) ((*((u16 *) (((char *) temp_s3_2) + 8))) + (temp_s0_2 * 0x16)), &sp18);
  }
  while (((u32) (var_s2 & 0xFF)) < 3U);
  temp_s3_3 = func_800592D0(0x12);
  temp_s4 = func_800592D0(0x11);
  var_s2_2 = 0;
  do
  {
    temp_s1 = var_s2_2 & 0xFF;
    temp_s0_3 = *(((&D_800C02AE) + 0x34A2) + ((temp_s1 * 0x10) + ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x20))) << 6)));
    func_80097E30(&sp18, 0, 0xF);
    func_80052E94(temp_s0_3, &sp18);
    func_800596F4(temp_s3_3, *((s16 *) (((char *) temp_s3_3) + 6)), (s16) ((*((u16 *) (((char *) temp_s3_3) + 8))) + (temp_s1 * 0x16)), &sp18);
    if (temp_s1 == 0)
    {
      var_s6 = temp_s0_3;
    }
    else
    {
      func_80097E30(&sp18, 0, 0xF);
      sp18 = D_800A5D04;
      sp1A = D_800A5D06;
      func_80052E94(temp_s0_3 - temp_s0_3, (s16 *) (&sp1A));
      func_800980D0(&sp18, &D_800A5D08);
      func_800596F4(temp_s4, *((s16 *) (((char *) temp_s4) + 6)), (s16) ((*((u16 *) (((char *) temp_s4) + 8))) + ((temp_s1 - 1) * 0x16)), &sp18);
    }
    var_s2_2 += 1;
  }
  while (((u32) (var_s2_2 & 0xFF)) < 3U);
  temp_s3_4 = func_800592D0(0x18);
  var_s2_3 = 0;
  new_var3 = 0x40;
  temp_s0_4 = (char *) (&D_800C02AE);
  temp_s0_4 += (s32) 0x37E8;
  do
  {
    if (((u16) (*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x20)))) < 8U)
    {
      temp_a3 = var_s2_3 & 0xFF;
      var_a2 = temp_a3 + ((unsigned short) 1);
      var_a3 = (temp_a3 * 0x10) + temp_s0_4;
      func_80099DF8(&sp18, &D_800A5CFC, var_a2, var_a3);
    }
    else
    {
      temp_a3_2 = var_s2_3 & 0xFF;
      var_a2 = temp_a3_2 + 1;
      var_a3 = (temp_a3_2 * 0x10) + (temp_s0_4 + new_var3);
      func_80099DF8(&sp18, &D_800A5CFC, var_a2, var_a3);
    }
    if (temp_s4_2)
    {
      temp_v1 = var_s2_3 & 0xFF;
      var_s2_3 += 1;
      func_800596F4(temp_s3_4, *((s16 *) (((char *) temp_s3_4) + 6)), (s16) ((*((u16 *) (((char *) temp_s3_4) + 8))) + (temp_v1 * 0x16)), &sp18);
    }
    else
    {
      temp_v1 = var_s2_3 & 0xFF;
      var_s2_3 += 1;
      func_800596F4(temp_s3_4, *((s16 *) (((char *) temp_s3_4) + 6)), (s16) ((*((u16 *) (((char *) temp_s3_4) + 8))) + (temp_v1 * 0x16)), &sp18);
    }
  }
  while (((u32) (var_s2_3 & 0xFF)) < 3U);
  temp_s3_5 = func_800592D0(0x1A);
  temp_s4_2 = func_800592D0(0x19);
  var_s2_4 = 0;
  do
  {
    func_80097E30(&sp18, 0, 0xF);
    var_s0 = (u16) (*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x20)));
    temp_v0 = var_s2_4 & 0xFF;
    if (var_s0 < 8U)
    {
      var_s0 = *(((&D_800C02AE) + 0x37E2) + (temp_v0 * 0x10));
      func_80097E30(&sp18, 0, 0xF);
      var_a0 = var_s0;
    }
    else
    {
      var_s0 = *(((&D_800C02AE) + 0x3822) + (temp_v0 * 0x10));
      var_a0 = var_s0;
    }
    func_80052E94(var_a0, &sp18);
    temp_s1_2 = var_s2_4 & 0xFF;
    func_800596F4(temp_s3_5, *((s16 *) (((char *) temp_s3_5) + 6)), (s16) ((*((u16 *) (((char *) temp_s3_5) + 8))) + (temp_s1_2 * 0x16)), &sp18);
    if (temp_s1_2 == 0)
    {
      var_s6 = var_s0;
    }
    else
    {
      func_80097E30(&sp18, 0, 0xF);
      sp18 = D_800A5D04;
      sp1A = D_800A5D06;
      func_80052E94(var_s0 - var_s6, (s16 *) (&sp1A));
      func_800980D0(&sp18, &D_800A5D08);
      func_800596F4(temp_s4_2, *((s16 *) (((char *) temp_s4_2) + 6)), (s16) ((*((u16 *) (((char *) temp_s4_2) + 8))) + ((temp_s1_2 - 1) * 0x16)), &sp18);
    }
    var_s2_4 += 1;
  }
  while (((u32) (var_s2_4 & 0xFF)) < 3U);
}
