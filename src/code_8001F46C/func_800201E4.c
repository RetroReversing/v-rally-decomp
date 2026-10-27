#include "common.h"

extern u8 D_800C02AE[];
 extern u8 D_800AE850[];
 extern u16 D_8009BBB6;

s32 func_80022668(s32,s32);
 s32 func_8007EAA0(s32,s32);
 s32 func_80097E30(s32,s32,s32);

void func_800201E4(s32 *arg0,s32 *arg1){
 s32 root,src,dst,record,half,off,v,w;
 s32 a,b;

 root=*(s32*)(D_800C02AE+0x5dce);

 *(u16*)(root+0x24)+=0x46;
*(u16*)(root+0x26)+=0x46;
*(u16*)(root+0x2a)+=0x46;

 *(u16*)(root+0x24)+=0x46;
*(u16*)(root+0x26)+=0x46;
*(u16*)(root+0x2a)+=0x46;

 dst=*(s32*)(arg1+0x22);
*(s32*)dst=root;

 *(s32*)(*(s32*)(arg1+0x22)+4)=*(s32*)(*(s32*)(root+0x10));

 *(s32*)(*(s32*)(arg1+0x22)+8)=*(s32*)(*(s32*)(root+0x10)+4);

 *(s32*)(*(s32*)(arg1+0x22)+0xc)=*(s32*)(*(s32*)(root+0x10)+8);

 *(s32*)(*(s32*)(arg1+0x22)+0x10)=*(s32*)(*(s32*)(root+0x10)+0xc);

 *(s32*)(*(s32*)(arg1+0x22)+0x14)=*(s32*)(*(s32*)(root+0x10)+0x10);

 *(s32*)(*(s32*)(arg1+0x22)+0x68)=func_80022668(*(s32*)((u32)D_800AE850+0x87f4),0);

 record=func_8007EAA0(1,0x20);
func_80097E30(record,0,0x20);

 if(*(s32*)((u8*)arg0+0x44)==1){
  a=0x4b;
b=10;

  *(s16*)record=a;
*(s16*)(record+2)=b;
  *(s16*)(record+4)=0xfa;
*(s16*)(record+0xc)=-0xfa;

  *(s16*)(record+0x10)=0x50;
*(s16*)(record+0x16)=0x50;
*(s16*)(record+0x12)=0x50;
*(s16*)(record+0x18)=0x50;

  *(s16*)(record+8)=a;
*(s16*)(record+0xa)=b;

  *(s16*)(record+0x14)=0x28;
*(s16*)(record+0x1a)=0x28;

 }else{
  w=*(s32*)((u8*)arg0+0x90);
half=*(s32*)((u32)D_800AE850+0x82ac);
*(s16*)record=w;
v=*(s32*)((u8*)arg0+0xdc);
half=half/2;
off=D_8009BBB6-10;

  v+=half;
v+=off;
*(s16*)(record+2)=v;
*(s16*)(record+4)=*(s32*)((u8*)arg0+0x128);
*(s16*)(record+8)=*(s32*)((u8*)arg0+0x174);

  *(s16*)(record+0xa)=*(s32*)((u8*)arg0+0x1c0)+half+off;
*(s16*)(record+0xc)=*(s32*)((u8*)arg0+0x20c);

  *(s16*)(record+0x10)=*(s32*)((u8*)arg0+0x258);
*(s16*)(record+0x16)=*(s32*)((u8*)arg0+0x258);

  *(s16*)(record+0x12)=*(s32*)((u8*)arg0+0x2a4);
*(s16*)(record+0x18)=*(s32*)((u8*)arg0+0x2a4);

  *(s16*)(record+0x14)=*(s32*)((u8*)arg0+0x2f0);
*(s16*)(record+0x1a)=*(s32*)((u8*)arg0+0x2f0);

  if(*(s32*)((u8*)arg0+0x44)==11){*(s16*)(record+0x1c)=*(s32*)((u8*)arg0+0x33c);
*(s16*)(record+0x1e)=*(s32*)((u8*)arg0+0x388)+half+off;
}
  else{*(s16*)(record+0x1c)=*(u16*)(record+8)-10;
*(s16*)(record+0x1e)=*(u16*)(record+0xa);
}
 }
 *(s32*)(*(s32*)(arg1+0x22)+0x7c)=record;

}
