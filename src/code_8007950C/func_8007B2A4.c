#include "snapshot31_verified.h"

extern u8 D_800C02AE[];
extern s16 D_800A18A4[], D_800A18AC[], D_800A18B4[], D_800A18BC[];
extern s32 D_800A1860, D_800A1864, D_800A1868, D_800A186C, D_800A1870, D_800A1874, D_800A1880;
void func_8002E288(void *, s16 *, s32 *);
typedef struct Triple { s16 a; s16 b; s16 c; } Triple;
void func_8007B2A4(u8 *a, u8 *b) {
    s32 out[3];
    s32 pos[3];
    Triple x, y;
    s32 *g;
    s16 dx, dz;
    if (*(u16 *)(*(u8 **)(D_800C02AE + 0x7cd6) + 32) & 8) {
        x = *(Triple *)D_800A18B4;
        y = *(Triple *)D_800A18BC;
    } else {
        x = *(Triple *)D_800A18A4;
        y = *(Triple *)D_800A18AC;
    }
    pos[0] = ((s32 *)*(void **)(a + 0x58))[3];
    pos[1] = ((s32 *)*(void **)(a + 0x58))[4];
    pos[2] = ((s32 *)*(void **)(a + 0x58))[5];
    func_8002E288(*(u8 **)(a + 0x5c) + 64, (s16 *)&x, out);
    g = &D_800A1860;
    g[0] = out[0] + pos[0];
    g[1] = out[1] + pos[1];
    g[2] = out[2] + pos[2];
    func_8002E288(*(u8 **)(a + 0x5c) + 64, (s16 *)&y, out);
    g[3] = out[0] + pos[0];
    g[4] = out[1] + pos[1];
    g[5] = out[2] + pos[2];
    dx = g[0] - *(s32 *)(b + 20);
    x.a = dx;
    dz = g[2] - *(s32 *)(b + 28);
    x.c = dz;
    D_800A1880 = 0;
    if (dx >= 20000) return;
    if (dz >= 20000) return;
    if (dx < -19999) return;
    if (dz < -19999) return;
    D_800A1880 = 1;
}
