#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
void *func_8007EAA0(s32,s32);
void *func_800592D0(s8,void*,s32);
void *func_800592AC(u16);
s32 func_80057918(s32,u16);
s16 func_8000C9B0(void*,s32,u8,s32,s32);
extern u8 *D_800A1468;
extern u8 D_800C02AE[];
void func_80057D5C(s32 arg0,s32 arg1,u8 arg2,s8 arg3) {
u8 *node,*ctx,*item,*p,*tab,*tail;
s16 hi,lo,v,w;
s8 i;
s32 id;
node=func_8007EAA0(1,12);
ctx=F(D_800C02AE,u8*,0x325A);
lo=240;
F(node,u16,4)=arg0-F(F(ctx,u8*,16)+F(ctx,s16,2)*20,u8,13);
hi=0;
F(node,u8,8)=arg2; F(node,s8,9)=arg3;
F(node,u16,6)=arg1-F(F(ctx,u8*,16)+F(ctx,s16,2)*20,u8,13);
item=func_800592D0(arg3,ctx,(s32)F(ctx,u8*,16));
i=0;
if(F(node,u8,8)) do {
id=func_80057918(F(D_800C02AE,s32,0x807A),F(item,u16,4));
tab=D_800A1468; p=tab+F(item,s8,10)*2;
v=func_8000C9B0(tab+F(p,u8,0xD0)*4+0xE4,id,F(p,u8,0xD1),F(item,s32,16),0);
if(hi<v)hi=v;
w=F(item,s16,8); if(w<lo)lo=w;
i++;
}while(i<F(node,u8,8));
p=func_800592AC(F(node,u16,4));
id=func_80057918(F(D_800C02AE,s32,0x807A),F(p,u16,8));
tab=D_800A1468; ctx=tab+F(p,s8,14)*2;
v=func_8000C9B0(tab+F(ctx,u8,0xD0)*4+0xE4,id,F(ctx,u8,0xD1),F(p,s32,20),0);
if(hi<v)hi=v;
if(F(p,s16,12)<lo)lo=F(item,u16,8);
p=func_800592AC(F(node,u16,6));
id=func_80057918(F(D_800C02AE,s32,0x807A),F(p,u16,8));
tab=D_800A1468; ctx=tab+F(p,s8,14)*2;
v=func_8000C9B0(tab+F(ctx,u8,0xD0)*4+0xE4,id,F(ctx,u8,0xD1),F(p,s32,20),0);
if(hi<v)hi=v;
if(F(p,s16,12)<lo)lo=F(item,u16,8);
F(node,u8,10)=0;
tail=F(D_800A1468,u8*,28);
if(!tail)F(D_800A1468,u8*,24)=node;else F(tail,u8*,0)=node;
F(D_800A1468,u8*,28)=node;
F(D_800A1468,s32,32)++;
}
