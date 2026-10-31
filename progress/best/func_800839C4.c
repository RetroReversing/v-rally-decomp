extern s32 D_800C33C0; extern u8 D_800C02AE[]; extern s32 func_80082094(void); extern s32 func_80082EB8(void); extern s32 func_800830C8(void); extern s32 func_8008328C(void);
s32 func_800839C4(s32 *arg0) {
s32 bitcount,n,kind,b; u32 bits; s32 *p; u8 *q;
bitcount=D_800C33C0; bits=*(u32 *)(D_800C02AE+0x310E);
if(bitcount==0){p=(s32 *)(D_800C02AE+0x3092);do{n=*p-1;*p=n;if(n>=0){q=(u8*)p[-1];p[-1]=(s32)(q+1);b=*q;}else b=func_80082094();if(b==-1)return 1;bits|=(u32)b<<bitcount;bitcount+=8;}while(bitcount==0);}
*arg0=bits&1;bitcount--;bits>>=1;
if((u32)bitcount<2){p=(s32 *)(D_800C02AE+0x3092);do{n=*p-1;*p=n;if(n>=0){q=(u8*)p[-1];p[-1]=(s32)(q+1);b=*q;}else b=func_80082094();if(b==-1)return 1;bits|=(u32)b<<bitcount;bitcount+=8;}while((u32)bitcount<2);}
kind=bits&3;bits>>=2;bitcount-=2;
*(u32 *)(D_800C02AE+0x310E)=bits;*(s32 *)(D_800C02AE+0x3112)=bitcount;
if(kind==2)return func_8008328C();if(kind==0)return func_80082EB8();if(kind==1)return func_800830C8();return 2;}
