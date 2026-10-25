#include "common.h"

extern s8 D_800B5AF0;
extern s8 D_800B5AF1;
extern s8 D_800B5AF2;
extern u8 D_800B5AF3;
extern u16 D_800C3598;
extern u16 D_800C359A;
extern u16 D_800C359C;
extern u16 D_800C359E;
extern u16 D_800B7074;
extern u16 D_800B7076;
extern u16 D_800B7078;
extern u16 D_800B707A;
extern s32 D_800C7F84;
s32 func_8000EF0C();
s32 func_8004240C();

void func_800490F0(void *arg0, s32 arg1) {
    s8 *s1;
    u16 *s2;
    u16 *s3;
    u16 t;

    s1 = &D_800B5AF0;
    *s1 = 0;
    D_800B5AF1 = 0;
    D_800B5AF2 = 0;
    D_800B5AF3 = 0xFF;
    s3 = &D_800C3598;
    *s3 = *(u16 *)((char *)arg0 + 8);
    t = *(u16 *)((char *)arg0 + 0xA);
    D_800C359C = 0x20;
    D_800C359A = t;
    D_800C359E = *(u16 *)((char *)arg0 + 0xE);
    s2 = &D_800B7074;
    *s2 = *(u16 *)((char *)arg0 + 0xC) - 0x20;
    D_800B7076 = *(u16 *)((char *)arg0 + 0xA);
    D_800B7078 = *(u16 *)((char *)arg0 + 0xC);
    D_800B707A = *(u16 *)((char *)arg0 + 0xE);
    D_800C7F84 = func_8004240C(((arg1 & 0xFFFF) * 2) | 1);
    func_8000EF0C(arg0, s3, s1);
    func_8000EF0C(arg0, s2, s1);
}
