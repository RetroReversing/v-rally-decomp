#include "common.h"

u64 osGetTime(void);
s32 func_80098090(void);
void func_800980C4(s32);
extern s32 D_8009F4F0[];
extern s32 D_8009F4F4[];
extern s32 D_8009F4F8[];
extern s32 D_8009F4FC[];
extern s32 D_8009F510[];

void func_80033724(void)
{
    s32 var_s3;
    s32 v;
    s32 idx;
    s32 ten;
    s32 five;
    s32 a;

    func_800980C4((s32)osGetTime());
    var_s3 = 0;
    ten = 10;
    five = 5;
    do {
        v = func_80098090() % ten;
        idx = (var_s3 & 0xFF) * 0x30;
        a = *(s32 *)(idx + (int)D_8009F4F0); v -= five; v *= a; v /= 100; a += v; *(s32 *)((char *)D_8009F4F0 + idx) = a;
        var_s3 += 1;
        v = func_80098090() % ten;
        a = *(s32 *)((char *)D_8009F4F4 + idx); v -= five; v *= a; v /= 100; a += v; *(s32 *)((char *)D_8009F4F4 + idx) = a;
        v = func_80098090() % ten;
        a = *(s32 *)((char *)D_8009F4F8 + idx); v -= five; v *= a; v /= 100; a += v; *(s32 *)((char *)D_8009F4F8 + idx) = a;
        v = func_80098090() % ten;
        a = *(s32 *)((char *)D_8009F4FC + idx); v -= five; v *= a; v /= 100; a += v; *(s32 *)((char *)D_8009F4FC + idx) = a;
        v = func_80098090() % ten;
        a = *(s32 *)((char *)D_8009F510 + idx); v -= five; v *= a; v /= 100; a += v; *(s32 *)((char *)D_8009F510 + idx) = a;
    } while ((u32)(var_s3 & 0xFF) < 3);
}
