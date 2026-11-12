s32 dl_reserve_vertices(void *, s32);

/* Appends one flat-shaded triangle to the display list in ctx (the first call
 * also emits the state setup words). Returns the index of the first vertex used. */
s32 func_800064AC(void *ctx, s16 color) {
    s32 vtx_index;
    s32 vtx_off;
    s32 vtx_off_2;
    void *cmd_dst;
    void *dl_p;
    void *dl_p_2;
    void *dl_p_3;
    void *dl_p_4;
    void *dl_p_5;
    void *dl_p_6;
    s32 tag;

    if (!(*(u16 *)((char *)ctx + 0x78) & 1)) {
        dl_p = *(void **)((char *)ctx + 0x14);
        *(u16 *)((char *)ctx + 0x78) |= 1U;
        *(void **)((char *)ctx + 0x14) = (void *)(dl_p + 8);
        *(s32 *)((char *)dl_p + 0) = 0xE7000000;
        *(s32 *)((char *)dl_p + 4) = 0;
        dl_p_2 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl_p_2 + 8);
        *(s32 *)((char *)dl_p_2 + 0) = 0xE3000A01;
        *(s32 *)((char *)dl_p_2 + 4) = 0;
        dl_p_3 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl_p_3 + 8);
        *(s32 *)((char *)dl_p_3 + 0) = 0xD7000000;
        *(s32 *)((char *)dl_p_3 + 4) = 0;
        dl_p_4 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl_p_4 + 8);
        *(s32 *)((char *)dl_p_4 + 0) = 0xFCFFFFFF;
        *(s32 *)((char *)dl_p_4 + 4) = 0xFFFE793C;
        dl_p_5 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl_p_5 + 8);
        *(s32 *)((char *)dl_p_5 + 0) = 0xD9E0F9FA;
        *(s32 *)((char *)dl_p_5 + 4) = 0;
        dl_p_6 = *(void **)((char *)ctx + 0x14);
        *(void **)((char *)ctx + 0x14) = (void *)(dl_p_6 + 8);
        *(s32 *)((char *)dl_p_6 + 0) = 0xD9FFFFFF;
        *(s32 *)((char *)dl_p_6 + 4) = 0x200005;
    }
    vtx_index = (u16)dl_reserve_vertices(ctx, 3);
    vtx_off = vtx_index * 0x10;
#ifdef PORT
    *(s16 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 4) = color;
    *(s16 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 0x14) = color;
    *(s16 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 0x24) = color;
    *(s16 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 6) = 0;
    *(s16 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 0x16) = 0;
    *(s16 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 0x26) = 0;
    *(u8 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 0xF) = 0xFF;
    *(u8 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 0x1F) = 0xFF;
    *(u8 *)((*(char **)((char *)ctx + 0x70) + vtx_off) + 0x2F) = 0xFF;
#else
    *(s16 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 4) = color;
    *(s16 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 0x14) = color;
    *(s16 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 0x24) = color;
    *(s16 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 6) = 0;
    *(s16 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 0x16) = 0;
    *(s16 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 0x26) = 0;
    *(u8 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 0xF) = 0xFF;
    *(u8 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 0x1F) = 0xFF;
    *(u8 *)((char *)(vtx_off + *(s32 *)((char *)ctx + 0x70)) + 0x2F) = 0xFF;
#endif
    cmd_dst = *(void **)((char *)ctx + 0x14);
    vtx_off_2 = vtx_index & 0x1F;
    *(void **)((char *)ctx + 0x14) = (void *)(cmd_dst + 8);
    tag = (vtx_off_2 << 0x11) | ((vtx_off_2 + 1) << 9) | ((vtx_off_2 + 2) * 2) | 0x05000000;
    *(s32 *)((char *)cmd_dst + 0) = tag;
    *(s32 *)((char *)cmd_dst + 4) = 0;
    return vtx_index;
}
