extern char D_800C3A50[];
extern char D_800C3750[];
extern char D_800C3650[];
extern char D_800C35A0[];
extern int D_800D0634;
extern int D_800D0638;
extern int D_800D063C;
extern int D_800D0640;
extern int D_800D0644;
s32 func_8002B618();
s32 func_80054838();
s32 func_8005508C();
s32 func_8006C640();
s32 func_8006C99C();
s32 func_8006CB9C();
s32 func_8006CE1C();
s32 func_8006D10C();
s32 func_8006DD04();
s32 func_8006DDD8();
s32 func_8006EE3C();
s32 func_8006F0E0();
s32 func_8006F4A8();
s32 func_8006F75C();
s32 func_8006F820();
s32 func_8006F8E0();
extern s8 D_800A16F0;
extern char D_800A57C0[];
extern char D_800C02AE[];
static inline static void *inline_fn(char *arg0)
{
  return *((void **) arg0);
}

void func_8006D564(s32 arg0)
{
  u8 sp17;
  s16 temp_v0;
  s16 temp_v0_2;
  s16 temp_v1;
  s16 temp_v1_2;
  s16 temp_v1_3;
  s16 temp_v1_4;
  s16 temp_v1_5;
  s16 temp_v1_6;
  short var_a0_8;
  s16 temp_v1_7;
  s16 temp_v1_8;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a0_3;
  s32 temp_a0_4;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 temp_s2_4;
  s32 temp_s2_5;
  s32 temp_s2_6;
  u16 var_a0;
  s32 var_a0_2;
  u16 var_a0_3;
  u16 var_a0_4;
  u8 var_a0_5;
  u16 var_a0_6;
  u16 var_a0_7;
  u8 var_s0;
  u8 var_s1;
  u8 var_s3;
  u8 __repair_var_s3_2;
  u8 __repair_var_s3_1;
  u8 var_v1;
  s32 var_v1_2;
  u8 temp_fp;
  u8 temp_fp_2;
  u8 temp_s7;
  volatile unsigned int pad;
  u8 temp_s7_2;
  void *temp_a0_5;
  short new_var;
  void *temp_s0_3;
  void *temp_s2;
  void *temp_s2_7;
  void *temp_s3;
  var_s3 = 0;
  temp_s7 = *((u8 *) (((char *) inline_fn(D_800C35A0)) + 0x1F));
  temp_fp = *((u8 *) (((char *) inline_fn(D_800C35A0)) + 0x21));
  sp17 = *((u8 *) (((char *) inline_fn(D_800C35A0)) + 0x23));
  var_v1 = 0 & 0xFF;
  do
  {
    temp_s2 = D_800D0634 + (var_v1 * 0x2C4);
    var_s0 = 0;
    if ((*((u16 *) (((char *) temp_s2) + 0x14))) != 0)
    {
      do
      {
        var_s1 = 0;
        var_a0 = 0 & 0xFF;
        loop_4:
        func_8006F820((temp_s2 + (((var_s0 & 0xFF) << 6) + 0x2C)) + (var_a0 * 0x10), arg0 & 0xFF);

        var_s1 += 1;
        var_a0 = var_s1 & 0xFF;
        if (((u32) (var_s1 & 0xFF)) < 3U)
        {
          goto loop_4;
        }
        temp_v1_6 = var_s0 & 0xFF;
        *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 0;
        *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = (s16) (var_s3 & 0xFF);
        *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = (s16) temp_v1_6;
        func_8006DDD8();
        var_s0 += 1;
      }
      while (((u32) (var_s0 & 0xFF)) < ((u16) (*((u16 *) (((char *) temp_s2) + 0x14)))));
    }
    var_s3 += 1;
    var_v1 = var_s3 & 0xFF;
  }
  while (((u32) (var_s3 & 0xFF)) < 8U);
  var_s0 = 0;
  do
  {
    var_s1 = 0;
    temp_s2_2 = D_800D0638;
    temp_s2_2 += ((var_s0 & 0xFF) << 6) + 0x2C;
    var_a0_2 = 0 & 0xFF;
    loop_9:
    func_8006F820(temp_s2_2 + (var_a0_2 * 0x10), arg0 & 0xFF);

    var_s1 += 1;
    var_a0_2 = var_s1;
    var_a0_2 = var_a0_2 & 0xFF;
    if (((u32) (var_s1 & 0xFF)) < 3U)
    {
      goto loop_9;
    }
    temp_v1 = var_s0 & 0xFF;
    var_s0 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1;
    func_8006D10C();
  }
  while (((u32) (var_s0 & 0xFF)) < 4U);
  var_s0 = 0;
  do
  {
    var_s1 = 0;
    temp_s2_3 = D_800D063C;
    temp_s2_3 += ((var_s0 & 0xFF) << 6) + 0x2C;
    var_a0_3 = 0 & 0xFF;
    loop_13:
    func_8006F820(temp_s2_3 + (var_a0_3 * 0x10), arg0 & 0xFF);

    var_s1 += 1;
    var_a0_3 = var_s1 & 0xFF;
    if (((u32) (var_s1 & 0xFF)) < 3U)
    {
      goto loop_13;
    }
    temp_v1_2 = var_s0 & 0xFF;
    var_s0 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 2;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1_2;
    func_8006D10C();
  }
  while (((u32) (var_s0 & 0xFF)) < 5U);
  var_s0 = 0;
  do
  {
    var_s1 = 0;
    temp_s2_4 = D_800D0640;
    temp_s2_4 += ((var_s0 & 0xFF) << 6) + 0x2C;
    var_a0_4 = 0 & 0xFF;
    loop_17:
    func_8006F820(temp_s2_4 + (var_a0_4 * 0x10), arg0 & 0xFF);

    var_s1 += 1;
    var_a0_4 = var_s1 & 0xFF;
    if (((u32) (var_s1 & 0xFF)) < 3U)
    {
      goto loop_17;
    }
    temp_v1_3 = var_s0 & 0xFF;
    var_s0 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 3;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1_3;
    func_8006D10C();
  }
  while (((u32) (var_s0 & 0xFF)) < 6U);
  var_s3 = (var_s0 = 0);
  do
  {
    var_s1 += 1;
    var_s1 = 0;
    temp_s2_5 = D_800D0644;
    temp_s2_5 += ((var_s0 & 0xFF) << 6) + 0x2C;
    var_a0_5 = 0 & 0xFF;
    loop_21:
    func_8006F820(temp_s2_5 + (var_a0_5 * 0x10), arg0 & 0xFF);

    var_s1 += 1;
    var_a0_5 = var_s1 & 0xFF;
    if (((u32) (var_s1 & 0xFF)) < 3U)
    {
      goto loop_21;
    }
    temp_v1_4 = var_s0 & 0xFF;
    var_s0 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 4;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1_4;
    func_8006D10C();
    var_s1 = 0;
  }
  while (((u32) (var_s0 & 0xFF)) < 3U);
  __repair_var_s3_1 = 0;
  do
  {
    var_a0_6 = 0 & 0xFF;
    loop_25:
    func_8006F820(((__repair_var_s3_1 & 0xFF) << 6) + ((var_a0_6 * 0x10) + D_800C3750), arg0 & 0xFF);

    var_s1 += 1;
    var_a0_6 = var_s1 & 0xFF;
    if (((u32) (var_s1 & 0xFF)) < 3U)
    {
      goto loop_25;
    }
    temp_v0 = __repair_var_s3_1 & 0xFF;
    __repair_var_s3_1 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = temp_v0;
    func_8006C640();
  }
  while (((u32) (__repair_var_s3_1 & 0xFF)) < 0xCU);
  do
  {
    var_a0_7 = 0 & 0xFF;
    loop_29:
    func_8006F820(((var_s3 & 0xFF) << 6) + ((var_a0_7 * 0x10) + D_800C3650), arg0 & 0xFF);

    var_s1 += 1;
    var_a0_7 = var_s1 & 0xFF;
    if (((u32) (var_s1 & 0xFF)) < 3U)
    {
      goto loop_29;
    }
    var_s3 += 1;
    func_8006CE1C();
    var_s1 = 0;
  }
  while (((u32) (var_s3 & 0xFF)) < 4U);
  temp_s2_6 = arg0 & 0xFF;
  temp_s3 = D_800C3A50;
  do
  {
    temp_s0 = (var_s1 & 0xFF) * 0x10;
    func_8006F820(temp_s0 + D_800C3A50, temp_s2_6);
    var_s1 += 1;
    func_8006CB9C();
    func_8006F820(temp_s0 + (D_800C3A50 + 0xC0), temp_s2_6);
    func_8006C99C();
  }
  while (((u32) (var_s1 & 0xFF)) < 3U);
  *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = (s16) (temp_s7 & 0xFF);
  *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = (s16) (temp_fp & 0xFF);
  temp_s0_2 = arg0 & 0xFF;
  *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = (s16) sp17;
  func_8006F4A8(temp_s0_2);
  func_8006EE3C(temp_s0_2);
  *((s8 *) (((char *) (inline_fn(D_800C35A0) + (temp_s0_2 * 0x28))) + 0x44)) = 0x5B;
  func_8006F0E0(temp_s0_2);
  __repair_var_s3_2 = 0;
  func_8006F75C();
  D_800A16F0 = 0;
  func_8002B618(&D_800A57C0, 0);
  func_8006F8E0();
  temp_s7_2 = *((u8 *) (((char *) inline_fn(D_800C35A0)) + 0x1F));
  temp_fp_2 = *((u8 *) (((char *) inline_fn(D_800C35A0)) + 0x21));
  sp17 = *((u8 *) (((char *) inline_fn(D_800C35A0)) + 0x23));
  var_v1_2 = 0 & 0xFF;
  do
  {
    temp_s2_7 = D_800D0634 + (var_v1_2 * 0x2C4);
    var_s0 = 0;
    if ((*((u16 *) (((char *) temp_s2_7) + 0x14))) != 0)
    {
      do
      {
        *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 0;
        *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = (s16) (__repair_var_s3_2 & 0xFF);
        *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = (s16) (var_s0 & 0xFF);
        func_8006DD04(temp_s2_7 + (((var_s0 & 0xFF) << 6) + 0x2C));
        var_s0 += 1;
        func_8006DDD8();
      }
      while (((u32) (var_s0 & 0xFF)) < ((u16) (*((u16 *) (((char *) temp_s2_7) + 0x14)))));
    }
    if (D_800C35A0)
    {
      __repair_var_s3_2 += 1;
      var_v1_2 = __repair_var_s3_2 & 0xFF;
    }
    else
    {
      __repair_var_s3_2 += 1;
      var_v1_2 = __repair_var_s3_2 & 0xFF;
    }
  }
  while (((u32) (__repair_var_s3_2 & 0xFF)) < 8U);
  var_s0 = 0;
  do
  {
    temp_v1_5 = 0xFF;
    temp_v1_5 = var_s0 & temp_v1_5;
    temp_a0 = var_s0 & 0xFF;
    var_s0 += 1;
    var_s1 = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1_5;
    func_8006DD04(D_800D0638 + ((temp_a0 << 6) + 0x2C));
    func_8006D10C();
  }
  while (((u32) (var_s0 & 0xFF)) < 4U);
  var_s0 = 0;
  do
  {
    temp_v1_6 = var_s0 & 0xFF;
    temp_a0_2 = var_s0 & 0xFF;
    var_s0 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 2;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1_6;
    func_8006DD04(D_800D063C + ((temp_a0_2 << 6) + ((unsigned char) 0x2C)));
    func_8006D10C();
  }
  while (((u32) (var_s0 & 0xFF)) < 5U);
  var_s0 = 0;
  do
  {
    temp_v1_7 = var_s0 & 0xFF;
    temp_a0_3 = var_s0 & 0xFF;
    var_s0 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 3;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1_7;
    func_8006DD04(D_800D0640 + ((temp_a0_3 << 6) + 0x2C));
    func_8006D10C();
  }
  while (((u32) (var_s0 & 0xFF)) < 6U);
  var_s0 = 0;
  do
  {
    temp_v1_8 = var_s0 & 0xFF;
    temp_a0_4 = var_s0 & 0xFF;
    var_s0 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = 4;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = 0;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = temp_v1_8;
    func_8006DD04(D_800D0644 + ((temp_a0_4 << 6) + 0x2C));
    func_8006D10C();
  }
  while (((u32) (var_s0 & 0xFF)) < 3U);
  var_s3 = (var_s3 = 0);
  do
  {
    temp_a0_5 = ((var_s3 & 0xFF) << 6) + D_800C3750;
    temp_v0_2 = var_s3 & 0xFF;
    var_s3 += 1;
    *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = temp_v0_2;
    do
    {
      func_8006DD04(temp_a0_5);
      func_8006C640();
    }
    while (0);
  }
  while (((u32) (var_s3 & 0xFF)) < 0xCU);
  var_a0_8 = 0 & 0xFF;
  do
  {
    func_8006DD04((var_a0_8 << 6) + D_800C3650);
    var_s3 = var_s3 + 1;
    func_8006CE1C();
    var_a0_8 = var_s3 & 0xFF;
  }
  while (((u32) (var_s3 & 0xFF)) < 4U);
  temp_s0_3 = D_800C3A50;
  func_8006DD04(temp_s0_3);
  func_8006CB9C();
  func_8006DD04(temp_s0_3 + 0xC0);
  new_var = (s16) sp17;
  func_8006C99C();
  *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x1E)) = (s16) (temp_s7_2 & 0xFF);
  *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x20)) = (s16) (temp_fp_2 & 0xFF);
  *((s16 *) (((char *) inline_fn(D_800C35A0)) + 0x22)) = new_var;
  func_80054838();
  func_8005508C();
}
