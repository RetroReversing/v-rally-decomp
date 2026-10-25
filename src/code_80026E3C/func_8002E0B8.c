#include "common.h"

void func_8002E0B8(s32 *arg0, s32 *arg1) {
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ((s32 *)((u8 *)arg0 + i * 16))[j] = 0;
        }
    }
    *(f32 *)((u8 *)arg0 + 0x30) = (f32)arg1[5];
    *(f32 *)((u8 *)arg0 + 0x34) = (f32)arg1[6];
    *(f32 *)((u8 *)arg0 + 0x38) = (f32)arg1[7];
    *(f32 *)((u8 *)arg0 + 0x3C) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x00) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x14) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x28) = 1.0f;
}
