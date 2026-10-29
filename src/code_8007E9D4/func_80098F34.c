#include "snapshot29_0433f7af8f6d.h"

extern u8 D_800A73E0[];
extern u8 *func_80098B7C(s32, s32, s32, s32 *, s32 *);
extern s32 func_80098290(u8 *);
extern s32 func_8008E13C(u8 *, u8 *, s32);


u8 *func_80098F34(s32 a0,s32 a1,s32 arg2,u8 *arg3){
 s32 sp18,sp1c,var_s1; u8 *var_a1,*var_s0,*var_s0_2;
 var_a1=func_80098B7C(a0,a1,arg2,&sp18,&sp1c); var_s0=arg3;
 if(sp1c){*arg3=0x2d;var_s0=arg3+1;}
 if(sp18==0x7fffffff){func_80098290(var_s0);return arg3;}
 if(sp18<=0){if(sp18>=-3){*var_s0++=0x30;*var_s0++=0x2e;var_s0_2=var_s0;
   if(sp18) do {*var_s0_2++=0x30;sp18=sp18+1;} while(sp18);
   func_8008E13C(var_s0_2,var_a1,arg2);var_s0=var_s0_2+arg2;
block10: if(*(s8*)(D_800A73E0+0x6b24))*var_s0=0;else{if(((s8*)var_s0)[-1]==0x30)do{var_s0--; }while(((s8*)var_s0)[-1]==0x30);var_s0-=((s8*)var_s0)[-1]==0x2e;*var_s0=0;} return arg3;} goto block27;}
 if(sp18<arg2){arg2--;if(arg2!=-1) do{
   *var_s0++=*var_a1++;sp18=sp18-1;if(sp18==0)*var_s0++=0x2e;arg2--;
 }while(arg2!=-1);
goto block10;
 } else if(arg2+1>=sp18){func_8008E13C(var_s0,var_a1,sp18);var_s0[arg2]=0x30;if(!*(s8*)(D_800A73E0+0x6b24))var_s0[sp18]=0;else{var_s0[sp18]=0x2e;(var_s0+sp18)[1]=0;}}
 else{block27:func_80098A1C(var_a1,arg2,sp18-1,var_s0);} return arg3;
}
