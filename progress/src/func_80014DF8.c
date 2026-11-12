extern s32 gSceneSlot0;
extern void *obj_get_owner(s32);

#define SCREEN_W 0x140
#define SCREEN_H 0xF0
#define SCREEN_STRIDE 0x280

/* Draws a circle outline of radius r around (x, y) into the 320x240 16-bit
 * framebuffer, using the midpoint algorithm with 8-way symmetry. Pixels off
 * screen are skipped; the fast path is used when the circle is fully on screen. */
#ifdef PORT
void func_80014DF8(s32 x, s32 y, s32 r, s32 color) {
    s16 *fb = (s16 *)obj_get_owner(gSceneSlot0);
    s32 err;
    u32 dx;
    u32 rsq;
#define PORT_PLOT(X, Y) do { if (((u32)(X) < 0x140U) & ((u32)(Y) < 0xF0U)) fb[(Y) * 0x140 + (X)] = color; } while (0)
    rsq = r * r;
    err = rsq - r;
    dx = 0;
    do {
        PORT_PLOT(x + dx, y - r);
        PORT_PLOT(x - dx, y - r);
        PORT_PLOT(x + dx, y + r);
        PORT_PLOT(x - dx, y + r);
        PORT_PLOT(x + r, y - dx);
        PORT_PLOT(x - r, y - dx);
        PORT_PLOT(x + r, y + dx);
        PORT_PLOT(x - r, y + dx);
        dx++;
        rsq += 1 - dx * 2;
        if (err >= rsq) {
            r--;
            err -= r * 2;
        }
    } while (r >= dx);
#undef PORT_PLOT
}
#else
void func_80014DF8(s32 x, s32 y, s32 r, s32 color) {
    s32 pad[2]; s32 *fb;
    s32 err;
    u32 dx;
    u32 rsq;
    s32 clipped;
    s32 px;
    s32 py;

    fb = (s32 *)obj_get_owner(gSceneSlot0);
    rsq = r * r;
    err = rsq - r;
    dx = 0;
    clipped = ((u32)(x + r) >= 0x140U || (u32)(y + r) >= 0xF0U);
    do {
        if (clipped) {
            px = x + dx;
            py = y - r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
            px = x - dx;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
            px = x + dx;
            py = y + r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
            px = x - dx;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
            px = x + r;
            py = y - dx;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
            px = x - r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
            px = x + r;
            py = y + dx;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
            px = x - r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)fb)) = color;
            }
        } else {
            *(s16 *)(((x+dx)*2+(s32)fb) + (y-r)*0x280) = color;
            *(s16 *)((y - r) * 0x280 + ((x - dx) * 2 + (s32)fb)) = color;
            *(s16 *)((y + r) * 0x280 + ((x + dx) * 2 + (s32)fb)) = color;
            *(s16 *)((y + r) * 0x280 + ((x - dx) * 2 + (s32)fb)) = color;
            *(s16 *)(((x+r)*2+(s32)fb) + (y-dx)*0x280) = color;
            *(s16 *)((y - dx) * 0x280 + ((x - r) * 2 + (s32)fb)) = color;
            *(s16 *)((y + dx) * 0x280 + ((x + r) * 2 + (s32)fb)) = color;
            *(s16 *)((y + dx) * 0x280 + ((x - r) * 2 + (s32)fb)) = color;
        }
        dx++;
        rsq += 1 - dx * 2;
        if (err >= rsq) {
            r--;
            err -= r * 2;
        }
    } while (r >= dx);
}
#endif
