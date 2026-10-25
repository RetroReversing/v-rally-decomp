#include "common.h"

s32 func_8005A05C();
s32 func_8005A6E0();
s32 func_8008A140();
extern void *D_800A1468;
extern void *D_800C3508;
extern char D_800C02AE[];

s32 func_80063F6C(void)
{
    *((s8 *) (((char *) D_800A1468) + 0x245)) = 0;
    func_8008A140(D_800C3508);
    if ((*((s16 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 2))) == 2)
    {
        return (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) + 0xF;
    }
    func_8005A05C(0);
    func_8005A6E0(0x13);
    func_8005A6E0(0x14);
    func_8005A6E0(0x15);
    func_8005A6E0(0x16);
    return (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20))) + 6;
}
