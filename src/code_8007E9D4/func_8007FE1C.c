#include "common.h"

extern void *func_8008D090(void *, void **, s32);
extern void func_8007F394(void *, void **);
extern void *func_8007F73C(s32, s32);
extern void func_8008DD00(void *);
extern void func_8008DF0C(void *);
extern void func_8008D4A0(void *, void *, s32);
extern u8 D_800AE850[];
extern u8 D_800B4568[];
extern u8 D_800C02AE[];

void func_8007FE1C(void *arg0) {
    void *sp10;
    void *sp14;
    u8 *s0;
    u8 *s2;
    u8 *s3;

    sp14 = NULL;
    s0 = D_800AE850 + 0x1D10;
    s2 = D_800C02AE + 0x7D8A;
    s3 = D_800B4568;
    for (;;) {
        func_8008D090(arg0 + 0x14, &sp10, 1);
        if (*(void **)(s0 + 0x55C) != NULL) {
            *(void **)(s0 + 0x560) = sp10;
            func_8008D090(s0 + 0x10, &sp14, 1);
            *(void **)(s0 + 0x560) = NULL;
        }
        func_8007F394(arg0, &sp10);
        ((void (*)(void *))*(void **)(s2 + *(u16 *)(arg0 + 0xE) * 4))(sp10);
        *(void **)(s0 + 0x558) = sp10;
        *(u8 **)((u8 *)sp10 + 0x40) = s3;
        func_8008DD00(sp10);
        func_8008DF0C(sp10);
        sp14 = func_8007F73C(0x22, 2);
        ((void (*)(void *))*(void **)(s2 + 0x90))(sp10);
        *(void **)(s0 + 0x558) = NULL;
        sp14 = func_8007F73C(0x22, 3);
        ((void (*)(void))*(void **)(s2 + 0x94))();
        func_8008D4A0(*(void **)((u8 *)sp10 + 0x40), *(void **)((u8 *)sp10 + 0x44), 0);
    }
}
