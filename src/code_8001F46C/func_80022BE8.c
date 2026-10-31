#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Item22 {
    u32 n0;
    u32 n1;
    u32 flags;
    s32 pad0C;
    void (*proc)(void *);
    s32 pad14[2];
} Item22;

typedef struct Obj22 {
    u8 pad0[0x1C];
    s32 *a[11];
    s32 *b[11];
    s32 *c[11];
    u8 padA0[0xD0 - 0xA0];
    Item22 *items;
} Obj22;

typedef struct Game22 {
    u8 pad0[0x1E];
    u16 f1E;
} Game22;

extern s32 D_8009C230;
extern Game22 *D_800C35A0;

void func_80022BE8(Obj22 *obj, s32 *data)
{
    u32 i;
    u32 k;

    for (i = 0; i < 11; i++) {
        if (obj->items[i].flags & 1) {
            for (k = 0; k < obj->items[i].n0; k++) {
                if (D_800C35A0->f1E != 0 || i != 10 || *obj->b[0] >= 4) {
                    if (i == 6 && k == 0x54) {
                        obj->b[i][k] = D_8009C230 - data[k];
                        obj->a[i][k] = D_8009C230 - data[k];
                    } else {
                        obj->b[i][k] = data[k];
                        obj->a[i][k] = data[k];
                    }
                }
            }
            data += obj->items[i].n0;
        }
        if (obj->items[i].flags & 2) {
            for (k = 0; k < obj->items[i].n1; k++) {
                obj->c[i][k] = data[k];
            }
            data += obj->items[i].n1;
        }
        if (obj->items[i].flags & 4) {
            obj->items[i].proc(obj);
        }
    }
}

