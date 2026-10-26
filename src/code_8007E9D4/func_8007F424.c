#include "common.h"

extern char D_800C02AE[];
void func_8007F394();
void osRecvMesg();

void func_8007F424(char *arg0) {
    s32 sp10;

    for (;;) {
        osRecvMesg(arg0 + 0x14, &sp10, 1);
        (*(void (**)())(D_800C02AE + 0x7D8A + *(u16 *)(arg0 + 0xE) * 4))();
        func_8007F394(arg0, &sp10);
    }
}
