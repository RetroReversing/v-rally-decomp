s32 func_8002E688(s32 *arg0, s32 *arg1)
{
 f32 v[3]; f32 len; s32 n;
 v[0]=(f32)arg0[0]; v[1]=(f32)arg0[1]; v[2]=(f32)arg0[2];
 len=v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
 if(len!=0.0f) n=(s32)__builtin_sqrtf(len); else n=0;
 if(n==0)n=1;
 arg1[0]=(s32)(((f32)arg0[0]/(f32)n)*4096.0f);
 arg1[1]=(s32)(((f32)arg0[1]/(f32)n)*4096.0f);
 arg1[2]=(s32)(((f32)arg0[2]/(f32)n)*4096.0f);
 return n;
}
