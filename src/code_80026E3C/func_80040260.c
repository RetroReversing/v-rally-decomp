#include "decompdecomp_contract_func_80040260.h"
#line 1 "func.c"
extern u32 D_8000A840;
void *func_800802A0(void *, s32);
typedef void (*SpriteHook)(void *);
typedef struct { u8 r; u8 g; u8 b; u8 a; } Color4;

void *func_80040260(void *arg0, s16 arg1, s16 arg2, s32 arg3, SpriteHook arg4, s32 unused_mode) {
    s16 layer = arg3;
    Color4 col;
    u8 *temp_v0;

    temp_v0 = func_800802A0(arg0, 0xB0);
    col.r = 0xFF;
    col.g = 0xFF;
    col.b = 0xFF;
    col.a = 0x80;
    *(s32 *)(temp_v0 + 0x80) = 1;
    *(s16 *)(temp_v0 + 0x7E) = -1;
    *(s16 *)(temp_v0 + 0x7C) = -1;
    *(s16 *)(temp_v0 + 0x7A) = 0;
    *(s16 *)(temp_v0 + 0x74) = layer;
    *(s16 *)(temp_v0 + 0xC) = arg1;
    *(s16 *)(temp_v0 + 0xE) = arg2;
    *(s32 *)(temp_v0 + 0x8C) = 0;
    *(s16 *)(temp_v0 + 0x78) = 0;
    *(s16 *)(temp_v0 + 0x70) = 0;
    *(s16 *)(temp_v0 + 0x72) = 0;
    *(s16 *)(temp_v0 + 0x98) = 0x400;
    *(s16 *)(temp_v0 + 0x9A) = 0x400;
    *(SpriteHook *)(temp_v0 + 0x84) = arg4;
    *(Color4 *)(temp_v0 + 0x90) = col;
    *(s32 *)(temp_v0 + 0xA0) = 1;
    *(u32 **)(temp_v0 + 0x88) = &D_8000A840;
    return temp_v0;
}

