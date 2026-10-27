#include "checkpoint_common.h"

s32 func_800056FC(void *);
void *func_80006008(s32);
void func_80006014(s32, void *);
void func_800061FC(s32, s32);
s32 func_8001BD1C(void);
void func_8004A0A0(void);
void func_8004AFB8(void);
void guMtxF2L(void *, s32);
void guMtxIdent(void *);
void guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
extern char D_800C02AE[];
extern void *D_800C7F84;

void func_8004BEB4(void) {
    s32 sp20[16];
    void *temp_s1;
    s32 temp_s0;
    s32 temp_a0;
    s32 *temp_v0_2;
    void *temp_v1;

    temp_s1 = D_800C02AE + 0x80D2;
    guMtxIdent(temp_s1);
    temp_a0 = func_800056FC(*(void **)((char *)D_800C7F84 + 0x178));
    temp_v0_2 = func_80006008(temp_a0);
    temp_v0_2[0] = 0xDA380003;
    temp_v0_2[1] = (s32)temp_s1;
    func_80006014(temp_a0, temp_v0_2 + 2);
    temp_s0 = func_8001BD1C();
    temp_v1 = *(void **)((char *)D_800C7F84 + 0x178);
    guOrthoF(sp20, (f32)*(s16 *)((char *)temp_v1 + 8), (f32)*(s16 *)((char *)temp_v1 + 0xC), (f32)*(s16 *)((char *)temp_v1 + 0xE), (f32)*(s16 *)((char *)temp_v1 + 0xA), -1.0f, 10.0f, 1.0f);
    guMtxF2L(sp20, temp_s0);
    func_800061FC(func_800056FC(*(void **)((char *)D_800C7F84 + 0x178)), temp_s0);
    func_8004A0A0();
    func_8004AFB8();
}
