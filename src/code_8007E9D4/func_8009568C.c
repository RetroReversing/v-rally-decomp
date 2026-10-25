#include "common.h"

s32 func_8008F1A0();

void *func_8009568C(void *arg0, s32 arg1, s32 arg2, void *arg3)
{
    s32 *dst;
    u16 temp_a1;
    s32 temp_a1_2;
    void *new_var;

    temp_a1 = arg1;
    dst = arg3;
    dst[0] = temp_a1 | 0x08000000;
    temp_a1_2 = (temp_a1 << 0x10) | ((arg2 << 1) & 0xFFFF);
    dst[1] = temp_a1_2;
    dst[2] = 0x0B000020;
    dst[3] = func_8008F1A0((char *) arg0 + 8, temp_a1_2, (arg2 << 1) & 0xFFFF);
    new_var = dst + 6;
    dst[4] = (((*((u8 *) arg0 + 0x2F)) << 0x10) | 0x0E000000) | *((u16 *) ((char *) arg0 + 2));
    dst[5] = func_8008F1A0(*((s32 *) ((char *) arg0 + 0x28)));
    *((s32 *) ((char *) arg0 + 0x2C)) = 0;
    return new_var;
}
