typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { char pad[20]; Gfx *dl; } Draw;
typedef struct { char pad[4]; u16 format; u16 width; u16 height; char padA[6]; void **palettes; void **images; } Tex;
u32 osVirtualToPhysical(void *);

#define CMD(d, a, b) { Gfx *_g = (d)->dl++; _g->w0 = (a); _g->w1 = (b); }
#define SH(v, s, w) (((u32)(v) & ((1 << (w)) - 1)) << (s))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

s32 func_800075BC(Draw *d, Tex *t, u8 idx)
{
    CMD(d, 0xD7000002, 0x80008000);
    CMD(d, 0xE3001201, 0x2000);
    CMD(d, 0xE3000C00, 0x80000);
    switch (t->format) {
    case 0x10:
        CMD(d, 0xFD500000, osVirtualToPhysical(t->images[idx]));
        CMD(d, 0xF5500000, 0x07000000);
        CMD(d, 0xE6000000, 0);
        CMD(d, 0xF3000000, 0x07000000 | SH(MIN((((t->width * t->height) + 3) >> 2) - 1, 0x7FF), 12, 12)
            | SH(((1 << 11) + MAX(1, t->width / 16) - 1) / MAX(1, t->width / 16), 0, 12));
        CMD(d, 0xE7000000, 0);
        CMD(d, 0xF5400000 | SH((((t->width >> 1) + 7) >> 3), 9, 9), 0);
        CMD(d, 0xF2000000, SH((t->width - 1) << 2, 12, 12) | SH((t->height - 1) << 2, 0, 12));
        CMD(d, 0xFD100000, osVirtualToPhysical(t->palettes[0]));
        CMD(d, 0xE8000000, 0);
        CMD(d, 0xF5000100, 0x07000000);
        CMD(d, 0xE6000000, 0);
        CMD(d, 0xF0000000, 0x07000000 | SH(15, 14, 10) << 2 >> 2);
        CMD(d, 0xE7000000, 0);
        break;
    case 0x100:
        CMD(d, 0xFD500000, osVirtualToPhysical(t->images[idx]));
        CMD(d, 0xF5500000, 0x07000000);
        CMD(d, 0xE6000000, 0);
        CMD(d, 0xF3000000, 0x07000000 | SH(MIN((((t->width * t->height) + 1) >> 1) - 1, 0x7FF), 12, 12)
            | SH(((1 << 11) + MAX(1, t->width / 8) - 1) / MAX(1, t->width / 8), 0, 12));
        CMD(d, 0xE7000000, 0);
        CMD(d, 0xF5480000 | SH(((t->width + 7) >> 3), 9, 9), 0);
        CMD(d, 0xF2000000, SH((t->width - 1) << 2, 12, 12) | SH((t->height - 1) << 2, 0, 12));
        CMD(d, 0xFD100000, osVirtualToPhysical(t->palettes[0]));
        CMD(d, 0xE8000000, 0);
        CMD(d, 0xF5000100, 0x07000000);
        CMD(d, 0xE6000000, 0);
        CMD(d, 0xF0000000, 0x07000000 | SH(255, 14, 10));
        CMD(d, 0xE7000000, 0);
        break;
    case 0xA0:
        CMD(d, 0xFD180000, osVirtualToPhysical(t->images[idx]));
        CMD(d, 0xF5180000, 0x07000000);
        CMD(d, 0xE6000000, 0);
        CMD(d, 0xF3000000, 0x07000000 | SH(MIN((t->width * t->height) - 1, 0x7FF), 12, 12)
            | SH(((1 << 11) + MAX(1, (s32)(t->width * 2) / 4) - 1) / MAX(1, (s32)(t->width * 2) / 4), 0, 12));
        CMD(d, 0xE7000000, 0);
        CMD(d, 0xF5180000 | SH((((t->width * 2) + 7) >> 3), 9, 9), 0);
        CMD(d, 0xF2000000, SH((t->width - 1) << 2, 12, 12) | SH((t->height - 1) << 2, 0, 12));
        CMD(d, 0xE3001001, 0);
        break;
    }
    return 0;
}
