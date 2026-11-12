s32 dl_reserve_vertices(void *, s32);

#ifdef PORT
#define DL_VTX_AT(vtxOff) ((char *)*(void **)((char *)dl + 0x70) + (vtxOff))
#else
#define DL_VTX_AT(vtxOff) ((char *)((vtxOff) + *(s32 *)((char *)dl + 0x70)))
#endif

/* Appends one flat-coloured triangle to the display list at dl. The first call (dirty flag
 * bit 0 set) also emits the render-mode setup words. It reserves 3 vertices from the vertex
 * buffer at dl+0x70, fills them with colour 'shade' and writes a 1-triangle command that uses
 * those vertices. Returns the first vertex index. */
s32 dlAddTri(void *dl, s16 shade) {
    s32 vtxOff;
    s32 vtxIdxBase;
    s32 vtxIdx;
    void *cmd;
    void *cmd2;
    void *cmd3;
    void *cmd4;
    void *tri;

    if (*(u16 *)((char *)dl + 0x78) & 1) {
        cmd = *(void **)((char *)dl + 0x14);
        *(u16 *)((char *)dl + 0x78) = 0U;
        *(void **)((char *)dl + 0x14) = (void *)(cmd + 8);
        *(s32 *)((char *)cmd + 0) = 0xD9C0F9FA;
        *(s32 *)((char *)cmd + 4) = 0;
        cmd2 = *(void **)((char *)dl + 0x14);
        *(void **)((char *)dl + 0x14) = (void *)(cmd2 + 8);
        *(s32 *)((char *)cmd2 + 0) = 0xD9FFFFFF;
        *(s32 *)((char *)cmd2 + 4) = 5;
        cmd3 = *(void **)((char *)dl + 0x14);
        *(void **)((char *)dl + 0x14) = (void *)(cmd3 + 8);
        *(s32 *)((char *)cmd3 + 0) = 0xD7000000;
        *(s32 *)((char *)cmd3 + 4) = 0;
        cmd4 = *(void **)((char *)dl + 0x14);
        *(void **)((char *)dl + 0x14) = (void *)(cmd4 + 8);
        *(s32 *)((char *)cmd4 + 0) = 0xFCFFFFFF;
        *(s32 *)((char *)cmd4 + 4) = 0xFFFE793C;
    }
    vtxIdxBase = (u16)dl_reserve_vertices(dl, 3);
    vtxOff = vtxIdxBase * 0x10;
    *(s16 *)(DL_VTX_AT(vtxOff) + 4) = shade;
    *(s16 *)(DL_VTX_AT(vtxOff) + 0x14) = shade;
    *(s16 *)(DL_VTX_AT(vtxOff) + 0x24) = shade;
    *(s16 *)(DL_VTX_AT(vtxOff) + 6) = 0;
    *(s16 *)(DL_VTX_AT(vtxOff) + 0x16) = 0;
    *(s16 *)(DL_VTX_AT(vtxOff) + 0x26) = 0;
    *(u8 *)(DL_VTX_AT(vtxOff) + 0xF) = 0xFF;
    *(u8 *)(DL_VTX_AT(vtxOff) + 0x1F) = 0xFF;
    *(u8 *)(DL_VTX_AT(vtxOff) + 0x2F) = 0xFF;
    tri = *(void **)((char *)dl + 0x14);
    vtxIdx = vtxIdxBase & 0x1F;
    *(void **)((char *)dl + 0x14) = (void *)(tri + 8);
    *(s32 *)((char *)tri + 0) = (vtxIdx << 0x11) | ((vtxIdx + 1) << 9) | ((vtxIdx + 2) * 2) | 0x05000000;
    *(s32 *)((char *)tri + 4) = 0;
    return vtxIdxBase;
}
