#include "common.h"

void func_8001C358(f32 *arg0, s32 arg1) {
    f32 *var_a2;
    f32 *var_v0;
    f32 var_fv0;
    s32 var_a3;
    s32 var_t0;
    s32 var_t1;
    s32 var_v1;
    f32 *phi_a0;

    var_t0 = 0;
    phi_a0 = arg0;
    do {
        var_a3 = 0;
        var_t1 = var_t0 * 4;
        var_a2 = phi_a0;
        var_v1 = arg1;
loop_2:
        var_fv0 = *var_a2;
        var_a2 += 1;
        var_v0 = (f32 *) (var_t1 + var_v1);
        *var_v0 = var_fv0;
        var_v1 += 0x10;
        if (++var_a3 < 4) {
            goto loop_2;
        }
        var_t0 += 1;
        phi_a0 = phi_a0 + 4;
    } while (var_t0 < 4);
}
