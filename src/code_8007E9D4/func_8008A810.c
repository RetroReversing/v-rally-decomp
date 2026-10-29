#include "snapshot29_0433f7af8f6d.h"

extern s32 D_800C3528; extern s32 D_800A1C90; extern u8 D_800B60E0,D_800C3520; extern char D_800AE850[],D_800C02AE[];
u64 osGetTime(void); s32 osCreateMesgQueue(void*,void*,s32); s32 osSetTimer(void*,u64,u64,void*,void*); s32 osRecvMesg(void*,void*,s32); s32 __osPackRequestData(s32); s32 func_80090DC0(s32,void*); void func_8008A9AC(s32,s32); void func_8008D860(void);
s32 func_8008A810(s32 *arg0,s32 arg1,s32 arg2){
 u8 timer[32]; u8 queue[24]; s32 msg; s32 result; u64 now; void *p;
 if(D_800A1C90)return 0;
 D_800A1C90=1; now=osGetTime();
 if(now<0x165A0BCULL){osCreateMesgQueue(queue,&msg,1);osSetTimer(timer,0x165A0BCULL-now,0,queue,&msg);osRecvMesg(queue,&msg,1);}
 D_800B60E0=4;__osPackRequestData(0);p=D_800AE850+0x1250;func_80090DC0(1,p);osRecvMesg(arg0,&msg,1);result=func_80090DC0(0,p);osRecvMesg(arg0,&msg,1);func_8008A9AC(arg1,arg2);D_800C3520=0;func_8008D860();osCreateMesgQueue(D_800C02AE+0x7F32,&D_800C3528,1);return result;
}
