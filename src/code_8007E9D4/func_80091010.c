#include "snapshot29_0433f7af8f6d.h"

extern u16 D_800ACCB0; extern u32 D_800B0D78,D_800AE854; extern u64 D_800B6168;
void *func_80095C80(void); void func_800911B0(void); u32 func_800937B0(void); void __osTimerInterrupt(void); void osRecvMesg(s32,void*,s32);void osSendMesg(s32,s32,s32);
#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
void func_80091010(void *arg0){
 u16 *msg=NULL; s32 first=0; u32 count; void *ctx; void *q;
 ctx=arg0;
 D_800ACCB0=F(func_80095C80(),u16,2); if(!D_800ACCB0)D_800ACCB0=1;
 first=0;
 q=ctx;
 for(;;){osRecvMesg(F(q,s32,12),&msg,1);switch(*msg){case 13:
 func_800911B0(); if(--D_800ACCB0==0){ctx=func_80095C80();if(F(ctx,s32,16))osSendMesg(F(ctx,s32,16),F(ctx,s32,20),0);D_800ACCB0=F(ctx,u16,2);}
 D_800B0D78++;if(first){first=0;count=func_800937B0();D_800B6168=count;}
 count=D_800AE854;D_800AE854=func_800937B0();count=D_800AE854-count;D_800B6168+=count;break;
 case 14:__osTimerInterrupt();break;}}}
