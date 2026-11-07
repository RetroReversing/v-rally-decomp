#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern void *D_800B7334;
extern s32 D_800B7320;
extern s32 D_800B731C;

extern s32 D_800B7300;
extern s32 D_800B7308;
typedef struct VRTransferArgs
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
  s32 f;
} VRTransferArgs;
extern VRTransferArgs D_800B0BA8;
void func_80081040(s32, s32, u32, VRTransferArgs);
s32 func_800817A0(void *, s32);
s32 func_80081C30(void);
s32 func_80081D50(s32);
typedef struct VRLoadState
{
  s32 x0;
  s32 x4;
  s32 x8;
  u8 padC[0x10];
  s32 x1C;
  u8 pad20[0x10];
  u16 x30;
  u16 x32;
  s32 x34;
  s32 x38;
  u8 pad3C[0x24];
  s32 x60;
} VRLoadState;
extern VRLoadState D_800C3338[];
typedef struct VREntry
{
  u8 pad0[0x10];
  s32 x10;
  s32 x14;
  u16 x18;
  u16 x1A;
  s32 x1C;
  s32 x20;
  s32 x24;
  s32 x28;
} VREntry;
static inline static VRLoadState *getState(void *q)
{
  VRLoadState *p;
  int k = 0;
  if (q)
    p = D_800C3338;
  else
    p = D_800C3338 + k;
  return p;
}

s32 func_8008188C(s32 arg0, s32 arg1)
{
  VREntry *e;
  VRLoadState *s;
  s32 *new_var;
  e = (VREntry *)func_800817A0(*((void **) 0x800B7308), arg0);
  s = getState(e);
  do
  {
    func_80081040((*((s32 *) 0x800B7300)) + e->x1C, D_800C3338[0].x0, 0x2000, D_800B0BA8);
    s = getState(e);
    s->x38 = e->x10;
    s->x34 = e->x14;
    s->x32 = e->x1A;
    s->x30 = e->x18;
  }
  while (0);
  do
  {
    s->x4 = e->x28;
    s->x8 = e->x24;
  }
  while (0);
  new_var = &e->x20;
  do
  {
    *((s32 *) 0x800B731C) = e->x14;
    (*((s32 **) 0x800B7334))[0] = *new_var;
  }
  while (0);
  do
  {
    ((s32 *) D_800B7334)[1] = e->x14;
    *((s32 *) 0x800B7320) = e->x10;
  }
  while (0);
  s->x1C = e->x1C;
  func_80081D50(arg1);
  func_80081C30();
  return s->x60;
}


