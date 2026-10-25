#include "common.h"

s32 func_8007EF5C(s32);
s32 func_8007EAA0(s32, s32);
void func_8007EE9C(s32);

s32 func_800225D8(s32 arg0)
{
    s32 r;
    s32 r2;

    r = func_8007EF5C(arg0);
    if (r != 0) {
        r2 = func_8007EAA0(arg0, r);
        if (r2 != 0) {
            r += func_800225D8(arg0);
            func_8007EE9C(r2);
        }
    }
    return r;
}
