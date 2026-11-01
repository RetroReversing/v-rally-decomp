#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern u8 *D_800C35A0;
void func_8003EE84(u8 *a1){
    s32 a2 = *(s32*)(*(s32*)(a1+0xA8)+0x24);
    u8 *a0;
    s32 v1;
    if (a2 != 0) {
        a0 = D_800C35A0;
        a0 = a0 + (*(u16*)(a1+0x76) + a0)[0x32]*0x28;
        a0 = a0 + *(u16*)(a1+0x78);
        v1 = a0[0x44];
        if (v1 < 0x41) *(s16*)(a1+0x7A) = v1-0x16; else *(s16*)(a1+0x7A) = v1-0x41;
        if (*(s32*)(*(s32*)(a2+0x6C)+8) == 1) {
            *(s16*)(a1+0xE) = *(u16*)(*(s32*)(*(s32*)(a1+0xA8)+0x178)+0xA) + 6;
        } else {
            *(s16*)(a1+0xE) = *(u16*)(*(s32*)(*(s32*)(a1+0xA8)+0x178)+0xA) + 0x10;
        }
    }
}
