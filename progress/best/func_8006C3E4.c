extern u8 D_800C02AE[],D_800A73E0[];
extern u8 *D_800D0648;
extern s32 D_8009D540;
void func_8006BF30(s32,s32,s32,s32);
extern u8 D_800C7124[];
static inline u16 *entry(s32 idx){u8 *base=D_800C7124; return (u16*)(base+idx*2+0x15A);}
void func_8006C3E4(s32 arg0){
s32 scratch[2];
u8 i=0;
s32 j,k=arg0&255,off,group=k*64,stride,x,total,n,trip;
u8 *p,*q;
u8 *timerbase=D_800A73E0+0x6B60;
s32 *timer=(s32*)(k*4+timerbase);
trip=k*3;
stride=k*708;
do{
j=i&255;
x=*entry(trip+j);
if(x!=65535){
p=D_800C02AE+0x6E26+((u32)x>>14)*14;
func_8006BF30(j,22,k,k);
off=j*16+group;
D_800C02AE[0x34A8+off]=((*(u16*)p>>10)&31)+65;
D_800C02AE[0x34A9+off]=((*(u16*)p>>5)&31)+65;
{s32 blue=p[1];
x&=0x3FFF;
D_800C02AE[0x34AE +off]=1;
D_800C02AE[0x34AA+off]=(blue&31)+65;
}
if(x&1)x=-x;
x=*timer-x;
*(s32*)(D_800C02AE+0x34A2+off)=x;
D_800C02AE[0x34A6+off]=(*(u16*)(p+2)>>12)+((*(u16*)p>>15)*16);
{u8 *base=D_800D0648;
total=0;
n=0;
if(*(u16*)((u32)base+stride+20)){
q=stride+base;
do{
s32 value;
u32 bound;
value=*(s32*)(q+(n&255)*4+0x22C);
bound=*(u16*)(q+20);
n++;
total+=value;
if((u32)(n&255)>=bound) break;
q=stride+base;
}while(1);
}
}
off=(i&255)*16+group; D_800C02AE[0x34AC+off]=(u32)(total*D_8009D540*3600)/(u32)(x*1000);
}
i++;
}while((u32)(i&255)<3);
}
