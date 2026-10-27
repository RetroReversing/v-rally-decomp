#include "common.h"

s32 func_8008BD90(); void func_8008BDB0(s32); u32 func_800937B0(); extern u8 D_800AE850[];
u64 osGetTime(void) {
s32 mask; u32 delta; u64 time;
mask=func_8008BD90();
delta=func_800937B0()-*(u32 *)(D_800AE850+4);
time=*(u64 *)(D_800AE850+0x7918);
func_8008BDB0(mask);
return time+delta;
}
