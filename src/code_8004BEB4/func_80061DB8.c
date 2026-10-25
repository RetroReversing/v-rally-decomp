#include "common.h"

extern unsigned short D_800D0630;
extern int D_800D0658;
s32 func_80034FF0();
s32 func_80081540();
s32 func_800980D0();
extern s32 D_800A1468;
extern char D_800A5408[];
extern char D_800A5640[];

void func_80061DB8(void) {
    char buf[16];
    u32 i;
    u8 k;
    char *base;

    func_80081540(D_800A5408);
    i = 0;
    if (D_800D0630 != 0) {
        do {
            base = (char *) D_800D0658 + ((i & 0xFF) * 0x2C4);
            k = 0;
            do {
                buf[k] = base[k];
                k++;
            } while (k < 5);
            buf[k] = 0;
            func_800980D0(buf, D_800A5640);
            *(s32 *)(((i & 0xFF) * 4) + D_800A1468 + 0x194) = func_80034FF0(buf, 0);
            i++;
        } while ((i & 0xFF) < (u16) D_800D0630);
    }
}
