#include "snapshot29_0433f7af8f6d.h"

typedef struct { s32 a,b; s8 c; } Cfg;
extern void *D_800A1468; extern s32 D_800A14D0; extern Cfg D_800A5CF0;
s32 func_800580D0(s32,s32); s32 func_80053A78(void); s32 func_8005E0D0(s32,s32); s32 func_8005C198(void); s32 func_8007EE9C(s32);
s32 func_8007102C(void){ Cfg *dst; func_800580D0(0,0); *((s8*)D_800A1468+0x24d)=0; func_80053A78(); dst=(Cfg*)((s8*)D_800A1468+0x204); __builtin_memcpy(dst,&D_800A5CF0,9); func_8005E0D0(0,0); func_8005C198(); if(D_800A14D0){func_8007EE9C(D_800A14D0);D_800A14D0=0;} return 0;}
