#include "common.h"

void *func_8003AEF8(void *arg0, s32 arg1);
s32 func_8003B198(void *arg0, s32 arg1);

void func_8003B2C0(void *arg0)
{
    void *temp_v0;

    temp_v0 = *(void **)((char *)*(void **)((char *)arg0 + 0xA8) + 0x24);
    if (temp_v0 != NULL) {
        temp_v0 = func_8003AEF8(arg0, (s32)temp_v0);
        if (temp_v0 != NULL) {
            func_8003B198(arg0, *(s32 *)(*(s32 *)((char *)temp_v0 + 0x6C) + 0xC));
        }
    }
}
