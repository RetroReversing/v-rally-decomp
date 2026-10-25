#include "common.h"

extern u8 D_800C02AE[];
extern u8 D_800A4D44[];
extern u8 D_800A4D48[];
extern u8 D_800A4D50[];
extern u8 D_800A4D58[];
extern u8 D_800A4D60[];
extern u8 D_800A4D68[];
extern u8 D_800A4D70[];
extern u8 D_800A4D74[];
extern u8 D_800A4D7C[];
extern u8 D_800A4D84[];
void func_8002B618(void *arg0, void *arg1);
void func_80023380(void);

void func_80041A04(s32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D48);
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D50);
        break;
    case 1:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D58);
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D50);
        break;
    case 2:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D60);
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D50);
        break;
    case 3:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D68);
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D50);
        break;
    case 4:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D70);
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D50);
        break;
    case 5:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D74);
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D50);
        break;
    case 6:
        func_80023380();
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D7C);
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D50);
        break;
    case 7:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(D_800A4D84, D_800A4D50);
        break;
    case 8:
        func_8002B618(*(u8 **)(D_800C02AE + 0x103AA) + arg1 * 708, D_800A4D44);
        func_80023380();
        func_8002B618(D_800A4D84, D_800A4D50);
        break;
    }
}
