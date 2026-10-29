#include "snapshot29_0433f7af8f6d.h"

extern s64 D_800A3B50[]; extern f64 D_800A7240; extern f64 func_8009A430(s64);
void func_80097770(const s64 xin,const s64 yin,f64 *out) {
s64 x=xin, y=yin; s64 z=0; s32 i=0; s64 *p=D_800A3B50; s64 next;
do {
if(y>=0) {next=x+(y>>i); y-=x>>i; z+=*p;}
else {next=x-(y>>i);y+=x>>i;z-=*p;}
x=next;i++;p++;
}while(i<52);
*out=func_8009A430(z)/D_800A7240;
}
