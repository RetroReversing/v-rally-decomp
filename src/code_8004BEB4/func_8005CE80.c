#include "snapshot31_verified.h"

extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 *D_800C35A0;
extern u8 *D_800A1468;
extern u16 D_800A1504[];
extern u16 D_800A150C[];
extern u16 D_800A1514[];
extern u16 D_800A1520[];
extern u16 D_800A1528;
extern u16 D_800A152A;
extern u16 D_800A152C;
extern s32 D_800A1538[];
extern u8 D_800A5408[];
extern void func_8004D31C(void);
extern s32 func_8006204C(u8, u8, u8);
extern u8 *func_800592D0(s32);
extern void func_80047CC0(s32);
extern u8 *func_8004240C(s32);
extern void func_80047C2C(s32, s32);
extern void func_80081540(void *);
extern void func_8004C7F0(void *);
static inline u8 inline_fn(int arg0)
{
  return D_800AE850[arg0];
}

void func_8005CE80(void)
{
  s32 color;
  u8 *slot;
  {
    u8 *t;
    func_8004D31C();
    t = D_800C35A0;
    color = func_8006204C(t[0x1F], t[0x21], t[0x23]);
  }
  slot = func_800592D0(4);
  *((u16 *) (slot + 4)) = D_800A1504[color & 0xFF];
  slot = func_800592D0(0xA);
  *((u16 *) (slot + 4)) = D_800A150C[inline_fn((D_800C35A0[0x2E] * 0x1C) + 0x1300)];
  slot = func_800592D0(6);
  *((u16 *) (slot + 4)) = D_800A1514[inline_fn((D_800C35A0[0x2E] * 0x1C) + 0x1301)];
  slot = func_800592D0(8);
  *((u16 *) (slot + 4)) = D_800A1520[inline_fn((D_800C35A0[0x2E] * 0x1C) + 0x1302)];
  slot = func_800592D0(0xC);
  if ((*((f32 *) ((D_800AE850 + (D_800C35A0[0x2E] * 0x1C)) + 0x1304))) <= 118.0f)
  {
    *((u16 *) (slot + 4)) = D_800A1528;
  }
  else
    if ((*((f32 *) ((D_800AE850 + (D_800C35A0[0x2E] * 0x1C)) + 0x1304))) <= 132.0f)
  {
    *((u16 *) (slot + 4)) = D_800A152A;
  }
  else
  {
    *((u16 *) (slot + 4)) = D_800A152C;
  }
  func_80047CC0(D_800A1538[color & 0xFF]);
  func_80047C2C(*((s32 *) (func_8004240C(0) + 0x178)), 0);
  func_80081540(D_800A5408);
  func_8004C7F0((D_800AE850 + (D_800C35A0[0x2E] * 0x1C)) + 0x130C);
  slot = func_800592D0(0x10);
  *((f32 *) (D_800C02AE + 0x6A4A)) = *((f32 *) (slot + 0x10));
  D_800A1468[0x2BD] = 1;
}
