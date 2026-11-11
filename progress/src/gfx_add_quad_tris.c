s32 dl_reserve_vertices(void *, s32);
typedef struct { u32 w0; u32 w1; } GfxW;
typedef struct { u8 pad0[0x14]; GfxW *dl; u8 pad1[0x70 - 0x18]; s32 base; } GfxBuf;
#define SHL(v,s,w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define TRIW(a,b,c) (SHL((a)*2,16,8)|SHL((b)*2,8,8)|SHL((c)*2,0,8))

/* Reserves four vertices in the buffer, clears their position and colour fields
   (alpha 0xFF), and adds a two-triangle quad as one F3DEX tri word pair.
   Returns the first vertex index. */
s32 gfx_add_quad_tris(GfxBuf *buf) {
    s32 firstVtx;
    s32 vtxOffset;
    s32 i;

    firstVtx = (u16)dl_reserve_vertices(buf, 4);
    vtxOffset = firstVtx * 0x10;
    *(s16 *)((char *)(vtxOffset + buf->base) + 6) = 0;
    *(s16 *)((char *)(vtxOffset + buf->base) + 0x16) = 0;
    *(s16 *)((char *)(vtxOffset + buf->base) + 0x26) = 0;
    *(s16 *)((char *)(vtxOffset + buf->base) + 0x36) = 0;
    *(u8 *)((char *)(vtxOffset + buf->base) + 0xF) = 0xFF;
    *(u8 *)((char *)(vtxOffset + buf->base) + 0x1F) = 0xFF;
    *(u8 *)((char *)(vtxOffset + buf->base) + 0x2F) = 0xFF;
    *(u8 *)((char *)(vtxOffset + buf->base) + 0x3F) = 0xFF;
    i = firstVtx & 0x1F;
    {
        GfxW *_g = (GfxW *)(buf->dl++);
        _g->w0 = SHL(7, 24, 8) | TRIW(i, i + 1, i + 2);
        _g->w1 = TRIW(i, i + 2, i + 3);
    }
    return firstVtx;
}
