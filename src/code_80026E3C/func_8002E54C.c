#include "common.h"

void func_8002DB18(void *a, void *b, void *c);
void func_8002D8A0(void *a, s32 *b, s32 *c);

void func_8002E54C(s32 *arg0, s32 *arg1, s32 *arg2)
{
    s32 sp10[3];
    s32 sp20[3];

    func_8002DB18(arg0, arg1, arg2);
    sp10[0] = arg1[5];
    sp10[1] = arg1[6];
    sp10[2] = arg1[7];
    func_8002D8A0(arg0, sp10, sp20);
    arg2[5] = sp20[0] + arg0[5];
    arg2[6] = sp20[1] + arg0[6];
    arg2[7] = sp20[2] + arg0[7];
}
