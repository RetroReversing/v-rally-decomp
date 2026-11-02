#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
void *func_800056FC();
s32 func_80006298(void *);
s32 func_800067FC(void *, s32, s16, s16);
u16 func_800070CC(void *);
s32 func_80007404(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80008770(void *, void *, u8, u16 *);
s32 func_80008C58(void *, s32, u16, s32);
extern s32 D_800A11B8;
typedef struct { u16 x; s16 y; u16 w; u16 h; } Rect8;
void func_8004C98C(void *arg0, void *arg1, void *arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8)
{
  Rect8 rect;
  u8 c0, c1, c2, c3;
  u16 n;
  s32 i;
  f32 scale, y0;
  s32 t;
  s32 v;
  s32 v0, v1, v2, v3;
  void *g;
  u32 *dl;
  g = func_800056FC(arg0);
  dl = *(u32 **)((char *)g + 0x14);
  c0 = arg4;
  c1 = arg5;
  *(u32 **)((char *)g + 0x14) = dl + 2;
  dl[0] = 0xDE000000;
  dl[1] = (u32)&D_800A11B8;
  if (arg8 == 0) n = *(u16 *)((char *)arg1 + 8);
  else n = *(u16 *)((char *)arg1 + 8) >> 1;
  scale = (f32)*(s16 *)((char *)arg2 + 6) / (f32)n;
  for (i = 0; i < n; i += *(u16 *)((char *)arg1 + 0xC)) {
    rect.y = i;
    rect.w = *(u16 *)((char *)arg1 + 6);
    if (arg8 != 0) rect.x = *(u16 *)((char *)arg1 + 6) >> 1;
    else rect.x = 0;
    if (i < n - *(u16 *)((char *)arg1 + 0xC)) {
      s32 a5, a4;
      a5 = arg5;
      rect.h = *(u16 *)((char *)arg1 + 0xC);
      c2 = (u32)((f32)(a5 * (n - (i + *(u16 *)((char *)arg1 + 0xC))) + arg6 * (i + *(u16 *)((char *)arg1 + 0xC))) / (f32)n);
      a4 = arg4;
      c3 = (u32)((f32)(a4 * (n - (i + *(u16 *)((char *)arg1 + 0xC))) + arg7 * (i + *(u16 *)((char *)arg1 + 0xC))) / (f32)n);
    } else {
      rect.h = (n - i) + 1;
      c2 = arg6;
      c3 = arg7;
    }
    func_80008770(g, arg1, arg3, &rect.x);
    v = func_800070CC(g) & 0xFFFF;
    y0 = (f32)i * scale;
    v0 = v & 0xFFFF;
    func_800067FC(g, v0, *(s16 *)((char *)arg2 + 0), (s16)(s32)((f32)*(s16 *)((char *)arg2 + 2) + y0));
    v1 = (u16)(v + 1);
    func_800067FC(g, v1, (s16)((u16)*(s16 *)((char *)arg2 + 0) + *(u16 *)((char *)arg2 + 4)), (s16)(s32)((f32)*(s16 *)((char *)arg2 + 2) + y0));
    v2 = (u16)(v + 2);
    func_800067FC(g, v2, (s16)((u16)*(s16 *)((char *)arg2 + 0) + *(u16 *)((char *)arg2 + 4)), (s16)(s32)((f32)*(s16 *)((char *)arg2 + 2) + (f32)((s16)rect.h + i) * scale));
    v3 = (u16)(v + 3);
    func_800067FC(g, v3, *(s16 *)((char *)arg2 + 0), (s16)(s32)((f32)*(s16 *)((char *)arg2 + 2) + (f32)((s16)rect.h + i) * scale));
    func_80007404(g, v0, 0xFF, 0xFF, 0xFF, c0, 0xFF, 0xFF, 0xFF, c1, 0xFF, 0xFF, 0xFF, c2, 0xFF, 0xFF, 0xFF, c3);
    func_80008C58(g, v0, rect.x, 0);
    func_80008C58(g, v1, rect.w - 1, 0);
    func_80008C58(g, v2, rect.w - 1, (rect.h - 1) & 0xFFFF);
    func_80008C58(g, v3, rect.x, (rect.h - 1) & 0xFFFF);
    c0 = c3;
    c1 = c2;
  }
  func_80006298(g);
}
