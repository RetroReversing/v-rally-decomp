#include "common.h"

s32 func_80005C48(void *);
void func_8000E9D4(void *, s32, u16 *, u8 *);
void func_8000EB58(void *, s32, u16 *);

void func_8000E8FC(void *arg0, void *arg1, void *arg2) {
    u16 sp10[4];
    u8 sp18[4];
    s32 temp;

    if (arg1 != NULL) {
        temp = func_80005C48(arg1);
        sp10[0] = ((u16 *)arg1)[0];
        sp10[1] = ((u16 *)arg1)[1];
        sp10[2] = ((u16 *)arg1)[2];
        sp10[3] = ((u16 *)arg1)[3];
        sp18[0] = ((u8 *)arg0)[0x10];
        sp18[1] = ((u8 *)arg0)[0x11];
        sp18[2] = ((u8 *)arg0)[0x12];
        sp18[3] = ((u8 *)arg0)[0x13];
        func_8000E9D4(arg0, temp, sp10, sp18);
    }
    if (arg2 != NULL) {
        temp = func_80005C48(arg2);
        sp10[0] = ((u16 *)arg2)[0];
        sp10[1] = ((u16 *)arg2)[1];
        sp10[2] = ((u16 *)arg2)[2];
        sp10[3] = ((u16 *)arg2)[3];
        func_8000EB58(arg0, temp, sp10);
    }
}
