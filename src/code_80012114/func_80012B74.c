#include "common.h"

s32 func_80098180(); extern void *D_8009C230; extern char D_800A40EC[],D_800A40F4[],D_800A73E0[];
s32 *func_80012B74(u32 arg0) {
s32 *s0; s32 *s3; s32 flag=0;
if(func_80098180(D_800A40F4,arg0)==0 || func_80098180(D_800A40EC,arg0)==0){
s0=D_8009C230; s0=*(s32 **)((char*)s0+0x5c);
if(func_80098180(D_800A40F4,arg0)==0) s0=*(s32 **)((char*)s0+0x7c);
else s0=*(s32 **)((char*)*(s32 **)((char*)s0+0x7c)+0x24);
}else{
s0=*(s32 **)(*(char **)(D_800A73E0+0x6c24)); s3=s0;
do { if(func_80098180(s0,arg0)==0) flag=1; else {s0=(s32*)((char*)s0+0x34);
if((u32)((*(u16*)(*(char **)(D_800A73E0+0x6c24)+4)-1)*0x34)<(u32)(((s32)((char*)s0-(char*)s3)*(s32)0xC4EC4EC5)>>2)) flag=1; }
}while((flag&255)==0);
}return s0;}
