void read_rate_params(S_func_80088D10_layout *dst, u8 *src);

/* Reads one variable-length index (1 or 2 bytes, high bit set means two bytes)
 * from src, looks up its 7-byte rate entry in the table at dst->unk_70, and
 * applies it with read_rate_params. Returns the position after the index. */
u8 *read_rate_entry(void *dst, u8 *src)
{
    u8 *p;
    u32 index;
    u32 lo;

    p = src;
    index = *p;
    p++;
    if (index & 0x80) {
        index = index & 0x7F;
        lo = *p;
        index = index << 8;
        p++;
        index = index | lo;
    }
    read_rate_params(dst, *(u8 **)(*(u8 **)((u8 *)dst + 0x70) + 0x10) + index * 7);
    return p;
}
