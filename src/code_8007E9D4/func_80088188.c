#include "common.h"

typedef struct { u8 pad40[0x40]; s32 x40; s32 x44; u8 pad48[0x2c]; s32 x74; u8 pad78[0x3c]; u8 b4; u8 b5; } Obj;
extern s32 func_80086C00(s32,s32,s32,s32,s32);
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
void *func_80088188(Obj *a, u8 *m) {
 s32 r,i,count,limit,code,v,high,old,b4,b5; u8 *p; u8 pad[8];
 code=*m++;
 if (code >= 0x80) { v=*m++; high=(code&0x7f)<<8; code=high+v; }
 b4=a->b4; old=a->x44; b5=a->b5;
 a->x44=old+1;
 r=func_80086C00(code,b4,b5,0,old);
 a->x44--;
 if (r) {
  count=*(s32*)(D_800C02AE+0x757e);
  p=*(u8**)(D_800AE850+0x80a0);
  i=0;
  if(count>0) {
   limit=count;
   do {
    if(*(s32*)(p+0x40)==r){*(s32*)(p+0x40)=a->x40;*(s32*)(p+0x74)=a->x74;}
    i++;
    p+=0x134;
   }while(i<limit);
  }
 }
 return m;
}
