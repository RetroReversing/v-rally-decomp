#include "decompdecomp_8005a05c_validated.h"
#line 1 "func.c"
extern void *D_800C5D28;
void func_8005A05C(s32 arg0)
{
    s32 var_a0;
    s32 var_a1;
    void *var_v1;

    var_v1 = **(void ***)((s8 *)D_800C5D28 + 0x10);
    var_a1 = 0;
    if (var_v1 != NULL) {
        var_a0 = arg0 & 0xFF;
loop_2:
        if ((var_a1 & 0xFF) == var_a0) {
            *(s32 *)((s8 *)var_v1 + 0xC) |= 2;
            return;
        }
        var_v1 = *(void **)((s8 *)var_v1 + 4);
        var_a1 += 1;
        if (var_v1 != NULL) {
            goto loop_2;
        }
    }
}

