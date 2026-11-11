#define halfX sv[0]
#define halfZ sv[2]
u16 dl_reserve_vertices();
void gfx_set_quad_pos();
void func_80008B28();
typedef struct
{
  u8 pad[0x14];
  u32 *p;
} GfxCtx;
typedef struct
{
  u8 pad[2];
  u16 w;
  u16 h;
  s16 x;
  s16 y;
  s16 z;
} Rect3;

/* Emits one textured quad for the sprite `rect` (an object at `obj`'s scale):
 * builds its four corner vertices in the vertex buffer, sets the texture, then
 * writes two F3DEX triangle words into the display list in ctx, and a
 * texture-reset word. Returns the vertex slot used. */
s32 func_80019C90(GfxCtx *ctx, u8 *obj, Rect3 *rect, u16 px, u16 py)
{
  f32 sv[3];
  s32 s1;
  u32 a2;
  u32 a1;
  u8 v1;
  u32 *a3;
  halfX = ((*((f32 *) (obj + 0x110))) * ((f32) rect->w)) * 0.5f;
  halfZ = ((*((f32 *) (obj + 0x118))) * ((f32) rect->w)) * 0.5f;
  s1 = dl_reserve_vertices(ctx, 4) & 0xFFFF;
  gfx_set_quad_pos(ctx, s1, (s16) ((s32) (((f32) rect->x) - halfX)), rect->y, (s16) ((s32) (((f32) rect->z) - halfZ)), (s16) ((s32) (((f32) rect->x) - halfX)), (s16) (rect->y - rect->h), (s16) ((s32) (((f32) rect->z) - halfZ)), (s16) ((s32) (((f32) rect->x) + halfX)), (s16) (rect->y - rect->h), (s16) ((s32) (((f32) rect->z) + halfZ)), (s16) ((s32) (((f32) rect->x) + halfX)), rect->y, (s16) ((s32) (((f32) rect->z) + halfZ)));
  func_80008B28(ctx, s1, px, py, px, 0, 0, 0, 0, py);
  {
    u32 *g = ctx->p;
    a1 = s1 & 0x1F;
    ctx->p = g + 2;
    g[0] = ((((a1 * 2) & 0xFF) << 16) | ((((a1 + 1) * 2) & 0xFF) << 8) | (((a1 + 2) * 2) & 0xFF)) | (7 << 24);
    g[1] = (((a1 * 2) & 0xFF) << 16) | ((((a1 + 2) * 2) & 0xFF) << 8) | (((a1 + 3) * 2) & 0xFF);
  }
  {
    u32 *g = ctx->p;
    ctx->p = g + 2;
    g[0] = 0xE7000000;
    g[1] = 0;
  }
  return s1;
}
