#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern f32 D_8009CEC0[3];
extern f32 D_8009CEC4;
extern s32 D_8009FF30;
extern u8 D_800C7926;
typedef struct { u16 idx; u16 c; u16 a; u16 b; } Vtx8;
typedef struct { Vtx8 *v; u16 count; u16 type; } Ent;
typedef struct { u8 r, g, b, a; s16 x, y, z; u8 pad[0x12 - 0xA]; u16 c; s16 a2; s16 b2; } Out;
typedef struct { u8 pad[0xC]; s16 *pos; u8 pad2[0x14 - 0x10]; Ent *ents; } Mdl;
typedef struct { u8 pad[0x10]; s16 *ys; u8 *cols; Mdl *mdl; u16 n; } Obj;
void func_8005639C(Out **out, Obj *arg)
{
  s32 n;
  s32 i;
  u8 color;
  u8 c;
  Ent *e;
  Vtx8 *p;
  n = arg->n;
  e = arg->mdl->ents;
  color = 0x8c;
  if (D_800C7926 == 0)
    color = 0x32;
  if (n != 0) {
    for (i = 0; i < n; e++, i++) {
      if (e->type == 0x23) {
        n = e->count;
        p = e->v;
        for (i = 0; i < n; p++, i++) {
          (*out)->x = arg->mdl->pos[p->idx * 2] * D_8009CEC0[0];
          (*out)->z = arg->mdl->pos[p->idx * 2 + 1] * D_8009CEC0[2];
          (*out)->y = arg->ys[p->idx] * D_8009CEC0[1];
          if (D_8009FF30 != 2) {
            u8 t = arg->cols[p->idx];
            c = t;
          } else
            c = color;
          (*out)->r = c;
          (*out)->g = c;
          (*out)->b = c;
          (*out)->a = 15;
          (*out)->a2 = (u32)(p->a * D_8009CEC0[0]);
          (*out)->b2 = (u32)(p->b * D_8009CEC4);
          (*out)->c = p->c;
          (*out)++;
        }
      }
    }
  }
}
