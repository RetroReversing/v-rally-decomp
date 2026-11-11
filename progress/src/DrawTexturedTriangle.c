extern u8 gOrderState[];
void func_80008CB8(void *, u16, u8, u8, s32);
void vtx_pool_set_uv(void *, u16, u8, u8);
void vtx_pool_add(void *, void *, s32, u16 *);
void gfx_set_texture(void *, s32, u8);
void gfx_add_tri1(void *, u16, u16, u16);
void gfx_sync_render_state(void *, s32);
typedef struct
{
  u8 w[4];
  s16 h;
} Elem6;

/* Draws one textured triangle: selects the material's texture (flagged in word
 * 0x84 of the display list), adds its three vertices from vtxTable (indices at
 * tri+0x10/0x12/0x14), sets their colours from tri+0..0xA and their UVs from
 * tri+0x18..0x1D, then emits the triangle. */
void DrawTexturedTriangle(void *gfx, u8 *tri, Elem6 *vtxTable)
{
  u16 out[3];
  Elem6 e[3];
  u8 *s0;
  u8 *v1;

  *((u32 *) (((u8 *) gfx) + 0x84)) = (*((u32 *) (((u8 *) gfx) + 0x84)) & 0xFCFFFFFF) | 0x1000000;
  s0 = tri;
  v1 = *((u8 **) (gOrderState + 0x237C)) + (*((u16 *) (s0 + 0x20))) * 0x14;
  gfx_set_texture(gfx, **((s32 **) (*((u8 **) (v1 + 0x10))) + 1), v1[0xF]);
  gfx_sync_render_state(gfx, 0);
  e[0] = vtxTable[*((u16 *) (s0 + 0x14))];
  e[1] = vtxTable[*((u16 *) (s0 + 0x10))];
  e[2] = vtxTable[*((u16 *) (s0 + 0x12))];
  vtx_pool_add(gfx, e, 3, out);
  func_80008CB8(gfx, out[0], s0[8], s0[9], s0[0xA]);
  func_80008CB8(gfx, out[1], s0[0], s0[1], s0[2]);
  func_80008CB8(gfx, out[2], s0[4], s0[5], s0[6]);
  vtx_pool_set_uv(gfx, out[0], s0[0x1C], s0[0x1D]);
  vtx_pool_set_uv(gfx, out[1], s0[0x18], s0[0x19]);
  vtx_pool_set_uv(gfx, out[2], s0[0x1A], s0[0x1B]);
  gfx_add_tri1(gfx, out[2], out[1], out[0]);
}
