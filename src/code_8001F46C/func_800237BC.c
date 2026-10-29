#include "snapshot29_0433f7af8f6d.h"

extern f32 func_8001BE68(void *,f32,f32,f32,f32*,f32*,f32*);
extern void func_80014598(s32,s32,s32,s32,s32);
extern s32 D_800AE850;
void func_800237BC(s32 arg0,s32 *arg1,s32 *arg2) {
f32 a,b,c,d,e,f;
f32 x1,y1,z1,x2,y2,z2;
s32 sx1,sy1,sx2,sy2;
x1=(f32)arg1[0];
y1=(f32)arg1[1];
z1=(f32)arg1[2];
x2=(f32)arg2[0]+x1;
y2=(f32)arg2[1]+y1;
z2=(f32)arg2[2]+z1;
func_8001BE68((u8*)&D_800AE850+0x72B0,x1,y1,z1,&a,&b,&c);
func_8001BE68((u8*)&D_800AE850+0x72B0,x2,y2,z2,&d,&e,&f);
sx1=(s32)(a*160.0f+160.0f);
sy1=(s32)(-b*120.0f+120.0f);
sx2=(s32)(d*160.0f+160.0f);
sy2=(s32)(-e*120.0f+120.0f);
func_80014598(sx1,sy1,sx2,sy2,0xFFC1FFC1);
}
