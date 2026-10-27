#include "common.h"

void *func_800592AC(s32); void func_80059618(void*,u8,u8,u8,s32); void func_800596F4(void*,s16,s16,s32); void func_8006874C(s8); extern u8 *D_800A1468; extern s32 D_800A1630; extern u8 D_800C02AE[];
void func_800683CC(void) {
 u8 *p; s32 v,off;
 if(D_800A1468[0x229]<4) {
 p=*(u8**)((u8*)func_800592AC(0)+0x28);
 func_80059618(p,p[11],p[12],p[13],255);
 off=(s8)D_800A1468[0x229]*5*8+0x44;
 func_800596F4(p,*(s16*)(p+6),*(s16*)(p+8),*(s32*)(D_800C02AE+0x32F2)+off);
 }
 v=D_800A1630;
 if(v!=-1) {u8 *q=*(u8**)(D_800C02AE+0x325A); *(u8*)(*(s32*)(q+16)+*(s16*)(q+2)*20+14)=v; D_800A1630=-1;}
 {u8 *r=*(u8**)(D_800C02AE+0x32F2);
 r+=(s8)D_800A1468[0x229];
 func_8006874C((s8)r[0x32]);}
}
