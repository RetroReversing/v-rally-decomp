#include "common.h"

extern char D_800AE850[];

s32 func_80022068(void *, s32);

void func_80024330(void *arg0) {
    s32 c;
    s32 temp;
    char *temp_v1;

    *(s32 *)(*(char **)((char *)arg0 + 0x54) + 0xA4) = 0;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x10) = *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x390) >> 1;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x14) = *(s32 *)(*(char **)((char *)arg0 + 0x80) + 4) + 0x1E;
    c = 0x80;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x18) = c;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x24) = -(*(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x390) >> 1);
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x28) = *(s32 *)(*(char **)((char *)arg0 + 0x80) + 4) + 0x1E;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x2C) = c;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x38) = *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x394) >> 1;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x3C) = *(s32 *)(*(char **)((char *)arg0 + 0x80) + 4) + 0x1E;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x40) = c - *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x398);
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x4C) = -(*(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x394) >> 1);
    temp_v1 = *(char **)((char *)arg0 + 0x80);
    temp = *(s32 *)(temp_v1 + 4);
    *(s32 *)(D_800AE850 + 0x80A4) = 0;
    *(s32 *)(temp_v1 + 0x50) = temp + 0x1E;
    *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x54) = c - *(s32 *)(*(char **)((char *)arg0 + 0x80) + 0x398);
    func_80022068(arg0, *(s32 *)(*(char **)((char *)arg0 + 0x84) + 0x48));
}
