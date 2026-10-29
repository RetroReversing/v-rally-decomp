#include "snapshot29_0433f7af8f6d.h"

typedef struct Tex3 {u16 h0,h2,type,width,height;u8 a,b;u32 c;u8 **pal,**image;u32 x,y;} Tex3;
typedef struct {u8 count,pad[3];Tex3 **tex;} Pack3;
void func_80081B78(s32,s32*,s32*);
Pack3 *func_800555A0(s32,u16);
void func_800556C4(Pack3*);
Pack3 *func_80081664(s32,s32);
void func_80055424(s32,u16,Pack3*);
Pack3 *func_80034FF0(s32 id,s32 extra){
s32 size,other;
Pack3 *r;
u8 *p;
u8 i,j;
u8 n1,n2;
u32 bcount;
func_80081B78(id,&size,&other);
r=func_800555A0(id,(u16)(size+extra));
if(r){func_800556C4(r);return r;}
r=func_80081664(6,id);
r->count=*((u8*)r+size-1);
func_80055424(id,(u16)(size+extra),r);
r->tex=(Tex3**)((u8*)r+8);
p=(u8*)r+(r->count*4+8);
for(i=0;i<r->count;i++){
while((u32)p&7)p++;
r->tex[i]=(Tex3*)p;
p+=32;
r->tex[i]->pal=(u8**)p;
p+=r->tex[i]->a*4;
r->tex[i]->image=(u8**)p;
{Tex3 *t=r->tex[i]; t->x=0;
bcount=t->b;}
r->tex[i]->y=0;
p+=bcount*4;
if(*(u16*)&r->tex[i]->a==0x101) {
if(r->tex[i]->type==0xa0){
r->tex[i]->pal[0]=p;
r->tex[i]->image[0]=p;
}else{
r->tex[i]->pal[0]=p;
p+=r->tex[i]->type*2;
r->tex[i]->image[0]=p;
}
if(r->tex[i]->type==16)p+=(r->tex[i]->width*r->tex[i]->height)/2;
else if(r->tex[i]->type==256)p+=r->tex[i]->width*r->tex[i]->height;
else p+=(r->tex[i]->width*r->tex[i]->height)*4;
}else if(r->tex[i]->a==1 && (n1=r->tex[i]->b)>1){
r->tex[i]->pal[0]=p;
p+=r->tex[i]->type*2;
for(j=0;j<n1;j++){
while((u32)p&7)p++;
r->tex[i]->image[j]=p;
if(r->tex[i]->type==16)p+=(r->tex[i]->width*r->tex[i]->height)/2;
else if(r->tex[i]->type==0x109)p+=r->tex[i]->width*r->tex[i]->height;
}
}else if((n2=r->tex[i]->a)>1 && r->tex[i]->b==1){
u8 a1;
a1=n2;
for(j=0;j<a1;j++){
r->tex[i]->pal[j]=p;
p+=r->tex[i]->type*2;
}
while((u32)p&7)p++;
r->tex[i]->image[0]=p;
if(r->tex[i]->type==16)p+=(r->tex[i]->width*r->tex[i]->height)/2;
else if(r->tex[i]->type==256)p+=r->tex[i]->width*r->tex[i]->height;
}
}
return r;
}
