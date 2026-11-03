#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
void func_80038AE4(s32 a);
void func_80046414(s32 a, s32 b)
{
    if (b == 1) {
        if (a == 1) goto s6;
        if (a == 0) goto s2;
        if (a == 2) goto s4;
        return;
    s2:
        a = 2;
        goto call;
    }
    if (b == 2) {
        if (a == 1) goto s5;
        if (a == 0) goto s1;
        if (a == b) goto s3;
        return;
    }
    if (a == 6) {
        if (b != 8) return;
        a = 0x12;
        goto call;
    }
    if (a != 3) return;
    a = 0;
    goto call;
s6: a = 6; goto call;
s4: a = 4; goto call;
s5: a = 5; goto call;
s1: a = 1; goto call;
s3: a = 3;
call:
    func_80038AE4(a);
}

