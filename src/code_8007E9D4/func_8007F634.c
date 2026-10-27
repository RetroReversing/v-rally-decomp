#include "common.h"

extern s32 D_800AE850;
extern s32 func_8007FBE4(s32);
extern s32 func_800803C0(void *, void *);
extern s32 func_8008D640(s32);

void func_8007F634(void *arg0) {
    s32 temp_s2;
    s32 *temp_s0;
    u8 *temp_s3;
    temp_s2 = func_8008D640(1);
    temp_s3 = (u8 *)&D_800AE850 + 0x5910;
    temp_s0 = (s32 *)(temp_s3 + ((u16 *)((u8 *)arg0 + 0xC))[0] * 0x5C);
    if (temp_s0[0] == temp_s0[1]) {
        func_8007FBE4(temp_s0[4]);
        temp_s0[4] = 0;
    }
    func_800803C0(arg0, temp_s3 + ((u16 *)((u8 *)arg0 + 0xC))[0] * 0x5C);
    func_8008D640(temp_s2);
}
