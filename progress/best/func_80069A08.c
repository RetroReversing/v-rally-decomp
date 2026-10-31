#define CMD(a,b) {Gfx *p=cursor++; p->w0=(a);p->w1=(b);}
#define currentCamera D_800C7F84
#define W(p,o) (*(s32 *)((char *)(p)+(o)))
#define P(p,o) (*(char **)((char *)(p)+(o)))
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define U(p,o) (*(u16 *)((char *)(p)+(o)))
#define B(p,o) (*(u8 *)((char *)(p)+(o)))
typedef struct 
{
  volatile u32 w0;
  volatile u32 w1;
} Gfx;
extern int D_800C5E50;
extern int D_800B5AF4;
extern int D_800AFB40;
extern int D_800AFA68;
typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} Vec3i;
extern char *D_800C7F84;
void func_80005500();
void *func_800056FC();
int func_80005C48();
void *func_80006008();
void func_80006014();
void func_800061FC();
void func_80010A6C();
void func_80010BFC();
void func_80015C74();
void func_80017B38();
int func_8001BD1C();
void func_8001C1A8();
void func_8001E3A8();
void func_80022668();
void *func_8004240C();
void func_8004D1A8(s32, s32, float, s32, s32);
int func_80084DD4();
void guMtxF2L();
void guMtxIdent();
int osVirtualToPhysical(int);
extern void *D_8009B5A8;
extern s32 D_800A11B0;
extern void *D_800A1468;
extern f32 D_800A1584;
extern f32 D_800A158C;
extern char D_800A159C[];
extern f32 D_800A15D0;
extern Vec3i D_800A1694;
extern Vec3i D_800A16A0;
extern u16 D_800A16AC;
extern u16 D_800A16AE;
extern s16 D_800A16B2;
extern s32 D_800A1B70;
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800C02AE[];
void func_80069A08(void)
{
  Gfx *cursor;
  s32 cameraBuffer;
  s32 temp_v0_10;
  u32 temp_v0_12;
  s32 temp_v0_13;
  s32 temp_v1;
  s32 var_s0;
  s32 var_s0_2;
  s32 var_s0_3;
  u8 temp_v1_3;
  void *temp_s0;
  void *temp_s1;
  void *temp_s6;
  void *temp_s6_10;
  int new_var4;
  int new_var3;
  void *temp_s6_11;
  void *temp_s6_12;
  volatile int new_var2;
  void *temp_s6_13;
  void *temp_s6_14;
  void *temp_s6_15;
  void *temp_s6_2;
  void *temp_s6_3;
  void *temp_s6_4;
  void *temp_s6_5;
  void *temp_s6_6;
  int new_var5;
  void *temp_s6_7;
  void *temp_s6_8;
  s32 *new_var;
  void *temp_s6_9;
  void *temp_s7_2;
  void *temp_v0;
  void *temp_v0_11;
  void *temp_v0_14;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_9;
  func_80022668(D_800A11B0, 0);
  temp_v0 = func_8004240C(3);
  cameraBuffer = W(temp_v0, 0x178);
  currentCamera = temp_v0;
  new_var = func_800056FC(cameraBuffer);
  temp_v0_2 = func_8004240C(3);
  currentCamera = temp_v0_2;
  *((Vec3i *) (((char *) temp_v0_2) + 0x118)) = D_800A1694;
  *((Vec3i *) (currentCamera + 0x124)) = D_800A16A0;
  F(currentCamera, 0x130) = 0;
  F(currentCamera, 0x134) = 100.0f;
  F(currentCamera, 0x138) = 0;
  F(currentCamera, 0x10C) = 0.4f;
  F(currentCamera, 0x110) = 0.4f;
  F(currentCamera, 0x114) = 1.0f;
  func_80005500(P(currentCamera, 0x178), &D_800A16AC);
  temp_v0_3 = func_8004240C(1);
  currentCamera = temp_v0_3;
  *((Vec3i *) (((char *) temp_v0_3) + 0x118)) = D_800A1694;
  *((Vec3i *) (currentCamera + 0x124)) = D_800A16A0;
  F(currentCamera, 0x130) = 0;
  F(currentCamera, 0x134) = 100.0f;
  F(currentCamera, 0x138) = 0;
  F(currentCamera, 0x10C) = 0.4f;
  F(currentCamera, 0x110) = 0.4f;
  F(currentCamera, 0x114) = 1.0f;
  cursor = func_80006008(new_var);
  CMD(0xE7000000, 0);
  CMD(0xE3000A01, 0x300000);
  temp_v1 = W(D_800AE850, 0x881c) - 0x80000000;
  CMD(0xFE000000, temp_v1);
  CMD((((*((s16 *) (((char *) D_8009B5A8) + 4))) - 1) & 0xfff) | 0xFF100000, temp_v1);
  CMD(0xF7000000, 0xFFFCFFFC);
  new_var5 = 0xfff;
  new_var2 = (((((*((s16 *) (((char *) D_8009B5A8) + 4))) - 1) & 0x3ff) << 14) | (((D_800A16B2 - 1) & 0x3ff) << 2)) | 0xF6000000;
  CMD(new_var2, ((D_800A16AC & 0x3ff) << 14) | ((D_800A16AE & 0x3ff) << 2));
  CMD(0xE7000000, 0);
  {
    Gfx *p = cursor++;
    p->w0 = (((*((s16 *) (((char *) D_8009B5A8) + 4))) - 1) & new_var5) | 0xFF100000;
    p->w1 = osVirtualToPhysical(func_80005C48(D_8009B5A8));
  }
  CMD(0xF7000000, 0x10001);
  new_var3 = D_800A16B2 - 1;
  CMD((((((*((s16 *) (((char *) D_8009B5A8) + 4))) - 1) & 0x3ff) << 14) | ((new_var3 & 0x3ff) << 2)) | 0xF6000000, ((D_800A16AC & 0x3ff) << 14) | (((((s16) D_800A16AE) + 60) & 0x3ff) << 2));
  CMD(0xE3000A01, 0);
  func_80006014(new_var, cursor);
  temp_s0 = func_8004240C(3);
  func_80010A6C(func_8004240C(3), &D_800A16AC);
  temp_v0_5 = func_800056FC(P(temp_s0, 0x178));
  cursor = func_80006008(temp_v0_5);
  new_var = &D_800A1B70;
  guMtxF2L(temp_s0 + 0x38, func_8001BD1C());
  temp_s1 = D_800C02AE + 0x80D2;
  guMtxIdent(temp_s1);
  CMD(0xDB0E0000, U(temp_s0, 0x104));
  CMD(0xDA380003, (u32) temp_s1);
  CMD(0xDC08000A, (u32) (temp_s0 + 0x158));
  CMD(0xDC08030A, (u32) (temp_s0 + 0x168));
  CMD(0xE7000000, 0);
  func_80006014(temp_v0_5, cursor);
  temp_v0_6 = func_8004240C(3);
  currentCamera = temp_v0_6;
  temp_s7_2 = func_800056FC(P(temp_v0_6, 0x178));
  new_var = func_8004240C(1);
  currentCamera = new_var;
  new_var4 = 0x178;
  currentCamera = func_8004240C(3);
  temp_v1_3 = func_8001BD1C();
  D_800A1584 = -90.0f;
  D_800A158C += 4.0f;
  func_8001C1A8(&D_800A1584, &D_800A159C);
  D_800A15D0 = 80.0f;
  func_80010BFC(temp_v1_3, currentCamera + 0x38, &D_800A159C);
  func_800061FC(temp_s7_2, temp_v1_3);
  new_var = P(temp_s7_2, 0x14);
  P(temp_s7_2, 0x14) = (void *) (new_var + 8);
  W(new_var, 0x0) = 0xFB000000;
  W(new_var, 0x4) = -1;
  func_8004D1A8(P(currentCamera, new_var4), 0, 4.0f, 0, 0xFF);
  if (D_800C5E50 == (-1))
  {
    void *__repair_cached_pointer = D_800A1468;
    var_s0 = 0;
    func_8001E3A8(B(__repair_cached_pointer, 0x237));
    D_800C5E50 = (s32) B(D_800A1468, 0x237);
    D_800AFB40 = 0;
    D_800B5AF4 = (s32) B(D_800A1468, 0x237);
    loop_2:
    if (func_80084DD4(var_s0 & 0xFF) != 0)
    {
      temp_v0_9 = (var_s0 * 2) + D_800A1B70;
      {
        u16 x = U(temp_v0_9, 0x4c);
        u16 y = U(temp_v0_9, 0x44);
        u16 z = U(temp_v0_9, 0x54);
        U(temp_v0_9, 0x4c) = x & 0x7fff;
        U(temp_v0_9, 0x44) = y & 0x7fff;
        U(temp_v0_9, 0x54) = z & 0x7fff;
      }
    }

    var_s0 += 1;
    if ((var_s0 - 1) < (4 - 1))
    {
      goto loop_2;
    }
    goto block_14;
  }
  temp_v1_3 = B(D_800A1468, 0x237);
  if (D_800C5E50 != temp_v1_3)
  {
    if (D_800B5AF4 != temp_v1_3)
    {
      D_800B5AF4 = (s32) temp_v1_3;
      D_800AFB40 = 0;
    }
    temp_v0_10 = D_800AFB40 + 1;
    D_800AFB40 = temp_v0_10;
    var_s0_2 = 0;
    if (temp_v0_10 >= 0xD)
    {
      func_80015C74(D_800A73E0 + 0x6BD0, 0);
      var_s0_2 = 0;
      func_8001E3A8(B(D_800A1468, 0x237));
      D_800AFB40 = 0;
      D_800C5E50 = (s32) B(D_800A1468, 0x237);
    }
    do
    {
      if (func_80084DD4(var_s0_2 & 0xFF) != 0)
      {
        temp_v0_11 = (var_s0_2 * 2) + D_800A1B70;
        {
          u16 x = U(temp_v0_11, 0x4c);
          u16 y = U(temp_v0_11, 0x44);
          u16 z = U(temp_v0_11, 0x54);
          U(temp_v0_11, 0x4c) = x & 0x7fff;
          U(temp_v0_11, 0x44) = y & 0x7fff;
          U(temp_v0_11, 0x54) = z & 0x7fff;
        }
      }
      var_s0_2 += 1;
    }
    while ((var_s0_2 + 1) <= 4);
    block_14:
    if (D_800C5E50 == B(D_800A1468, 0x237))
    {
      goto block_15;
    }

    temp_v0_12 = D_800AFA68 - 0x32;
    if (D_800AFA68 > 0)
    {
      D_800AFA68 = temp_v0_12;
      if (temp_v0_12 < 0)
      {
        D_800AFA68 = 0;
      }
    }
  }
  else
  {
    block_15:
    temp_v0_13 = D_800AFA68 + 0x32;

    D_800AFA68 = temp_v0_13;
    var_s0_3 = 0;
    if (temp_v0_13 < 0x100)
    {
      loop_17:
      if (func_80084DD4(var_s0_3 & 0xFF) != 0)
      {
        temp_v0_14 = (var_s0_3 * 2) + (*new_var);
        {
          u16 x = U(temp_v0_14, 0x4c);
          u16 y = U(temp_v0_14, 0x44);
          u16 z = U(temp_v0_14, 0x54);
          U(temp_v0_14, 0x4c) = x & 0x7fff;
          U(temp_v0_14, 0x44) = y & 0x7fff;
          U(temp_v0_14, 0x54) = z & 0x7fff;
        }
      }

      var_s0_3 += 1;
      if (var_s0_3 < 4)
      {
        goto loop_17;
      }
    }
    else
    {
      D_800AFA68 = 0xFF;
    }
  }
  func_80017B38(D_800A73E0 + 0x6C0C, 0, temp_s7_2, new_var + 0x38);
}
