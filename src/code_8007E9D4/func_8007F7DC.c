#include "common.h"

s32 func_8008D4A0();
extern char D_800AE850[];

void func_8007F7DC(s32 arg0, s32 arg1, s32 arg2) {
    func_8008D4A0(((arg0 + arg1) * 0x5C) + (D_800AE850 + 0x5924), arg2, 1);
}
