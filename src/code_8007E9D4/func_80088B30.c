#include "common.h"

typedef struct {u8 p0[8];u32 limit;u8 p1[4];u32 count;u8 p2[0x20];u8 * volatile ptr;u8 p3[0x62];u16 timer;u8 p4[0x18];s8 b4;} S88B30;
void func_80088B30(S88B30 *arg0){
 S88B30 *base=arg0; u16 one=1,t; u8 *p;u8 *last;u8 *p2; u8 c; s32 x;
 do { base->count+=0x100; t=base->timer-1; base->timer=t;
  if(t==0){ p=base->ptr; base->ptr=p+1; c=*p;
   if(c>=0x80){ p2=base->ptr; base->b4=c&0x7f; base->ptr=p2+1; c=*p2;
    if(c>=0x80){last=base->ptr;x=(c&0x7f)<<8;base->timer=x;base->ptr=last+1;base->timer=*last+(x+2);}
    else base->timer=c+2;
   } else {base->b4=c;base->timer=one;}
  }
 } while(base->count<base->limit);
}
