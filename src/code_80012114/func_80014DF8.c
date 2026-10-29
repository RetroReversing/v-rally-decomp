#include "snapshot29_0433f7af8f6d.h"

extern s32 D_8009B5A4;
extern void *func_80005C48(s32);

void func_80014DF8(s32 x, s32 y, s32 r, s32 color) {
    s32 pad[2]; s32 *base;
    s32 d;
    u32 a;
    u32 rr;
    s32 t3;
    s32 px;
    s32 py;

    base = (s32 *)func_80005C48(D_8009B5A4);
    rr = r * r;
    d = rr - r;
    a = 0;
    t3 = ((u32)(x + r) >= 0x140U || (u32)(y + r) >= 0xF0U);
    do {
        if (t3) {
            px = x + a;
            py = y - r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
            px = x - a;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
            px = x + a;
            py = y + r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
            px = x - a;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
            px = x + r;
            py = y - a;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
            px = x - r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
            px = x + r;
            py = y + a;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
            px = x - r;
            if (((u32)px < 0x140U) & ((u32)py < 0xF0U)) {
                *(s16 *)(py * 0x280 + (px * 2 + (s32)base)) = color;
            }
        } else {
            *(s16 *)(((x+a)*2+(s32)base) + (y-r)*0x280) = color;
            *(s16 *)((y - r) * 0x280 + ((x - a) * 2 + (s32)base)) = color;
            *(s16 *)((y + r) * 0x280 + ((x + a) * 2 + (s32)base)) = color;
            *(s16 *)((y + r) * 0x280 + ((x - a) * 2 + (s32)base)) = color;
            *(s16 *)(((x+r)*2+(s32)base) + (y-a)*0x280) = color;
            *(s16 *)((y - a) * 0x280 + ((x - r) * 2 + (s32)base)) = color;
            *(s16 *)((y + a) * 0x280 + ((x + r) * 2 + (s32)base)) = color;
            *(s16 *)((y + a) * 0x280 + ((x - r) * 2 + (s32)base)) = color;
        }
        a++;
        rr += 1 - a * 2;
        if (d >= rr) {
            r--;
            d -= r * 2;
        }
    } while (r >= a);
}
