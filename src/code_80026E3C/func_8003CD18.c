#include "decompdecomp_snapshot_8003cd18.h"
#line 1 "func.c"
typedef void (*SpriteHook)(void);
typedef struct { u8 pad[0x7A]; s16 x7A; u8 pad2[0x28]; s32 xA4; void *xA8; } Btn3CD18;
typedef struct { u8 pad[8]; s16 x; s16 y; s16 w; s16 h; } Rect3CD18;
typedef struct { u8 pad[0xC]; s32 type; u8 pad2[0x168]; Rect3CD18 *rect; } Obj3CD18;
typedef struct { u8 pad[0xE]; u16 mode; u8 pad2[2]; u16 flags; u8 pad3[0xA]; u16 x1E; } Mgr3CD18;
s32 func_80034FF0(void *, s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
Obj3CD18 *func_8004240C(s32);
void func_8003CB8C();
void func_8003CC0C();
void func_8003CC50();
extern char D_800A73E0[];
extern Mgr3CD18 *D_800C35A0;
extern Obj3CD18 *D_800C7F84;
#define D_800ADFE0 (*(u8 *)(D_800A73E0 + 0x6C00))
#define D_800ADFE1 (*(u8 *)(D_800A73E0 + 0x6C01))

#define BTN_A(X, Y, CB) \
    b = ((Btn3CD18 *)func_80040260((void *)(arg0), X, Y, 2, (SpriteHook)(CB), 0)); \
    name = (u8 *)arg1 + 0x4C; \
    b->xA4 = func_80034FF0(name, 0); \
    b->xA8 = D_800C7F84;
#define BTN_B(X, Y, CB) \
    b = ((Btn3CD18 *)func_80040260((void *)(arg0), X, Y, 2, (SpriteHook)(CB), 0)); \
    b->xA4 = func_80034FF0(name, 0); \
    b->x7A = 15; \
    b->xA8 = D_800C7F84;
#define BTN_C(X, Y, CB) \
    b = ((Btn3CD18 *)func_80040260((void *)(arg0), X, Y, 2, (SpriteHook)(CB), 0));

void func_8003CD18(void *arg0, void *arg1, u16 arg2)
{

    Btn3CD18 *b;
    Obj3CD18 *obj;
    Rect3CD18 *r;
    s32 left;
    s32 top;
    s32 y0;
    s32 x;
    s32 w;
    s32 bottom;
    s32 h;
    u16 xr;
    s16 y;

    u8 *pc;

    if (D_800C35A0->x1E == 7) {
        return;
    }
    pc = &D_800ADFE0;
    if (*pc < 2) {
        return;
    }
    obj = func_8004240C(((arg2 - 1) * 2) | 1);
    r = obj->rect;
    D_800C7F84 = obj;
    left = r->x;
    top = r->y;
    bottom = r->h;
    x = left + 0x14;
    w = r->w - 0x10;
    y0 = top + 6;
    h = bottom - 8;
    switch (D_800C35A0->mode) {
    case 1:
        if (D_800ADFE1 || D_800C35A0->x1E == 0) {
            xr = x + w;
            y = top + 0x10;
{ u8 *name; 
            BTN_A(xr - 0x38, y, func_8003CB8C)
            BTN_B(xr - 0x31, y, func_8003CC50)
            BTN_C(xr - 0x2A, y, func_8003CC50)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
        } else {
            xr = x + w;
            y = top + 0x10;
{ u8 *name; 
            BTN_A(xr - 0x38, y, func_8003CC0C)
            BTN_B(xr - 0x31, y, 0)
            BTN_C(xr - 0x2A, y, 0)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
        }
        break;
    case 2:
        if (D_800C35A0->x1E == 0) {
            if (D_800C35A0->flags & 1) {
                x = left;
                y = top + 0x10;
{ u8 *name; 
                BTN_A(x, y, func_8003CB8C)
                BTN_B(x + 7, y, func_8003CC50)
                BTN_C(x + 14, y, func_8003CC50)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
            } else if (obj->type == 3) {
                if (D_800ADFE1) {
                    xr = x + w;
                    y = top + 0x10;
{ u8 *name; 
                    BTN_A(xr - 0x32, y, func_8003CB8C)
                    BTN_B(xr - 0x32 + 7, y, func_8003CC50)
                    BTN_C(xr - 0x32 + 14, y, func_8003CC50)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
                } else {
                    xr = x + w;
                    y = top + 0x10;
{ u8 *name; 
                    BTN_A(xr - 0x32, y, func_8003CC0C)
                    BTN_B(xr - 0x32 + 7, y, 0)
                    BTN_C(xr - 0x32 + 14, y, 0)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
                }
            } else if (D_800ADFE1) {
                y = top + 0x10;
{ u8 *name; 
                BTN_A(x, y, func_8003CB8C)
                BTN_B(left + 0x1B, y, func_8003CC50)
                BTN_C(left + 0x22, y, func_8003CC50)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
            } else {
                y = top + 0x10;
{ u8 *name; 
                BTN_A(x, y, func_8003CC0C)
                BTN_B(left + 0x1B, y, 0)
                BTN_C(left + 0x22, y, 0)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
            }
        } else if (D_800C35A0->flags & 1) {
            if (obj->type == 1) {
                y0 = top + 8;
            }
            xr = x;
            if (D_800ADFE1) {
                y = y0 + h - 0x15;
{ u8 *name; 
                BTN_A(left, y, func_8003CB8C)
                BTN_B(xr - 0x14 + 7, y, func_8003CC50)
                BTN_C(xr - 0x14 + 14, y, func_8003CC50)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
            } else {
                y = y0 + h - 0x15;
{ u8 *name; 
                BTN_A(left, y, func_8003CC0C)
                BTN_B(xr - 0x14 + 7, y, 0)
                BTN_C(xr - 0x14 + 14, y, 0)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
            }
        } else {
            if (obj->type == 3) {
                x = left + 6;
            }
            if (D_800ADFE1) {
                y = bottom - 0x26;
{ u8 *name; 
                BTN_A(x, y, func_8003CB8C)
                BTN_B(x + 7, y, func_8003CC50)
                BTN_C(x + 14, y, func_8003CC50)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
            } else {
                y = bottom - 0x26;
{ u8 *name; 
                BTN_A(x, y, func_8003CC0C)
                BTN_B(x + 7, y, 0)
                BTN_C(x + 14, y, 0)
    b->xA4 = func_80034FF0(name, 0);
    b->xA8 = D_800C7F84;
    b->x7A = *pc - 1;
}
            }
        }
        break;
    default:
        return;
    }

}

