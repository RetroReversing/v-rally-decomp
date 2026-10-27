#include "common.h"

typedef struct T {struct T *next,*prev; u64 interval,value; void *mq; s32 msg;} T;
extern T *__osTimerList;
extern u8 D_800AE850;
void __osTimerServicesInit(void){
T *p=__osTimerList;
*(u64*)((u8*)&D_800AE850+0x7918)=0;
*(s32*)((u8*)&D_800AE850+4)=0;
*(s32*)((u8*)&D_800AE850+0x2528)=0;
p->value=0; p->interval=0;
p->prev=p;p->next=p;p->mq=0;p->msg=0;
}
