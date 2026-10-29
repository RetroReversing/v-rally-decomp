#include "snapshot29_0433f7af8f6d.h"

extern s32 func_800056FC(s32);
extern u8 *func_80006008(s32);
extern void func_80006014(s32, u8 *);
extern u8 *func_80009E54(void);
static __inline__ void copyObj(u8*d,u8*s){u32 *a,*b;int n;if(d<s+96&&s<d){a=(u32*)(s+96);b=(u32*)(d+96);n=24;do{--a;--b;--n;*b=*a;}while(n);}else{a=(u32*)s;b=(u32*)d;n=24;do{u32 v=*a++;--n;*b++=v;}while(n);}}
extern u32 D_8009B5D0;
void func_8000BA38(s32 arg0,s32 x0,s32 y0,u8 *o0,s32 mode,u8 c0,u8 c1,u8 c2,u8 c3,u8 c4){
 u8 *o=o0; s32 x=x0,y=y0;
 s32 q=func_800056FC(arg0);u8 *a,*p=func_80006008(q);u16 v;
 {u32 *g=(u32*)p;p+=8;g[0]=0xDE000000;g[1]=(u32)&D_8009B5D0;}
 switch(c0){case 0xc8:v=0x200;goto scale;case 0x96:v=0x300;goto scale;case 0x4b:v=0x600;goto scale;case 0x19:v=0x1000;goto scale;case 0x32:v=0x800;goto scale;case 0x64:v=0x400;scale:*(u16*)(o+0x42)=v;*(u16*)(o+0x4a)=v;break;}
 *(u16*)(o+0x40)=x*4;*(u16*)(o+0x48)=y*4;
 {u32 *g=(u32*)p;p+=8;g[0]=0xE200001C;g[1]=0x5041C8;}
 {u32 *g=(u32*)p;p+=8;g[0]=0xFCFFFE61;g[1]=0xFF64F3FF;}
 {u32 *g=(u32*)p;p+=8;g[0]=0xFA000000;g[1]=((u32)c1<<24)|((u32)c2<<16)|((u32)c3<<8)|c4;}
 {u32 *g=(u32*)p;p+=8;g[0]=0xFB000000;g[1]=0;}
 {u32 *g=(u32*)p;p+=8;g[0]=0xE3000A01;g[1]=0;}
 {u32 *g=(u32*)p;p+=8;g[0]=0xE3001001;g[1]=0;}
 {u32 *g=(u32*)p;p+=8;g[0]=0xE7000000;g[1]=0;}
 {u32 *g=(u32*)p;p+=8;g[0]=0x05000017;g[1]=(u32)(o+0x28);}
 if(mode==0){{u32 *g=(u32*)p;p+=8;g[0]=0x0800002F;g[1]=(u32)(o+0x28);}}
 else if(mode==8){
o[0x57]=0x10;{u32 *g=(u32*)p;p+=8;g[0]=0x0800002f;g[1]=(u32)(o+0x28);}{u32 *g=(u32*)p;p+=8;g[0]=0xe7000000;g[1]=0;}
a=func_80009E54();copyObj(a,o);a[0x57]=0x11;
{s32 h=y*4; s32 w=(x+*(u16*)(*(u8**)(o+12)+6))*4; *(u16*)(a+0x48)=h;*(u16*)(a+0x40)=w;}
{u32 *g=(u32*)p;p+=8;g[0]=0x0800002f;g[1]=(u32)(a+0x28);}{u32 *g=(u32*)p;p+=8;g[0]=0xe7000000;g[1]=0;}
a=func_80009E54();copyObj(a,o);a[0x57]=0;*(u16*)(a+0x40)=x*4;*(u16*)(a+0x48)=(y+*(u16*)(*(u8**)(o+12)+8))*4;
{u32 *g=(u32*)p;p+=8;g[0]=0x0800002f;g[1]=(u32)(a+0x28);}{u32 *g=(u32*)p;p+=8;g[0]=0xe7000000;g[1]=0;}
a=func_80009E54();copyObj(a,o);a[0x57]=1;*(u16*)(a+0x40)=(x+*(u16*)(*(u8**)(o+12)+6))*4;*(u16*)(a+0x48)=(y+*(u16*)(*(u8**)(o+12)+8))*4;
{u32 *g=(u32*)p;p+=8;g[0]=0x0800002f;g[1]=(u32)(a+0x28);}{u32 *g=(u32*)p;p+=8;g[0]=0xe7000000;g[1]=0;}}
 func_80006014(q,p);
}
