#include "common.h"

void func_8001FB4C(void *);
void func_8002D830(void *);
void func_8002D9D8(void *);
void func_8002DA20(void *, void *);
void func_8002DD20(void *, void *);
void func_8002E654(void *, void *, void *);

void func_80010E08(void *arg0, s16 arg1, s16 arg2, s32 *arg3, s16 arg4) {
    s32 sp10[8];
    s16 sp30[3];
    u32 sp38;

    func_8001FB4C(sp10);
    func_8002DD20(arg0, sp10);
    sp10[5] = 0;
    sp10[6] = 0;
    sp10[7] = 0;
    func_8002D9D8(sp10);
    arg3[1] = 0x1000;
    arg3[0] = arg4;
    arg3[2] = arg4;
    func_8002DA20(sp10, arg3);
    func_8002D830(sp10);
    sp30[0] = arg1;
    sp30[1] = 0;
    sp30[2] = arg2;
    func_8002E654(sp30, arg3, &sp38);
}
