#include "common.h"

extern char D_800AE850[];

void func_8003EFF8(void *arg0) {
    void *obj;
    void *p;
    s32 bit;

    obj = *(void **)((char *)arg0 + 0xA8);
    p = *(void **)((char *)obj + 0x24);
    if (p != NULL) {
        *(s16 *)((char *)arg0 + 0x78) = 0;
        *(s32 *)((char *)arg0 + 0x80) |= 4;
        if ((*(s32 *)((char *)p + 0x14) & 0x320) == 0x20) {
            bit = (*(u32 *)(D_800AE850 + 0x121C) >> 3) & 1;
            *(s16 *)((char *)arg0 + 0x78) = 1;
            if (bit) {
                *(s32 *)((char *)arg0 + 0x80) &= ~4;
            }
        }
    }
}
