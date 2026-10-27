#include "common.h"

extern s32 D_800A2540;
extern void *D_800A2544,*D_800A2548,*D_800A254C,*D_800A2550,*D_800A2554,*D_800A2558;
extern s32 D_800A39A0;
extern u8 D_800A73E0[],D_800AE850[];
extern u8 D_800AB9E0[], D_800ACB90[], D_800ACBA8[], D_800B6FF8[];
extern void __osDevMgrMain(void),func_80094750(void),func_800932E0(void),func_800903F0(void);
extern s32 func_800937D0(s32),func_80094660(void),func_8008BD90(void),func_8008BDB0(s32);
extern s32 osCreateMesgQueue(void *,void *,s32),osCreateThread(void *,s32,void (*)(void),void *,void *,s32),osStartThread(void *),osSetEventMesg(s32,void *,s32),osSetThreadPri(s32,s32);
void func_80090250(s32 arg0,void *arg1,void *arg2,s32 arg3){
 s32 *flag=&D_800A2540; s32 temp_v0,temp_v0_2,var_s2; void *temp_s0,*temp_s1;
 if(*flag) return;
 func_800903F0();
 osCreateMesgQueue(arg1,arg2,arg3);
 temp_s0=D_800ACB90;
 osCreateMesgQueue(temp_s0,D_800ACBA8,1);
 if(D_800A39A0==0) func_80094660();
 osSetEventMesg(8,temp_s0,0x22222222);
 var_s2=-1;
 temp_v0=func_800937D0(0);
 if(temp_v0<arg0){var_s2=temp_v0;osSetThreadPri(0,arg0);}
 temp_v0_2=func_8008BD90();
 temp_s1=D_800AB9E0;
 *flag=1;
 D_800A2550=D_800AE850+0x87A8;
 D_800A2554=func_80094750;
 D_800A2558=func_800932E0;
 D_800A254C=temp_s0;
 D_800A2544=temp_s1;
 D_800A2548=arg1;
 osCreateThread(temp_s1,0,__osDevMgrMain,flag,D_800A73E0+0x57B0,arg0);
 osStartThread(temp_s1);
 func_8008BDB0(temp_v0_2);
 if(var_s2!=-1) osSetThreadPri(0,var_s2);
}
