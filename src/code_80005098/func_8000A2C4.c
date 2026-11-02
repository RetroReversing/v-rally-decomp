#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { s16 a10; u16 a12; s16 a14; u16 a16; s16 a18; u16 a1A; s16 a1C; u16 a1E; } VpPart;
typedef struct { u8 pad[0x10]; s16 a10; u16 a12; s16 a14; u16 a16; s16 a18; u16 a1A; s16 a1C; u16 a1E; } Q;
typedef struct { s16 x; s16 y; s16 w; s16 h; u8 pad[0x24]; Q *p; } R;
s32 func_800056FC();
s32 func_80005C48(s32);
Gfx *func_80006008(s32);
void func_80006014(s32, Gfx *);
u32 osVirtualToPhysical(s32);
extern s16 *D_8009B5A4;
extern s32 D_8009B5A8;
extern s32 D_8009B5D0;
#define GW(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
#define SHL(v, s, w) (((u32)(v) & ((1 << (w)) - 1)) << (s))
#define SCISSOR(pkt, ulx, uly, lrx, lry) { Gfx *_g = (Gfx *)(pkt); \
  _g->w0 = SHL(0xED, 24, 8) | SHL((int)((float)(ulx) * 4.0F), 12, 12) | SHL((int)((float)(uly) * 4.0F), 0, 12); \
  _g->w1 = SHL(0, 24, 2) | SHL((int)((float)(lrx) * 4.0F), 12, 12) | SHL((int)((float)(lry) * 4.0F), 0, 12); }
void func_8000A2C4(R *a, s32 arg1, s32 arg2, u8 arg3)
{
  Q *q;
  s32 v;
  s32 t;
  Gfx *g;
  q = a->p;
  v = func_800056FC();
  g = func_80006008(v);
  t = func_80005C48(D_8009B5A8);
  GW(g++, 0xDE000000, (u32)&D_8009B5D0);
  GW(g++, 0xFF100000 | ((D_8009B5A4[2] - 1) & 0xFFF), osVirtualToPhysical(t));
  if (!arg3)
  {
    a->p->a10 = 0;
    a->p->a18 = 0;
    a->p->a14 = arg1 * 4;
    a->p->a1C = arg2 * 4;
    a->p->a16 = a->p->a12;
    a->p->a1E = a->p->a1A;
    SCISSOR(g++, a->x, a->y, a->w, a->h);
  }
  else
  {
    a->p->a10 = 0;
    a->p->a18 = 0;
    SCISSOR(g++, a->x, a->y, a->w + 8, a->h);
  }
  GW(g++, 0xE200001C, 0);
  GW(g++, 0xE3000A01, 0x200000);
  GW(g++, 0xE3001001, 0x8000);
  GW(g++, 0x05000017, (u32)q + 0x38);
  GW(g++, 0xE7000000, 0);
  GW(g++, 0x0A000000, (u32)q + 0x10);
  GW(g++, 0xE7000000, 0);
  GW(g++, 0xE3000A01, 0);
  func_80006014(v, g);
}

