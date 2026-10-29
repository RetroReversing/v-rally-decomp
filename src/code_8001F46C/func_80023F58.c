#include "snapshot29_0433f7af8f6d.h"

#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif





s32 func_8002DA20();
s32 func_8002E148();
extern u8 *D_800C35A0;

void func_80023F58(void *arg0, void *arg1, s32 arg2) {
    s16 rot[3];
    s32 scale[9];
    s32 temp_v0;
    u32 var_a2;
    s32 var_s2;
    u16 temp_v1_2;
    void *temp_v0_10;
    void *temp_v0_11;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1;

    var_a2 = arg2; temp_v1 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v1 + 0) = 0;
    *(s32 *)((char *)temp_v1 + 4) = 0x32;
    temp_v0 = *(s32 *)((char *)arg0 + 0x90);
    {
        const u8 *gptr;
        gptr = D_800C35A0;
        *(s32 *)((char *)temp_v1 + 8) = temp_v0;
        rot[0] = 0;
        rot[1] = 0;
        rot[2] = 0;
        temp_v1_2 = *(u16 *)(gptr + 0x16);
    }
    var_s2 = *(s32 *)((char *)arg0 + 0xDC);
    switch (temp_v1_2) {                            /* irregular */
    case 0:
        var_a2 = 0;
        var_s2 -= *(s32 *)((char *)arg0 + 0xDC) / 10;
    case 1:
        break;
    case 2:
        var_a2 = 0;
        var_s2 += *(s32 *)((char *)arg0 + 0xDC) / 10;
        break;
    }
    M2C_FIELD(*(void * *)((char *)arg1 + 0x84), s32 *, 0x40) = var_s2;
    M2C_FIELD(*(void * *)((char *)arg1 + 0x84), s32 *, 0x44) = (s32) (0x3E8000 / var_s2);
    func_8002E148(&rot[0], *(void * *)((char *)arg1 + 0x84));
    scale[0] = (*(s32 *)((char *)arg0 + 0x128) * var_s2) / 1000;
    scale[1] = (*(s32 *)((char *)arg0 + 0x174) * var_s2) / 1000;
    scale[2] = (*(s32 *)((char *)arg0 + 0x1C0) * var_s2) / 1000;
    func_8002DA20(*(void * *)((char *)arg1 + 0x84), &scale[0]);
    scale[0] = 0x20000 / scale[0];
    scale[1] = 0x20000 / scale[1];
    scale[2] = 0x20000 / scale[2];
    func_8002E148(&rot[0], *(void * *)((char *)arg1 + 0x84) + 0x20);
    func_8002DA20(*(void * *)((char *)arg1 + 0x84) + 0x20, &scale[0]);
    temp_v0_2 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_2 + 0xC) = 0;
    *(s32 *)((char *)temp_v0_2 + 0x10) = 0;
    *(s32 *)((char *)temp_v0_2 + 0x14) = 0;
    temp_v0_3 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_3 + 0x20) = 0;
    *(s32 *)((char *)temp_v0_3 + 0x24) = 0;
    *(s32 *)((char *)temp_v0_3 + 0x28) = 0;
    temp_v0_4 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_4 + 0x34) = 0;
    *(s32 *)((char *)temp_v0_4 + 0x38) = 0;
    *(s32 *)((char *)temp_v0_4 + 0x3C) = 0;
    temp_v0_5 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_5 + 0x48) = 0;
    *(s32 *)((char *)temp_v0_5 + 0x4C) = 0;
    *(s32 *)((char *)temp_v0_5 + 0x50) = 0;
    M2C_FIELD(*(void * *)((char *)arg1 + 0x84), s32 *, 0x48) = (s32) *(s32 *)((char *)arg0 + 0x20C);
    M2C_FIELD(*(void * *)((char *)arg1 + 0x2C), s32 *, 0x50) = 0;
    M2C_FIELD(*(void * *)((char *)arg1 + 0x2C), s32 *, 0x4C) = (s32) (*(s32 *)((char *)arg0 + 0x258) << 5);
    temp_v0_6 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_6 + 0x5C) = 0;
    *(s32 *)((char *)temp_v0_6 + 0x60) = 0;
    *(s32 *)((char *)temp_v0_6 + 0x64) = 0;
    temp_v0_7 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_7 + 0x70) = 0;
    *(s32 *)((char *)temp_v0_7 + 0x74) = 0;
    *(s32 *)((char *)temp_v0_7 + 0x78) = 0;
    temp_v0_8 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_8 + 0x98) = 0;
    *(s32 *)((char *)temp_v0_8 + 0x9C) = 0;
    *(s32 *)((char *)temp_v0_8 + 0xA0) = 0;
    temp_v0_9 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_9 + 0xAC) = 0;
    *(s32 *)((char *)temp_v0_9 + 0xB0) = 0;
    *(s32 *)((char *)temp_v0_9 + 0xB4) = 0;
    temp_v0_10 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_10 + 0xC0) = 0;
    *(s32 *)((char *)temp_v0_10 + 0xC4) = 0;
    *(s32 *)((char *)temp_v0_10 + 0xC8) = 0;
    temp_v0_11 = *(void * *)((char *)arg1 + 0x2C);
    *(s32 *)((char *)temp_v0_11 + 0xD4) = 0;
    *(s32 *)((char *)temp_v0_11 + 0xD8) = 0;
    *(s32 *)((char *)temp_v0_11 + 0xDC) = 0;
    M2C_FIELD(*(void * *)((char *)arg1 + 0x80), s32 *, 0x388) = (s32) ((var_s2 * 0xA) / 22);
    M2C_FIELD(*(void * *)((char *)arg1 + 0x88), s32 *, 0x84) = 0;
}
