#include "common.h"

void *func_8007EAA0();
s32 func_8000DBC0();

void *func_80005CB8(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_v0;
    void *temp_v0_2;
    s32 temp_s0;

    temp_v0 = func_8007EAA0(arg3, 0x90);
    if (temp_v0 != NULL) {
        if (arg1 != 0) {
            if (arg2 != 0) {
                arg2 *= 0x10;
                temp_v0_2 = func_8007EAA0(arg4, arg2);
                *(void **)((char *)temp_v0 + 0x70) = temp_v0_2;
                temp_v0_2 += arg2;
                *(void **)((char *)temp_v0 + 0x74) = temp_v0_2;
            } else {
                *(void **)((char *)temp_v0 + 0x70) = NULL;
                *(void **)((char *)temp_v0 + 0x74) = NULL;
            }
            temp_s0 = arg1 * 8;
            temp_v0_2 = func_8007EAA0(arg4, temp_s0);
            *(void **)((char *)temp_v0 + 0x10) = temp_v0_2;
            temp_v0_2 += temp_s0;
            *(void **)((char *)temp_v0 + 0xC) = temp_v0_2;
        } else {
            *(void **)((char *)temp_v0 + 0x10) = NULL;
            *(void **)((char *)temp_v0 + 0x70) = NULL;
            *(void **)((char *)temp_v0 + 0x74) = NULL;
            *(void **)((char *)temp_v0 + 0xC) = NULL;
        }
        *(s16 *)((char *)temp_v0 + 0x1C) = arg0;
        *(s16 *)((char *)temp_v0 + 4) = 0;
        *(s16 *)((char *)temp_v0 + 6) = 0;
        *(s16 *)((char *)temp_v0 + 0x7A) = 0;
        func_8000DBC0(temp_v0);
    }
    return temp_v0;
}
