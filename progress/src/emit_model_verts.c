extern f32 vtx_scale[3];
extern f32 uv_scale;
extern s32 gShadeMode;
extern u8 g_dark_mode;
typedef struct { u16 idx; u16 c; u16 a; u16 b; } Vtx8;
typedef struct { Vtx8 *v; u16 count; u16 type; } Ent;
typedef struct { u8 r, g, b, a; s16 x, y, z; u8 pad[0x12 - 0xA]; u16 c; s16 a2; s16 b2; } Out;
typedef struct { u8 pad[0xC]; s16 *pos; u8 pad2[0x14 - 0x10]; Ent *ents; } Mdl;
typedef struct { u8 pad[0x10]; s16 *ys; u8 *cols; Mdl *mdl; u16 n; } Obj;

/* Writes the vertices of every type-0x23 entity in obj's model into the output buffer at *out,
 * scaled by vtx_scale and uv_scale, then advances *out past them. Colours come from obj->cols,
 * or from a fixed shade when the colour mode is 2. */
void emit_model_verts(Out **out, Obj *obj)
{
  s32 n;
  s32 i;
  u8 color;
  u8 c;
  Ent *e;
  Vtx8 *p;
  n = obj->n;
  e = obj->mdl->ents;
  color = 0x8c;
  if (g_dark_mode == 0)
    color = 0x32;
  if (n != 0) {
    for (i = 0; i < n; e++, i++) {
      if (e->type == 0x23) {
        n = e->count;
        p = e->v;
        for (i = 0; i < n; p++, i++) {
          (*out)->x = obj->mdl->pos[p->idx * 2] * vtx_scale[0];
          (*out)->z = obj->mdl->pos[p->idx * 2 + 1] * vtx_scale[2];
          (*out)->y = obj->ys[p->idx] * vtx_scale[1];
          if (gShadeMode != 2) {
            u8 t = obj->cols[p->idx];
            c = t;
          } else
            c = color;
          (*out)->r = c;
          (*out)->g = c;
          (*out)->b = c;
          (*out)->a = 15;
          (*out)->a2 = (u32)(p->a * vtx_scale[0]);
          (*out)->b2 = (u32)(p->b * uv_scale);
          (*out)->c = p->c;
          (*out)++;
        }
      }
    }
  }
}
