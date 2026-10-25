#include "common.h"

extern s32 D_800C6F14;
extern s32 D_800C5CF0;
extern s32 D_800C358C;
extern s32 D_800A1B80;
extern void *D_800C80C0;
s32 func_8007F4E4(s32, s32, s32);
s32 func_8007FB3C(void *, s32, s32, s32);
void func_80085D90(void);
void func_80085FB8(void);

void func_800860B4(void)
{
    s32 old;

    D_800C6F14 = func_8007F4E4(0xC, 3, 8);
    D_800C5CF0 = func_8007F4E4(0xC, 4, 8);
    D_800C358C = func_8007FB3C(func_80085D90, 0x2000, 0x74, 0);
    old = (s32) D_800C80C0;
    D_800C80C0 = func_80085FB8;
    D_800A1B80 = old;
}
