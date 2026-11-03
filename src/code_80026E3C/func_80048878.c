#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 pad[8]; u16 n; } FrmB;
typedef struct { FrmB *f; } Anim0B;
typedef struct { u8 pad[4]; Anim0B *a; } AnimB;
typedef struct { u8 pad[0xC]; AnimB *anim; } ItemB;
typedef struct { u8 pad[0xA]; s16 x; u8 padC[2]; s16 y; } BoxB;
typedef struct { u8 pad[0x178]; BoxB *box; } ObjB;
typedef struct {
  u8 pad0[0xC];
  u8 sub0[4];
  u16 ang;
  u8 pad12[2];
  s32 dang;
  s32 x18;
  u8 pad1C[0x14];
  ItemB *i30;
  u8 pad34[0x10];
  u8 sub1[4];
  s16 ang2;
  u8 pad4A[0x1E];
  ItemB *i68;
  u8 pad6C[0x10];
  s32 x7C;
} SprB;
void func_80048394(void *, void *, void *, s32, s32);
void func_800485F8(s32, s32, void *, void *);
void func_80048878(ObjB *obj, SprB *s)
{
  s16 a;
  s32 d;
  s32 w1;
  s32 w0;
  s32 n;
  void *p;

  a = s->ang + s->dang;
  if (a < 0) a += 0x1000;
  a = (a * 0x600) / 0x1000;
  s->ang = a;
  s->ang2 = a;
  d = -s->x7C - s->x18;
  w0 = s->i68->anim->a->f->n;
  w1 = s->i30->anim->a->f->n;
  p = s->sub0;
  func_80048394(s, p, obj, obj->box->x + d, 0);
  if (d != 0)
    func_800485F8(obj->box->x, d, p, obj);
  {
    void *q = s->sub1;
    func_80048394(s, q, obj, obj->box->x + d + w1, 0);
    n = d + w1 + w0;
    if (n < 0) n = 0;
    func_800485F8(obj->box->x + n, obj->box->y, q, obj);
  }
}

