extern f64 D_800A6D20;

/* Reads one byte from the stream into obj's float at +0x68 (scaled by D_800A6D20) and squares obj's float at +0x6C into +0x20. Returns the advanced stream pointer. */
u8 *func_80088258(void *obj, u8 *src) {
    double scaled;
    f32 speed;

    scaled = ((f64)((f32)(*src))) * D_800A6D20;
    speed = *((f32 *)((char *)obj + 0x6C));
    *((f32 *)((char *)obj + 0x20)) = (f32)(speed * speed);
    *((f32 *)((char *)obj + 0x68)) = (f32)scaled;
    return src + 1;
}
