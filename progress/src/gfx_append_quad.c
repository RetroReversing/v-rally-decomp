typedef struct DisplayListCtx
{
  u8 pad00[0x14];
  u32 *dl;
  u8 pad18[0x70 - 0x18];
  s32 vtx_base;
  u8 pad74[0x78 - 0x74];
  u16 flags;
  u16 pos;
} DisplayListCtx;

u16 dl_reserve_vertices();

/* Appends a quad (two F3DEX triangles over four ring-buffer vertices) to the
 * display list. The first call also emits the render-mode setup and marks the
 * context as initialised in bit 0 of flags. Returns the first vertex slot. */
s32 gfx_append_quad(DisplayListCtx *ctx, s16 depth)
{
  s32 mode;
  u16 flags;
  u32 *cmd_a;
  u32 *cmd_b;
  u32 *cmd_c;
  u32 *cmd_d;
  u32 *cmd_e;
  u32 *cmd_f;
  u32 *tri;
  u32 *end;
  s32 slot;
  s32 a;
  s32 a_shl17;
  s32 a_index2;
  s32 n;

  mode = ctx->flags;
  flags = mode;
  if (!(flags & 1))
  {
    cmd_a = ctx->dl;
    ctx->flags = (u16) (flags | 1);
    ctx->dl = cmd_a + 2;
    cmd_a[0] = 0xE7000000;
    cmd_a[1] = 0;
    cmd_b = ctx->dl;
    ctx->dl = cmd_b + 2;
    cmd_b[0] = 0xE3000A01;
    cmd_b[1] = 0;
    cmd_c = ctx->dl;
    ctx->dl = cmd_c + 2;
    cmd_c[0] = 0xD7000000;
    cmd_c[1] = 0;
    mode = 0xFCFFFFFF;
    cmd_d = ctx->dl;
    ctx->dl = cmd_d + 2;
    cmd_d[0] = 0xFCFFFFFF;
    cmd_d[1] = 0xFFFE793C;
    cmd_e = ctx->dl;
    ctx->dl = cmd_e + 2;
    cmd_e[0] = 0xD9E0F9FA;
    cmd_e[1] = 0;
    cmd_f = ctx->dl;
    ctx->dl = cmd_f + 2;
    cmd_f[0] = 0xD9FFFFFF;
    cmd_f[1] = 0x200005;
  }
  slot = dl_reserve_vertices(ctx, 4, mode) & 0xFFFF;
  n = slot * 0x10;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 4)) = depth;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 0x14)) = depth;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 0x24)) = depth;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 0x34)) = depth;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 6)) = 0;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 0x16)) = 0;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 0x26)) = 0;
  *((s16 *) (((u8 *) (n + ctx->vtx_base)) + 0x36)) = 0;
  *((u8 *) (((u8 *) (n + ctx->vtx_base)) + 0xF)) = 0xFF;
  *((u8 *) (((u8 *) (n + ctx->vtx_base)) + 0x1F)) = 0xFF;
  *((u8 *) (((u8 *) (n + ctx->vtx_base)) + 0x2F)) = 0xFF;
  *((u8 *) (((u8 *) (n + ctx->vtx_base)) + 0x3F)) = 0xFF;
  a = slot & 0x1F;
  a_shl17 = a << 0x11;
  tri = ctx->dl;
  a_index2 = a_shl17 | ((a + 1) << 9);
  n = a + 2;
  n = n * 2;
  ctx->dl = tri + 2;
  tri[0] = (u32) ((a_index2 | n) | 0x07000000);
  tri[1] = (u32) ((a_shl17 | (n << 8)) | ((a + 3) * 2));
  end = ctx->dl;
  ctx->dl = end + 2;
  end[0] = 0xE7000000;
  end[1] = 0;
  return slot;
}
