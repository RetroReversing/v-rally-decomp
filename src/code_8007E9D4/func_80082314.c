#include "common.h"

u8 func_80082314(s32 arg0)
{
    s32 v1;
    u8 c;

    v1 = arg0;
    if ((u8)(arg0 - 0x41) < 0x1B) {
        return (u8)(arg0 + 0x20);
    }
    c = v1;
    if (c == 0x5C) {
        return 0x2F;
    }
    return c;
}
