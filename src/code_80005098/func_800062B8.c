#include "common.h"

s32 osVirtualToPhysical();

void func_800062B8(u8 *arg0)
{
    s32 t;
    u16 s0;
    u32 *s1;
    s32 temp_a0;
    s32 temp_v0;

    s0 = *(u16 *) (arg0 + 0x7A);
    t = s0 & 0x1F;
    if (t != 0) {
        temp_a0 = t << 12;
        s1 = *(u32 **) (arg0 + 0x18);
        temp_v0 = (t << 1) | 0x01000000;
        *s1 = temp_a0 | temp_v0;
        s0 &= 0xFFE0;
        s1[1] = osVirtualToPhysical(*(s32 *) (arg0 + 0x70) + s0 * 16);
        s0 += 0x20;
        *(u16 *) (arg0 + 0x7A) = s0;
    }
}
