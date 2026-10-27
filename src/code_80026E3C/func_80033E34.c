#include "common.h"

s32 func_8001FEDC(); void func_80030180(void *,s32,s16,s16*);
void func_80033E34(void *arg0,s32 arg1,void *arg2){
s16 sp10[3]; void *p,*a,*t; s32 n,k,x; void *q;
t=*(void**)((u8*)arg0+0x8c); p=*(void**)((u8*)t+0x2c);
n=*(s32*)((u8*)*(void**)((u8*)arg0+0x60)+0x2c);
a=(void*)func_8001FEDC(); k=(-((s32)a>=5000)&5)|4;
if((s32)a<3000)k=3; if((s32)a<1000)k=2;
a=(void*)(u32)*(u16*)((u8*)p+0x88); x=n+k;
if(x<(s32)a)a=p; else {q=*(void**)((u8*)p+0x5c);if(q)p=q; x=(x-k)-(s32)a+k+1;a=p;}
func_80030180(a,x,(s16)arg1,sp10);
*(s32*)arg2=sp10[0]+*(s32*)((u8*)p+0x24);
*(s32*)((u8*)arg2+4)=sp10[1]+*(s32*)((u8*)p+0x28);
*(s32*)((u8*)arg2+8)=sp10[2]+*(s32*)((u8*)p+0x2c);
}
