#include "common.h"

extern void *D_8009B5A4;
u16 *func_80005C48();

void func_8006AB6C(u16 *arg0) {
    s32 i;
    s32 j;
    u16 *src;
    u16 *dst;

    src = arg0;
    dst = func_80005C48(D_8009B5A4);
    for (i = 0; i < ((s16 *) D_8009B5A4)[3]; i++) {
        for (j = 0; j < ((s16 *) D_8009B5A4)[2]; j++) {
            *dst++ = *src;
            src += 2;
        }
        src += 0x280;
    }
}
