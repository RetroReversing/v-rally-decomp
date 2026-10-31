#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
extern u8 **D_800B55E4;
void *func_8004240C();
#define TEX(p,k) F(F(F(p,void*,0x24),void*,k),void**,4)[0]
void func_8005D4A4(s32 arg0){s16 rect[4];f32 scale=1.25f;u8 *base,*p;if(arg0&255)scale=0.625f;base=*D_800B55E4;p=base+12;
rect[0]=0;rect[1]=(arg0&255)?135:269;
rect[2]=(s32)((f32)F(TEX(p,0xC),u16,6)*scale);
rect[3]=(s32)((f32)F(TEX(p,0xC),u16,8)*scale);
func_8004CEB4(F(func_8004240C(1),s32,0x178),TEX(p,0xC),rect,F(p,u8,0x37),0,0,100,100,0);
p=base+68;
rect[0]=0;rect[1]=(arg0&255)?187:375;
rect[2]=(s32)((f32)F(TEX(p,0xC),u16,6)*scale);
rect[3]=(s32)((f32)F(TEX(p,0xC),u16,8)*scale);
func_8004CEB4(F(func_8004240C(1),s32,0x178),TEX(p,0xC),rect,F(p,u8,0x37),100,100,200,200,0);
p=base+12;
if(arg0&255){rect[1]=135;rect[0]=160;}else{rect[1]=269;rect[0]=320;}
rect[2]=(s32)((f32)F(TEX(p,0x5C),u16,6)*scale);
rect[3]=(s32)((f32)F(TEX(p,0x5C),u16,8)*scale);
func_8004CEB4(F(func_8004240C(1),s32,0x178),TEX(p,0x5C),rect,F(p,u8,0x37),0,0,100,100,0);
p=base+68;
if(arg0&255){rect[1]=187;rect[0]=160;}else{rect[1]=375;rect[0]=320;}
rect[2]=(s32)((f32)F(TEX(p,0x5C),u16,6)*scale);
rect[3]=(s32)((f32)F(TEX(p,0x5C),u16,8)*scale);
func_8004CEB4(F(func_8004240C(1),s32,0x178),TEX(p,0x5C),rect,F(p,u8,0x37),100,100,200,200);
}
