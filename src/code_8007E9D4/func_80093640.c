#include "common.h"

typedef struct { u8 pad0[5]; u8 unk5,unk6,unk7,unk8,unk9; u8 padA[2]; s32 unkC; } S_dev;
extern S_dev *D_800A2560[4];
extern volatile u8 D_A0000000[];
s32 func_80093640(S_dev *arg0, s32 arg1, s32 arg2) {
    s32 t0;
    S_dev *v1;
    while (*(volatile u32 *)0xA4600010 & 3) {}
    t0 = arg0->unk9;
    v1 = D_800A2560[t0];
    if (v1 != arg0) {
        if (t0 == 0) {
            if (v1->unk5 != arg0->unk5) *(volatile u32 *)0xA4600014 = arg0->unk5;
            if (v1->unk6 != arg0->unk6) *(volatile u32 *)0xA460001C = arg0->unk6;
            if (v1->unk7 != arg0->unk7) *(volatile u32 *)0xA4600020 = arg0->unk7;
            if (v1->unk8 != arg0->unk8) *(volatile u32 *)0xA4600018 = arg0->unk8;
        } else {
            if (v1->unk5 != arg0->unk5) *(volatile u32 *)0xA4600024 = arg0->unk5;
            if (v1->unk6 != arg0->unk6) *(volatile u32 *)0xA460002C = arg0->unk6;
            if (v1->unk7 != arg0->unk7) *(volatile u32 *)0xA4600030 = arg0->unk7;
            if (v1->unk8 != arg0->unk8) *(volatile u32 *)0xA4600028 = arg0->unk8;
        }
        D_800A2560[t0] = arg0;
    }
    *(volatile u32 *)((arg0->unkC | arg1 | 0xA0000000) ) = arg2;
    return 0;
}
