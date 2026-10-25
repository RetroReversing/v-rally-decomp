#include "common.h"

extern s32 D_800AFAE0;
s32 func_8009A580();
extern char D_800AE850[];

f64 func_80098750(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f64 arg4, f64 arg5)
{
    struct {
        s32 sp10[4];
        f64 sp20;
        f64 sp28;
    } buf;

    buf.sp10[0] = arg0;
    buf.sp10[1] = arg1;
    buf.sp10[2] = arg2;
    buf.sp10[3] = arg3;
    buf.sp20 = arg4;
    buf.sp28 = arg5;
    if (func_8009A580(buf.sp10) == 0) {
        if ((u32)(arg0 - 3) < 2) {
            *((s32 *)(D_800AE850 + 0x1290)) = 0x22;
        } else {
            *((s32 *)(D_800AE850 + 0x1290)) = 0x21;
        }
    }
    return buf.sp28;
}
