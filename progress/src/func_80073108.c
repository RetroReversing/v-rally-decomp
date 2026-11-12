typedef struct 
{
  unsigned char pad[6];
  u16 x;
  u16 y;
} Pt;
typedef struct 
{
  unsigned char pad[4];
  void *base;
} PtList;
extern u32 D_800A1748;
void *gfx_get_dl(void);
void gfx_set_dl(s32, void *);
void gfx_round_vtx_pos(s32);
s32 gfx_add_quad_tris(s32);
void texture_build_dl(s32, void *, s32);
void gfx_set_quad_pos(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void gfx_set_quad_uv(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void gfx_set_quad_colors_shared_alpha(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* Draws the quad for entry idx of list, offset by (ox, oy): the quad spans from the origin to the
 * entry's x/y. Pushes a DL call to D_800A1748, then the quad, its outline and a fill with
 * colour 0x50 and alpha 0x7D. */
void func_80073108(s32 ctx, s16 ox, s16 oy, PtList *list, u8 idx)
{
  s32 temp_s0;
  s32 temp_s5;
  void *temp_v0;
  temp_v0 = gfx_get_dl();
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((u8 *) temp_v0) + 4)) = &D_800A1748;
  gfx_set_dl(ctx, ((u8 *) temp_v0) + 8);
  temp_s0 = idx * 4;
  texture_build_dl(ctx, *((void **) (((u8 *) list->base) + (idx * 4))), 0);
  temp_s5 = gfx_add_quad_tris(ctx) & 0xffff;
  gfx_set_quad_pos(ctx, temp_s5, ox, oy, 0, (s16) (ox + ((Pt *) (*((void **) (((u8 *) list->base) + (idx * 4)))))->x), oy, 0, (s16) (ox + ((Pt *) (
#ifdef PORT
*((void **) (((u8 *) list->base) + temp_s0))
#else
*((void **) (temp_s0 + (int)list->base))
#endif
))->x), (s16) (oy + ((Pt *) (*((void **) (((u8 *) list->base) + (idx * 4)))))->y), 0, ox, (s16) (oy + ((Pt *) (*((void **) (((u8 *) list->base) + (idx * 4)))))->y), 0);
  gfx_set_quad_uv(ctx, temp_s5, 0, 0, ((Pt *) (*((void **) (((u8 *) list->base) + (idx * 4)))))->x, 0, ((Pt *) (*((void **) (((u8 *) list->base) + (idx * 4)))))->x, ((Pt *) (*((void **) (((u8 *) list->base) + (idx * 4)))))->y, 0, ((Pt *) (*((void **) (((u8 *) list->base) + (idx * 4)))))->y);
  gfx_set_quad_colors_shared_alpha(ctx, temp_s5, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x7d);
  gfx_round_vtx_pos(ctx);
}
