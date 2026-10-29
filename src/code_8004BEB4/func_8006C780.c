#include "snapshot29_0433f7af8f6d.h"

extern s32 func_8006BF30(u32, s32, s32, s32);
extern u8 D_800A73E0[];
extern u8 D_800C02AE[];
void func_8006C780(void) {
    s32 count; u32 index; u32 entry; u8 *src; u8 *table; s32 offset;
    table=D_800C02AE+28278; count=0; index=count&255;
    do {
        index=count&255;
        entry=*(u16 *)(table+index*2+334);
        if(entry!=0xFFFF) {
            src=D_800C02AE+28198+(entry>>14)*14;
            if(index<3) {
                func_8006BF30(index,25,0,0); offset=index*16;
                D_800C02AE[14312+offset]=((*(u16*)src>>10)&31)+65;
                D_800C02AE[14313+offset]=((*(u16*)src>>5)&31)+65;
                D_800C02AE[14314+offset]=(src[1]&31)+65;
                {u8 flag=*(u8 *)((s32)table+index+331); entry=entry&0x3fff; D_800C02AE[14318+offset]=1;
                D_800C02AE[14310+offset]=flag&15;}
                if(entry&1)entry=-entry;
                entry=*(s32 *)(D_800A73E0+27540)-entry; *(s32 *)(D_800C02AE+14306+offset)=entry;
                count++; goto tail;
            } else {
                func_8006BF30((count-3)&255,26,0,0); offset=(index-3)*16;
                D_800C02AE[14376+offset]=((*(u16*)src>>10)&31)+65;
                D_800C02AE[14377+offset]=((*(u16*)src>>5)&31)+65;
                D_800C02AE[14378+offset]=(src[1]&31)+65;
                {u8 flag=*(u8 *)((s32)table+index+328); entry=entry&0x3fff; D_800C02AE[14382+offset]=1;
                D_800C02AE[14374+offset]=flag>>4;}
                if(entry&1)entry=-entry;
                entry=*(s32 *)(D_800A73E0+27544)-entry; *(s32 *)(D_800C02AE+14370+offset)=entry;
            }
        }
        count++; tail: ;
    } while((u32)(count&255)<6);
}
