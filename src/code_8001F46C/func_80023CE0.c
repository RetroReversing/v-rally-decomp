#include "common.h"

void func_80023CE0(void *arg0, void *arg1) {
    s32 *temp_a2;
    s32 *p;
    s32 i;
    s32 *q;
    s32 *v;
    s32 val;

    v = *(s32 **)((u8 *)arg1 + 0x24);
    val = *(s32 *)((u8 *)arg0 + 0x90);
    temp_a2 = *(s32 **)((u8 *)arg1 + 0x7C);
    v[1] = val;
    *(s32 *)(*(u8 **)((u8 *)arg1 + 0x24)) = *(s32 *)(*(u8 **)((u8 *)arg1 + 0x24) + 4) + 1;
    *(s32 *)(*(u8 **)((u8 *)arg1 + 0x24) + 0xC) = *(s32 *)((u8 *)arg0 + 0xDC);
    temp_a2[8] = *(s32 *)((u8 *)arg0 + 0x128);
    p = temp_a2 + 7;
    for (i = 7; i >= 0; i--) {
        *p-- = 0;
    }
    i = 0;
    if (temp_a2[8] >= 0) {
        q = temp_a2;
        do {
            *q++ = *(s32 *)((u8 *)arg0 + 0x174);
            arg0 = (u8 *)arg0 + 0x4C;
            i++;
        } while (temp_a2[8] >= i);
    }
}
