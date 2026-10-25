#include "common.h"

void func_8002D75C(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    *arg3 = ((arg0 >> 16) * (s16)arg1) + ((arg1 >> 16) * (s16)arg2) + ((arg2 >> 16) * (s16)arg0) - ((arg0 >> 16) * (s16)arg2) - ((arg1 >> 16) * (s16)arg0) - ((arg2 >> 16) * (s16)arg1);
}
