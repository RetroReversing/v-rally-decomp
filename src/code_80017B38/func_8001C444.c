#include "common.h"

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

void func_8002D2C8(s32, s32, s16, Vec3s *);

void func_8001C444(s32 *arg0, S1 *arg1) {
    s32 i;
    s32 off;
    Vec3s *w;
 s32 x, val; Vec3s *base;

    i = arg1->unk88 >> 1;
 i *= arg1->unk8A;
 i += arg1->unk4C;
    
    x = arg1->unk24;
 base = arg1->unk54;
 off = i * 6;
 val=((Vec3s *)(off + (int)base))->x;
 val+=x;
 arg0[0]+=val;
    arg0[1] = (((Vec3s *)(off + (int)arg1->unk54))->y + arg1->unk28) - 0x96;
    arg0[2] += ((Vec3s *)(off + (int)arg1->unk54))->z + arg1->unk2C;
    i += arg1->unk8A;
    w = (Vec3s *)(i * 6 + (int)arg1->unk54);
    func_8002D2C8(w->x - ((Vec3s *)(off + (int)arg1->unk54))->x, w->z - ((Vec3s *)(off + (int)arg1->unk54))->z, w->x, (Vec3s *)(off + (int)arg1->unk54));
}
