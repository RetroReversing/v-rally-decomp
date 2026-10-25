#include "common.h"

s32 func_8008BF00(void *a0, s32 a1, s32 a2, s32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8, f32 a9, f32 a10);
s32 func_8008C6E0(void *a0, s32 a1);

void func_8008C478(s32 arg0, s32 a1, s32 a2, s32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8, f32 a9, f32 a10) {
    s32 buf[16];

    func_8008BF00(buf, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    func_8008C6E0(buf, arg0);
}
