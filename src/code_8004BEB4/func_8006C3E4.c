#include "decompdecomp_promoted_8006c3e4.h"
#line 1 "func.c"
typedef struct Lap { s32 time; u8 c4; u8 pad5; char name[3]; u8 pad9; u8 speed; u8 padB; u8 valid; u8 padD[3]; } Lap;
typedef struct Drv { u16 w0; u16 w2; char pad[10]; } Drv;
typedef struct Rec { char pad0[0x14]; u16 n; char pad16[0x22C - 0x16]; s32 vals[8]; char pad24C[0x2C4 - 0x24C]; } Rec;

extern void func_8006BF30(s32,s32,s32,s32);
extern s32 D_8009D540;
extern s32 D_800ADF40[];
extern Lap D_800C3750[][4];
extern Drv D_800C70D4[];
extern u8 D_800C7124[];
extern Rec *D_800D0648;

void func_8006C3E4(u8 arg0) {
    u8 i;
    s32 j;
    u32 x;
    Drv *d;
    u16 *tbl;
    s32 total;
    u8 n;

    for (i = 0; i < 3; i++) {
        j = i;
        tbl = (u16 *)D_800C7124;
        x = tbl[arg0 * 3 + j + 0xAD];
        if (x != 0xFFFF) {
            d = &D_800C70D4[x >> 14];
            func_8006BF30((u8)(j), 22,(u8)(arg0),(u8)(arg0));
            D_800C3750[arg0][j].name[0] = ((d->w0 >> 10) & 0x1F) + 'A';
            D_800C3750[arg0][j].name[1] = ((d->w0 >> 5) & 0x1F) + 'A';
            {
                s32 blue = ((u8 *)d)[1];
                x &= 0x3FFF;
                D_800C3750[arg0][j].valid = 1;
                D_800C3750[arg0][j].name[2] = (blue & 0x1F) + 'A';
            }
            if (x & 1) x = -x;
            x = D_800ADF40[arg0] - x;
            D_800C3750[arg0][j].time = x;
            D_800C3750[arg0][j].c4 = (d->w2 >> 12) + (d->w0 >> 15) * 16;
            total = 0;
            for (n = 0; n < D_800D0648[arg0].n; n++) {
                total += D_800D0648[arg0].vals[n];
            }
            D_800C3750[arg0][i].speed = (u32)(total * D_8009D540 * 3600) / (u32)(x * 1000);
        }
    }
}

