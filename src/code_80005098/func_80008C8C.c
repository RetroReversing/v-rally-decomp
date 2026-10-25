#include "common.h"

void func_80008C8C(s16 *arg0, s32 arg1)
{
    s32 pad;
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg0[3] = 3;
        arg0 += 8;
    }
}
