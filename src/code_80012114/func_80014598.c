#include "common.h"

s32 func_80005C48(s32);void func_80014564(s32,s32,s32,s32);extern s32 D_8009B5A8;
void func_80014598(s32 x0,s32 y0,s32 x1,s32 y1){
s32 sp14=0xFFC1FFC1,color,dx,dy,err,s5,s6,s7,t,temp;
temp=func_80005C48(D_8009B5A8);
dx=x1-x0;dy=y1-y0;dx=__builtin_abs(dx);if(dy<0)dy=-dy;color=temp;
if(dx>=dy){
if(x1<x0){t=x1;x1=x0;x0=t;t=y1;y1=y0;y0=t;}
s7=y0>=y1?-1:1;err=dy*2-dx;s6=dy*2;s5=(dy-dx)*2;
func_80014564(x0,y0,0xFFC1FFC1,color);x0++;
while(x1>=x0){if(err<0)err+=s6;else{err+=s5;y0+=s7;}func_80014564(x0,y0,sp14,color);x0++;}
}else{
if(y1<y0){t=x1;x1=x0;x0=t;t=y1;y1=y0;y0=t;}
s7=x0>=x1?-1:1;err=dx*2-dy;s6=dx*2;s5=(dx-dy)*2;
func_80014564(x0,y0,0xFFC1FFC1,color);y0++;
while(y1>=y0){if(err<0)err+=s6;else{err+=s5;x0+=s7;}func_80014564(x0,y0,sp14,color);y0++;}
}}
