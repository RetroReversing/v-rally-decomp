#include "common.h"

extern s32 D_800C782C;
extern char *D_800B68F0;
void func_80086D90(void *arg0, s16 arg1) {
    char pad[8];
    char *base;
    char *p;
    s32 i;
    s32 n;
    n = D_800C782C;
    base = D_800B68F0;
    i = 0;
    if (n > 0) {
        p = base + 0x96;
        do {
            if (*(s32 *)(p - 0x56) == *(s32 *)((char *)arg0 + 4)) {
                *(s16 *)p = arg1;
                i = n;
            }
            i++;
            p += 0x134;
            n = D_800C782C;
        } while (i < n);
    }
}
