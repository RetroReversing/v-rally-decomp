#include "common.h"

void guMtxL2F(f32 *arg0, s32 *arg1)
{
    volatile s32 sp0;
    volatile s32 sp4;
    s32 var_t1;
    s32 var_a3;
    s32 temp_v0;
    s32 temp_v1;
    s32 *var_a1;
    u16 *var_t0;
    f32 *var_a2;

    var_t0 = (u16 *) ((char *) arg1 + 0x20);
    var_t1 = 0;
    var_a1 = arg1;
    do {
        var_a3 = 0;
        var_a2 = arg0;
        do {
            temp_v0 = (*var_a1 & 0xFFFF0000) | var_t0[0];
            sp0 = temp_v0;
            temp_v1 = ((*var_a1 << 0x10) & 0xFFFF0000) | var_t0[1];
            sp4 = temp_v1;
            var_a2[0] = (f32) temp_v0 * 0.000015258789f;
            var_a2[1] = (f32) temp_v1 * 0.000015258789f;
            var_a3 += 1;
            var_t0 += 2;
            var_a1 += 1;
            var_a2 += 2;
        } while (var_a3 < 2);
        var_t1 += 1;
        arg0 += 4;
    } while (var_t1 < 4);
}
