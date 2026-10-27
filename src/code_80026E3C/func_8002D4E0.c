#include "common.h"

static inline s32 roundadd(s32 a) { return a+0xFFF; }
void func_8002D4E0(s32 *arg0,s32 *arg1,s32 arg2,s32 arg3,s32 *arg4)
{
s32 v;
s32 x;
v = arg0[0] * arg2; v += arg1[0] * arg3;
if(v>=0) { x=v; } else { x=roundadd(v); }
v=x>>12;
arg4[0]=v;
v = arg0[1] * arg2; v += arg1[1] * arg3;
if(v>=0) { x=v; } else { x=roundadd(v); }
v=x>>12;
arg4[1]=v;
v = arg0[2] * arg2; arg2=v; arg2 += arg1[2] * arg3;
if(arg2>=0) { x=arg2; } else { x=roundadd(arg2); }
arg2=x>>12;
arg4[2]=arg2;
}
