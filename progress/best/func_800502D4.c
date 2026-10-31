extern u8 D_800C02AE[],D_800AE850[],D_800C8214[],D_800C8120[],D_800C8324[];
extern u32 D_8009D538; extern u8 D_800A1234[]; extern void *func_80051404(void *); extern void func_8004F89C(void *);
typedef struct {u8 pad0[8];u16 flags,state,index,count;u8 rest[0x104];} EntryBase;
s32 func_800502D4(EntryBase *p) {
unsigned int __repair_literal;
 u8 i=((u8*)p)[0x114]; EntryBase *e=(EntryBase*)((u8*)p+i*68); s32 ret; u16 n,state;
 if(e->state!=4){u8*g=*(u8**)(D_800C02AE+0x32F2);if(!*(u16*)(g+0x1E)){if(*(u16*)(g+0x1A)){((u8*)p)[0x114]=i+1;if((u8)(i+1)==*(u16*)((u8*)p+0x110))((u8*)p)[0x114]=0;}}return 0;}
 if(e->flags&8){u8*g=*(u8**)(D_800C02AE+0x32F2);if(!*(u16*)(g+0x1E)&&!*(u16*)(g+0x1A)){for(i=0;i<*(u16*)((u8*)p+0x110);i++){EntryBase*x=(EntryBase*)((u8*)p+i*68);x->state=4;x->flags&=0xFFF7;}}else{for(i=0;i<4;i++){EntryBase*x=(EntryBase*)((u8*)p+i*68);x->state=4;x->flags&=0xFFF7;}}}
 n=e->index;if(n==0&&!(e->flags&0x400))func_8004F89C(p);
 { s32 *values=*(s32**)((u8*)e+4); unsigned int offset=e->index * 4; n=e->index; ret=*(s32*)((u8*)values+offset); e->index=n+1; }if(e->index<e->count)goto advance;
 if(e->flags&0x10){u8*q=func_80051404(p);*(u32*)(*(u32*)(q+0x5C)+0x6C)=0;*(u32*)(*(u32*)(q+0x30)+0x6C)=0;}
 e->state=5;{u8*g=*(u8**)(D_800C02AE+0x32F2);state=*(u16*)(g+0x1E);if(state==7){u32*s=(u32*)D_800C8214,*d=(u32*)g;u32*end=s+60;do{struct Copy4 {u32 a,b,c,d;}; *(struct Copy4 *)d=*(struct Copy4 *)s;s+=4;d+=4;}while(s!=end);d[0]=s[0];g=*(u8**)(D_800C02AE+0x32F2);{u32 f=D_8009D538;s32 players;*(u16*)(g+0x12)=*(u8*)(D_800C02AE+0x38F2);players=*(u8*)(D_800C02AE+0x38F0);*(u8*)D_800C8120=0;*(u32*)(D_800AE850+0x8030)=5;*(u16*)(g+0x1E)=0;D_8009D538=f&0xFFFFFFFE;*(u16*)(g+0xE)=players;}}else{
__repair_literal = 0;
e->index=0; if((u8*)p==*(u8**)D_800A1234){if(state!=0&&state<5&&*(u32*)(D_800AE850+0x8030)==2)D_8009D538&=0xFFFFFFFE;if(((u8*)p)[0x114]==0)*(u8*)D_800C8324=(u8)1;else if(((u8*)p)[0x114]==1 && *(u16*)(*(u8**)(D_800C02AE+0x32F2)+0xE)==2)*(u8*)(D_800C02AE+0x8076)|=2;}}}
 advance: ((u8*)p)[0x114]++; if(((u8*)p)[0x114]==*(u16*)((u8*)p+0x110))((u8*)p)[0x114]=0;done: return ret;}
