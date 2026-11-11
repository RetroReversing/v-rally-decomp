/* Writes one F3DEX quad command (0x07) for four vertex indices into the display list.
 * Each index is 5 bits. v3 is read from the low halfword of v3_arg. The two words are
 * stored at the list cursor at ctx+0x14, which then advances by 8 bytes. */
void gfx_add_quad(void *ctx, s32 v0, s32 v1, s32 v2, s32 v3_arg)
{
    s32 *cursor = *(s32 **)((char *)ctx + 0x14);
    s32 w1;
    s32 w0;
    s32 v2_bits;

    w1 = (v0 & 0x1F) << 17;
    w0 = w1 | ((v1 & 0x1F) << 9);
    v2_bits = v2 & 0x1F;
    v2_bits = v2_bits << 1;
    w0 = w0 | v2_bits;
    cursor[0] = w0 | 0x07000000;
    v2_bits = v2_bits << 8;
    w1 |= v2_bits;
    w1 |= (((u16 *)&v3_arg)[1] & 0x1F) << 1;
    cursor[1] = w1;
    cursor = (s32 *)((char *)*(void **)((char *)ctx + 0x14) + 8);
    *(void **)((char *)ctx + 0x14) = cursor;
}
