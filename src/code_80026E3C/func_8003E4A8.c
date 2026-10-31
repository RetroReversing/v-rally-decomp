#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Cfg3E {
    u8 pad0[8];
    s16 x;
    s16 y;
    u8 padC[2];
    s16 h;
} Cfg3E;

typedef struct View3E {
    u8 pad0[0x178];
    Cfg3E *cfg;
} View3E;

typedef struct Game3E {
    u8 pad0[0xE];
    u16 mode;
    u8 pad10[0xE];
    u16 state;
} Game3E;

extern View3E *D_800C7F84;
extern Game3E *D_800C35A0;
void func_8003A794(void *, s32, s32, void (*)(), s32, u16, u8 *);
void func_8003B7BC();

void func_8003E4A8(void *arg0, s32 arg1)
{
    u8 col[4];
    u32 i;
    s32 x;
    s32 y;
    s32 h;
    Cfg3E *cfg = D_800C7F84->cfg;

    x = cfg->x + 0x14;
    y = cfg->y + 6;
    h = cfg->h;
    if (D_800C35A0->mode == 1 && D_800C35A0->state == 0) {
        h -= 8;
        for (i = 0; i < 4; i++) {
            switch (i) {
            case 0:
                col[0] = 0x78;
                col[1] = 0x78;
                col[2] = 0x78;
                col[3] = 0xFF;
                break;
            case 1:
                col[0] = 0xA0;
                col[1] = 0xA0;
                col[2] = 0xA0;
                col[3] = 0xFF;
                break;
            case 2:
                col[0] = 0xC8;
                col[1] = 0xC8;
                col[2] = 0xC8;
                col[3] = 0xFF;
                break;
            case 3:
                col[0] = 0xF0;
                col[1] = 0xF0;
                col[2] = 0xF0;
                col[3] = 0xFF;
                break;
            }
            func_8003A794(arg0, x, y + h - (6 - i) * 10 + 2, func_8003B7BC, arg1, i, col);
        }
    }
}

