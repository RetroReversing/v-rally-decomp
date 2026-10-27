#include "common.h"

extern s32 D_800B5C40, D_800B6880;
extern u8 D_800C8308;
extern void *D_800C35A0;
extern void func_80021AB8();
extern void func_8005322C();
extern void func_80053784();
extern void func_80053A78();
extern void func_80054838();

void func_80053B2C(void) {
    u16 v0; s32 v1;
    if ((u32)(D_800B6880 - 2) >= 2 && D_800B6880 != 5) {
        v1 = *(u16 *)((u8 *)D_800C35A0 + 0x1e);
        D_800B6880 = 0;
        switch (v1) {
        case 5:
            func_8005322C();
            break;
        case 0:
            func_80054838();
            D_800B6880 = 2;
            break;
        case 1: case 2: case 3: case 4:
            func_80053784();
            break;
        }
        D_800C8308 = 0;
    }
    if ((u32)(D_800B6880 - 2) < 2) {
        v0 = *(u16 *)((u8 *)D_800C35A0 + 0x1e);
        if ((v0 != 0) & (v0 < 5))
            func_80053A78();
    }
    func_80021AB8(D_800B5C40);
}
