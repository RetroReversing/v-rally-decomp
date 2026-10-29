#include "snapshot29_0433f7af8f6d.h"

extern signed char D_800AE864;
s32 func_8000DD40(void *, s32, s32, void **);
extern char D_800AE850[];

u8 func_80005F38(void *arg0, void *arg1) {
    s32 var_a1;
    s32 var_a2;
    u8 var_v0;
    u8 var_v1;
    void **var_a3;

    var_a3 = (void **)(D_800AE850 + 0xC);
    var_a2 = 1;
    *(void **)(D_800AE850 + 0x10) = arg0;
    *var_a3 = arg1;
    D_800AE864 = 1;
    *(s32 *)((char *)arg0 + 8) = var_a2;
    var_v0 = *(u8 *)((char *)arg1 + 0x14);
    var_v1 = 0;
    if (var_v0 != 0) {
        *(void **)(D_800AE850 + 0x10) = arg0;
        *var_a3 = arg1;
        var_a1 = 0;
        *(volatile s32 *)((char *)arg0 + 8) = var_a2;
        func_8000DD40(arg0, var_a1, var_a2, var_a3);
        var_v1 = 1;
    }
    return var_v1;
}
