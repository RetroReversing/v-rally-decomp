#include "common.h"

extern void func_8008D8B4(void);
extern void func_8008D920(void);
extern void func_8008F788(s32);
extern u32 func_8008FA20(s32, u16 *);
extern void func_80090DC0(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 D_800B6EB0[];

u32 func_8008F5F0(s32 arg0, u8 arg1, u8 *arg2) {
    u8 work[20];
    s32 var_v0;
    u16 temp_v1;
    u32 var_s0;
    u32 result;
    u8 *var_s3 = arg2;
    u8 *var_v1;
    u8 *var_s2;
    func_8008D8B4();
    result = func_8008FA20(arg0, (u16 *)work);
    temp_v1 = (*(u16 *)work & 0xC000) & 0xFFFF;
    var_s2 = D_800B6EB0;
    var_s0 = result;
    if (var_s0 == 0) {
        if (temp_v1 == 0x8000) {
            if (((u32)arg1 & 0xFF) >= 0x40U) var_s0 = -1;
        } else if (temp_v1 != 0xC000) var_s0 = 8;
        if (var_s0 == 0) {
            do {
                if ((work[2] & 0x80) != 0)
                    func_8008FA20(arg0, (u16 *)work);
            } while ((work[2] & 0x80) != 0);
            func_8008F788(arg1 & 0xFF);
            func_80090DC0(1, D_800B6EB0);
            osRecvMesg(arg0, 0, 1);
            func_80090DC0(0, D_800B6EB0);
            D_800C02AE[0x3272] = 4;
            osRecvMesg(arg0, 0, 1);
            var_v0 = 3;
            do { var_v0--; var_s2++; } while (var_v0 >= 0);
            __builtin_memcpy(work + 8, var_s2, 12);
            var_s0 = (work[9] & 0xC0) >> 4;
            var_v1 = &work[12];
            if (var_s0 == 0) {
                u8 *end = &work[20];
                do { *var_s3++ = *var_v1++; } while ((s32)var_v1 < (s32)end);
            }
        }
    }
    func_8008D920();
    return var_s0;
}
