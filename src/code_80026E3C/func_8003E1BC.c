#include "decompdecomp_snapshot_8003e1bc.h"
#line 1 "func.c"
typedef void (*SpriteHook)(void);
typedef struct Pos {
    u8 pad00[8];
    s16 x8;
    s16 xA;
    s16 xC;
    s16 xE;
} Pos;
typedef struct Obj {
    u8 pad00[0xC];
    s32 type;
    u8 pad10[0x178 - 0x10];
    Pos *pos;
} Obj;
typedef struct Widget {
    u8 pad00[0x7A];
    s16 kind;
    u8 pad7C[0x90 - 0x7C];
    u8 r, g, b, a;
    u8 pad94[0xA4 - 0x94];
    s32 text;
    Obj *obj;
} Widget;
typedef struct Game {
    u8 pad00[0xE];
    u16 mode;
    u8 pad10[2];
    u16 opts;
    u8 pad14[0x1E - 0x14];
    u16 state;
} Game;
extern Game *D_800C35A0;
extern Obj *D_800C7F84;
extern void func_8003E06C();
extern void func_8003E0D4();
extern void func_8003E134();
extern s32 func_80034FF0(s32, s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);

void func_8003E1BC(s32 arg0, s32 arg1)
{
    Obj *obj;
    Pos *pos;
    Widget *w;
    u32 i;
    s32 x;
    s32 y;
    s32 px;

    obj = D_800C7F84;
    pos = obj->pos;
    x = pos->x8;
    y = pos->xA + 6;
    px = x + 0x14;
    switch (D_800C35A0->mode) {
    case 1:
        if (D_800C35A0->state != 0) {
            for (i = 0; i < 4; i++) {
                w = ((Widget *)func_80040260((void *)(arg0), px, y + i * 0xB, (u16)(5), (SpriteHook)(func_8003E06C), 1));
                w->text = func_80034FF0(arg1 + 0x4C, 0);
                w->kind = i + 1;
                w->obj = D_800C7F84;
            }
        }
        break;
    case 2:
        if (D_800C35A0->state != 0) {
            if (!(D_800C35A0->opts & 1)) {
                if (obj->type == 3) {
                    px = x + 6;
                }
            } else {
                px = x;
            }
            w = ((Widget *)func_80040260((void *)(arg0), px, y + 0xA, (u16)(5), (SpriteHook)(func_8003E0D4), 1));
            w->text = func_80034FF0(arg1 + 0x4C, 0);
            w->obj = D_800C7F84;
            w->r = 0xFE;
            w->g = 0xD5;
            w->b = 0x1E;
            w->a = 0xFF;
            w = ((Widget *)func_80040260((void *)(arg0), px, y, (u16)(5), (SpriteHook)(func_8003E134), 1));
            w->text = func_80034FF0(arg1 + 0x4C, 0);
            w->obj = D_800C7F84;
        }
        break;
    }
}

