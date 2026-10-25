#include "common.h"

s32 func_80010EC8();
s32 func_80010F3C();
s32 func_80085374();
s32 func_800855F8();
extern s32 D_8009D538;

void func_80010F90(s32 arg0, void *arg1) {
    s32 var_s1;
    s32 var_v0;
    s32 temp_a0;

    if (!(D_8009D538 & 0x800)) {
        temp_a0 = *(s32 *)(*(u8 **)((u8 *)arg1 + 0x48));
        var_s1 = 0;
        if (temp_a0 < 4) {
            var_s1 = func_80085374(temp_a0 & 0xff);
        }
        if (var_s1 & 0x400) {
            func_800855F8(*(u8 *)(*(u8 **)((u8 *)arg1 + 0x48) + 3), 0x400);
            func_800855F8(*(u8 *)(*(u8 **)((u8 *)arg1 + 0x48) + 3), 0x800);
            func_80010EC8(arg0, arg1);
            func_80010F3C(arg0, 0);
        }
        var_v0 = var_s1 & 0x800;
        if (var_v0 != 0) {
            func_80010F3C(arg0, 1);
        } else {
            func_80010F3C(arg0, 0);
        }
    }
}
