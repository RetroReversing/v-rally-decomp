#include "common.h"

void *func_80022668(s32, s32);
s32 func_8004CEB4(s32, void *, s16 *, u8, s32, s32, s32, s32, s32);
extern void *D_800A11B0;

#define NODE_Q(t) (*(void ***)((u8 *)*(void ***)((u8 *)(t) + 0xC) + 4))

void func_8004CF7C(s32 arg0, u16 arg1, s16 arg2, s16 arg3, f32 arg4, u8 arg5, u16 arg6) {
    s16 sp28[4];
    void *temp_v0;
    u8 temp_s4;
    s32 temp_s2;

    temp_s4 = arg5;
    temp_s2 = arg6;
    temp_v0 = func_80022668((s32)D_800A11B0, arg1);
    if (temp_v0 != NULL) {
        sp28[0] = arg2;
        sp28[1] = arg3;
        sp28[2] = (s16)(s32)((f32)*(u16 *)((u8 *)*NODE_Q(temp_v0) + 6) * arg4);
        sp28[3] = (s16)(s32)((f32)*(u16 *)((u8 *)*NODE_Q(temp_v0) + 8) * arg4);
        func_8004CEB4(arg0, *NODE_Q(temp_v0), sp28, temp_s4, temp_s2 & 0xFF, temp_s2 & 0xFF, temp_s2 & 0xFF, temp_s2 & 0xFF, 0);
    }
}
