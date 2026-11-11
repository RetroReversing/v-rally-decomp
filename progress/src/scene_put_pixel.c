extern s32 gSceneSlot0;
void *func_80005C48(s32);

/* Writes one 16-bit pixel at (x, y) in the scene framebuffer. Points outside the
 * 320x240 screen are ignored. Rows are 640 bytes apart. */
void scene_put_pixel(u32 x, u32 y, s16 color)
{
    u8 *framebuf;
    u32 row_offset;
    u32 pixel_addr;

    if ((x < 0x140) & (y < 0xF0)) {
        framebuf = func_80005C48(gSceneSlot0);
        row_offset = (y * 5) << 7;
        pixel_addr = x * 2 + (u32) framebuf;
        *(s16 *) (row_offset + pixel_addr) = color;
    }
}
