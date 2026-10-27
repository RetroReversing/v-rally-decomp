#include "common.h"

#define C (*(C02 *)(D_800C02AE+2))
#define O (C.o)
#define I(n) (*(s32 *)(D_800C02AE+(n)))
#define F(n) (*(f32 *)(D_800C02AE+(n)))
typedef struct 
{
  u8 p[0x12];
  u16 x12;
  u8 q[2];
  u16 x16;
  u8 r[0x14];
  u16 x2c;
  u8 t[0x22];
  u16 x50;
} Obj;
typedef struct 
{
  u8 p[0x32a6];
  u16 a;
  s32 b;
  u8 q[0x44];
  Obj *o;
  u8 r[0x38];
  f32 f;
  f32 g;
  u8 t[4];
  f32 h;
} C02;
extern u8 D_800C02AE[];
extern u8 D_800AE850[];
extern u8 *D_800A1468;
extern u8 D_800A14E0;
extern u8 D_800A14E1;
extern u8 D_800A14E2;
void func_8004D31C();
void func_8005EA28();
void func_800592F4(s32, s32);
void func_8005EE50(s32, s16, s32);
void func_80057D5C(s32, s32, s32, s32);
void *func_8005A744(s32, s32);
void func_8008A104(s32, s32, s32, s32);
void func_8005EB48(void)
{
  s32 a;
  s32 b;
  int new_var;
  s32 c;
  s32 x;
  u8 *p;
  func_8004D31C();
  func_8005EA28();
  func_800592F4(10, O->x16);
  func_800592F4(16, C.a & 1);
  func_800592F4(11, O->x12 & 1);
  func_8005EE50(12, (s16) (F(0x3332) * 8.0f), 0);
  func_8005EE50(13, (s16) (F(0x333a) * 8.0f), 0);
  func_8005EE50(14, (s16) (F(0x332e) * 8.0f), 0);
  x = C.b;
  if (x)
  {
    func_800592F4(15, x - 1);
  }
  else
  {
    func_800592F4(15, 0);
  }
  new_var = 0;
  func_800592F4(17, O->x50 != new_var);
  if (!D_800A1468[0x245])
  {
    func_80057D5C(21, 22, 1, new_var);
  }
  D_800A1468[0x245] = 1;
  a = D_800AE850[0x2544] + D_800AE850[0x2545];
  b = D_800AE850[0x2546] + D_800AE850[0x2547];
  c = D_800AE850[0x2548];
  D_800A14E0 = a;
  D_800A14E1 = c;
  D_800A14E2 = b;
  if (((u8) a) == 100)
  {
    goto fail;
  }
  if (c == 100)
  {
    goto fail;
  }
  if (((u8) b) == 100)
  {
    goto fail;
  }
  if (O->x2c & 0x1000)
  {
    goto fail;
  }
  {
    func_8008A104(I(0x325a), 18, new_var, new_var);
    p = func_8005A744(8, *((s32 *) (D_800A1468 + 12)));
    p[15] = 80;
    p[16] = 80;
    p[17] = 80;
    return;
  }
  fail:
  func_8008A104(I(0x325a), 18, 1, 1);

}
