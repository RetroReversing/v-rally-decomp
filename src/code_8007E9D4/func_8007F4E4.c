#include "snapshot29_0433f7af8f6d.h"

s32 func_8007FB3C(void *, s32, s32, void *);
void *func_800801D0(void *, s32);
void osCreateMesgQueue(void *, void *, s32);
s32 func_8008D640(s32);
extern u8 D_800AE850[];
extern void func_8007F424;
extern void func_8007F490;
extern void func_8007FC44;
extern void func_8007FE1C;

void *func_8007F4E4(s32 arg0, s32 arg1, s32 arg2) {
    void *var_a0;
    s32 var_a2;
    s32 temp_s4;
    u32 temp_s1;
    void *temp_s0;
    void *temp_v0;

    temp_s4 = func_8008D640(1);
    temp_s1 = arg0 + arg1;
    temp_s0 = (void *)((u8 *)D_800AE850 + 0x5910 + temp_s1 * 0x5C);
    temp_v0 = func_800801D0(temp_s0, (arg2 * 4) + 0x28);
    osCreateMesgQueue((void *)((u8 *)temp_v0 + 0x10), (void *)((u8 *)temp_v0 + 0x28), arg2);
    *(u16 *)((u8 *)temp_v0 + 0xC) = (u16)temp_s1;
    *(s16 *)((u8 *)temp_v0 + 0xE) = 0;
    if ((*(s32 *)((u8 *)temp_s0 + 0) == *(s32 *)((u8 *)temp_s0 + 4)) && (*(s32 *)((u8 *)temp_s0 + 0x10) == 0)) {
        switch (temp_s1) {
        case 10U:
            *(s32 *)((u8 *)temp_s0 + 0x10) = func_8007FB3C(&func_8007FE1C, 0x400, 0x71, temp_s0);
            break;
        case 38U:
            *(s32 *)((u8 *)temp_s0 + 0x10) = func_8007FB3C(&func_8007FC44, 0x400, 0x73, temp_s0);
            break;
        case 34U:
            *(s32 *)((u8 *)temp_s0 + 0x10) = func_8007FB3C(&func_8007F490, 0x400, 0x7F, temp_s0);
            break;
        default:
            *(s32 *)((u8 *)temp_s0 + 0x10) = func_8007FB3C(&func_8007F424, 0x400, 0x78, temp_s0);
            break;
        }
    }
    func_8008D640(temp_s4);
    return temp_v0;
}
