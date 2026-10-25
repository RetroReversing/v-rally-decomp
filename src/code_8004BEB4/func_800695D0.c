#include "common.h"

s32 func_8005A388();
void func_80069648();
void func_80069690();
extern char *D_800A1468;
extern char *D_800C35A0;

s32 func_800695D0(s32 arg0)
{
    char *p;
    char *tbl;
    func_8005A388();
    p = D_800A1468;
    *(u8 *)(p + 0x228) = arg0;
    tbl = D_800C35A0;
    *(void (**)())(p + 0x288) = func_80069648;
    *(void (**)())(p + 0x28C) = func_80069690;
    *(u8 *)(D_800A1468 + 0x22A) = *(u8 *)(tbl + arg0 + 0x32);
    *(u8 *)(D_800A1468 + 0x22B) = *(u8 *)(D_800A1468 + 0x228);
    return 0;
}
