#include "common.h"

extern s32 D_80000308; extern volatile s32 D_A4600000; extern s32 osVirtualToPhysical(void*);
s32 func_80094750(s32 a,s32 b,void*c,s32 d){s32 r; while(*(vu32*)0xA4600010&3){} *(vu32*)0xA4600000=osVirtualToPhysical(c); *(vu32*)0xA4600004=(D_80000308|b)&0x1fffffff; switch(a){case 0:r=0xA460000C;break;case 1:r=0xA4600008;break;default:return -1;} *(vu32*)r=d-1; return 0;}
