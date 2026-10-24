#include "common.h"

s32 func_8008E650();
s32 func_8008E6F0();
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80088AA4(void *arg0, s32 arg1) {
    if (*(u8 *)((char *)arg0 + 0xC1) != 0) {
        func_8008E6F0(D_800AE850 + 0x2304, *(s32 *)(D_800C02AE + 0x7576) + (arg1 * 0x1C));
    }
    *(u8 *)((char *)arg0 + 0xC1) = 1U;
    func_8008E650(D_800AE850 + 0x2304, *(s32 *)(D_800C02AE + 0x7576) + (arg1 * 0x1C), *(s32 *)((char *)arg0 + 4));
    *(s32 *)((char *)arg0 + 4) = 0;
}
