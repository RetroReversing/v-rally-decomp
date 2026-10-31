typedef struct {u8 unk[2];} BFArg;
extern s16 func_8000BF10(s16); extern void *func_8007EAA0(s32,s32); extern void func_8008E13C(void*,void*,s32);
#define DATA (*(u8**)(obj+0x18))
void *func_8000BF2C(BFArg *arg0){
u8 *obj,*item; u32 count,n,i,x; s32 a; u8 *q; u8 copy[24];
obj=func_8007EAA0(1,0x828); item=func_8007EAA0(1,0x1c); count=arg0->unk[1]; i=0;n=count&255;x=n<<4;
*(void**)(item+8)=(u8*)arg0+(x+8);*(void**)(obj+0x10)=item;
DATA=func_8007EAA0(1,x);func_8008E13C(DATA,(u8*)arg0+8,x);
if(n){u32 limit=n; do{x=(i&255)<<4;a=*(s16*)(DATA+x);i++;*(s16*)(DATA+x)=func_8000BF10(a);*(s16*)(DATA+x+2)=func_8000BF10(*(s16*)(DATA+x+2));}while((i&255)<limit);}
i=0;obj[8]=0;do{*(f32*)(obj+0x81c+((i&255)<<2))=1.0f;i++;}while((i&255)<3);
i=0;if(count&255){do{x=(i&255)<<4;a=*(s16*)(DATA+x);{u16 b=a; if(a!=-128){q=obj+x;*(s16*)(q+0x1c)=b;
*(s16*)(q+0x24)=*(u16*)(DATA+x+2)+DATA[x+5];
*(s16*)(q+0x1e)=*(u16*)(DATA+x)+DATA[x+4];
*(s16*)(q+0x26)=*(u16*)(DATA+x+2)+DATA[x+5];
*(s16*)(q+0x20)=*(u16*)(DATA+x)+DATA[x+4];
*(s16*)(q+0x28)=*(u16*)(DATA+x+2);*(s16*)(q+0x22)=*(u16*)(DATA+x);*(s16*)(q+0x2a)=*(u16*)(DATA+x+2);}
}__builtin_memcpy(copy,obj+x+0x1c,16);i++;}while((i&255)<(count&255));}return obj;}
