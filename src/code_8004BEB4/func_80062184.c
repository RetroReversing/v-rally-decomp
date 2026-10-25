#include "common.h"

extern u8 D_800C02AE[];
extern u8 *D_800A1468;
extern s32 D_800C8328;
s32 func_80057918(s32, s32);
void *func_800592D0(s32);
void func_80059618(void *, u32, u32, u32, u32);
void func_800596F4(void *, s16, s16, s32);
void func_800620F0(s32);

typedef struct {
    s32 w[4];
} Args;

void func_80062184(Args args, s32 arg4, s32 arg5) {
    u8 i;
    u8 *obj;
    s32 flag;

    flag = *((u8 *)&args + 0x2C7);
    i = 0;
    if (*(u16 *)&arg5 != 0) {
        do {
            obj = func_800592D0(i);
            if (i == *(u16 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0x22) && D_800A1468[0x245] != 0) {
                func_80059618(obj, 0xDC, 0xDC, 0xE, 0xFF);
            } else {
                if (flag != 0 && (*(u8 *)(D_800C02AE + 0x327E + *(u16 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0x20)) & (1 << i)) != (1 << i)) {
                    func_80059618(obj, obj[0xB] >> 1, obj[0xC] >> 1, obj[0xD] >> 1, obj[0xE] >> 1);
                    func_800620F0(i);
                } else {
                    func_80059618(obj, obj[0xB], obj[0xC], obj[0xD], obj[0xE]);
                }
            }
            func_800596F4(obj, *(s16 *)(obj + 6), *(s16 *)(obj + 8), func_80057918(D_800C8328, ((u8 *)&args)[i * 64 + 0x37] + 0x1E4));
            i++;
        } while (i < *(u16 *)&arg5);
    }
}
