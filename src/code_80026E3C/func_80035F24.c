#include "snapshot29_0433f7af8f6d.h"

typedef struct {u8 pad[0x118];f32 a,b,c;} Ctx;
typedef struct {void *p;u8 pad[2];u8 r,g;u32 n; s32 d;} Obj;
typedef struct {u8 b[2];s16 ss[2];u16 u[3];} Packet;
extern u8 D_800C02AE[],D_8009F5A0;
extern Ctx *D_800C7F84; extern Obj *D_800C811C;
extern s32 func_8001BD1C();
extern void guMtxIdentF(void*);
extern void func_80010BFC(void*,void*,void*),func_80035C4C(s16*,s32),func_800061FC(void*,void*);
extern void*func_80006008(void*);
extern void func_80006014(void*,void*),func_800075BC(void*,s32,u8),func_80019C90(void*,void*,void*,u16,u16),func_8001BE68(void*,f32,f32,f32,f32*,f32*,f32*);
void func_80035F24(s16*p,void*a,s32 k){
 s16*q; u32 *m; void*v; f32 M[16]; Packet pkt; f32 x,y,z; u32 i,n,old; s32 one,two,t,A; u8 r,g;
 t=func_8001BD1C(); guMtxIdentF(M); M[12]=D_800C7F84->a;M[13]=D_800C7F84->b;M[14]=D_800C7F84->c;
 func_80010BFC((void*)t,(u8*)D_800C7F84+0x38,M); func_80035C4C(p,k&255); func_800061FC(a,(void*)t); m=func_80006008(a);
 {u32 *g=m; Obj *o=D_800C811C;m+=2;g[0]=0xDE000000;g[1]=(u32)&D_8009F5A0;
 {u32 *g=m;m+=2;g[0]=0xFB000000;r=o->r;g[1]=(r<<24)|(r<<16)|(r<<8)|o->g;}}
 func_80006014(a,m); i=D_800C811C->n; one=1;two=0; n=(i>>1)-1;
 while((old=i,i--,old!=0)){q=p+1; if(i==n)two=1;
  func_8001BE68((u8*)D_800C7F84+0xB8,(f32)*p,(f32)q[0],(f32)q[1],&x,&y,&z);
  if(x<1.0f&&x>-1.0f&&y<1.0f&&y>-1.0f&&z<1.0f&&z>-1.0f){
   if(one){v=*(void**)((u8*)D_800C811C->p+4);A=*(s32*)v;func_800075BC(a,A,*((u8*)q+4));one=0;}
   else if(two){v=*(void**)((u8*)D_800C811C->p+4);A=*(s32*)v;two=0;func_800075BC(a,A,*((u8*)q+4));}
   pkt.b[0]=3;pkt.b[1]=0;pkt.ss[0]=D_800C811C->d*2;pkt.ss[1]=D_800C811C->d*2;pkt.u[0]=*p;pkt.u[1]=q[0];pkt.u[2]=q[1];
   v=*(void**)*(void**)((u8*)D_800C811C->p+4); func_80019C90(a,(u8*)D_800C7F84+0x38,&pkt,*(u16*)((u8*)v+6),*(u16*)((u8*)v+8));
  } else q[0]=1001; p+=4;
 }
}
