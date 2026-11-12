void *view_get_ctx_id();
s32 gfx_round_vtx_pos(void *);
s32 vertex_record_set_xy(void *, s32, s16, s16);
u16 gfx_add_quad_tris(void *);
s32 gfx_set_quad_colors(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80008770(void *, void *, u8, u16 *);
s32 func_80008C58(void *, s32, u16, s32);
extern s32 D_800A11B8;
typedef struct { u16 x; s16 y; u16 w; u16 h; } Rect8;

/* Draws a vertically shaded bar: the bar is cut into strips of height
 * bar->step (the last strip takes the remainder), each strip becomes a
 * textured quad at the position from `bounds`, and its two colours step from
 * the top pair (col_a, col_b) towards the bottom pair (col_c, col_d). With
 * `split` set the bar is drawn as two halves. Uses the display list of `ctx`. */
void draw_shaded_bar(void *ctx, void *bar, void *bounds, u8 tex, u8 col_a, u8 col_b, u8 col_c, u8 col_d, u8 split)
{
  Rect8 rect;
  u8 c0, c1, c2, c3;
  u16 n;
  s32 i;
  f32 scale, y0;
  s32 t;
  s32 v;
  s32 v0, v1, v2, v3;
  void *g;
  u32 *dl;
  g = view_get_ctx_id(ctx);
  dl = *(u32 **)((char *)g + 0x14);
  c0 = col_a;
  c1 = col_b;
#ifdef PORT
  *(u32 **)((char *)g + 0x14) = dl + 4;
  ((uintptr_t *)dl)[0] = 0xDE000000;
  ((uintptr_t *)dl)[1] = (uintptr_t)&D_800A11B8;
#else
  *(u32 **)((char *)g + 0x14) = dl + 2;
  dl[0] = 0xDE000000;
  dl[1] = (u32)&D_800A11B8;
#endif
  if (split == 0) n = *(u16 *)((char *)bar + 8);
  else n = *(u16 *)((char *)bar + 8) >> 1;
  scale = (f32)*(s16 *)((char *)bounds + 6) / (f32)n;
  for (i = 0; i < n; i += *(u16 *)((char *)bar + 0xC)) {
    rect.y = i;
    rect.w = *(u16 *)((char *)bar + 6);
    if (split != 0) rect.x = *(u16 *)((char *)bar + 6) >> 1;
    else rect.x = 0;
    if (i < n - *(u16 *)((char *)bar + 0xC)) {
      s32 a5, a4;
      a5 = col_b;
      rect.h = *(u16 *)((char *)bar + 0xC);
      c2 = (u32)((f32)(a5 * (n - (i + *(u16 *)((char *)bar + 0xC))) + col_c * (i + *(u16 *)((char *)bar + 0xC))) / (f32)n);
      a4 = col_a;
      c3 = (u32)((f32)(a4 * (n - (i + *(u16 *)((char *)bar + 0xC))) + col_d * (i + *(u16 *)((char *)bar + 0xC))) / (f32)n);
    } else {
      rect.h = (n - i) + 1;
      c2 = col_c;
      c3 = col_d;
    }
    func_80008770(g, bar, tex, &rect.x);
    v = gfx_add_quad_tris(g) & 0xFFFF;
    y0 = (f32)i * scale;
    v0 = v & 0xFFFF;
    vertex_record_set_xy(g, v0, *(s16 *)((char *)bounds + 0), (s16)(s32)((f32)*(s16 *)((char *)bounds + 2) + y0));
    v1 = (u16)(v + 1);
    vertex_record_set_xy(g, v1, (s16)((u16)*(s16 *)((char *)bounds + 0) + *(u16 *)((char *)bounds + 4)), (s16)(s32)((f32)*(s16 *)((char *)bounds + 2) + y0));
    v2 = (u16)(v + 2);
    vertex_record_set_xy(g, v2, (s16)((u16)*(s16 *)((char *)bounds + 0) + *(u16 *)((char *)bounds + 4)), (s16)(s32)((f32)*(s16 *)((char *)bounds + 2) + (f32)((s16)rect.h + i) * scale));
    v3 = (u16)(v + 3);
    vertex_record_set_xy(g, v3, *(s16 *)((char *)bounds + 0), (s16)(s32)((f32)*(s16 *)((char *)bounds + 2) + (f32)((s16)rect.h + i) * scale));
    gfx_set_quad_colors(g, v0, 0xFF, 0xFF, 0xFF, c0, 0xFF, 0xFF, 0xFF, c1, 0xFF, 0xFF, 0xFF, c2, 0xFF, 0xFF, 0xFF, c3);
    func_80008C58(g, v0, rect.x, 0);
    func_80008C58(g, v1, rect.w - 1, 0);
    func_80008C58(g, v2, rect.w - 1, (rect.h - 1) & 0xFFFF);
    func_80008C58(g, v3, rect.x, (rect.h - 1) & 0xFFFF);
    c0 = c3;
    c1 = c2;
  }
  gfx_round_vtx_pos(g);
}
