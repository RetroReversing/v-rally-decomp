extern f64 D_800A6D08;

/* Reads three bytes from src: the first goes to obj+0xAE, the second to obj+0xCD,
 * and the third, scaled by D_800A6D08, to the float at obj+0x1C. Returns src
 * advanced past the three bytes. */
void *func_80087BE0(void *obj, u8 *src) {
    *(u8 *)((char *)obj + 0xAE) = src[0];
    src++;
    *(u8 *)((char *)obj + 0xCD) = src[0];
    src++;
    *(f32 *)((char *)obj + 0x1C) = (f64)(f32)src[0] * D_800A6D08;
    return src + 1;
}
