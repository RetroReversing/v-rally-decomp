#include "common.h"

extern s32 *D_800C81D4;

void func_80038F64(s32 arg0)
{
    s32 temp_a0;
    s32 *temp_v1;

    temp_a0 = arg0 & 0xFF;
    if (temp_a0 == 2) {
        goto block_6;
    }
    if (temp_a0 < 3) {
        goto block_4;
    }
    if (temp_a0 == 3) {
        goto block_7;
    }
    return;
block_4:
    if (temp_a0 < 0) {
        return;
    }
    temp_v1 = D_800C81D4;
    temp_v1[0] = 8;
    temp_v1[3] = 9;
    temp_v1[6] = 0xA;
    temp_v1[9] = 0xB;
    temp_v1[12] = 0xC;
    temp_v1[15] = 0xE;
    temp_v1[18] = 0xF;
    temp_v1[51] = 0x1F;
    temp_v1[54] = 0x20;
    temp_v1[57] = 0x21;
    return;
block_6:
    temp_v1 = D_800C81D4;
    temp_v1[0] = 0x3B;
    temp_v1[3] = 0x3C;
    temp_v1[6] = 0x3D;
    temp_v1[9] = 0x3E;
    temp_v1[12] = 0x3F;
    temp_v1[15] = 0x40;
    temp_v1[18] = 0x41;
    temp_v1[51] = 0x42;
    temp_v1[54] = 0x43;
    temp_v1[57] = 0x44;
    return;
block_7:
    temp_v1 = D_800C81D4;
    temp_v1[0] = 0x31;
    temp_v1[3] = 0x32;
    temp_v1[6] = 0x33;
    temp_v1[9] = 0x34;
    temp_v1[12] = 0x35;
    temp_v1[15] = 0x36;
    temp_v1[18] = 0x37;
    temp_v1[51] = 0x38;
    temp_v1[54] = 0x39;
    temp_v1[57] = 0x3A;
}
