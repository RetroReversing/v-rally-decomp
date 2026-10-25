#include "common.h"

s32 func_800106F4(void *a, void *b, s32 c, s32 d);
s32 func_800425F4(void *a);
extern u8 *D_800C7F84;

typedef struct {
    s32 w[4];
} Block16;

void func_80010A6C(u8 *arg0, void *arg1) {
    Block16 *src;
    Block16 *end;
    Block16 *dst;

    func_800106F4(D_800C7F84 + 0x38, arg1, *(s32 *)(*(u8 **)(D_800C7F84 + 0x178) + 0x3C), *(s32 *)(*(u8 **)(D_800C7F84 + 0x178) + 0x40));
    func_800425F4(D_800C7F84);
    dst = (Block16 *)(arg0 + 0x38);
    src = (Block16 *)(D_800C7F84 + 0x38);
    end = (Block16 *)(D_800C7F84 + 0x178);
    do {
        *dst++ = *src++;
    } while (src != end);
}
