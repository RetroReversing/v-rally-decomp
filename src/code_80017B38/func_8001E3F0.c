#include "common.h"

extern u8 D_800C8246[];
extern u8 D_800C8262[];
extern void *D_800B5C40;

s32 func_80041A04(s32, u16);

void func_8001E3F0(void) {
    s32 i;
    void *node;

    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[0] * 40));
    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[1] * 40));
    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[2] * 40));
    func_80041A04(8, *(u16 *)(D_800C8262 + D_800C8246[3] * 40));
    node = *(void **)D_800B5C40;
    i = 0;
    if (node != 0) {
        do {
            *(s32 *)((u8 *)*(void **)((u8 *)node + 0x28) + 0x50) = 1;
            *(s32 *)((u8 *)*(void **)((u8 *)node + 0x54) + 0x50) = 1;
            *(s32 *)((u8 *)*(void **)((u8 *)node + 0x1C) + 0x2C) = i & 0xFF;
            *(s32 *)((u8 *)*(void **)((u8 *)node + 0x48) + 0x2C) = i & 0xFF;
            node = *(void **)((u8 *)node + 4);
            i += 1;
        } while (node != 0);
    }
}
