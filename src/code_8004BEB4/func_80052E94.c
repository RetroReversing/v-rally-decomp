#include "snapshot29_0433f7af8f6d.h"

s32 func_80099DF8(s32,void*,u16,u16,u16); extern u32 D_8009D540; extern u8 D_8009D544; extern char D_800A5050;
void func_80052E94(s32 arg0,s32 arg1) {
 s32 a3=arg0; u32 d; u32 q,rem,sec,cs;
 if(D_8009D544==0) a3=(a3*2)/3;
 d=D_8009D540;
 q=a3/(((d<<4)-d)<<2);
 rem=a3-((((q<<4)-q)<<2)*d);
 sec=rem/d;
 rem-=sec*d; cs=(rem*100)/d;
 func_80099DF8(arg1,&D_800A5050,q&0xffff,sec&0xffff,cs&0xffff);
}
