#include "common.h"

extern u8 *D_800C35A0;
s32 func_8006204C(u8, u8, u8);
void func_80021EE4(u8 *, s32);

void func_800239CC(u8 *arg0, u8 *arg1) {
    s32 idx;
    u32 i;
    u8 *p;
    u8 *temp;
    s32 pad[8];

    idx = func_8006204C(D_800C35A0[0x1F], D_800C35A0[0x21], D_800C35A0[0x23]);
    if (*(s32 *)(*(u8 **)(arg0 + 0x48)) != 5) {
        for (i = 0; i < 4; i++) {
            *(s32 *)(*(u8 **)(arg0 + 0x80) + i * 4 + 0x2E0) = arg1[8];
        }
        *(s32 *)(*(u8 **)(arg0 + 0x24) + 4) = arg1[9] & 1;
        *(s32 *)(*(u8 **)(arg0 + 0x50) + 4) = arg1[9] & 1;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x60) = *(u16 *)(arg1 + 0xC);
        *(s32 *)(*(u8 **)(arg0 + 0x5C) + 0x60) = *(u16 *)(arg1 + 0xC);
        *(s32 *)(*(u8 **)(arg0 + 0x28) + 0x30) = *(s16 *)(arg1 + (idx & 0xFF) * 2 + 0x1C);
        *(s32 *)(*(u8 **)(arg0 + 0x28) + 0x34) = *(s16 *)(arg1 + (idx & 0xFF) * 2 + 0x1C);
        *(s32 *)(*(u8 **)(arg0 + 0x28) + 0x38) = -*(s16 *)(arg1 + (idx & 0xFF) * 2 + 0x1C);
        *(s32 *)(*(u8 **)(arg0 + 0x28) + 0x3C) = -*(s16 *)(arg1 + (idx & 0xFF) * 2 + 0x1C);
        for (i = 0xC; i < 0x10; i++) {
            *(s32 *)(*(u8 **)(arg0 + 0x54) + i * 4) = *(s32 *)(*(u8 **)(arg0 + 0x28) + i * 4);
        }
        temp = *(u8 **)(arg0 + 0x80);
        p = arg1 + (idx & 0xFF);
        *(s32 *)(temp + 0x38C) = p[0x14];
        func_80021EE4(arg0, (*(s32 *)(*(u8 **)(arg0 + 0x84) + 0x40) * 0xA) / 22);
        *(s32 *)(*(u8 **)(arg0 + 0x24) + 0xC) = p[0x18];
        *(s32 *)(*(u8 **)(arg0 + 0x50) + 0xC) = p[0x18];
        *(s32 *)(*(u8 **)(arg0 + 0x1C) + 0x30) = p[0x10];
        *(s32 *)(*(u8 **)(arg0 + 0x48) + 0x30) = p[0x10];
    }
}
