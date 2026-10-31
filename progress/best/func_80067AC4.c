#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
#define S(p,o) (*(s8*)((char*)(p)+(o)))
typedef struct 
{
  int pad[4];
  int x[4];
  int y[4];
  int id[4];
  u8 r[4];
  u8 g[4];
  u8 b[4];
  u8 a[4];
} Draw;
extern s8 D_800A5700;
extern s8 D_800A5701;
extern char *D_800A1468;
extern char *D_800C35A0;
extern u16 D_800C6F12;
extern int D_800C8328;
extern int D_8009D540;
char *func_800592D0(int);
char *func_80057918(int, int);
char *func_8004240C(int);
void func_80059618(void *, u8, u8, u8, ...);
void func_800596F4(void *, s16, s16, char *);
void func_8004C370(void *, Draw *);
void func_8006874C(s8);
void func_80067AC4(void)
{
  volatile s8 str[2];
  Draw draw;
  s32 sp94;
  s32 sp7C;
  s8 sp87;
  s32 temp_s0_3;
  s32 temp_s0_4;
  s32 temp_s5;
  s32 temp_v0_9;
  s32 temp_v0_10;
  s32 temp_v0_11;
  s32 temp_v1_2;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 var_a0;
  s32 var_a1;
  s32 var_a2;
  s32 var_a3;
  s32 var_v1;
  s32 var_v1_2;
  s32 var_v1_3;
  s32 var_v1_4;
  char *temp_s0;
  char *temp_s3_2;
  char *temp_s0_2;
  char *temp_s7;
  s8 temp_a0;
  s8 temp_v0_12;
  s8 temp_v0_2;
  s8 temp_v0_4;
  s8 temp_v0_6;
  s8 temp_v0_7;
  s8 temp_v0_8;
  s8 temp_v1;
  s32 var_fp;
  short var_s1;
  char *new_var;
  s8 var_s4;
  s8 var_s4_2;
  s8 var_s4_3;
  s8 var_v0;
  u8 temp_a1;
  u8 temp_v0_3;
  u8 temp_v0_5;
  u8 var_a1_2;
  u8 var_a2_2;
  u8 var_a3_2;
  str[0] = D_800A5700;
  str[1] = D_800A5701;
  temp_s7 = func_800592D0(9);
  if (D_800C6F12 != 0)
  {
    D_800C6F12 = (u16) (D_800C6F12 - 1);
    temp_s0 = func_80057918(D_800C8328, 0x136);
    func_80059618(temp_s7, 0xFFU, 0U, 0U, (((u32) (D_800C6F12 * 0xFF)) / ((u32) (D_8009D540 * 2))) & 0xFF);
    func_800596F4(temp_s7, H(temp_s7, 0x6), H(temp_s7, 0x8), temp_s0);
  }
  temp_s0_2 = D_800A1468;
  temp_s7 = func_800592D0(5);
  temp_s7 = temp_s0_2 + 0x280;
  S(temp_s7 + B(temp_s0_2, 0x282), 3) = (s8) (B(temp_s0_2, 0x281) + 0x41);
  temp_v1 = S(temp_s0_2, 0x280);
  if (temp_v1 > 0)
  {
    do
    {
      temp_v0_2 = temp_v1 + 8;
      S(temp_s0_2, 0x280) = temp_v0_2;
      var_s4 = 0;
      if (temp_v0_2 == 0x20)
      {
        temp_v0_3 = S(temp_s0_2, 0x281) + 1;
        S(temp_s0_2, 0x281) = temp_v0_3;
        if (((s8) temp_v0_3) == 0x1A)
        {
          S(temp_s0_2, 0x281) = 0U;
          goto block_14;
        }
        S(temp_s0_2, 0x280) = 0;
      }
    }
    while (0);
  }
  else
  {
    var_s4 = 0;
    if (temp_v1 < 0)
    {
      temp_v0_4 = temp_v1 - 8;
      S(temp_s0_2, 0x280) = temp_v0_4;
      if (temp_v0_4 == (-0x20))
      {
        temp_v0_5 = S(temp_s0_2, 0x281) - 1;
        S(temp_s0_2, 0x281) = temp_v0_5;
        if (!(temp_v0_5 & 0x80))
        {
          S(temp_s0_2, 0x280) = 0;
        }
        else
        {
          S(temp_s0_2, 0x281) = 0x19U;
          block_14:
          S(temp_s0_2, 0x280) = 0;

          var_s4 = 0;
        }
      }
    }
  }
  do
  {
    temp_v1_2 = var_s4 << 0x18;
    temp_a0 = var_s4 + 1;
    var_s4 = temp_a0;
    temp_v1_3 = temp_v1_2 >> 0x18;
    draw.id[temp_v1_3] = -1;
    draw.r[temp_v1_3] = 0x1E;
    draw.g[temp_v1_3] = 0x32;
    draw.b[temp_v1_3] = 0x8E;
    draw.a[temp_v1_3] = 0x80;
  }
  while (temp_a0 < 4);
  temp_a1 = B(temp_s7, 0x1);
  temp_v0_6 = temp_a1 + 0xD;
  sp87 = temp_v0_6;
  sp7C = (S(temp_s0_2, 0x280) * 0xFFF) / 832;
  if (temp_v0_6 >= 0x1A)
  {
    sp87 = temp_a1 - 0xC;
  }
  var_fp = 0;
  do
  {
    var_s4_2 = 0;
    var_s1 = ((u8) sp87) - var_fp;
    sp94 = (s32) var_fp;
    var_v0 = var_s1 + 0x41;
    loop_22:
    str[0] = var_v0;

    temp_s0_3 = ((((((s8) S(temp_s7, 0x1)) - var_s1) * 0xFFF) / 26) - 0x400) + sp7C;
    var_v1 = func_8002D2E4(temp_s0_3) * 0xC0;
    if (var_v1 < 0)
    {
      var_v1 += 0xFFF;
    }
    var_v1_2 = func_8002D348(temp_s0_3) * 0xC0;
    if (var_v1_2 < 0)
    {
      var_v1_2 += 0x3FFF;
    }
    temp_s0_4 = var_v1_2 >> 0xE;
    if (var_s1 == ((s8) S(temp_s7, 0x1)))
    {
      var_a1 = 0xDC;
      var_a2 = 0xDC;
      var_a3 = 0xDC;
    }
    else
    {
      var_a1 = 0x14;
      if (temp_s0_4 < 0)
      {
        var_a2 = (((var_s4_2 * 0x3C) / 13) + 0x14) + ((S(temp_s0_2, 0x280) * 0x14) / 416);
        var_a1 = var_a2;
        var_a3 = var_a2;
      }
      else
      {
        var_a2 = 0x14;
        var_a3 = 0x14;
      }
    }
    func_80059618(temp_s7, var_a1 & 0xFF, var_a2 & 0xFF, var_a3 & 0xFF, 0xFF);
    func_800596F4(temp_s7, (s16) (H(temp_s7, 0x6) - (var_v1 >> 0xC)), (s16) (H(temp_s7, 0x8) - temp_s0_4), &str[0]);
    if (sp94 == 0)
    {
      var_s1 += 1;
      if (var_s1 >= 0x19)
      {
        var_s1 = 0;
      }
    }
    else
    {
      var_s1 -= 1;
      if ((var_s1 << 0x18) == 0)
      {
        var_s1 = 0x19;
      }
    }
    temp_v0_8 = var_s4_2 + 1;
    var_s4_2 = temp_v0_8;
    var_v0 = var_s1 + 0x41;
    if (temp_v0_8 < 0xD)
    {
      goto loop_22;
    }
    temp_v0_7 = var_fp + 1;
    var_fp = temp_v0_7;
  }
  while (temp_v0_7 < 2);
  if (S(D_800A1468, 0x24D) == 0)
  {
    var_v1_3 = func_8002D2E4(-0x400) * 0xC0;
    if (var_v1_3 < 0)
    {
      var_v1_3 += 0xFFF;
    }
    temp_s5 = var_v1_3 >> 0xC;
    var_a0 = func_8002D348(-0x400) * 0xC0;
    if (var_a0 < 0)
    {
      var_a0 += 0x3FFF;
    }
    draw.a[0] = 0x32;
    draw.a[1] = 0xB4;
    draw.a[2] = 0x32;
    draw.a[3] = 0xB4;
    temp_v0_9 = (((s16) H(temp_s7, 0x6)) + temp_s5) - 8;
    draw.x[0] = temp_v0_9;
    draw.x[3] = temp_v0_9;
    temp_v1_4 = (((s16) H(temp_s7, 0x6)) + temp_s5) + 0x20;
    draw.x[1] = temp_v1_4;
    draw.x[2] = temp_v1_4;
    temp_v1_4 = var_a0 >> 0xE;
    temp_v0_10 = (((s16) H(temp_s7, 0x8)) - temp_v1_4) - 8;
    draw.y[1] = temp_v0_10;
    draw.y[0] = temp_v0_10;
    temp_v0_11 = (((s16) H(temp_s7, 0x8)) - temp_v1_4) + 0x24;
    draw.y[3] = temp_v0_11;
    draw.y[2] = temp_v0_11;
    func_8004C370(W(func_8004240C(1), 0x178), &draw);
  }
  temp_s3_2 = func_800592D0(8);
  var_s4_3 = 0;
  if (((s32) B(temp_s7, 0x2)) >= 0)
  {
    var_v1_4 = 0 << 0x18;
    do
    {
      temp_v1_5 = var_v1_4 >> 0x18;
      str[0] = S(temp_s7 + temp_v1_5, 3);
      if (((u8) temp_v1_5) == ((u8) B(temp_s7, 2)))
      {
        var_a1_2 = 0xDC;
        var_a2_2 = 0xDC;
        var_a3_2 = 0xE;
        func_80059618(temp_s3_2, var_a1_2, var_a2_2, var_a3_2, 0xFF);
      }
      else
      {
        var_a1_2 = S(temp_s3_2, 0xB);
        var_a2_2 = S(temp_s3_2, 0xC);
        var_a3_2 = S(temp_s3_2, 0xD);
        func_80059618(temp_s3_2, var_a1_2, var_a2_2, var_a3_2, B(temp_s3_2, 0xE));
      }
      func_800596F4(temp_s3_2, (s16) (H(temp_s3_2, 0x6) + (var_s4_3 * 0x14)), H(temp_s3_2, 0x8), (char *) (&str[0]));
      temp_v0_12 = var_s4_3 + 1;
      var_s4_3 = temp_v0_12;
      var_v1_4 = var_s4_3 << 0x18;
    }
    while (((s32) S(temp_s7, 0x2)) >= temp_v0_12);
  }
  new_var = D_800C35A0;
  func_8006874C(S(new_var + S(D_800A1468, 0x228), 0x32));
}
