#include "common.h"

extern s32 D_8009E230;
extern s32 D_8009FF30;
extern char D_800A47C4[], D_800A47CC[], D_800A47D4[], D_800A47DC[], D_800A47E4[], D_800A47EC[], D_800A47F4[], D_800A4800[];
void func_8002B618(void *a0, void *a1);

void func_8001DAF0(u8 *arg0) {
    func_8002B618(arg0 + 0x4C, D_800A47C4);
    D_8009E230 = 0;
    switch (D_8009FF30) {
    case 0:
        func_8002B618(arg0 + 0x4C, D_800A47CC);
        break;
    case 1:
        func_8002B618(arg0 + 0x4C, D_800A47D4);
        break;
    case 2:
        func_8002B618(arg0 + 0x4C, D_800A47DC);
        break;
    case 3:
        func_8002B618(arg0 + 0x4C, D_800A47E4);
        D_8009E230 = 0xD;
        break;
    case 4:
        func_8002B618(arg0 + 0x4C, D_800A47EC);
        break;
    case 5:
        func_8002B618(arg0 + 0x4C, D_800A47F4);
        break;
    }
    func_8002B618(arg0 + 0x4C, D_800A4800);
}
