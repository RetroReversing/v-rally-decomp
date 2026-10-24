#include "common.h"

s32 func_800056FC();
void *func_80006008();
s32 func_80006014();
s32 func_80006298();
s32 func_800068C0();
s32 func_80006CF8();
s32 func_80007404();
extern char D_800A03E0[];

void func_8004C370(s32 arg0, void *arg1) {
    s32 temp_s2;
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0 = func_800056FC();
    temp_v0_2 = func_80006008(temp_v0);
    *(s32 *)((char *)temp_v0_2 + 0) = 0xDE000000;
    *(s32 * *)((char *)temp_v0_2 + 4) = &D_800A03E0;
    func_80006014(temp_v0, temp_v0_2 + 8);
    temp_s2 = func_80006CF8(temp_v0, 0) & 0xFFFF;
    func_800068C0(temp_v0, temp_s2, *(s16 *)((char *)arg1 + 0x12), *(s16 *)((char *)arg1 + 0x22), (s32) *(s16 *)((char *)arg1 + 0x32), (s32) *(s16 *)((char *)arg1 + 0x16), (s32) *(s16 *)((char *)arg1 + 0x26), (s32) *(s16 *)((char *)arg1 + 0x36), (s32) *(s16 *)((char *)arg1 + 0x1A), (s32) *(s16 *)((char *)arg1 + 0x2A), (s32) *(s16 *)((char *)arg1 + 0x3A), (s32) *(s16 *)((char *)arg1 + 0x1E), (s32) *(s16 *)((char *)arg1 + 0x2E), (s32) *(s16 *)((char *)arg1 + 0x3E));
    func_80007404(temp_v0, temp_s2, *(u8 *)((char *)arg1 + 0x40), *(u8 *)((char *)arg1 + 0x44), (s32) *(u8 *)((char *)arg1 + 0x48), (s32) *(u8 *)((char *)arg1 + 0x4C), (s32) *(u8 *)((char *)arg1 + 0x41), (s32) *(u8 *)((char *)arg1 + 0x45), (s32) *(u8 *)((char *)arg1 + 0x49), (s32) *(u8 *)((char *)arg1 + 0x4D), (s32) *(u8 *)((char *)arg1 + 0x42), (s32) *(u8 *)((char *)arg1 + 0x46), (s32) *(u8 *)((char *)arg1 + 0x4A), (s32) *(u8 *)((char *)arg1 + 0x4E), (s32) *(u8 *)((char *)arg1 + 0x43), (s32) *(u8 *)((char *)arg1 + 0x47), (s32) *(u8 *)((char *)arg1 + 0x4B), (s32) *(u8 *)((char *)arg1 + 0x4F));
    func_80006298(temp_v0);
}
