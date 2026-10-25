#include "common.h"

extern void *D_8009C230;
extern s32 D_800B5C40;
extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_8001C444();
s32 func_80022ED8();
s32 func_800230C0();
s32 func_800231A8();
s32 func_800232C4();
s32 func_8002D8A0();

void func_8001C524(void *arg0) {
    s32 a[3];
    s32 b[3];
    u32 i;
    void *s0;
    void *ptr;
    s32 r;

    s0 = D_8009C230;
    i = 0;
    do {
        a[i] = *(s32 *)((char *)arg0 + 0x90 + i * 0x4C);
        i++;
    } while (i < 3U);
    i = 0;
    do {
        b[i] = *(s32 *)((char *)arg0 + 0x174 + i * 0x4C);
        i++;
    } while (i < 3U);
    if (*(s32 *)((char *)arg0 + 0x258) == 0) {
        func_8002D8A0((char *)s0 + 0x10, a, a);
        b[0] = *(s16 *)((char *)s0 + 0x14);
        r = func_8001C444(a, s0);
        b[1] = r;
        b[2] = *(s16 *)((char *)s0 + 0x20);
    }
    ptr = *(void **)(D_800C02AE + 0x32F2);
    if ((((*(u16 *)((char *)ptr + 0x1E) != 0) & (*(u16 *)((char *)ptr + 0x1E) < 5)) || *(u16 *)((char *)ptr + 0x1E) == 5) && *(u16 *)((char *)ptr + 0x22) != 0 || *(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0x1E) == 8) {
        r = func_800232C4(D_800B5C40, ptr);
    } else {
        r = func_800231A8(D_800B5C40, ptr);
    }
    if (r != 0) {
        func_800230C0(r, a, b);
        func_80022ED8(r);
    }
}
