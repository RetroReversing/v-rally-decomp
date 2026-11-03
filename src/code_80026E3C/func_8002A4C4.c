#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define W(p,o) (*(s32*)((u8*)(p)+(o)))
#define P(p,o) (*(u8**)((u8*)(p)+(o)))
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
extern void func_8002E688(s32 *, s32 *);
extern void func_8002E530(void *, void *, void *);
extern void func_8002DA98(void *, void *);
typedef struct 
{
  s32 w[8];
} Mat;
void func_8002A4C4(u8 *obj, s16 *point, s32 idx, s32 edge)
{
  s32 first = 0;
  s32 second = 0;
  s32 x;
  s32 z;
  s32 height;
  s32 slot;
  u8 *new_var;
  u8 *table;
  u8 *list;
  u8 *entry;
  s32 d[4];
  s16 rel[4];
  union 
  {
    s16 h[16];
    Mat m;
  } mat;
  Mat inv;
  s16 unused[4];
  new_var = P(P(obj, 0x8c), idx * 4);
  table = P(obj, 0x60);
  x = W(table, idx * 4);
  z = W(table, (idx * 4) + 0x30);
  switch (edge)
  {
    case -8:
      first = (H(new_var, 0x8a) * x) + z;
      second = first + 1;
      break;
    case -7:
      second = ((H(new_var, 0x8a) * x) + z) + H(new_var, 0x8a);
      first = second + 1;
      break;
    case -6:
      second = (H(new_var, 0x8a) * x) + z;
      first = second + H(new_var, 0x8a);
      break;
    case -5:
      first = ((H(new_var, 0x8a) * x) + z) + 1;
      second = first + H(new_var, 0x8a);
      break;
    case -4:
      { s32 base = H(new_var, 0x8a) * x + z;
      first = base + 1;
      second = base + H(new_var, 0x8a); }
      break;
    case -3:
      second = (H(new_var, 0x8a) * x) + z;
      first = (second + H(new_var, 0x8a)) + 1;
      break;
    case -2:
      first = (H(new_var, 0x8a) * (x + 1)) + z;
      second = (first - H(new_var, 0x8a)) + 1;
      break;
    case -1:
      first = (H(new_var, 0x8a) * x) + z;
      second = (first + H(new_var, 0x8a)) + 1;
      break;
  }
  d[0] = ((s16 *) P(new_var, 0x54))[second * 3] - ((s16 *) P(new_var, 0x54))[first * 3];
  d[1] = ((s16 *) P(new_var, 0x54))[(second * 3) + 1] - ((s16 *) P(new_var, 0x54))[(first * 3) + 1];
  d[2] = ((s16 *) P(new_var, 0x54))[(second * 3) + 2] - ((s16 *) P(new_var, 0x54))[(first * 3) + 2];
  switch (edge)
  {
    case -5:
      first = ((H(new_var, 0x8a) * (x + 1)) + z) + 1;
      break;
    case -6:
      first = (H(new_var, 0x8a) * (x + 1)) + z;
      break;
    case -7:
      first = (H(new_var, 0x8a) * x) + z;
      break;
    case -8:
      first = ((H(new_var, 0x8a) * x) + z) + 1;
      break;
  }
  func_8002E688(d, d);
  mat.h[0] = -d[0];
  mat.h[1] = 0;
  mat.h[2] = -d[2];
  mat.h[3] = -d[2];
  mat.h[4] = 0;
  mat.h[5] = d[0];
  mat.h[6] = 0;
  mat.h[7] = 4096;
  mat.h[8] = 0;
  rel[0] = point[0] - ((u16 *) P(new_var, 0x54))[first * 3];
  rel[1] = point[1] - ((u16 *) P(new_var, 0x54))[(first * 3) + 1];
  rel[2] = point[2] - ((u16 *) P(new_var, 0x54))[(first * 3) + 2];
  func_8002E530(&mat, rel, d);
  func_8002DA98(&mat, &inv);
  mat.m = inv;
  if ((height = d[1] << 4) > 0)
    goto L8C0;
  list = P(obj, 0x8c);
  slot = W(list, 0x334);
  list += 0x338;
  height = slot * 48;
  entry = (u8 *)(height + (u32)list);
  W(entry, 0x28) = d[1] << 4;
  W(entry, 0x24) = idx;
  W(entry, 0x20) = 0;
  *((Mat *) entry) = mat.m;
  W(entry, 0x2c) = 0;
  list = P(obj, 0x8c);
  W(list, 0x334)++;
L8C0:
  if (((((u32) (idx - 4)) < 2) || (idx == 10)) || (idx == 11))
  {
    slot = (idx == 4) * 2;
    if (idx == 5) { slot = 3; }
    if (idx == 10) { slot = 0; }
    if (idx == 11) { slot = 1; }
    W(P(obj, 0x8c), (slot * 20) + 0xb0) = point[0];
    W(P(obj, 0x8c), (slot * 20) + 0xb8) = point[2];
  }
}

