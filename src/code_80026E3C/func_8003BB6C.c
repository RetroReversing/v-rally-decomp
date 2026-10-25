#include "common.h"

s32 func_8003A594();
extern char D_800C02AE[];

void func_8003BB6C(void *arg0)
{
    s32 temp_a1;
    s32 var_v0;
    void *temp_v1;

    temp_v1 = *(void **)(*(void **)(D_800C02AE + 0x7CD6) + 0x24);
    if (temp_v1 == NULL) {
        return;
    }
    temp_a1 = *(s32 *)((u8 *)temp_v1 + 0x14);
    if (temp_a1 & 0x300) {
        var_v0 = *(s32 *)((u8 *)arg0 + 0x80) | 4;
    } else if (temp_a1 & 0x200) {
        temp_v1 = (void *) -5;
        var_v0 = *(s32 *)((u8 *)arg0 + 0x80) & (s32) temp_v1;
    } else {
        func_8003A594(arg0, *(s16 *)(*(u8 **)((u8 *)temp_v1 + 0x6C) + 0x12), 0);
        return;
    }
    *(s32 *)((u8 *)arg0 + 0x80) = var_v0;
}
