#include "common.h"

s32 func_80086B34(); s32 func_80086D34(); s32 func_80086D90(); s64 osGetTime(void); s32 func_80098090(); s32 func_800980C4(u32); extern char D_800C02AE[];
void func_80038B3C(void){
u32 r; s32 i; s32 idx; u8 *p; u16 *q; char *base; u16 t; u8 a,b,c,d; s32 obj;
func_800980C4((u32)osGetTime()); r=func_80098090()%100; base=D_800C02AE+0x331b; i=0; if(*(u8*)base){p=(u8*)(base+7); do{
do{idx=i&255;q=(u16*)(idx*2+(u32)p);t=*q;if(t)*q=t-1;if(r<*(u8*)(D_800C02AE+0x331f+idx))goto next;
a=p[-3]-1;p[-3]=a;r=0;if(a<90)p[-3]=90;b=p[-2]-1;p[-2]=b;if(b<90)p[-2]=90;c=p[-1]-1;p[-1]=c;if(c<90)p[-1]=90;
d=*(u8*)(D_800C02AE+0x331f+idx)+4;*(u8*)(D_800C02AE+0x331f+idx)=d;if(d>=99)*(u8*)(D_800C02AE+0x331f+idx)=92;
}while(0);
if(*q==0){*q=0x113;b=*(u8*)(D_800C02AE+0x331c+idx);obj=*(s32*)(D_800C02AE+0x7f26)+b*12;if(func_80086D34(obj)){func_80086B34(obj);func_80086D90(obj,(s32)*(f32*)(p+0x14));}}next:;i++;}while((u8)i<*(u8*)(D_800C02AE+0x331b));}}
