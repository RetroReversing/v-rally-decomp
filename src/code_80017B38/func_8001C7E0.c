#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 D_8009CE8C;
extern s32 D_8009CE90;
extern s32 D_8009CE94;

void func_8001C7E0(void *arg0) {
    s32 state;
    s32 *p0;
    s32 *p1;
    s32 *p2;
    state = *(s32 *)(*(char **)(*(char **)(D_800AE850 + 0x23D0) + 0x1C));
    state &= -(state != 6);
    if ((u32)state < 4) {
        if (*(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0xE) == 2 &&
            !(*(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0x12) & 1) &&
            *(s32 *)((char *)arg0 + 0x90) == 3) {
            p0 = (s32 *)((char *)&D_8009CE8C + state * 12);
            p0[0] = *(s32 *)((char *)arg0 + 0xDC);
            p1 = (s32 *)((char *)&D_8009CE90 + state * 12);
            p1[0] = *(s32 *)((char *)arg0 + 0x128);
            p2 = (s32 *)((char *)&D_8009CE94 + state * 12);
            p2[0] = *(s32 *)((char *)arg0 + 0x174);
        } else if (*(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0xE) == *(s32 *)((char *)arg0 + 0x90) &&
                   (*(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0x12) & 1) &&
                   *(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0xE) == 2) {
            p0 = (s32 *)((char *)&D_8009CE8C + state * 12);
            p0[0] = *(s32 *)((char *)arg0 + 0xDC);
            p1 = (s32 *)((char *)&D_8009CE90 + state * 12);
            p1[0] = *(s32 *)((char *)arg0 + 0x128);
            p2 = (s32 *)((char *)&D_8009CE94 + state * 12);
            p2[0] = *(s32 *)((char *)arg0 + 0x174);
        } else if (*(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0xE) == 1 &&
                   *(s32 *)((char *)arg0 + 0x90) == *(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0xE)) {
            p0 = (s32 *)((char *)&D_8009CE8C + state * 12);
            p0[0] = *(s32 *)((char *)arg0 + 0xDC);
            p1 = (s32 *)((char *)&D_8009CE90 + state * 12);
            p1[0] = *(s32 *)((char *)arg0 + 0x128);
            p2 = (s32 *)((char *)&D_8009CE94 + state * 12);
            p2[0] = *(s32 *)((char *)arg0 + 0x174);
        }
    }
}
