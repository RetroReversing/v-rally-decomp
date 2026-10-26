#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

s32 func_800056FC(s32);
void *func_80006008(s32);
s32 func_80006014(s32, void *);
void *func_8004240C(u32);
s32 guMtxIdent(void *);
extern u8 *D_800C35A0;
extern u8 D_800C8380[];

void func_80010AF4(void) {
    u8 *p;
    Gfx *dl;
    Gfx *q;
    Gfx *r;
    u8 *s4;
    s32 s1;
    u8 count;
    u32 s3;

    count = (*(u16 *)(D_800C35A0 + 0xE) * 2) & 0xFF;
    s3 = 1;
    if (count != 0) {
        s4 = D_800C8380;
        do {
            p = func_8004240C(s3);
            s3 += 1;
            s1 = func_800056FC(*(s32 *)(p + 0x178));
            dl = func_80006008(s1);
            guMtxIdent(s4);
            q = dl++;
            q->w0 = 0xDB0E0000;
            q->w1 = *(u16 *)(p + 0x104);
            r = dl++;
            r->w0 = 0xDA380003;
            r->w1 = (u32)s4;
            dl->w0 = 0xE7000000;
            dl->w1 = 0;
            func_80006014(s1, dl + 1);
        } while (count >= s3);
    }
}
