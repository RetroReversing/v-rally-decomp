#include "common.h"

s32 osSendMesg();
extern char D_800AE850[];

void func_8007F7DC(s32 arg0, s32 arg1, s32 arg2) {
    osSendMesg(((arg0 + arg1) * 0x5C) + (D_800AE850 + 0x5924), arg2, 1);
}
