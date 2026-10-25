#include "common.h"

s32 func_80054838();
extern char D_800AE850[];
extern char *D_800C35A0;

void func_80053A78(void) {
    u8 i;
    s32 off;
    char *p;

    i = 0;
    do {
        p = D_800C35A0;
        off = i * 0x28;
        *(u8 *)(p + off + 0x44) = *(u8 *)(D_800AE850 + 0x7F28 + off);
        *(u8 *)(D_800C35A0 + off + 0x45) = *(u8 *)(D_800AE850 + 0x7F29 + off);
        *(u8 *)(D_800C35A0 + off + 0x46) = *(u8 *)(D_800AE850 + 0x7F2A + off);
        *(u16 *)(D_800C35A0 + off + 0x4E) = *(u16 *)(D_800AE850 + 0x7F32 + off);
        i++;
    } while (i < 4);
    func_80054838();
}
