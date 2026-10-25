#include "common.h"

void *func_80022668(s32, s32);
s32 func_8004CEB4(s32, void *, s16 *, u8, s32, s32, s32, s32, s32);
extern s32 D_800A11B0;

void func_8004D08C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7) {
    s16 sp28[4];
    void *temp_v0;

    temp_v0 = func_80022668(D_800A11B0, arg1 & 0xFFFF);
    if (temp_v0 != NULL) {
        sp28[0] = arg2;
        sp28[1] = arg3;
        sp28[2] = (s16)(s32)((f32)*(u16 *)(*(char **)(*(char **)(*(char **)((char *)temp_v0 + 0xC) + 4)) + 6) * arg4);
        sp28[3] = (s16)(s32)((f32)*(u16 *)(*(char **)(*(char **)(*(char **)((char *)temp_v0 + 0xC) + 4)) + 8) * arg5);
        func_8004CEB4(arg0, *(void **)(*(char **)(*(char **)((char *)temp_v0 + 0xC) + 4)), sp28, arg6, arg7, arg7, arg7, arg7, 0);
    }
}
