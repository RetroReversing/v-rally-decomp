#include "common.h"

extern char D_800C02AE[];

u8 func_8006B9E0(u8 arg0, u8 arg1) {
    switch (arg0) {
    case 0:
        break;
    case 1:
        arg1 += 7;
        break;
    case 2:
        arg1 += 13;
        break;
    case 3:
        arg1 += 19;
        break;
    case 4:
        arg1 += 25;
        break;
    case 5:
        arg1 += 31;
        break;
    case 6:
        arg1 += 38;
        break;
    case 7:
        arg1 += 45;
        break;
    }
    return arg1;
}
