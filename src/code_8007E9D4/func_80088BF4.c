#include "common.h"

extern f64 D_800A6D30;
typedef struct S88 {u8 p0[8];s32 end;u8 p0c[8];s32 cur;u8 p18[8];f32 value;u8 p24[0xc];u8 * volatile data;u8 p34[0x34];f32 scale;f32 result;u8 p70[0x2c];u16 count;} S88;
void func_80088BF4(S88 *p) {
 f32 x;
u16 n;
u8 *q;
u8 b;
u8 *r;
 do {
  p->cur+=0x100;
n=--p->count;
  if(n==0) {
   b=*p->data++;
   if(b>=0x80) {
    x=(f32)((f64)(f32)(b&0x7f)-D_800A6D30);
q=p->data;
p->data=q+1;
    p->result=x;
p->value=x*p->scale;
b=*q;
    if(b>=0x80) { s32 high=(b&0x7f)<<8;
p->count=high;
r=p->data;
p->data=r+1;
high+=2;
p->count=*r+high;
}
    else p->count=b+2;
   } else {
    x=(f32)((f64)(f32)b-D_800A6D30);
p->count=1;
p->result=x;
p->value=x*p->scale;
   }
  }
 } while((u32)p->cur<(u32)p->end);
}
