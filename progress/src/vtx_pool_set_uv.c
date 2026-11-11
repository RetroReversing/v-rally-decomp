/* Sets the texture coordinates of vertex `vtxIndex` in a pool owner. If the vertex
 * is flagged dirty (bit 1), its stored ST values are rewritten and the flag is
 * cleared. Otherwise a G_MODIFYVTX display-list command is emitted for the vertex. */
void vtx_pool_set_uv(char *pool, u16 vtxIndex, s32 s, s32 t)
{
  s32 idx;
  s32 *gfx;
  u32 w1;
  idx = vtxIndex & 0xffff;
  if (*(u16 *)(*(char **)(pool + 0x70) + idx * 16 + 6) & 2) {
    *(u16 *)(*(char **)(pool + 0x70) + idx * 16 + 6) &= 0xfffd;
    *(u16 *)(*(char **)(pool + 0x70) + idx * 16 + 8) = (u32)(s * *(u16 *)(pool + 0x8a)) >> 2;
    *(u16 *)(*(char **)(pool + 0x70) + idx * 16 + 10) = (u32)(t * *(u16 *)(pool + 0x88)) >> 2;
    return;
  }
  w1 = (s * *(u16 *)(pool + 0x8a)) << 13; w1 += (u32)(t * *(u16 *)(pool + 0x88)) >> 3;
  gfx = *(s32 **)(pool + 0x14);
  *(s32 **)(pool + 0x14) = gfx + 2;
  gfx[0] = 0x02140000 | ((idx & 31) << 1);
  gfx[1] = w1;
}
