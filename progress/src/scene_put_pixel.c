extern s32 gSceneSlot0;
void *obj_get_owner(s32);

/* Writes one 16-bit pixel at (x, y) in the scene framebuffer. Points outside the
 * 320x240 screen are ignored. Rows are 640 bytes apart. */
void scene_put_pixel(u32 x, u32 y, s16 color)
{
    u8 *framebuf;
    u32 row_offset;
#ifdef PORT
    u8 *pixel_addr;
#else
    u32 pixel_addr;
#endif

    if ((x < 0x140) & (y < 0xF0)) {
        framebuf = obj_get_owner(gSceneSlot0);
        row_offset = (y * 5) << 7;
#ifdef PORT
        pixel_addr = framebuf + x * 2;
#else
        pixel_addr = x * 2 + (u32) framebuf;
#endif
        *(s16 *) (row_offset + pixel_addr) = color;
    }
}
