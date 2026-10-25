#include "common.h"

extern void *D_800C811C;
extern s32 *D_800C60D4;
extern unsigned char D_800C7926;
s32 func_80035438();
s32 func_8007EE9C();
s32 func_800803C0();
s32 func_80080478();

void func_80035A10(void) {
    s32 *temp_s1;
    void *temp_s0;

    if (*(s32 *)D_800C811C) {
        func_80035438(*(s32 *)D_800C811C);
    }
    if (*(u16 *)((char *)D_800C811C + 4) == 0 && D_800C7926 == 0) {
        temp_s1 = D_800C60D4;
        if (temp_s1[0] != 0) {
            do {
                temp_s0 = (void *)temp_s1[1];
                func_80035438(*(s32 *)(*(char **)(((char *)temp_s0) + 0xC) + 0xA4));
                func_8007EE9C(*(void **)(((char *)temp_s0) + 0xC));
                func_800803C0(temp_s0, temp_s1);
            } while (temp_s1[0] != 0);
        }
        func_80080478(temp_s1);
    }
    if (*(void **)((char *)D_800C811C + 0x10)) {
        func_8007EE9C(*(void **)((char *)D_800C811C + 0x10));
    }
    if (*(void **)((char *)D_800C811C + 0x14)) {
        func_8007EE9C(*(void **)((char *)D_800C811C + 0x14));
    }
    func_8007EE9C(D_800C811C);
}
