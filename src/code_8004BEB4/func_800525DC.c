#include "common.h"

s32 func_80035438();

void *func_800525DC(void *arg0) {
    char pad[1];
    s32 temp_a0;
    s32 var_s0;
    void *temp_s2;
    void *temp_v0;
    void *var_s1;

    temp_v0 = *(void **)((u8 *)arg0 + 8);
    var_s0 = 0;
    temp_a0 = 0;
    var_s1 = *(void **)((u8 *)temp_v0 + 0x24);
    temp_s2 = (u8 *)temp_v0 + 0x24;
    if ((s32)*(u16 *)((u8 *)temp_v0 + 0x28) > temp_a0) {
        do {
            temp_a0 = *(s32 *)((u8 *)var_s1 + 0x10);
            var_s1 = (u8 *)var_s1 + 0x14;
            func_80035438(temp_a0);
            var_s0 += 1;
        } while (var_s0 < (s32)*(u16 *)((u8 *)temp_s2 + 4));
    }
    return temp_s2;
}
