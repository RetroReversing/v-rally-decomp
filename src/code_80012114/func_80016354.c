#include "common.h"

extern s16 D_8009BBB6;extern f64 D_800A4180;
void func_80016354(f32 *a,f32 *b){
f32 x=a[14],y=b[14]; f64 p=(f64)a[2]*D_800A4180; f32 h=D_8009BBB6; f64 q=(f64)a[7]*D_800A4180;
a[14]=x-y;a[15]-=b[15]-h;
{f64 r=(f64)a[12]*D_800A4180;
a[16]-=b[16];a[2]=p;a[7]=q;a[12]=r;}
}
