#include "snapshot31_manual_verified.h"

typedef struct {u64 at,v0,v1,a0,a1,a2,a3,t0,t1,t2,t3,t4,t5,t6,t7,s0,s1,s2,s3,s4,s5,s6,s7,t8,t9,gp,sp,s8,ra,lo,hi;u32 sr,pc,cause,badvaddr,rcp,fpcsr;} CT;
typedef struct T {struct T *next;s32 priority;struct T **queue;struct T *tlnext;u16 state,flags;s32 id,fp;void *prof;CT context;} T;
extern char func_8008B634[];extern T *D_800A251C;u32 func_8008BD90(void);void func_8008BDB0(u32);
void func_8008ACD0(T*t,s32 id,void(*entry)(void*),void*arg,void*sp,s32 p){u32 mask;
t->id=id;t->priority=p;t->next=0;t->queue=0;t->context.pc=(u32)entry;t->context.a0=(s64)(s32)arg;t->context.sp=(s64)(s32)sp-16;t->context.ra=(u64)(func_8008B634+0x17c);t->context.sr=0xff03;t->context.rcp=0x3f;t->context.fpcsr=0x1000800;t->fp=0;t->state=1;t->flags=0;
mask=func_8008BD90();t->tlnext=D_800A251C;D_800A251C=t;func_8008BDB0(mask);}