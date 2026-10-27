#include "common.h"

u64 osGetTime();
u64 func_8009A2B0(u64,u64);
extern s32 (*D_8009BB18)();
extern char *D_800C7304;
static inline char *inline_fn(char *arg0){return arg0;}
void func_80014288(void)
{
char *s1;u32 s0;char *new_var2;u64 ret;u32 new_var3,new_var;
D_8009BB18();
if(*(u32*)D_800C7304<8){
ret=osGetTime();
s1=D_800C7304;
new_var3=*(u32*)s1;
s0=new_var3;
*(u32*)s1=s0+1;
s0=(u32)inline_fn(s1+s0*8);
ret=func_8009A2B0(ret<<6,0xBB8);
new_var2=(char*)s0+0x50;
*(u64*)new_var2=ret-*(u64*)(s1+8);
ret=osGetTime();
s1=D_800C7304;
new_var=*(u32*)s1;
s0=new_var;
s0=(u32)(s1+s0*((unsigned long long)8));
ret=func_8009A2B0(ret<<6,0xBB8);
*(u64*)((char*)s0+0x10)=ret-*(u64*)(s1+8);
}}
