#include "snapshot29_0433f7af8f6d.h"

typedef struct { u8 b[8]; } Buf8;

extern u8 *D_8009B5A4;
extern f32 D_8009BB94, D_8009BB98, D_8009BB9C, D_8009BBA0;
extern u16 D_8009FF88, D_8009FF8A, D_8009FF8C, D_8009FF8E;
extern u16 D_8009FF90, D_8009FF92, D_8009FF94, D_8009FF96;
extern u16 D_8009FF98, D_8009FF9A;
extern char D_800A4C60[], D_800A4C68[], D_800A4C74[], D_800A4C7C[], D_800A4C88[];
extern void *D_800C7F84;

void func_80041320(void) {
    s32 s0;
    void *s2;
    u16 mode;
    u16 t0;
    u16 t1;
    u16 half2;
    u16 v1;
    u8 stackbuf[8];

    s0 = 2;
    mode = (u16)s0;
    t0 = *(u16 *)(D_8009B5A4 + 0);
    t1 = *(u16 *)(D_8009B5A4 + 2);
    half2 = *(u16 *)(D_8009B5A4 + 4);
    v1 = *(u16 *)(D_8009B5A4 + 6);
    *(u16 *)(stackbuf + 0) = t0;
    *(u16 *)(stackbuf + 2) = t1;
    *(u16 *)(stackbuf + 4) = half2;
    *(u16 *)(stackbuf + 6) = v1;
    *(Buf8 *)&stackbuf[0] = *(Buf8 *)D_8009B5A4;

    s2 = func_80042078(stackbuf, 5, D_8009FF88, D_8009FF8A, mode);
    func_800424A4(s2, D_800A4C68);
    {
        u8 *p;
        p = D_8009B5A4;
        *(s32 *)((u8 *)s2 + 12) = 0;
        *(Buf8 *)&stackbuf[0] = *(Buf8 *)p;
    }
    s2 = func_80042078(stackbuf, 2, D_8009FF94, D_8009FF96, mode);
    func_800424A4(s2, D_800A4C74);
    *(s32 *)((u8 *)s2 + 12) = 3;
    *(f32 *)((u8 *)s2 + 0x18C) = 250.0f;
    *(f32 *)((u8 *)s2 + 0x190) = 2000.0f;
    D_8009BB94 = 250.0f;
    D_8009BB9C = 2000.0f;
    D_8009BB98 = 250.0f;
    D_8009BBA0 = 2000.0f;

    s2 = func_80042078(stackbuf, 2, D_8009FF8C, D_8009FF8E, mode);
    func_800424A4(s2, D_800A4C7C);
    *(s32 *)((u8 *)s2 + 12) = 1;

    D_800C7F84 = s2;
    s2 = func_80042078(stackbuf, 5, D_8009FF90, D_8009FF92, mode);
    func_800424A4(s2, D_800A4C88);
    *(s32 *)((u8 *)s2 + 12) = s0;

    s2 = func_80042078(stackbuf, 2, D_8009FF98, D_8009FF9A, mode);
    func_800424A4(s2, D_800A4C60);
    *(s32 *)((u8 *)s2 + 12) = 4;
}
