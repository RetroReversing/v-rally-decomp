#include "common.h"

s32 func_8002E288();
extern char D_800AE850[];

void func_8002E5E0(s32 arg0, void *arg1) {
    func_8002E288(D_800AE850 + 0x7928, arg0, arg1);
    *(s32 *)((char *)arg1 + 0) = (s32) (*(s32 *)((char *)arg1 + 0) + *(s32 *)(D_800AE850 + 0x793C));
    *(s32 *)((char *)arg1 + 4) = (s32) (*(s32 *)((char *)arg1 + 4) + *(s32 *)(D_800AE850 + 0x7940));
    *(s32 *)((char *)arg1 + 8) = (s32) (*(s32 *)((char *)arg1 + 8) + *(s32 *)(D_800AE850 + 0x7944));
}
