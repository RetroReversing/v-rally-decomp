#include "snapshot29_0433f7af8f6d.h"

extern u8 *D_800A2560[]; extern s32 D_A4600000; extern s32 osVirtualToPhysical(void*);
s32 func_800932E0(u8 *s0,s32 s1,s32 s2,void *dram,s32 s3){
u32 domain;u8 *old;u32 value;volatile u32 *reg;
if(*(volatile u32*)0xa4600010&3)do{}while(*(volatile u32*)0xa4600010&3);
domain=s0[9];old=D_800A2560[domain];
if(old!=s0){
 if(domain==0){
 if(old[5]!=s0[5])*(volatile u32*)0xa4600014=s0[5];
 if(old[6]!=s0[6])*(volatile u32*)0xa460001c=s0[6];
 if(old[7]!=s0[7])*(volatile u32*)0xa4600020=s0[7]; value=old[8];old=(u8 *)(u32)s0[8];if(value!=(u32)old){reg=(volatile u32*)0xa4600018;goto writeTiming;}
 }else{
 if(old[5]!=s0[5])*(volatile u32*)0xa4600024=s0[5];
 if(old[6]!=s0[6])*(volatile u32*)0xa460002c=s0[6];
 if(old[7]!=s0[7])*(volatile u32*)0xa4600030=s0[7];
 value=old[8];old=(u8 *)(u32)s0[8];if(value!=(u32)old){reg=(volatile u32*)0xa4600028;goto writeTiming;}
 }
 goto done;
 writeTiming:*reg=(u32)old;
 done:D_800A2560[domain]=s0;
}
*(volatile u32*)0xa4600000=osVirtualToPhysical(dram);
*(volatile u32*)0xa4600004=(*(u32*)(s0+12)|s2)&0x1fffffff;
{ volatile u32 *tail;
switch(s1){case 0:tail=(volatile u32*)0xa460000c;break;case 1:tail=(volatile u32*)0xa4600008;break;default:return -1;}
*tail=s3-1;return 0; }
}
