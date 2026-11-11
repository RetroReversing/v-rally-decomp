extern s32 D_800C3528; extern s32 D_800A1C90; extern u8 D_800B60E0,D_800C3520; extern char gOrderState[],gStreamState[];
u64 osGetTime(void); s32 osCreateMesgQueue(void*,void*,s32); s32 osSetTimer(void*,u64,u64,void*,void*); s32 osRecvMesg(void*,void*,s32); s32 __osPackRequestData(s32); s32 __osSiRawStartDma(s32,void*); void __osContGetInitData(s32,s32); void func_8008D860(void);
/* Controller manager init: runs once. Waits about 1.5s after boot (0x165A0BC ticks)
   for the controllers to settle, then probes the pads and sets up the reply queue. */
s32 osContInit(s32 *mq, s32 arg1, s32 arg2){
 u8 timer[32]; u8 queue[24]; s32 msg; s32 result; u64 now; void *p;
 if(D_800A1C90)return 0;
 D_800A1C90=1; now=osGetTime();
 if(now<0x165A0BCULL){osCreateMesgQueue(queue,&msg,1);osSetTimer(timer,0x165A0BCULL-now,0,queue,&msg);osRecvMesg(queue,&msg,1);}
 D_800B60E0=4;__osPackRequestData(0);p=gOrderState+0x1250;__osSiRawStartDma(1,p);osRecvMesg(mq,&msg,1);result=__osSiRawStartDma(0,p);osRecvMesg(mq,&msg,1);__osContGetInitData(arg1,arg2);D_800C3520=0;func_8008D860();osCreateMesgQueue(gStreamState+0x7F32,&D_800C3528,1);return result;
}
