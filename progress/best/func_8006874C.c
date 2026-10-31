typedef struct {u32 words[9];} Style;
#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern Style *func_800592D0(s32);extern void func_80059618(Style *,u8,u8,u8,s32);extern void func_800596F4(Style *,s16,s16,void *);extern void func_80098290(void *,void *);extern s32 func_80099DF8(void *,void *,...);extern void *func_80057918(s32,s32);
extern u32 D_8009D540;extern u8 *D_800A1468,*D_800C3508,*D_800C35A0;extern s32 D_800C8328;
extern u8 D_800A5704[],D_800A5708[],D_800A570C[],D_800A5710[],D_800A5718[];extern f64 D_800A5720;
typedef struct {u8 a,b,c,d,e;} Rating;extern Rating D_800B0D80[];
void func_8006874C(s8 selected){
Style saved;char text[8];Style *style;u16 x;s16 y;u8 shown,i;u8 *p,*unit; s32 value;f32 average;u32 digit,whole;u16 fraction;u8 *list;
style=func_800592D0(0);saved=*style;x=F(style,u16,6);shown=0;i=0;y=F(style,u16,8)+14;list=D_800C35A0+68;
do{
if(list[i*40]!=91){
F(style,u8,11)=255;F(style,u8,12)=255;F(style,u8,13)=255;
if(F(D_800C3508,s16,2)!=3){
if((s8)selected==i){F(style,u8,11)=220;F(style,u8,12)=220;F(style,u8,13)=14;}
if(F(D_800C3508,s16,2)==3)goto blink;
}else{
blink:
if(F(D_800A1468,s8,0x229)==i&&(F(D_800C3508,u16,4)%(D_8009D540>>1))<(D_8009D540>>2)){F(style,u8,11)=220;F(style,u8,12)=220;F(style,u8,13)=14;}
}
func_80059618(style,F(style,u8,11),F(style,u8,12),F(style,u8,13),F(style,u8,14));
p=list+i*40;func_80098290(text,p);func_800596F4(style,(s16)x,(s16)y,text);
if(F(p,u16,12)==0){value=F(p,u16,14);
func_80099DF8(text,D_800A5704,value);unit=D_800A5708;}else{value=F(p,u16,14)*100/160;
func_80099DF8(text,D_800A5704,value);unit=D_800A570C;}
func_800596F4(style,(s16)-(x+88),(s16)y,text);func_800596F4(style,(s16)(x+104),(s16)y,unit);
average=(f64)(D_800B0D80[i].a+D_800B0D80[i].b+D_800B0D80[i].c+D_800B0D80[i].d+D_800B0D80[i].e)*D_800A5720;
digit=(u16)(u32)(average*10.0f);fraction=digit%10;whole=average;
if(fraction)func_80099DF8(text,D_800A5710,(u8)whole,fraction);
else func_80099DF8(text,D_800A5718,(u8)whole);
func_800596F4(style,(s16)-(x+194),(s16)y,text);y+=14;shown += 1;
}
++i;
}while(i<4);
func_80059618(style,255,255,255,255);
while(shown<4){void *str;str=func_80057918(D_800C8328,341);shown += 1;func_800596F4(style,(s16)x,(s16)y,str);y+=14;}
*style=saved;
}
