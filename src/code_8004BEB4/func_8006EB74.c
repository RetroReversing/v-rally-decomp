#include "common.h"

extern f64 D_800A58C0;extern u8 D_800C02AE[];extern u8 *D_800C35A0;
#define F8(o,t) (*(t *)(D_800C02AE+(o)))
#define O8(o,t) (*(t *)(D_800C35A0+(o)))
static inline s16 *slot8(u8 *base, s32 idx) { return (s16 *)(base+idx*40+0x50); }
void func_8006EB74(void) {
s32 i,j;u16 *p=(u16 *)(D_800C02AE+0x6e5e);u8 *obj;
i=0;
F8(0x333a,f32)=(f32)((f64)((*p>>4)&15)*D_800A58C0);
F8(0x332e,f32)=(f32)((f64)(*p&15)*D_800A58C0);
F8(0x3332,f32)=(f32)((f64)(F8(0x6e76,u8)&15)*D_800A58C0);
obj=D_800C35A0;
do {
*slot8(obj,i&255)=(*p>>12)&1;
i++;
}while((u32)(i&255)<4);
O8(0x2a,u16)=p[1];
O8(0x38,s16)=*p>>15;
O8(0x2f,s8)=p[2];
F8(0x32a8,s16)=(*p>>14)&1;
O8(0x12,s16)=(*p>>13)&1;
O8(0x16,s16)=(*p>>10)&3;
F8(0x32aa,s32)=(*p>>8)&3;
}
