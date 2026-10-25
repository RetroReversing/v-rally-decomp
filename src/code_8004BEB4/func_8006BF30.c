#include "common.h"

extern u8 D_800C02AE[];
void func_8006BE50(u8 *p, u8 a);

void func_8006BF30(u8 a, u8 b, u8 c, u8 d) {
    switch (b) {
    case 0:
        func_8006BE50(((u8 **)((u8 *)D_800C02AE + 0x10386))[b] + c * 708 + ((d << 6) + 0x2C), a);
        break;
    case 1:
        func_8006BE50((u8 *)D_800C02AE + 0x34A2 + (d << 6), a);
        break;
    case 2:
        func_8006BE50((u8 *)D_800C02AE + 0x33A2 + (d << 6), a);
        break;
    case 3:
        func_8006BE50((u8 *)D_800C02AE + 0x37A2, a);
        break;
    case 4:
        func_8006BE50((u8 *)D_800C02AE + 0x37E2, a);
        break;
    case 5:
        func_8006BE50((u8 *)D_800C02AE + 0x3822, a);
        break;
    case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
    case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24: case 25: case 26:
        break;
    }
}
