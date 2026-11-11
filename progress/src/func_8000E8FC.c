s32 func_80005C48(void *);
void func_8000E9D4(void *, s32, u16 *, u8 *);
void gfx_clear_zbuffer_rect(void *, s32, u16 *);

/* Draws the fill rect for obj (its colour is at offset 0x10) if fillRect is set, and clears
 * the z-buffer rect zRect for obj if it is set. Each rect is four u16 words: x, y, w, h. */
void func_8000E8FC(void *obj, void *fillRect, void *zRect) {
    u16 rect[4];
    u8 color[4];
    s32 addr;

    if (fillRect != NULL) {
        addr = func_80005C48(fillRect);
        rect[0] = ((u16 *)fillRect)[0];
        rect[1] = ((u16 *)fillRect)[1];
        rect[2] = ((u16 *)fillRect)[2];
        rect[3] = ((u16 *)fillRect)[3];
        color[0] = ((u8 *)obj)[0x10];
        color[1] = ((u8 *)obj)[0x11];
        color[2] = ((u8 *)obj)[0x12];
        color[3] = ((u8 *)obj)[0x13];
        func_8000E9D4(obj, addr, rect, color);
    }
    if (zRect != NULL) {
        addr = func_80005C48(zRect);
        rect[0] = ((u16 *)zRect)[0];
        rect[1] = ((u16 *)zRect)[1];
        rect[2] = ((u16 *)zRect)[2];
        rect[3] = ((u16 *)zRect)[3];
        gfx_clear_zbuffer_rect(obj, addr, rect);
    }
}
