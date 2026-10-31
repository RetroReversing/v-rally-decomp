void *func_80006008(void); void func_80006014(s32,void *,u32);
extern u16 D_8009C02A,D_8009C02E; extern s32 D_8009FF30; extern u8 D_800A73E0[];
void func_80015F3C(s32 arg0){
 s32 *a3; s32 *a2; s32 *fog,*other,*last; s32 cmd; s32 v0,v1,a0,a1,den,rate; s16 sum,x,y; s32 packed; u32 color,cgreen,cblue;
 a3=func_80006008(); a2=a3; a3+=2;
 *a2=0xF8000000;
 a2[1]=(D_800A73E0[0x6bd9]<<24)|(D_800A73E0[0x6bdb]<<16)|(D_800A73E0[0x6bdd]<<8)|D_800A73E0[0x6bdf];
 if(D_8009FF30==5){
  sum=*(u16*)(D_800A73E0+0x6bd4)+*(u16*)(D_800A73E0+0x6be0);
  x=sum;if(x>=0x3e5)x=0x3e4;if(x<0x2bc)x=0x2bc;
  y=1000-((1000-x)/10);if(y>=0x3e5)y=0x3e4;
  a1=0x1f400; den=1000-y; a1/=den;
  v0=0x1f4-y;v0<<=8; v0/=den;
  fog=a3; a3+=2; fog[0]=0xdb080000;a1<<=16; a1|=v0&0xffff; fog[1]=a1;
 }else{
  other=a3;
  packed=((D_8009C02A<<16)|D_8009C02E);
  a3+=2;other[0]=0xdb080000;other[1]=packed;
 }
 last=a3; a3+=2; last[0]=0xfb000000;
 color=D_800A73E0[0x6be7]; cgreen=D_800A73E0[0x6be9]; cblue=D_800A73E0[0x6beb];
 color<<=24; cgreen<<=16; color|=cgreen; cgreen=D_800A73E0[0x6bed]; color|=cblue<<8; color|=cgreen; last[1]=color;
 func_80006014(arg0,a3,cgreen);
}
