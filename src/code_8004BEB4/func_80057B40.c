#include "decompdecomp_snapshot_80057b40.h"
#line 1 "func.c"
typedef struct { s16 pad0; s16 idx; s32 pad4[3]; u8 *tbl; } Hdr;
typedef struct { void *next; s16 x; u16 y; u8 a; u8 b; u8 c; u8 pad; } Node;
typedef struct { s32 pad0; u16 id; s16 pad6; s16 pad8; s8 k; s8 padb; s32 padc; s32 v; } RecA;
typedef struct { s32 pad0; s32 pad4; u16 id; s16 pada; s16 padc; s8 k; s8 padf; s32 pad10; s32 v; } RecB;
s32 func_8000C9B0(u8 *, s32, u8, s32, s32);
s32 func_80057918(s32, u16);void *func_800592AC(u32);void *func_800592D0(u32);
Node *func_8007EAA0(s32, s32);
extern u8 *D_800A1468;
extern char D_800C02AE[];
void func_80057B40(s32 arg0, u16 arg1, u8 arg2, u8 arg3)
{
  Node *node;
  Hdr *h;
  RecA *a;
  RecB *b;
  u16 base;
  s16 max;
  s8 i;
  s16 r;
  u8 *e;

  node = func_8007EAA0(1, 0xC);
  h = *(Hdr **)(D_800C02AE + 0x325A);
  base = arg0 - h->tbl[h->idx * 20 + 0xD];
  max = 0;
  node->b = arg3;
  node->y = arg1;
  node->a = arg2;
  node->x = base;
  if (arg3 != 0) {
    a = func_800592D0((u8)(arg2));
    for (i = 0; i < arg3; i++) {
      s32 t = func_80057918(*(s32 *)(D_800C02AE + 0x807A), a->id);
      e = D_800A1468 + a->k * 2;
      r = func_8000C9B0(D_800A1468 + (e[0xD0] * 4 + 0xE4), t, e[0xD1], a->v, 0);
      if (r > max) max = r;
    }
  }
  b = func_800592AC((u16)(base));
  for (i = 0; i < arg1; i++) {
    s32 t = func_80057918(*(s32 *)(D_800C02AE + 0x807A), b->id);
    e = D_800A1468 + b->k * 2;
    r = func_8000C9B0(D_800A1468 + (e[0xD0] * 4 + 0xE4), t, e[0xD1], b->v, 0);
    if (r > max) max = r;
  }
  node->c = 0;
  if (*(void **)(D_800A1468 + 0x28) != 0) {
    *(void **)*(void **)(D_800A1468 + 0x28) = node;
  } else {
    *(void **)(D_800A1468 + 0x24) = node;
  }
  *(void **)(D_800A1468 + 0x28) = node;
  *(s32 *)(D_800A1468 + 0x2C) += 1;
}

