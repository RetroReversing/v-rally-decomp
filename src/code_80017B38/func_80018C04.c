#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern u8 D_800C7926;
extern s16 D_800B5B50;
extern s32 D_8009D538;
extern char *D_800C7F84;
s32 func_8001FEE8();
typedef struct { u8 pad[0x10]; s32 x0; s32 p14; s32 x1; s32 p1c; s32 z0; s32 z1; u8 p28[8]; } Box;
typedef struct { Box *boxes; u16 n; } BoxList;
typedef struct { u8 pad[0xE0]; f32 x; f32 y; f32 z; } Pos;

Box *func_80018C04(BoxList *l, Pos *p, Box *b)
{
  char pad[8];
  s32 i;
  s32 n;
  Box *q;

  if (b != NULL && !(p->x < b->x0) && !(b->x1 < p->x) && !(p->z < b->z0) && !(b->z1 < p->z)) {
    if ((func_8001FEE8(*(s32 *)(D_800C7F84 + 0x24)) < 50 && D_800C7926 == 0) || (D_8009D538 & 0x800)) {
      D_800B5B50 = 0;
    }
    return b;
  }
  n = l->n;
  D_800B5B50 = 0;
  i = 0;
  if (n > 0) {
    q = l->boxes;
    do {
      if (!(p->x < q[i].x0) && !(q[i].x1 < p->x) && !(p->z < q[i].z0) && !(q[i].z1 < p->z)) return &q[i];
      i++;
    } while (i < n);
  }
  return NULL;
}
