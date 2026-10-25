#include "common.h"

extern char D_800C02AE[];
void func_8006F424(void)
{
    u8 i;
    char *temp_a1;

    temp_a1 = D_800C02AE + 0x6E64;
    *((u16 *) temp_a1) = (u16) ((*((u16 *) temp_a1) | 0x100) & 0x1D00);
    *((s8 *) (D_800C02AE + 0x6E6D)) = 0;
    *((s16 *) (D_800C02AE + 0x6E66)) = *((u8 *) (D_800C02AE + 0x6E67));
    i = 0;
    do {
        *((s16 *) (temp_a1 + 0xA + i * 2)) = 0;
        i++;
    } while (i < 4);
    i = 0;
    do {
        (temp_a1 + i)[3] = 0;
        i++;
    } while (i < 6);
}
