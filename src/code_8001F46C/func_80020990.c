#include "snapshot29_0433f7af8f6d.h"

u16 func_80022648(void *);
void func_80012F7C(void *);
void func_80022374(s32, void *, s32);
void func_80042D20(s32, void *);
s32 func_80046398(void *);
void func_80047474(void *);
extern s32 D_800A0200;
extern u8 D_800A4900[];
extern u8 D_800A73E0[];
extern u8 D_800AE850[];

void func_80020990(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 i;
    s32 flags;
    void *obj;
    void *node;

    if (*(u16 *)(D_800A73E0 + 0x6BFE) == 0) {
        *(u16 *)(D_800A73E0 + 0x6BFE) = func_80022648(*(void **)(D_800AE850 + 0x73F0));
        func_80012F7C(arg0);
    }
    temp_v1 = *(s32 *)(D_800AE850 + 0x73F0);
    if (*(void **)(temp_v1 + 4) == arg0) {
        node = *(void **)temp_v1;
        i = 0;
        if (*(u16 *)(D_800A73E0 + 0x6BFE) != 0) {
            do {
                temp_v1 = i & 0xFFFF;
                *(s32 *)((u8 *)*(void **)((u8 *)node + 0x1C) + 0x2C) = temp_v1;
                i++;
                *(s32 *)((u8 *)*(void **)((u8 *)node + 0x48) + 0x2C) = temp_v1;
                node = *(void **)((u8 *)node + 4);
            } while ((u32)(i & 0xFFFF) < *(u16 *)(D_800A73E0 + 0x6BFE));
        }
        func_80042D20(i, node);
        func_80047474(arg0);
    }
    flags = *(s32 *)((u8 *)arg0 + 0x14);
    *(s32 *)(D_800A73E0 + 0x706C) = 0;
    D_800A73E0[0x6BC8] = 0;
    D_800A0200 = 0;
    flags &= ~0x20;
    flags &= ~0x40;
    flags &= ~0x80;
    flags &= ~0x100;
    flags &= ~0x200;
    *(s32 *)((u8 *)arg0 + 0x14) = flags;
    temp_v0 = func_80046398(arg0);
    if (temp_v0 != 0) {
        func_80022374(temp_v0 + 0x28, D_800A4900, 0);
    }
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 0x28) = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x28);
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 4) = 1;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 0) = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0);
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 8) = 0;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 0xC) = 0;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 0x20) = 0;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 0x24) = 0;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x9C) + 0x34) = 0;
}
