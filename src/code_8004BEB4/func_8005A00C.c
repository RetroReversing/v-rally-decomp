#include "common.h"

extern char D_800C02AE[];

void func_8005A00C(s32 arg0)
{
    s32 a1;
    void *v0;
    char *v1;

    v0 = *(void **)(D_800C02AE + 0x5A7A);
    v0 = *(void **)((char *)v0 + 0x10);
    v1 = *(char **)v0;
    a1 = 0;
    if (v1 != NULL) {
        arg0 = arg0 & 0xFF;
        do {
            if ((a1 & 0xFF) == arg0) {
                *(s32 *)(v1 + 0xC) &= -3;
                return;
            }
            v1 = *(char **)(v1 + 4);
            a1++;
        } while (v1 != NULL);
    }
}
