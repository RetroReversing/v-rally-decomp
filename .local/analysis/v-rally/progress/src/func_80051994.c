#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
s32 func_8000665C(void*,s32);
s32 func_800068C0(void*,s32,s16,s16,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
s32 func_80008B28(void*,s32,u16,u16,s32,s32,s32,s32,s32,s32);
s32 func_80051994(void* arg0,void*arg1,void*arg2,void*arg3){
 struct { f32 x,y,z; } dims;
#define sp38 dims.x
#define sp3c dims.y
#define sp40 dims.z
 u32 id;
 sp38=F(arg1,f32,0x110)*(f32)F(arg2,u16,2)*0.5f;
 sp3c=(f32)(F(arg2,u16,4)>>1);
 sp40=F(arg1,f32,0x118)*(f32)F(arg2,u16,2)*0.5f;
 id=(u16)func_8000665C(arg0,4);
 func_800068C0(arg0,id,(s16)(s32)((f32)F(arg2,s16,6)-sp38),(s16)(s32)((f32)F(arg2,s16,8)+sp3c),(s32)(s16)(s32)((f32)F(arg2,s16,10)-sp40),(s32)(s16)(s32)((f32)F(arg2,s16,6)-sp38),(s32)(s16)(s32)((f32)F(arg2,s16,8)-sp3c),(s32)(s16)(s32)((f32)F(arg2,s16,10)-sp40),(s32)(s16)(s32)((f32)F(arg2,s16,6)+sp38),(s32)(s16)(s32)((f32)F(arg2,s16,8)-sp3c),(s32)(s16)(s32)((f32)F(arg2,s16,10)+sp40),(s32)(s16)(s32)((f32)F(arg2,s16,6)+sp38),(s32)(s16)(s32)((f32)F(arg2,s16,8)+sp3c),(s32)(s16)(s32)((f32)F(arg2,s16,10)+sp40));
 func_80008B28(arg0,(u16)id,F(arg3,u16,6),F(arg3,u16,8),F(arg3,u16,6),0,0,0,0,F(arg3,u16,8));
 { u32 *_g = (u32 *)(F(arg0,u8*,0x14)); F(arg0,u8*,0x14) += 8;
   _g[0] = ((((u32)((id & 31) * 2) & 0xFF) << 16) | (((u32)(((id & 31) + 1) * 2) & 0xFF) << 8) | ((u32)(((id & 31) + 2) * 2) & 0xFF)) | ((u32)(0x07 & 0xFF) << 24);
   _g[1] = (((u32)((id & 31) * 2) & 0xFF) << 16) | (((u32)(((id & 31) + 2) * 2) & 0xFF) << 8) | ((u32)(((id & 31) + 3) * 2) & 0xFF); }
 return id;
}
