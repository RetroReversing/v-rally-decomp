#include "common.h"

s32 alEnvmixerParam(char *arg0, s32 arg1, s32 *arg2)
{
    char *temp_v1 = arg0;
    s32 *temp_a0;
    s32 *temp_v0;
    s32 (*var_v0)(s32 *, s32);

    switch (arg1) {
    case 1:
        *(s32 **)arg0 = arg2;
        break;
    case 3:
        temp_v0 = *(s32 **)(arg0 + 0x40);
        if (temp_v0 != NULL) {
            *temp_v0 = (s32)arg2;
        } else {
            *(s32 **)(arg0 + 0x3C) = arg2;
        }
        *(s32 **)(temp_v1 + 0x40) = arg2;
        break;
    case 4:
        temp_v1 = *(char **)arg0;
        *(s32 *)(arg0 + 0x38) = 1;
        *(s32 *)(arg0 + 0x48) = 0;
        *(s16 *)(arg0 + 0x1A) = 1;
        if (temp_v1 != NULL) {
            temp_a0 = (s32 *)temp_v1;
            var_v0 = *(s32 (**)(s32 *, s32))((char *)temp_a0 + 8);
            var_v0(temp_a0, 4);
        }
        break;
    case 9:
        temp_v1 = *(char **)arg0;
        *(s32 *)(arg0 + 0x48) = 1;
        if (temp_v1 != NULL) {
            temp_a0 = (s32 *)temp_v1;
            var_v0 = *(s32 (**)(s32 *, s32))((char *)temp_a0 + 8);
            var_v0(temp_a0, 9);
        }
        break;
    default:
        temp_a0 = *(s32 **)arg0;
        if (temp_a0 != NULL) {
            var_v0 = *(s32 (**)(s32 *, s32))((char *)temp_a0 + 8);
            var_v0(temp_a0, arg1);
        }
        break;
    }
    return 0;
}
