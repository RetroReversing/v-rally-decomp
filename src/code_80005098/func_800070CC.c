#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
s32 func_8000665C(void *, s32);
typedef struct { u32 w0; u32 w1; } GfxW;
typedef struct { u8 pad0[0x14]; GfxW *dl; u8 pad1[0x70 - 0x18]; s32 base; } ObjQ;
#define SHL(v,s,w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define TRIW(a,b,c) (SHL((a)*2,16,8)|SHL((b)*2,8,8)|SHL((c)*2,0,8))

s32 func_800070CC(ObjQ *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 i;

    temp_v0 = (u16)func_8000665C(arg0, 4);
    temp_a0 = temp_v0 * 0x10;
    *(s16 *)((char *)(temp_a0 + arg0->base) + 6) = 0;
    *(s16 *)((char *)(temp_a0 + arg0->base) + 0x16) = 0;
    *(s16 *)((char *)(temp_a0 + arg0->base) + 0x26) = 0;
    *(s16 *)((char *)(temp_a0 + arg0->base) + 0x36) = 0;
    *(u8 *)((char *)(temp_a0 + arg0->base) + 0xF) = 0xFF;
    *(u8 *)((char *)(temp_a0 + arg0->base) + 0x1F) = 0xFF;
    *(u8 *)((char *)(temp_a0 + arg0->base) + 0x2F) = 0xFF;
    *(u8 *)((char *)(temp_a0 + arg0->base) + 0x3F) = 0xFF;
    i = temp_v0 & 0x1F;
    {
        GfxW *_g = (GfxW *)(arg0->dl++);
        _g->w0 = SHL(7, 24, 8) | TRIW(i, i + 1, i + 2);
        _g->w1 = TRIW(i, i + 2, i + 3);
    }
    return temp_v0;
}
