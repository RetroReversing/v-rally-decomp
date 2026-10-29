#include "snapshot29_0433f7af8f6d.h"

typedef struct Packet {
    s32 w[5];
} Packet;

extern s32 D_800AE850;
extern s32 D_800C02AE;

void func_80081040(s32, s32, s32, s32, Packet);
void *func_800817A0(s32);
void func_80081C30(void);
void osWritebackDCacheAll(void);

void func_800819B4(s32 arg0) {
    void *p;
    s32 base;

    *(s32 *)((u8 *)&D_800C02AE + 0x30EA) = arg0;
    *(s32 *)((u8 *)&D_800C02AE + 0x30EE) = arg0;
    p = func_800817A0(*(s32 *)((u8 *)&D_800AE850 + 0x8AB8));
    base = *(s32 *)((u8 *)&D_800AE850 + 0x8AB0) + *(s32 *)((u8 *)p + 0x1C);
    func_80081040(base, *(s32 *)((u8 *)&D_800C02AE + 0x308A), 0x2000,
                  *(s32 *)((u8 *)&D_800AE850 + 0x2358),
                  *(Packet *)((u8 *)&D_800AE850 + 0x235C));
    *(s32 *)((u8 *)&D_800C02AE + 0x30C2) = *(s32 *)((u8 *)p + 0x10);
    *(s32 *)((u8 *)&D_800C02AE + 0x30BE) = *(s32 *)((u8 *)p + 0x14);
    *(u16 *)((u8 *)&D_800C02AE + 0x30BC) = *(u16 *)((u8 *)p + 0x1A);
    *(u16 *)((u8 *)&D_800C02AE + 0x30BA) = *(u16 *)((u8 *)p + 0x18);
    *(s32 *)((u8 *)&D_800C02AE + 0x308E) = *(s32 *)((u8 *)p + 0x28);
    *(s32 *)((u8 *)&D_800C02AE + 0x3092) = *(s32 *)((u8 *)p + 0x24);
    *(s32 *)((u8 *)&D_800AE850 + 0x8ACC) = *(s32 *)((u8 *)p + 0x14);
    *(s32 *)*(s32 *)((u8 *)&D_800AE850 + 0x8AE4) = *(s32 *)((u8 *)p + 0x20);
    *(s32 *)(*(s32 *)((u8 *)&D_800AE850 + 0x8AE4) + 4) = *(s32 *)((u8 *)p + 0x14);
    *(s32 *)((u8 *)&D_800AE850 + 0x8AD0) = *(s32 *)((u8 *)p + 0x10);
    *(s32 *)((u8 *)&D_800C02AE + 0x30A6) = *(s32 *)((u8 *)p + 0x1C);
    func_80081C30();
    osWritebackDCacheAll();
}
