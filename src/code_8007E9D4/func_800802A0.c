#include "decompdecomp_snapshot_800802a0.h"
#line 1 "func.c"
s32 func_8007EAA0(s32, s32, ...);
s32 memset(s32, s32, u32);
void func_80080110(void *, void *);
void *func_800802A0(void *list, s32 size) {
    void *object;
    object = (void *)func_8007EAA0(6, size);
    memset((s32)object, 0, (u32)size);
    func_80080110(object, list);
    return object;
}

