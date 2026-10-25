#include "common.h"

s32 func_8008D4A0();

void func_8007F394(void **arg0, s32 arg1)
{
    char *s0;

    s0 = *arg0;
    if (s0 != NULL) {
        do {
            if (((*(s32 *)(s0 + 0xC)) & 0xFFFF0001) == 0x40001 || *(u16 *)(s0 + 0xC) != 4) {
                func_8008D4A0(s0 + 0x10, arg1, 0);
            }
            s0 = *(char **)(s0 + 4);
        } while (s0 != NULL);
    }
}
