#include "common.h"

extern int D_800B56EC;
void func_80015460(u32 *arg0, s32 arg1) {
    char pad[8];
    s32 i;
    u32 *p;
    u32 v;
    p = arg0;
    i = 0;
    if (arg1 > 0) {
        do {
            v = *p;
            i++;
            if (v <= 0x7FFFFFFFU) *p = v + D_800B56EC;
            p += 2;
        } while (i < arg1);
    }
}
