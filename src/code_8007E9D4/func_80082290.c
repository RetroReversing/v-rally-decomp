#include "common.h"

s32 func_80081E8C();
extern char D_800AE850[];

s32 func_80082290(s32 arg0) {
    if (arg0 != 0) {
        func_80081E8C(D_800AE850 + 0x8A30, arg0);
        *(D_800AE850 + 0x8A30 + arg0) = 0;
    }
    return 0;
}
