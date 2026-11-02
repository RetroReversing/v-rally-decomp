#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define CMD(a,b) {u32 *g=p; p+=2; g[0]=(a);g[1]=(b);}
void *func_80006008(s32);
s32 func_80006014(s32, void *);
s32 func_800061FC(s32, s32);
s32 func_800068C0(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80006CF8(s32, s32);
s32 func_800072F4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80010BFC(s32, void *, void *);
s32 func_8001BD1C();
s32 guMtxIdentF(void *);
extern u8 *D_800C7F84;
void func_8003737C(s32 arg0)
{
  f32 mtx[4][4];
  f32 pos[3];
  f32 x;
  s32 m;
  s32 col;
  u8 *s;
  s = *((u8 **) (D_800C7F84 + 0x178));
  guMtxIdentF(mtx);
  m = func_8001BD1C();
  mtx[3][0] = *((f32 *) (D_800C7F84 + 0x118));
  mtx[3][1] = *((f32 *) (D_800C7F84 + 0x11C));
  mtx[3][2] = *((f32 *) (D_800C7F84 + 0x120));
  func_80010BFC(m, D_800C7F84 + 0x38, mtx);
  {
    u32 *p = func_80006008(arg0);
    CMD(0xE7000000, 0);
    CMD(0xE3000A01, 0x100000);
    CMD(0xE200001C, 0x504240);
    CMD(0xFCFFFFFF, 0xFFFE793C);
    CMD(0xD9FFF9FF, 0);
    CMD(0xD9FFFFFF, 0x200004);
    func_80006014(arg0, p);
  }
  func_800061FC(arg0, m);
  col = func_80006CF8(arg0, 0) & 0xFFFF;
  pos[0] = x = *((f32 *) (D_800C7F84 + 0x148));
  pos[2] = *((f32 *) (D_800C7F84 + 0x150));
  func_800068C0(arg0, col,
    (s16) (-*((s16 *) (s + 0xC)) - x),
    (s16) (-*((u16 *) (s + 0xE))),
    (s16) (-200.0f - pos[2]),
    (s16) (*((s16 *) (s + 0xC)) - pos[0]),
    (s16) (-*((u16 *) (s + 0xE))),
    (s16) (-200.0f - pos[2]),
    (s16) (*((s16 *) (s + 0xC)) + pos[0]),
    (s16) (*((u16 *) (s + 0xE))),
    (s16) (pos[2] + -200.0f),
    (s16) (-*((s16 *) (s + 0xC)) + pos[0]),
    (s16) (*((u16 *) (s + 0xE))),
    (s16) (pos[2] + -200.0f));
  func_800072F4(arg0, col, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80);
}

