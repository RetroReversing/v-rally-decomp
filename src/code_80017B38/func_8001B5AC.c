#include "common.h"

void func_8001B5AC(u8 *arg0)
{
    u8 i = 0;
    s16 one = 1;
    u8 three = 3;

    *(s16 *) (arg0 + 0xE) = one;
    *(arg0 + 0x30) = three;
    *(s16 *) (arg0 + 0x12) = one;
    *(s16 *) (arg0 + 0x14) = one;
    *(s16 *) (arg0 + 0x16) = 0;
    *(s16 *) (arg0 + 0x1C) = 0;
    *(s16 *) (arg0 + 0x2A) = 0;
    *(s16 *) (arg0 + 0x2C) = 0x10;
    *(arg0 + 0x2F) = 0;
    *(s16 *) (arg0 + 0x38) = 0;
    *(s16 *) (arg0 + 0x1A) = one;
    do {
        *(arg0 + i + 0x32) = i;
        i++;
    } while (i < 4);
    *(s16 *) (arg0 + 0xC) = 0x1C;
}
