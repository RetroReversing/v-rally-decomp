extern f64 D_800A6D10;

/* Reads three bytes from src: the first two go to dst[0xAE] and dst[0xCD], the third is
 * negated, scaled by D_800A6D10 and stored as a float at dst+0x1C. Returns the position after them. */
u8 *stream_read_obj_params(u8 *dst, u8 *src)
{
    dst[0xAE] = src[0];
    src++;
    dst[0xCD] = src[0];
    src++;
    *(f32 *)(dst + 0x1C) = (f32) ((f64) -(f32) src[0] * D_800A6D10);
    return src + 1;
}
