#include "common.h"

s32 func_80084FBC();

void func_800852FC(u8 arg0, u8 *arg1, u32 arg2) {
    u8 i;

    i = 0;
    if (arg2 != 0) {
        do {
            func_80084FBC(arg0, *(s32 *)(arg1 + i * 8), *(s32 *)(arg1 + i * 8 + 4));
            i++;
        } while (i < arg2);
    }
}
