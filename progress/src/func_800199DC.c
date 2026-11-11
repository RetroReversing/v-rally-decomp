typedef struct SpriteRec
{
  u8 pad00[4];
  s16 x;
  s16 y;
  s16 z;
  u8 pad0A[0x14 - 0xA];
  u16 scale;
  u16 height;
} SpriteRec;
typedef struct SpriteScale
{
  u8 pad00[0x110];
  f32 width;
  u8 pad114[4];
  f32 depth;
} SpriteScale;
typedef struct SpriteCtx
{
  u8 pad00[0x14];
  void *dl;
} SpriteCtx;

s32 dl_reserve_vertices();
s32 gfx_set_quad_pos();

/* Emits one textured sprite quad: sizes it from the object's scale, loads its
 * texture tile into the display list, writes the four corner vertices, then
 * adds the two triangle words. Returns the tile index. */
s32 func_800199DC(void *ctx_arg, void *obj_arg, void *rec_arg)
{
  SpriteCtx *ctx = ctx_arg;
  SpriteScale *obj = obj_arg;
  SpriteRec *rec = rec_arg;
  SpriteRec *rec_copy;
  f32 size[3];
  s32 tile;
  s16 z_lo;
  void *dl;
  s32 slot;
  s32 slot_hi;
  s32 tile_flags;

  size[0] = ((obj->width) * ((f32) (rec->scale))) * 0.5f;
  tile_flags = 4;
  size[2] = ((obj->depth) * ((f32) (rec->scale))) * 0.5f;
  size[1] = (f32) (rec->height);
  tile = dl_reserve_vertices(ctx, tile_flags);
  tile = tile & 0xffff;
  obj_arg = obj_arg;
  rec_copy = rec;
  z_lo = (s16) ((s32) (((f32) (rec->z)) - size[2]));
  gfx_set_quad_pos(ctx, tile, (s16) ((s32) (((f32) (rec->x)) - size[0])), rec->y, (s32) z_lo, (s32) ((s16) ((s32) (((f32) (rec->x)) - size[0]))), (s32) ((s16) (((u16) (rec->y)) - (rec->height))), (s32) ((s16) ((s32) (((f32) (rec->z)) - size[2]))), (s32) ((s16) ((s32) (((f32) (rec->x)) + size[0]))), (s32) ((s16) (((u16) (rec->y)) - (rec->height))), (s32) ((s16) ((s32) (((f32) (rec->z)) + size[2]))), (s32) ((s16) ((s32) (((f32) (rec->x)) + size[0]))), rec->y, (s32) ((s16) ((s32) (((f32) (rec_copy->z)) + size[2]))));
  dl = ctx->dl;
  slot = tile & 31;
  slot_hi = slot << 17;
  ctx->dl = dl + 8;
  *((s32 *) dl) = ((slot_hi | ((slot + 1) << 9)) | ((u8)((slot + 2) * 2))) | 0x07000000;
  *((s32 *) (((char *) dl) + 4)) = (slot_hi | (((u8)((slot + 2) * 2)) << 8)) | ((slot + 3) * 2);
  return tile;
}
