#include "common.h"

s32 __osPfsSelectBank(void *, s32);
s32 func_80096830(s32, s32, s32, s32 *);
s32 func_80097620(void *, s32 *, s32);

s32 __osCheckId(void *arg0)
{
    s32 buf[8];
    s32 v;

    if (*(u8 *)((char *) arg0 + 0x65) != 0) {
        v = __osPfsSelectBank(arg0, 0);
        if (v == 2) {
            v = __osPfsSelectBank(arg0, 0);
        }
        if (v != 0) {
            return v;
        }
    }
    v = func_80096830(*(s32 *)((char *) arg0 + 4), *(s32 *)((char *) arg0 + 8), 1, buf);
    if (v != 0) {
        if (v != 2) {
            return v;
        }
        v = func_80096830(*(s32 *)((char *) arg0 + 4), *(s32 *)((char *) arg0 + 8), 1, buf);
        if (v != 0) {
            return v;
        }
    }
    return (func_80097620((char *) arg0 + 0xC, buf, 0x20) != 0) * 2;
}
