typedef struct { u32 w0, w1; } Gfx;
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GPACK_RGBA5551(r, g, b, a) ((((r) << 8) & 0xf800) | (((g) << 3) & 0x7c0) | (((b) >> 2) & 0x3e) | ((a) & 0x1))
#define gDPNoParam(pkt, cmd) { Gfx *_g = (Gfx *)(pkt); _g->w0 = _SHIFTL(cmd, 24, 8); _g->w1 = 0; }
#define gDPPipeSync(pkt) gDPNoParam(pkt, 0xE7)
#define gDPSetCycleType(pkt, type) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (_SHIFTL(0xE3, 24, 8) | _SHIFTL(32 - (20) - (2), 8, 8) | _SHIFTL((2) - 1, 0, 8)); _g->w1 = (u32)(type); }
#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry) { Gfx *_g = (Gfx *)pkt; _g->w0 = _SHIFTL(0xED, 24, 8) | _SHIFTL((int)((float)(ulx) * 4.0F), 12, 12) | _SHIFTL((int)((float)(uly) * 4.0F), 0, 12); _g->w1 = _SHIFTL(mode, 24, 2) | _SHIFTL((int)((float)(lrx) * 4.0F), 12, 12) | _SHIFTL((int)((float)(lry) * 4.0F), 0, 12); }
#define gDPSetColorImage(pkt, f, s, w, i) { Gfx *_g = (Gfx *)(pkt); _g->w0 = _SHIFTL(0xFF, 24, 8) | _SHIFTL(f, 21, 3) | _SHIFTL(s, 19, 2) | _SHIFTL((w) - 1, 0, 12); _g->w1 = (u32)(i); }
#define gDPSetFillColor(pkt, d) { Gfx *_g = (Gfx *)(pkt); _g->w0 = _SHIFTL(0xF7, 24, 8); _g->w1 = (d); }
#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (_SHIFTL(0xF6, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10)); _g->w1 = (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10)); }

typedef struct { u8 pad[4]; s16 width; } FrameInfo;
extern FrameInfo *D_8009B5A8;
void *func_80005C48(FrameInfo *arg0);
s32 func_800056FC(s32 arg0);
Gfx *func_80006008(s32 arg0);
void func_80006014(s32 arg0, Gfx *arg1);
u32 osVirtualToPhysical(void *);

void func_8000EC94(s32 arg0, s16 *rect, u8 *color)
{
    void *fb;
    s32 task;
    Gfx *gdl;

    fb = func_80005C48(D_8009B5A8);
    task = func_800056FC(arg0);
    gdl = func_80006008(task);
    gDPSetScissor(gdl++, 0, rect[0], rect[1], rect[2], rect[3]);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, 0x300000);
    gDPSetColorImage(gdl++, 0, 2, D_8009B5A8->width, osVirtualToPhysical(fb));
    gDPSetFillColor(gdl++, GPACK_RGBA5551(color[0], color[1], color[2], 1) << 16 | GPACK_RGBA5551(color[0], color[1], color[2], 1));
    gDPFillRectangle(gdl++, rect[0], rect[1], rect[2] - 1, rect[3] - 1);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, 0);
    func_80006014(task, gdl);
}
