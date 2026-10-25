#include "common.h"

s32 func_8008D8B4();
s32 func_8008D920();
s32 func_8008FA20();

s32 func_8008F570(s32 arg0) {
    u16 sp10;
    s32 s0;
    s32 r;
    u16 v;

    s0 = arg0;
    func_8008D8B4(s0);
    r = func_8008FA20(s0, &sp10);
    v = sp10 & 0xC000;
    if (r == 0) {
        switch (v) {
        case 0x8000:
            s0 = 1;
            break;
        case 0xC000:
            s0 = 2;
            break;
        default:
            s0 = 0;
            break;
        }
    } else {
        s0 = 0;
    }
    func_8008D920();
    return s0;
}
