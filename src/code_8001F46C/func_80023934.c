#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

s32 func_800237BC(s32, Vec3i *, Vec3i *);

void func_80023934(s32 arg0, Vec3i *arg1, Vec3i *arg2) {
    Vec3i sp10;
    Vec3i sp20;

    sp10 = *arg2;
    sp10.x >>= 2;
    sp10.y >>= 2;
    sp10.z >>= 2;
    sp20 = *arg1;
    sp20.x >>= 5;
    sp20.y >>= 5;
    sp20.z >>= 5;
    func_800237BC(arg0, &sp20, &sp10);
}
