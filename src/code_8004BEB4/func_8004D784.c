#include "common.h"

extern char D_800C02AE[];
void *func_8004D784(s32 arg0)
{
    char pad[8];
    char *base;
    char *p;
    u16 temp_v0;
    u32 count;
    u32 i;
    void *result;

    base = *(char **)(D_800C02AE + 0x7CDE);
    temp_v0 = *(u16 *)(base + 4);
    i = 0;
    result = NULL;
    if (temp_v0 != 0) {
        count = temp_v0;
        p = *(char **)base;
        do {
            if (*(s32 *)(p + 0x24) == arg0) {
                result = p;
                goto done;
            }
            i++;
            p += 0x3C;
        } while (i < count);
    }
done:
    return result;
}
