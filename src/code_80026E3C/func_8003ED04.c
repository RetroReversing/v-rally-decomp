#include "common.h"

extern char D_800C02AE[];
s32 func_80041564();

void func_8003ED04(void *arg0) {
    u8 *s0;
    s32 base;
    s32 count;
    s32 raw;
    u32 val;
    u8 *p;

    s0 = *(u8 **)((u8 *)(*(u8 **)((u8 *)arg0 + 0xA8)) + 0x24);
    func_80041564();
    base = *(s32 *)(D_800C02AE + 0x32F2);
    count = *(u8 *)(base + **(s32 **)(s0 + 0x48) + 0x32);
    p = (u8 *)(base + count * 40);
    p = p + *(u16 *)((u8 *)arg0 + 0x78);
    raw = *(u8 *)(p + 0x44);
    val = raw & 0xFF;
    if (val < 0x41) {
        *(s16 *)((u8 *)arg0 + 0x7A) = raw - 0x16;
    } else {
        *(s16 *)((u8 *)arg0 + 0x7A) = val - 0x41;
    }
    if (*(s16 *)((u8 *)arg0 + 0x7A) < 0) {
        *(s16 *)((u8 *)arg0 + 0x7A) = 0;
    }
}
