#include "common.h"

s32 func_8000E20C();
s32 func_8007EE9C();
extern s32 D_8009B5A0;
extern s32 *D_8009B5A4;
extern s32 *D_8009B5A8;
extern s32 *D_8009B5AC;

s32 func_80005B00(s32 arg0, s32 arg1) {
    s32 var_s1;
    s32 var_v1;
    s32 *temp_v0;
    s32 *temp_s0;

    var_s1 = arg1;
    var_v1 = 0;
    if (arg0 != 0) {
        temp_v0 = D_8009B5A4;
        if (temp_v0 == NULL) {
            goto done;
        }
        temp_s0 = temp_v0;
        if (var_s1 == temp_s0[6]) {
            goto done;
        }
        if (temp_s0[3] != 0) {
            func_8007EE9C(temp_s0[3]);
        }
        temp_s0[3] = 0;
        if (D_8009B5A4 != D_8009B5A8) {
            temp_s0 = D_8009B5A8;
            if (temp_s0[3] != 0) {
                func_8007EE9C(temp_s0[3]);
            }
            temp_s0[3] = 0;
        }
        temp_v0 = D_8009B5AC;
        if (temp_v0 != NULL) {
            temp_s0 = temp_v0;
            if (temp_s0[3] != 0) {
                func_8007EE9C(temp_s0[3]);
            }
            temp_s0[3] = 0;
        }
    }
    func_8000E20C(var_s1);
    D_8009B5A0 = var_s1;
    var_v1 = 1;
done:
    return var_v1;
}
