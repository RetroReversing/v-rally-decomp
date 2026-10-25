#include "common.h"

s32 func_80081E8C(void *, s32);
u16 func_800822D4(void *);
s32 func_800822E8(void *);
extern s32 D_800AE850;
extern s32 D_800C02AE;

s32 func_800847CC(void)
{
    u8 sp10[0x1A];
    s32 temp_v0;

    func_80081E8C(sp10, 0x1A);
    *((u16 *) (((char *) (&D_800C02AE)) + 0x30BA)) = func_800822D4(&sp10[2]);
    *((u16 *) (((char *) (&D_800C02AE)) + 0x30BC)) = func_800822D4(&sp10[4]);
    *((s32 *) (((char *) (&D_800C02AE)) + 0x30BE)) = func_800822E8(&sp10[14]);
    *((s32 *) (((char *) (&D_800C02AE)) + 0x30C2)) = func_800822E8(&sp10[18]);
    *((u16 *) (((char *) (&D_800C02AE)) + 0x30C6)) = func_800822D4(&sp10[22]);
    *((s32 *) (((char *) (&D_800AE850)) + 0x8ACC)) = *((s32 *) (((char *) (&D_800C02AE)) + 0x30BE));
    *((s32 *) (((char *) (&D_800AE850)) + 0x8AD0)) = *((s32 *) (((char *) (&D_800C02AE)) + 0x30C2));
    if (*((u16 *) (((char *) (&D_800C02AE)) + 0x30BA)) & 8)
    {
        temp_v0 = *((s32 *) (((char *) (*((void **) (((char *) (&D_800AE850)) + 0x8AE4)))) + 4));
        *((s32 *) (((char *) (&D_800C02AE)) + 0x30BE)) = temp_v0;
        *((s32 *) (((char *) (&D_800AE850)) + 0x8ACC)) = temp_v0;
    }
    return 0;
}
