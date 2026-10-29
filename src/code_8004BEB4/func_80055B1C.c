#include "snapshot29_0433f7af8f6d.h"

typedef struct {s32 a,b,c,d;} W55;
typedef struct {s32 a,b,c,d;} __attribute__((packed)) P55;
typedef struct {u8 *p;u16 n;} H55;
extern u8 D_800AE850[],D_800A1300[],D_800A1308[];
s32 func_80098180(void *,void *);
void func_80055B1C(u8 **arg0,H55 *arg1){
u8 *base;u8 *s;u8 *src,*dst,*end;u16 *tail;u16 n;s32 i;s32 pad[2];
n=arg1->n;src=arg1->p;i=0;
if(n){u8 fill=255;tail=(u16 *)(src+32);do {
dst=*arg0;
s=src;if(((u32)src|(u32)dst)&3){end=(u8 *)tail;do{*(P55 *)dst=*(P55 *)s;s+=16;dst+=16;}while(s!=end);}
else {end=(u8 *)tail;do{*(W55 *)dst=*(W55 *)s;s+=16;dst+=16;}while(s!=end);}
{ s32 half=*(s16 *)s; *(s16 *)dst=half; }
(*arg0)[3]=10;
base=*(u8 **)(D_800AE850+0x237c)+*tail*20;
if(func_80098180(base,D_800A1300)==0 || func_80098180(base,D_800A1308)==0){
(*arg0)[0]=fill;(*arg0)[1]=fill;(*arg0)[2]=fill;
(*arg0)[4]=fill;(*arg0)[5]=fill;(*arg0)[6]=fill;(*arg0)[7]=fill;
(*arg0)[8]=fill;(*arg0)[9]=fill;(*arg0)[10]=fill;(*arg0)[11]=fill;
(*arg0)[12]=fill;(*arg0)[13]=fill;(*arg0)[14]=fill;(*arg0)[15]=fill;}
tail+=17;i++;*arg0+=34;src+=34;
}while(i<n);}}
