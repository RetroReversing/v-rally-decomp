#include "common.h"

s32 func_80050DF4();
s32 func_80050FC4();
extern char D_800A1214[];
extern char D_800C02AE[];
extern void *D_800C35A0;
extern char D_800C8214[];

typedef struct
{
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Chunk;

void func_80050F08(void)
{
    char *var_a2;
    char *var_a3;
    s32 temp_v0;
    char *temp_t0;

    *(u16 *)((char *)D_800C35A0 + 0x2C) |= 0x10;
    temp_v0 = func_80050DF4() & 0xFF;
    if (*(u16 *)((char *)D_800C35A0 + 0x2C) & 0x10)
    {
        func_80050FC4(*(s32 *)(D_800A1214 + (temp_v0 << 2)));
    }
    else
    {
        var_a3 = D_800C8214;
        var_a2 = D_800C35A0;
        temp_t0 = var_a2 + 0xF0;
        do
        {
            *(Chunk *)var_a3 = *(Chunk *)var_a2;
            var_a2 += 0x10;
            var_a3 += 0x10;
        } while (var_a2 != temp_t0);
        *(s32 *)var_a3 = *(s32 *)var_a2;
    }
    *(s16 *)((char *)D_800C35A0 + 0x1E) = 7;
    *(s16 *)((char *)D_800C35A0 + 0xE) = 1;
}
