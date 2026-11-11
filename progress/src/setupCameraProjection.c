extern u16 D_800C3556;
s32 guFrustumF(void *,f32,f32,f32,f32,f32,f32,f32);
s32 guLookAtReflectF(void *,void *,s32,s32,f32,f32,f32,f32,f32,f32,f32);
extern s32 gSelectState;
extern f64 D_800A4000;
#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
/* Sets up a camera: the perspective frustum from the viewport size and the aspect/zoom
 * settings, then the reflection look-at matrix and the fixed-point fog/scale value. */
void setupCameraProjection(void *cam,void *viewport,f32 near,f32 far) {
f32 temp_ft0,temp_ft1,temp_ft1_2,temp_ft2,temp_ft3,temp_fv1;
s32 scale_bits;
u16 vp_height;
vp_height=F(viewport,u16,6);
scale_bits=(s16)F(viewport,u16,4)/2;
temp_ft2=scale_bits;
temp_ft3=(f32)((s16)vp_height/2);
if(gSelectState==0) {
if(D_800C3556==1) {
F(cam,f32,0xd4)=1.328f;
}else{
F(cam,f32,0xd4)=1.0f;
}
}else if(D_800C3556==1) {
F(cam,f32,0xd4)=0.6f;
}else{
F(cam,f32,0xd4)=0.4f;
}
temp_ft1=F(cam,f32,0xd4); temp_ft0=F(cam,f32,0xdc); temp_ft1_2=F(cam,f32,0xd8); guFrustumF(cam,temp_ft2*temp_ft1*temp_ft0*0.1f,-temp_ft2*temp_ft1*temp_ft0*0.1f,temp_ft3*temp_ft1_2*temp_ft0*0.1f,-temp_ft3*temp_ft1_2*temp_ft0*0.1f,near*0.1f,far,1.0f);
temp_fv1=(f32)(D_800A4000/(f64)(near+far));
temp_fv1*=65536.0f;
scale_bits=(u32)temp_fv1;
F(cam,s16,0xcc)=(s16)scale_bits;
guLookAtReflectF((u8 *)cam+0x40,(u8 *)cam+0x120,F(cam,s32,0xe0),F(cam,s32,0xe4),F(cam,f32,0xe8),F(cam,f32,0xec),F(cam,f32,0xf0),F(cam,f32,0xf4),F(cam,f32,0xf8),F(cam,f32,0xfc),F(cam,f32,0x100));
}
