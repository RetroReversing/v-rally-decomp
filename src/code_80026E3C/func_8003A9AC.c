#include "common.h"

extern s32 D_800C7F84;
s32 func_80034FF0();
void *func_80040260();
extern void func_8003A73C();

void func_8003A9AC(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4, u16 arg5, u8 *arg6)
{
    s32 var_s2;
    s32 var_s5;
    s32 var_s4;
    u32 var_s3;
    u16 var_s6;
    u8 *var_s0;
    s32 *var_fp;
    s32 ret;
    s32 d;

    var_s2 = arg1;
    var_fp = arg3;
    var_s6 = arg5;
    var_s5 = (s16)arg2;
    var_s4 = arg4 + 0x4C;
    var_s3 = 0;
    do {
        var_s0 = func_80040260(arg0, (s16)var_s2, (s16)var_s5, 2, var_fp, 0);
        *(u16 *)(var_s0 + 0x78) = var_s3;
        ret = func_80034FF0(var_s4, 0);
        d = D_800C7F84;
        var_s2 += 7;
        *(s32 *)(var_s0 + 0xA4) = ret;
        *(u16 *)(var_s0 + 0x76) = var_s6;
        *(s32 *)(var_s0 + 0xA8) = d;
        if (arg6 != NULL) {
            var_s0[0x90] = arg6[0];
            var_s0[0x91] = arg6[1];
            var_s0[0x92] = arg6[2];
            var_s0[0x93] = arg6[3];
        }
        if (var_s3 == 1) {
            var_s0 = func_80040260(arg0, (s16)var_s2, (s16)var_s5, 2, func_8003A73C, 0);
            ret = func_80034FF0(var_s4, 0);
            d = D_800C7F84;
            var_s2 += 4;
            *(s32 *)(var_s0 + 0xA4) = ret;
            *(u16 *)(var_s0 + 0x76) = var_s6;
            *(s16 *)(var_s0 + 0x7A) = 0xC;
            *(s32 *)(var_s0 + 0xA8) = d;
            if (arg6 != NULL) {
                var_s0[0x90] = arg6[0];
                var_s0[0x91] = arg6[1];
                var_s0[0x92] = arg6[2];
                var_s0[0x93] = arg6[3];
            }
        }
        var_s3++;
    } while (var_s3 < 3);
}
