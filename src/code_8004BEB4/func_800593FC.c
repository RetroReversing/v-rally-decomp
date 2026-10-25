#include "common.h"

void *func_800592AC();
extern char D_800C02AE[];

void func_800593FC(s32 arg0, s32 arg1)
{
    void *temp_v0;
    s32 temp_a2;
    s32 temp_t;
    s32 temp_x;
    void *temp_s0;
    void *temp_v0_2;
    u8 temp_b;

    temp_v0 = *((void **) (D_800C02AE + 0x325A));
    temp_a2 = *((s32 *) (((char *) temp_v0) + 0x10));
    temp_t = *((u8 *) ((temp_a2 + ((*((s16 *) (((char *) temp_v0) + 2))) * 0x14)) + 0xD));
    temp_x = arg1 - temp_t;
    temp_s0 = func_800592AC(arg0 - temp_t);
    temp_v0_2 = func_800592AC(temp_x);
    *((s32 *) (((char *) temp_v0_2) + 0x28)) = *((s32 *) (((char *) temp_s0) + 0x28));
    temp_b = *((u8 *) (((char *) temp_s0) + 0x4D));
    *((u8 *) (((char *) temp_v0_2) + 0x4E)) = 1;
    *((u8 *) (((char *) temp_v0_2) + 0x4D)) = temp_b;
}
