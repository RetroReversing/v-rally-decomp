#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 r, g, b, a; } Col;
typedef struct { s8 a, b; } Pair;
typedef struct {
    Col c0, c1, c2;
    u16 x, y, z;
    Pair n[3];
    u16 id;
} Src;
typedef struct {
    Col c0, c1, c2, c3;
    u16 x, y, z;
    s16 w;
    Pair n[3];
    u8 e, f;
    u16 id;
} Dst;
typedef struct { Src *items; u16 count; } SrcList;
s32 func_80098180(u8 *, u8 *);
extern u8 D_800A1300[];
extern u8 D_800A1308[];
extern u8 D_800AE850[];

void func_80055904(Dst **out, SrcList *list)
{
    Src *src = list->items;
    u16 count = list->count;
    s32 i;
    u8 *name;

    for (i = 0; i < count; src++, i++) {
        (*out)->x = src->x;
        (*out)->y = src->y;
        (*out)->z = src->z;
        (*out)->w = 0;
        (*out)->c0 = src->c0;
        (*out)->c0.a = 6;
        (*out)->c1 = src->c1;
        (*out)->c2 = src->c2;
        (*out)->c3.r = 0;
        (*out)->c3.g = 0;
        (*out)->c3.b = 0;
        (*out)->c3.a = 0;
        (*out)->n[0] = src->n[0];
        (*out)->n[1] = src->n[1];
        (*out)->n[2] = src->n[2];
        (*out)->e = 0;
        (*out)->f = 0;
        (*out)->id = src->id;
        name = *(u8 **)(D_800AE850 + 0x237C) + src->id * 0x14;
        if (func_80098180(name, D_800A1300) == 0 || func_80098180(name, D_800A1308) == 0) {
            (*out)->c0.r = 0xFF;
            (*out)->c0.g = 0xFF;
            (*out)->c0.b = 0xFF;
            (*out)->c1.r = 0xFF;
            (*out)->c1.g = 0xFF;
            (*out)->c1.b = 0xFF;
            (*out)->c1.a = 0xFF;
            (*out)->c2.r = 0xFF;
            (*out)->c2.g = 0xFF;
            (*out)->c2.b = 0xFF;
            (*out)->c2.a = 0xFF;
        }
        (*out)++;
    }
}
