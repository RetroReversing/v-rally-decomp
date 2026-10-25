#include "common.h"

s32 func_8001B834();
s32 func_8001B854();
s32 func_80081540();
s32 func_80081664();
s32 func_80098290();
extern u8 D_800A16D5;
extern char D_800A476C[];
extern char D_800AE850[];
extern char D_800C02AE[];

void func_8001C718(s32 arg0)
{
    s32 temp_s0;

    func_80098290(D_800AE850 + 0x23D8, arg0 + 0x98);
    func_80098290(D_800C02AE + 0x5B82, arg0 + 0xE4);
    if (D_800A16D5 == 0) {
        temp_s0 = func_80081664(1, arg0 + 0x4C);
        func_80081540(arg0 + 0x130);
        func_8001B854(temp_s0, D_800A476C);
    } else {
        func_8001B834();
    }
}
