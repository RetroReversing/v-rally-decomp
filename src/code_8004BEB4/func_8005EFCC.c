#include "common.h"

extern f64 D_800A54D8;
extern f64 D_800A54E0;
void func_8005EFCC(s32 arg0, f32 *arg1)
{
    f32 var_fv1;
    var_fv1 = (f64)(*arg1);
    if (var_fv1 < D_800A54D8) {
        var_fv1 = (f32)(var_fv1 + D_800A54E0);
    } else {
        var_fv1 = 1.0f;
    }
    *arg1 = var_fv1;
}
