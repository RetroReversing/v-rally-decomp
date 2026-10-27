#include "common.h"

extern s32 D_800B0100;
extern s32 *D_800B6160;
extern void func_800885CC(void);
s32 func_800898D0(u8 *arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4) {
    s32 counter;
    s32 value;
    s32 *table;
    func_800885CC();
    counter = D_800B0100;
    D_800B0100 = counter + 1;
    arg0[0xB3] = 0x7F;
    table = D_800B6160;
    *(s16 *)(arg0 + 0x9E) = arg1;
    arg1 <<= 2;
    *(s16 *)(arg0 + 0x96) = arg2;
    *(s16 *)(arg0 + 0xA8) = arg3;
    *(s32 *)(arg0 + 0x40) = counter;
    *(s32 *)(arg0 + 0x44) = arg4;
    value = *(s32 *)(arg1 + (s32)table);
    *(s32 *)(arg0 + 0x78) = value;
    *(s32 *)arg0 = value;
    return *(s32 *)(arg0 + 0x40);
}
