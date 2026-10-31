#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern s32 func_80057918(s32,u16);extern s32 func_8000C9B0(void *,s32,u8,s32,s32);
extern void func_8004C100(s32,s32,s32,s32,s32);extern void func_8004C1B4(s32,s32,s32,s32,s32,s32,s32,s32,s32);
extern u8 D_800A73E0[],D_800C02AE[]; extern s32 D_800ADF80; extern u8 D_80000002[],D_80000004[];extern u8 *D_800A1468,*D_800A14D0;
extern f64 D_800A55E8,D_800A55F0,D_800A55F8,D_800A5600,D_800A5608,D_800A5610,D_800A5618,D_800A5620,D_800A5628,D_800A5630,D_800A5638;
#define CV(out,val,threshold) {f64 d=(val);if(!((threshold)<=d))out=(s32)d;else out=(s32)(d-(threshold))|0x80000000;}
void func_8006185C(u8 *arg0,s32 arg1){
u32 scratch[2];s32 result,font;u32 boxheight;u8 *table; s32 x,xend,top,extent,gap,height,y,center; s16 anchor; s32 offset;s32 width=0;u32 h,c,w;u8 i,count;u8 *node;
font=func_80057918(*(s32*)(D_800C02AE+0x807A),F(arg0,u16,8));
table=D_800A1468+F(arg0,s8,14)*2;
result=func_8000C9B0(D_800A1468+(F(table,u8,0xd0)*4+0xe4),font,F(table,u8,0xd1),F(arg0,s32,20),0);
extent=(unsigned short)(result+24);anchor=F(arg0,s16,10);offset=anchor;if(anchor<0)offset=-offset-result;x=offset-12;
xend=x+extent;top=F(arg0,u16,12)-8;boxheight=32;
func_8004C1B4(D_800ADF80,(u16)x,(u16)top,(u16)x,(u16)(top+boxheight),(u16)xend,(u16)(top+boxheight),(u16)xend,(u16)top);
if(!(arg1&255)){
gap=F(D_800A14D0,u16,0)-xend;
CV(w,((f64)F(D_800A14D0,f32,4)-D_800A55E8)*D_800A55F0,D_800A55F8);
width=w;
CV(h,(f64)F(D_800A14D0,f32,4)*D_800A5600,D_800A5608);height=h;
y=F(D_800A14D0,u16,2)+F(D_800A14D0,u8,8)*F(F(D_800C02AE,u8 *,0x32F2),u16,34);
CV(c,(f64)(u16)y+(f64)(u16)height*D_800A5610,D_800A5618);
func_8004C100(D_800ADF80,(u16)(x+extent),(u16)(top+(boxheight>>1)),(u16)(gap+(x+extent)-4),(u16)c);
func_8004C1B4(D_800ADF80,(u16)(F(D_800A14D0,u16,0)-3),(u16)(y-3),(u16)(F(D_800A14D0,u16,0)-3),(u16)(y+height+2),(u16)(F(D_800A14D0,u16,0)+width+2),(u16)(y+height+2),(u16)(F(D_800A14D0,u16,0)+width+2),(u16)(y-3));
}else{
gap=356-xend;i=0;count=F(arg0,u8,77);node=F(arg0,u8 *,40);
if(count){do{if(i==F(D_800A1468,u8,0x239)){
font=func_80057918(*(s32*)(D_800C02AE+0x807A),F(node,u16,4));table=D_800A1468+F(node,s8,10)*2;
width=func_8000C9B0(D_800A1468+(F(table,u8,0xd0)*4+0xe4),font,F(table,u8,0xd1),F(node,s32,16),0);break;
}++i;node=F(node,u8 *,0);}while(i<count);}
CV(h,(f64)F(node,f32,20)*D_800A5620,D_800A5628);height=h;
if(F(D_800A1468,u8,0x238)==0)y=F(D_800A1468,u8,0x239)*20+280;
else if(F(D_800A1468,u8,0x238)==1)y=F(D_800A1468,u8,0x239)*20+260;
else y=F(D_800A1468,u8,0x239)*20+292;
CV(c,(f64)(u16)y+(f64)(u16)height*D_800A5630,D_800A5638);
func_8004C100(D_800ADF80,(u16)(x+extent),(u16)(top+(boxheight>>1)),(u16)(gap+(x+extent)-4),(u16)c);
func_8004C1B4(D_800ADF80,352,(u16)(y-4),352,(u16)(y+height+4),(u16)(width+360),(u16)(y+height+4),(u16)(width+360),(u16)(y-4));
}
}
