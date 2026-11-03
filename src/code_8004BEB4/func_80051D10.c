#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 pad[0x14]; void *p14; } A0;
typedef struct { u8 pad48[0x48]; struct { s32 x[5]; } *p48; s32 pad4c; s32 *p50; u8 pad88[0x34]; void *p88; } A1;
typedef struct { u8 pad110[0x110]; f32 x110; u8 pad114[4]; f32 x118; } A2;
extern s32 D_8009FF30; extern void *D_800A1240; extern u8 D_800A12C0;
extern void *func_80006008(s32); extern void func_80006014(s32,void*);
extern void func_800075BC(s32,s32,s32); extern void func_80051994(s32, A2*, u16*, s32);
typedef struct {u32 w0,w1;} G;
void func_80051D10(s32 a0,A1 *a1,A2 *a2,u32 a3){
 u16 sp[6]; u8 *s0; s32 s1;  s32 s7; G *v;
 a3 = a3 & 255;
 a3 &= 255;
 if(D_800A1240){
  s0=(u8*)*(void**)((u8*)a1->p88+0x7c); v=func_80006008(a0);
  { G *p=v++; p->w0=0xde000000; p->w1=(u32)&D_800A12C0;}
  { G *p=v++; s7=a3|~255; p->w0=0xfa000000; p->w1=s7;}
  func_80006014(a0,v);
  if(D_8009FF30==2){
   s1=*(s32*)((u8*)*(void**)((u8*)D_800A1240+4)+4); func_800075BC(a0,s1,0);
   sp[1]=*(u16*)(s0+0x10);sp[2]=*(u16*)(s0+0x16);sp[3]=*(u16*)s0;sp[4]=*(u16*)(s0+2);sp[5]=*(u16*)(s0+4);
   func_80051994(a0,a2,sp,s1);sp[3]=-(s16)*(u16*)s0;func_80051994(a0,a2,sp,s1);
   v=func_80006008(a0);
   if(a1->p48->x[4]<0x78 || *a1->p50==0){{ G *p=v++; p->w0=0xfa000000;p->w1=(a3>>1)|~255;}}else{{ G *p=v++;p->w0=0xfa000000;p->w1=s7;}}
   func_80006014(a0,v);
   if(D_8009FF30==2) goto L2;
  }
  if(a1->p48->x[4]>=0x79 && *a1->p50){
L2: s1=*(s32*)((u8*)*(void**)((u8*)D_800A1240+4)+8);func_800075BC(a0,s1,0);
   sp[1]=*(u16*)(s0+0x12);sp[2]=*(u16*)(s0+0x18);sp[3]=*(u16*)(s0+8);sp[4]=*(u16*)(s0+10);sp[5]=*(u16*)(s0+12);
   func_80051994(a0,a2,sp,s1);sp[3]=-(s16)*(u16*)(s0+8);func_80051994(a0,a2,sp,s1);
   v=func_80006008(a0);{ G *p=v++;p->w0=0xfa000000;p->w1=a3|~255;}func_80006014(a0,v);
  }
  if(*a1->p50==0){s1=*(s32*)((u8*)*(void**)((u8*)D_800A1240+4)+12);func_800075BC(a0,s1,0);
   sp[1]=*(u16*)(s0+0x14);sp[2]=*(u16*)(s0+0x1a);sp[3]=*(u16*)(s0+0x1c);sp[4]=*(u16*)(s0+0x1e);sp[5]=*(u16*)(s0+0xc);
   func_80051994(a0,a2,sp,s1);sp[3]=-(s16)*(u16*)(s0+0x1c);func_80051994(a0,a2,sp,s1);
  }
 }
}

