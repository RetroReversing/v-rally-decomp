#include "common.h"

s32 func_80014598();

void func_80014C70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_80014598(arg0, arg1, arg0, arg3, arg4);
    func_80014598(arg0, arg3, arg2, arg3, arg4);
    func_80014598(arg2, arg3, arg2, arg1, arg4);
    func_80014598(arg2, arg1, arg0, arg1, arg4);
}
