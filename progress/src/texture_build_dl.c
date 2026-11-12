typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { char pad[20]; Gfx *dl; } Draw;
typedef struct { char pad[4]; u16 format; u16 width; u16 height; char padA[6]; void **palettes; void **images; } Tex;
u32 osVirtualToPhysical(void *);

/* Append one F3D/RDP command (two words) to the display list. */
#define GFX_CMD(list, a, b) { Gfx *_g = (list)->dl++; _g->w0 = (a); _g->w1 = (b); }
/* Pack v into the low w bits and shift it to bit position s. */
#define GFX_FIELD(v, s, w) (((u32)(v) & ((1 << (w)) - 1)) << (s))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* Builds the RDP texture-load and tile setup commands for texture t (frame idx) into the
 * display list. The command set depends on the texture format: 0x10 is 4bpp-style, 0x100
 * is 8bpp-style, 0xA0 is 16bpp. Always returns 0. */
s32 texture_build_dl(Draw *list, Tex *t, u8 idx)
{
    Draw *d = list;
    GFX_CMD(d, 0xD7000002, 0x80008000);
    GFX_CMD(d, 0xE3001201, 0x2000);
    GFX_CMD(d, 0xE3000C00, 0x80000);
    switch (t->format) {
    case 0x10:
        GFX_CMD(d, 0xFD500000, osVirtualToPhysical(t->images[idx]));
        GFX_CMD(d, 0xF5500000, 0x07000000);
        GFX_CMD(d, 0xE6000000, 0);
        GFX_CMD(d, 0xF3000000, 0x07000000 | GFX_FIELD(MIN((((t->width * t->height) + 3) >> 2) - 1, 0x7FF), 12, 12)
            | GFX_FIELD(((1 << 11) + MAX(1, t->width / 16) - 1) / MAX(1, t->width / 16), 0, 12));
        GFX_CMD(d, 0xE7000000, 0);
        GFX_CMD(d, 0xF5400000 | GFX_FIELD((((t->width >> 1) + 7) >> 3), 9, 9), 0);
        GFX_CMD(d, 0xF2000000, GFX_FIELD((t->width - 1) << 2, 12, 12) | GFX_FIELD((t->height - 1) << 2, 0, 12));
        GFX_CMD(d, 0xFD100000, osVirtualToPhysical(t->palettes[0]));
        GFX_CMD(d, 0xE8000000, 0);
        GFX_CMD(d, 0xF5000100, 0x07000000);
        GFX_CMD(d, 0xE6000000, 0);
        GFX_CMD(d, 0xF0000000, 0x07000000 | GFX_FIELD(15, 14, 10));
        GFX_CMD(d, 0xE7000000, 0);
        break;
    case 0x100:
        GFX_CMD(d, 0xFD500000, osVirtualToPhysical(t->images[idx]));
        GFX_CMD(d, 0xF5500000, 0x07000000);
        GFX_CMD(d, 0xE6000000, 0);
        GFX_CMD(d, 0xF3000000, 0x07000000 | GFX_FIELD(MIN((((t->width * t->height) + 1) >> 1) - 1, 0x7FF), 12, 12)
            | GFX_FIELD(((1 << 11) + MAX(1, t->width / 8) - 1) / MAX(1, t->width / 8), 0, 12));
        GFX_CMD(d, 0xE7000000, 0);
        GFX_CMD(d, 0xF5480000 | GFX_FIELD(((t->width + 7) >> 3), 9, 9), 0);
        GFX_CMD(d, 0xF2000000, GFX_FIELD((t->width - 1) << 2, 12, 12) | GFX_FIELD((t->height - 1) << 2, 0, 12));
        GFX_CMD(d, 0xFD100000, osVirtualToPhysical(t->palettes[0]));
        GFX_CMD(d, 0xE8000000, 0);
        GFX_CMD(d, 0xF5000100, 0x07000000);
        GFX_CMD(d, 0xE6000000, 0);
        GFX_CMD(d, 0xF0000000, 0x07000000 | GFX_FIELD(255, 14, 10));
        GFX_CMD(d, 0xE7000000, 0);
        break;
    case 0xA0:
        GFX_CMD(d, 0xFD180000, osVirtualToPhysical(t->images[idx]));
        GFX_CMD(d, 0xF5180000, 0x07000000);
        GFX_CMD(d, 0xE6000000, 0);
        GFX_CMD(d, 0xF3000000, 0x07000000 | GFX_FIELD(MIN((t->width * t->height) - 1, 0x7FF), 12, 12)
            | GFX_FIELD(((1 << 11) + MAX(1, (s32)(t->width * 2) / 4) - 1) / MAX(1, (s32)(t->width * 2) / 4), 0, 12));
        GFX_CMD(d, 0xE7000000, 0);
        GFX_CMD(d, 0xF5180000 | GFX_FIELD((((t->width * 2) + 7) >> 3), 9, 9), 0);
        GFX_CMD(d, 0xF2000000, GFX_FIELD((t->width - 1) << 2, 12, 12) | GFX_FIELD((t->height - 1) << 2, 0, 12));
        GFX_CMD(d, 0xE3001001, 0);
        break;
    }
    return 0;
}
