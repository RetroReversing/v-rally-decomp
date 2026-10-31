#include "snapshot31_manual_verified.h"

extern u8 *D_800C35A0;
extern s32 D_8009F4F0,D_8009F4F4,D_8009F4F8,D_8009F4FC,D_8009F500,D_8009F504,D_8009F508,D_8009F50C,D_8009F514,D_8009F518,D_8009F51C;
#define F(n,o) (*(s32*)((char*)&D_8009F##n+(o)))
#define IDX(p) (*(u16*)((p)+0x16)*0x30)
void func_8003354C(void){u8 *p;s32 off;u32 o;char *base;
off=IDX(D_800C35A0);if(F(4FC,off)>=256)F(4FC,off)=255;
off=IDX(D_800C35A0);if(F(4F8,off)>=256)F(4F8,off)=255;
o=IDX((p=D_800C35A0));F(500,o)=F(4F0,o);
o=IDX(p);F(504,o)=F(4FC,o);
base=(char*)&D_8009F4F0;
F(508,IDX(p))=(F(4F4,IDX(p))-*(s32*)(base+IDX(p)))/3;
F(50C,IDX(p))=(F(4F8,IDX(p))-F(4FC,IDX(p)))/3;
o=IDX(p);F(518,o)=F(514,o)/3;
F(51C,IDX(p))=F(514,IDX(p))/2;
}