#include "common.h"

void *func_800056FC(void *);
s32 func_800061FC(void *, s32);
s32 func_8001BD1C();
void guMtxIdent(s32);
void guOrtho(s32, f32, f32, f32, f32, f32, f32, f32);

void func_8004C898(void *arg0) {
    s32 var_s2;
    u32 *temp_v1;
    void *var_s1;

    var_s1 = func_800056FC(arg0);
    var_s2 = func_8001BD1C();
    guMtxIdent(var_s2);
    temp_v1 = *(u32 **)((u8 *)var_s1 + 0x14);
    *(u32 **)((u8 *)var_s1 + 0x14) = temp_v1 + 2;
    temp_v1[0] = 0xDA380003;
    temp_v1[1] = var_s2;
    var_s2 = func_8001BD1C();
    guOrtho(var_s2, (f32)*(s16 *)((u8 *)arg0 + 8), (f32)*(s16 *)((u8 *)arg0 + 0xC), (f32)*(s16 *)((u8 *)arg0 + 0xE), (f32)*(s16 *)((u8 *)arg0 + 0xA), -1.0f, 10.0f, 1.0f);
    func_800061FC(var_s1, var_s2);
}
