#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct S1 {
    u8 pad0[0x24];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x4C - 0x30];
    s32 unk4C;
    u8 pad50[0x54 - 0x50];
    Vec3s *unk54;
    u8 pad58[0x88 - 0x58];
    u16 unk88;
    u16 unk8A;
} S1;

void func_8002D2C8(s32, s32);

void func_8001FFC4(s32 *arg0, S1 *arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 off;
    s32 t;
    s32 x;
    Vec3s *base;
    Vec3s *w;

    i = (s16)arg3;
    i *= arg1->unk8A; t = (s16)arg2;
    i += arg1->unk4C; i += t;
    x = arg1->unk24;
    base = arg1->unk54;
    off = i * 6;
    arg0[0] = ((Vec3s *)(off + (int)base))->x + x;
    arg0[1] = ((Vec3s *)(off + (int)arg1->unk54))->y + arg1->unk28;
    arg0[2] = ((Vec3s *)(off + (int)arg1->unk54))->z + arg1->unk2C;
    i += arg1->unk8A;
    w = (Vec3s *)(i * 6 + (int)arg1->unk54);
    func_8002D2C8(w->x - ((Vec3s *)(off + (int)arg1->unk54))->x, w->z - ((Vec3s *)(off + (int)arg1->unk54))->z);
}

