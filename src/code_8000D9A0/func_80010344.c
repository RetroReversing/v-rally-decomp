#include "common.h"

s32 func_80098180();
extern s32 D_8009B9E0;
extern s32 D_8009B9E4;

s32 *func_80010344(s32 arg0) {
    s32 *var_s0;

    var_s0 = &D_8009B9E0;
    if (D_8009B9E4 == 0) {
        goto block_6;
    }
loop_1:
    if (func_80098180(arg0, *var_s0) == 0) {
        goto block_3;
    }
    var_s0 += 3;
    goto block_5;
block_3:
    return var_s0;
block_5:
    if (var_s0[1] != 0) {
        goto loop_1;
    }
block_6:
    return NULL;
}
