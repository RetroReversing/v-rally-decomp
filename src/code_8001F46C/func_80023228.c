#include "common.h"

void *func_800231A8();
extern u8 D_800C02AE[];

void *func_80023228(void **arg0, s32 arg1, s32 arg2, void *arg3)
{
    s32 i;
    s32 v;

    i = 0;
    if (arg0 != NULL && D_800C02AE[0x7CF3] != D_800C02AE[0x7D0B]) {
        arg3 = *arg0;
        if (arg3 != NULL) {
            arg2 = (arg2 & 0xFF) * 0x18;
            arg1 &= 0xFF;
            i = 0;
            do {
                s32 k = i;
                i++;
                if (D_800C02AE[0x7CF3 + arg2] == (u8)k) {
                    v = *(s32 *)((char *)arg3 + 0x14);
                    if ((v & arg1) != arg1) {
                        *(s32 *)((char *)arg3 + 0x14) = v | arg1;
                        return arg3;
                    }
                }
                arg3 = *(void **)((char *)arg3 + 4);
            } while (arg3 != NULL);
        }
    }
    return func_800231A8(arg0, arg1, arg2, arg3);
}
