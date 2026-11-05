#include "decompdecomp_snapshot_80067ac4.h"
#line 1 "func.c"
typedef struct Draw { s32 pad[4]; s32 x[4]; s32 y[4]; s32 id[4]; u8 r[4]; u8 g[4]; u8 b[4]; u8 a[4]; s32 pad2[2]; } Draw;
typedef struct TextObj { char pad0[6]; s16 x; s16 y; char padA; u8 r; u8 g; u8 b; u8 a; } TextObj;
typedef struct NameEntry { s8 scroll; s8 sel; u8 len; char name[16]; } NameEntry;
typedef struct GameState { char pad0[0x228]; s8 cfg; char pad229[0x24D - 0x229]; u8 hide; char pad24E[0x280 - 0x24E]; NameEntry entry; } GameState;void *func_800592D0(u32);
extern char *func_80057918(s32, s32);
extern char *func_8004240C(s32);
extern void func_80059618(TextObj *, u8, u8, u8, u8);
extern void func_800596F4(TextObj *, s16, s16, char *);
extern void func_8004C370(s32, Draw *);
extern void func_8006874C(s8);
extern s32 func_8002D2E4(s32);
extern s32 func_8002D348(s32);
extern u32 D_8009D540;
extern GameState *D_800A1468;
extern char *D_800C35A0;
extern u16 D_800C6F12;
extern s32 D_800C8328;

void func_80067AC4(void) {
    Draw draw;
    char str[2] = "A";
    TextObj *obj;
    char *msg;
    GameState *gs;
    NameEntry *st;
    s8 i;
    s8 k;
    s32 base;
    s8 c;
    s8 cur;
    s32 ang;
    s32 dx;
    s32 dy;
    s32 r;
    s32 g;
    s32 b;

    obj = func_800592D0(9);
    if (D_800C6F12 != 0) {
        D_800C6F12--;
        msg = func_80057918(D_800C8328, 0x136);
        func_80059618(obj, 0xFF, 0, 0, D_800C6F12 * 255 / (D_8009D540 * 2));
        func_800596F4(obj, obj->x, obj->y, msg);
    }
    gs = D_800A1468;
    obj = func_800592D0(5);
    st = &gs->entry;
    st->name[st->len] = st->sel + 'A';
    if (st->scroll > 0) {
        st->scroll += 8;
        if (st->scroll == 32) {
            st->sel++;
            if (st->sel == 26) st->sel = 0;
            st->scroll = 0;
        }
    } else if (st->scroll < 0) {
        st->scroll -= 8;
        if (st->scroll == -32) {
            st->sel--;
            if (st->sel < 0) st->sel = 25;
            st->scroll = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        draw.id[i] = -1;
        draw.r[i] = 0x1E;
        draw.g[i] = 0x32;
        draw.b[i] = 0x8E;
        draw.a[i] = 0x80;
    }
    base = st->scroll * 0xFFF / 832;
    c = st->sel + 13;
    if (c >= 26) c = st->sel - 12;
    for (k = 0; k < 2; k++) {
        cur = (u8)c - k;
        for (i = 0; i < 13; i++) {
            str[0] = cur + 'A';
            ang = (st->sel - cur) * 0xFFF / 26 - 0x400;
            ang += base;
            dx = func_8002D2E4(ang) * 192 / 4096;
            dy = func_8002D348(ang) * 192 / 16384;
            if (cur == st->sel) {
                r = 0xDC;
                g = 0xDC;
                b = 0xDC;
            } else {
                r = 0x14;
                if (dy < 0) {
                    g = i * 60 / 13 + r + st->scroll * 20 / 416;
                    r = g;
                    b = g;
                } else {
                    g = 0x14;
                    b = 0x14;
                }
            }
            func_80059618(obj, r, g, b, 0xFF);
            func_800596F4(obj, obj->x - dx, obj->y - dy, str);
            if (k != 0) {
                if (cur == 0) cur = 25;
                else cur--;
            } else {
                if (cur < 25) cur++;
                else cur = 0;
            }
        }
    }
    if (D_800A1468->hide == 0) {
        dx = func_8002D2E4(-0x400) * 192 / 4096;
        dy = func_8002D348(-0x400) * 192 / 16384;
        draw.a[0] = 0x32;
        draw.a[1] = 0xB4;
        draw.a[2] = 0x32;
        draw.a[3] = 0xB4;
        draw.x[0] = obj->x + dx - 8;
        draw.x[1] = obj->x + dx + 32;
        draw.x[3] = draw.x[0];
        draw.x[2] = draw.x[1];
        draw.y[0] = draw.y[1] = obj->y - dy - 8;
        draw.y[2] = draw.y[3] = obj->y - dy + 36;
        func_8004C370(*(s32 *)(func_8004240C(1) + 0x178), &draw);
    }
    obj = func_800592D0(8);
    for (i = 0; i <= st->len; i++) {
        str[0] = st->name[i];
        if (i == st->len) {
            func_80059618(obj, 0xDC, 0xDC, 0x0E, 0xFF);
        } else {
            func_80059618(obj, obj->r, obj->g, obj->b, obj->a);
        }
        func_800596F4(obj, obj->x + i * 20, obj->y, str);
    }
    func_8006874C(((struct { char pad[0x32]; s8 arr[1]; } *)D_800C35A0)->arr[D_800A1468->cfg]);
}

