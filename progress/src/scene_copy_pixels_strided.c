extern void *gSceneSlot0;
u16 *func_80005C48();

/* Copies a block of pixels from src into the scene's frame buffer, taking every
 * second pixel. src skips 640 pixels after each row of the block. */
void scene_copy_pixels_strided(u16 *src) {
    s32 row;
    s32 col;
    u16 *dst;

    dst = func_80005C48(gSceneSlot0);
    for (row = 0; row < ((s16 *) gSceneSlot0)[3]; row++) {
        for (col = 0; col < ((s16 *) gSceneSlot0)[2]; col++) {
            *dst++ = *src;
            src += 2;
        }
        src += 0x280;
    }
}
