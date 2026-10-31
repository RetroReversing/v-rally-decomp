extern void *D_800C35A0; extern void *D_800C7F84;
extern void *func_8004240C(s32);
extern void *func_80040260(s32,s16,s16,s32,void *,s32);
extern void *func_80034FF0(s32,s32);
extern void func_8003F11C(void),func_8003F34C(void),func_8003F2CC(void);
#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
void func_8003F834(s32 arg0,s32 arg1) {
u32 i,j,n; u32 mode,w; u16 x; s16 y; void *obj,*rec,*p,*screen; u16 *q;
screen=D_800C35A0;
mode=F(screen,u16,0x1E);
if((mode!=0)&(mode!=7)) {
n=F(screen,u16,0xE);
if(n) {
i=1; j=(i << 1)-1;
do {
obj=func_8004240C(j);
rec=F(obj,void *,0x178); q=(u16 *)((u8 *)rec+8);
w=F(rec,u16,0xC); x=(s16)w/2;
y=F(rec,s16,0xE)/4;
screen=D_800C35A0;
if(F(screen,u16,0xE)==2 && (F(screen,u16,0x12)&1)) y+=8;
p=func_80040260(arg0,(s16)(q[0]+x),(s16)(q[1]+y),15,func_8003F11C,1);
F(p,void *,0xA4)=func_80034FF0(arg1+0x4C,0); F(p,void *,0xA8)=obj;
screen=D_800C7F84; rec=F(screen,void *,0x178);
y=F(rec,s16,0xE)/3; w=F(rec,u16,0xC); x=(u32)((s16)w+(w>>15))>>1;
screen=D_800C35A0;
if(F(screen,u16,0xE)==2 && (F(screen,u16,0x12)&1)) y+=12;
p=func_80040260(arg0,(s16)(q[0]+x),(s16)(q[1]+y),15,func_8003F34C,1);
screen=func_80034FF0(arg1+0x4C,0); F(p,void *,0xA4)=screen; F(p,void *,0xA8)=obj;
F(p,s16,0x70)=-(F(F(F(screen,void *,4),void *,0),u16,8)>>1);
screen=D_800C7F84; rec=F((short)screen,void *,0x178);
w=F(rec,u16,0xC); x=(s16)w/2; y=F(rec,s16,0xE)/2;
screen=D_800C35A0;
if(F(screen,u16,0xE)==2 && (F(screen,u16,0x12)&1)) y+=8;
p=func_80040260(arg0,(s16)(q[0]+x),(s16)(q[1]+y),15,func_8003F2CC,1);
F(p,void *,0xA4)=func_80034FF0(arg1+0x4C,0); F(p,void *,0xA8)=obj;
F(p,s16,0x70)=-(F(F(F(F(p,void *,0xA4),void *,4),void *,0),u16,8)>>1);
i++; j=(i << 1)-1;
} while(i<=n);
}
}
}
