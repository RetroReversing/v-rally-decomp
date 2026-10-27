#include "common.h"

extern s32 D_800AE850;
extern s32 D_800C02AE;
void func_80086AD8(void *arg0, s32 arg1) {
    s32 saved = arg1;
    s32 value = arg1;
    s32 i;
    s32 count;
    char pad[8];
    volatile s32 *p;
    s32 *base;
    s32 field;
    if (!value) value = 1;
    count = *(s32 *)((u8 *)&D_800C02AE + 0x757E);
    base = *(s32 **)((u8 *)&D_800AE850 + 0x80A0);
    i = 0;
    if (count > 0) {
        s32 limit = count;
        p = (volatile s32 *)((u8 *)base + 0x18);
        do {
            field = p[10];
            i++;
            if (field == *(s32 *)((u8 *)arg0 + 4)) {
                p[-3] = saved;
                p[0] = value;
            }
            p = (volatile s32 *)((u8 *)p + 0x134);
        } while (i < limit);
    }
    (void)&pad;
}
