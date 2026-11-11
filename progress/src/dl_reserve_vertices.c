typedef struct 
{
  u8 pad0[0x14];
  u32 *dl;
  u8 pad1[0x70 - 0x18];
  s32 base;
  u8 pad2[0x7A - 0x74];
  u16 pos;
} VtxBuffer;
s32 osVirtualToPhysical();
extern u16 D_8009B5C0;

/* Reserves count vertices in the vertex buffer and returns how many slots are left before the next reserve
 * would cross a 32-vertex block. A block switch emits a display list load for the new block. */
s32 dl_reserve_vertices(VtxBuffer *buf, s32 count)
{
  s32 lastVtx;
  s32 endPos;
  s32 countArg;
  u16 countU16;
  u16 pos;
  u32 pos32;
  u32 *dl;
  ;
  countArg = count;
  countU16 = countArg;
  if (!(buf->pos & 0x1F))
  {
    dl = buf->dl;
    buf->dl = dl + 2;
    dl[0] = 0x01020040;
    dl[1] = osVirtualToPhysical(buf->base + (buf->pos << 4));
  }
  pos = buf->pos;
  pos32 = pos;
  endPos = pos32 + (countU16 & 0xFFFF);
  lastVtx = 1;
  lastVtx = endPos - lastVtx;
  if (lastVtx < 0)
  {
    lastVtx = endPos + 0x1E;
  }
  if ((lastVtx >> 5) == ((s32) (pos32 >> 5)))
  {
    buf->pos = pos + count;
  }
  else
  {
    dl = buf->dl;
    buf->dl = dl + 2;
    dl[0] = 0x01020040;
    D_8009B5C0 = (pos32 >> 5) + 1;
    dl[1] = osVirtualToPhysical(buf->base + (D_8009B5C0 << 9));
    buf->pos = (D_8009B5C0 << 5) + count;
  }
  return (u16)(buf->pos - countU16);
}
