#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Obj356
{
  s32 x;
  u16 mode;
  s8 b6;
  s8 b7;
  u32 n;
  s32 c;
  void *p;
  void *q;
  f32 f18;
  f32 f1c;
  f32 f20;
  f32 f24;
  f32 f28;
  f32 f2c;
  void *cb;
  void *cb2;
  f32 x38;
  f32 x3c;
  f32 x40;
} Obj356;
typedef struct
{
  char pad[0x118];
  f32 x;
  f32 y;
  f32 z;
} N356;
typedef struct
{
  char pad[0xE];
  u16 hE;
  char pad2[0xE];
  u16 h1E;
} R356;
extern s8 D_800C34D0;
extern u8 D_800C7926[];
#define D_800C7926 D_800C7926[0]
extern s32 D_8009FF30;
extern Obj356 *D_800C811C;
extern N356 *D_800C7F84;
extern R356 *D_800C35A0;
void *func_80034FF0(void *, s32);
void func_80035B04(void *);
void func_80036260(void *);
void func_80036C48(void *, Obj356 *);
N356 *func_8004240C(s32);
void *func_8007EAA0(s32, s32);
void func_80035C4C(void);
void func_80035F24(void);
void func_8003647C(void);
void func_8003678C(void);

void func_80035684(char *arg0)
{
  N356 *n;
  u32 cnt;
  u16 t;

  D_800C811C = func_8007EAA0(1, 0x44);
  D_800C811C->mode = D_8009FF30;
  n = func_8004240C(1);
  D_800C811C->f18 = n->x;
  D_800C811C->f18 = n->y;
  D_800C811C->f20 = n->z;
  D_800C811C->f24 = n->x;
  D_800C811C->f24 = n->y;
  D_800C811C->f2c = n->z;
  D_800C7F84 = n;
  D_800C34D0 = 0;
  switch (D_800C811C->mode)
  {
    case 0:
      D_800C811C->x = 0;
      D_800C811C->p = 0;
      D_800C811C->q = 0;
      if (D_800C7926 == 0)
      {
        D_800C811C->x38 = *(s32 *) (arg0 + 0x420);
        D_800C811C->x3c = (f32) -*(s32 *) (arg0 + 0x46C) * 0.1f;
        D_800C811C->x40 = *(s32 *) (arg0 + 0x4B8);
        func_80036C48(arg0, D_800C811C);
      }
      break;
    case 3:
      cnt = *(s32 *) (arg0 + 0xDC) - 50;
      D_800C811C->n = cnt;
      if ((u32) (D_800C7926 - 1) < 2 || (t = D_800C35A0->h1E) == 5 || (t != 0 && t < 5))
        D_800C811C->n = D_800C811C->n / 3;
      else if (D_800C7926 == 3)
        D_800C811C->n = cnt >> 2;
      D_800C811C->b7 = *(s32 *) (arg0 + 0x128);
      D_800C811C->cb = func_8003647C;
      D_800C811C->x = 0;
      D_800C811C->cb2 = func_8003678C;
      D_800C811C->p = func_8007EAA0(1, D_800C811C->n * 20);
      if (D_800C35A0->hE == 2)
      {
        D_800C811C->q = func_8007EAA0(1, D_800C811C->n * 20);
        func_80036260(D_800C811C->p);
        func_80036260(D_800C811C->q);
      }
      else
      {
        D_800C811C->q = 0;
        func_80036260(D_800C811C->p);
      }
      break;
    case 4:
      {
      u32 c4 = *(u32 *) (arg0 + 0x174);
      D_800C811C->n = c4;
      if ((u32) (D_800C7926 - 1) < 2)
        D_800C811C->n = c4 >> 1;
      else if (D_800C7926 == 3)
        D_800C811C->n = c4 >> 2;
      }
      D_800C811C->c = *(s32 *) (arg0 + 0x1C0);
      D_800C811C->b6 = *(s32 *) (arg0 + 0x20C);
      D_800C811C->b7 = *(s32 *) (arg0 + 0x258);
      D_800C811C->x = (s32) func_80034FF0(arg0 + 0x260, 0);
      D_800C811C->cb = func_80035C4C;
      D_800C811C->cb2 = func_80035F24;
      D_800C811C->p = func_8007EAA0(1, D_800C811C->n * 8);
      if (D_800C35A0->hE == 2)
      {
        D_800C811C->q = func_8007EAA0(1, D_800C811C->n * 8);
        func_80035B04(D_800C811C->p);
        func_80035B04(D_800C811C->q);
      }
      else
      {
        D_800C811C->q = 0;
        func_80035B04(D_800C811C->p);
      }
      break;
    default:
      D_800C811C->x = 0;
      D_800C811C->p = 0;
      D_800C811C->q = 0;
      break;
  }
}

