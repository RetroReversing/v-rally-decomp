s32 dl_reserve_vertices(void *, s32);
typedef struct { u32 w0; u32 w1; } GfxW;
#define SHL(v,s,w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define TRIW(a,b,c) (SHL((a)*2,16,8)|SHL((b)*2,8,8)|SHL((c)*2,0,8))

/* Draws one flat-coloured quad (two triangles) into the display list in ctx.
 * The first call after a reset also writes the render-state setup commands.
 * Reserves four vertices, fills them with the colour in col, writes the two
 * triangles and returns the index of the first vertex. */
s32 func_80006B4C(void *ctx, s16 col) {
    s32 vtxOff;
    s32 vtxIndex;
    s32 i;
    void *dl;
    void *dl2;
    void *dl3;
    void *dl4;

    if (*(u16 *)((char *)ctx + 0x78) & 1) {
        dl = *(void **)((char *)ctx + 0x14);
        *(u16 *)((char *)ctx + 0x78) = 0U;
        *(void **)((char *)ctx + 0x14) = (void *)(dl + 8);
        *(s32 *)((char *)dl + 0) = 0xD9C0F9FA;
        *(s32 *)((char *)dl + 4) = 0;
        dl2 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl2 + 8);
        *(s32 *)((char *)dl2 + 0) = 0xD9FFFFFF;
        *(s32 *)((char *)dl2 + 4) = 5;
        dl3 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl3 + 8);
        *(s32 *)((char *)dl3 + 0) = 0xD7000000;
        *(s32 *)((char *)dl3 + 4) = 0;
        dl4 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl4 + 8);
        *(s32 *)((char *)dl4 + 0) = 0xFCFFFFFF;
        *(s32 *)((char *)dl4 + 4) = 0xFFFE793C;
    }
    vtxIndex = (u16)dl_reserve_vertices(ctx, 4);
    vtxOff = vtxIndex * 0x10;
#ifdef PORT
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 4) = col;
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x14) = col;
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x24) = col;
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x34) = col;
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 6) = 0;
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x16) = 0;
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x26) = 0;
    *(s16 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x36) = 0;
    *(u8 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0xF) = 0xFF;
    *(u8 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x1F) = 0xFF;
    *(u8 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x2F) = 0xFF;
    *(u8 *)((char *)(vtxOff + *(char **)((char *)ctx + 0x70)) + 0x3F) = 0xFF;
#else
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 4) = col;
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x14) = col;
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x24) = col;
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x34) = col;
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 6) = 0;
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x16) = 0;
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x26) = 0;
    *(s16 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x36) = 0;
    *(u8 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0xF) = 0xFF;
    *(u8 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x1F) = 0xFF;
    *(u8 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x2F) = 0xFF;
    *(u8 *)((char *)(vtxOff + *(s32 *)((char *)ctx + 0x70)) + 0x3F) = 0xFF;
#endif
    i = vtxIndex & 0x1F;
    {
        GfxW *_g = (GfxW *)((*(GfxW **)((char *)ctx + 0x14))++);
        _g->w0 = SHL(7, 24, 8) | TRIW(i, i + 1, i + 2);
        _g->w1 = TRIW(i, i + 2, i + 3);
    }
    return vtxIndex;
}
