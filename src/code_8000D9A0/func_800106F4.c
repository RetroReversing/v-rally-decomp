#include "common.h"

extern u16 D_800C3556;
s32 guFrustumF(void *,f32,f32,f32,f32,f32,f32,f32);
s32 guLookAtReflectF(void *,void *,s32,s32,f32,f32,f32,f32,f32,f32,f32);
extern s32 D_800A1468;
extern f64 D_800A4000;
#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
void func_800106F4(void *arg0,void *arg1,f32 arg2,f32 arg3) {
f32 temp_ft0,temp_ft1,temp_ft1_2,temp_ft2,temp_ft3,temp_fv1;
s32 var_v1;
u16 temp_a0;
temp_a0=F(arg1,u16,6);
var_v1=(s16)F(arg1,u16,4)/2;
temp_ft2=var_v1;
temp_ft3=(f32)((s16)temp_a0/2);
if(D_800A1468==0) {
if(D_800C3556==1) {
F(arg0,f32,0xd4)=1.328f;
}else{
F(arg0,f32,0xd4)=1.0f;
}
}else if(D_800C3556==1) {
F(arg0,f32,0xd4)=0.6f;
}else{
F(arg0,f32,0xd4)=0.4f;
}
temp_ft1=F(arg0,f32,0xd4); temp_ft0=F(arg0,f32,0xdc); temp_ft1_2=F(arg0,f32,0xd8); guFrustumF(arg0,temp_ft2*temp_ft1*temp_ft0*0.1f,-temp_ft2*temp_ft1*temp_ft0*0.1f,temp_ft3*temp_ft1_2*temp_ft0*0.1f,-temp_ft3*temp_ft1_2*temp_ft0*0.1f,arg2*0.1f,arg3,1.0f);
temp_fv1=(f32)(D_800A4000/(f64)(arg2+arg3));
temp_fv1*=65536.0f;
var_v1=(u32)temp_fv1;
F(arg0,s16,0xcc)=(s16)var_v1;
guLookAtReflectF((u8 *)arg0+0x40,(u8 *)arg0+0x120,F(arg0,s32,0xe0),F(arg0,s32,0xe4),F(arg0,f32,0xe8),F(arg0,f32,0xec),F(arg0,f32,0xf0),F(arg0,f32,0xf4),F(arg0,f32,0xf8),F(arg0,f32,0xfc),F(arg0,f32,0x100));
}
