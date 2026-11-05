#include "decompdecomp_snapshot_800885cc.h"
#line 1 "func.c"
typedef struct {
s32 f0;
u8 pad4[8];
s32 fC;
u8 pad10[20];
f32 f24;
u8 pad28[44];
f32 f54;
f32 f58;
f32 f5C;
u8 pad60[8];
f32 f68;
u8 pad6C[8];
s32 f74;
u8 pad78[24];
s16 f90;
s16 f92;
s16 f94;
s16 f96;
u16 f98;
s16 f9A;
s16 f9C;
u8 pad9E[2];
s16 fA0;
u8 padA2[6];
s16 fA8;
u8 padAA[10];
u8 fB4;
u8 fB5;
u8 fB6;
u8 fB7;
u8 padB8[1];
u8 fB9;
u8 fBA;
u8 padBB[3];
u8 fBE;
u8 fBF;
u8 fC0;
u8 fC1;
u8 padC2[2];
u8 fC4;
u8 padC5[5];
u8 fCA;
u8 fCB;
} Obj;
extern s32 D_800B68EC;
extern s32 D_800C34D4;
void func_800885CC(u8 *arg)
{
  Obj *p;
  u8 save;
  u32 i;
  s16 v;
  s32 t;
  p = (Obj *)arg;
  save = p->fC1;
  p->f0 = 0;
  for (i = 0; i < 0x134; i++)
  {
    *(arg++) = 0;
  }

 p->f98 = 0xFFFF;
 p->fC4 = 0xFF;
 p->fB6 = 0xFF;
 p->f24 = 99.9f;
 p->f94 = p->fA0 = 0x6000 / D_800B68EC;
 p->fCA = 0;
 p->f92 = 1;
 p->fCB = 127;
 p->fB4 = 127;
 p->f68 = 2*(1.0/64.0);
 p->fB5 = 64;
 p->f9A = 1;
 p->f9C = 1;
 p->fC = -1;
 p->f96 = 0x80;
 p->fA8 = 0x80;
 p->f90 = 0x80;
 p->fB7 = 1;
 p->fBE = 1;
 p->f54 = 1.0f;
 p->fB9 = 127;
 p->fBF = 255;
 p->f58 = 1.0/255.0;
 p->fBA = 127;
 p->fC0 = 15;
 p->f5C = 1.0/15.0;
 p->f74 = D_800C34D4;
 p->fC1 = save;
}

