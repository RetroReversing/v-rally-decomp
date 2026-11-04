#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { s16 x; s16 y; s16 w; s16 h; } Rect5500;
typedef struct { s16 x0; s16 y0; s16 x1; s16 y1; Rect5500 r; u8 pad10[0xC]; void *vp; } View5500;
typedef struct { s16 pad[2]; s16 w; s16 h; } Screen5500;
typedef struct { u32 w0; u32 w1; } Gfx5500;
s32 func_800056FC(void *);
Gfx5500 *func_80006008(s32);
void func_80006014(s32, Gfx5500 *);
void func_8000DEF0(void *, Rect5500 *);
u32 osVirtualToPhysical(void *);
extern Screen5500 *D_8009B5A4;
void func_80005500(void *vv, Rect5500 *r)
{
  View5500 *v = vv;
  s32 ctx;
  Gfx5500 *gdl;
  View5500 *new_var;
  Gfx5500 *g;
  s32 t;
  s32 __repair_phase_t;
  ctx = func_800056FC(v);
  gdl = func_80006008(ctx);
  v->r.x = r->x;
  v->r.y = r->y;
  v->r.w = r->w;
  v->r.h = r->h;
  t = v->r.x;
  if (v->r.x >= 0)
  {
    v->x0 = v->r.x;
    if ((t + v->r.w) <= D_8009B5A4->w)
    {
      v->x1 = v->x0 + v->r.w;
    }
  }
  else
  {
    v->x1 = v->r.w + v->r.x;
  }
  new_var = v;
  __repair_phase_t = v->r.y;
  if (v->r.y >= 0)
  {
    v->y0 = v->r.y;
    if ((__repair_phase_t + v->r.h) <= D_8009B5A4->h)
    {
      v->y1 = v->y0 + v->r.h;
    }
  }
  else
  {
    new_var->y1 = v->r.w + v->r.y;
  }
  func_8000DEF0(v->vp, r);
  g = gdl++;
  g->w0 = 0xDC080008;
  g->w1 = osVirtualToPhysical(v->vp);
  {
  Gfx5500 *g;
  g = gdl++;
  g->w0 = (0xED000000 | ((((s32) (((f32) v->x0) * 4.0f)) & 0xFFF) << 12)) | (((s32) (((f32) v->y0) * 4.0f)) & 0xFFF);
  g->w1 = ((((s32) (((f32) v->x1) * 4.0f)) & 0xFFF) << 12) | (((s32) (((f32) v->y1) * 4.0f)) & 0xFFF);
  }
  func_80006014(ctx, gdl);
}
