#include "common.h"

s32 alLink();
s32 alUnlink();

s32 _allocatePVoice(u8 *arg0, void **arg1, s16 arg2)
{
    s32 found = 0;
    void *s0;

    s0 = *(void **)(arg0 + 0x14);
    if (s0 == NULL) {
        s0 = *(void **)(arg0 + 0x4);
    }
    if (s0 != NULL) {
        *arg1 = s0;
        alUnlink(s0);
        alLink(s0, arg0 + 0xC);
    } else {
        s0 = *(void **)(arg0 + 0xC);
        while (s0 != NULL) {
            if (arg2 >= *(s16 *)(*(u8 **)((u8 *)s0 + 8) + 0x16) && *(s32 *)((u8 *)s0 + 0xD8) == 0) {
                *arg1 = s0;
                found = 1;
                arg2 = *(u16 *)(*(u8 **)((u8 *)s0 + 8) + 0x16);
            }
            s0 = *(void **)s0;
        }
    }
    return found;
}
