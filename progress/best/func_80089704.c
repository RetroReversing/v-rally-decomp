/* Partial candidate from function #26061 in project #57; rechecked locally. */
extern f64 D_800A6DB8; extern s32 func_8008989C(void*,void*,s32); extern void osWritebackDCacheAll(void);
void func_80089704(void *arg0,s32 arg1){
 u8 scratch[16];
 s32 status=*(s32*)((u8*)arg0+0x10); s32 index, byteIndex, val, raw, old, mask=0xFF000000; u8 *p; u8 *digit; void **refs;
 if(status<0)return;
 *(s32*)((u8*)arg0+0x10)=status|0x80000000;
 func_8008989C((u8*)arg0+0x24,arg0,3);
 func_8008989C(*(void**)((u8*)arg0+0x2c),arg0,*(s32*)((u8*)arg0+0x20));
 if(*(s32*)((u8*)arg0+0x20)>0){
 f64 scale=D_800A6DB8;
 byteIndex=0; index=0;
 do {
 p=*(u8**)((u8*)arg0+0x28)+index;
 val=*p;
 if(val&0x80)raw=(val&0xff)-0x100;else raw=val&0xff;
 *(f32*)p=(f32)((f64)(f32)raw*scale);
 digit=*(u8**)((u8*)arg0+0x24)+byteIndex;
 val=*digit-0x30;
 if(val&0x80)raw=(val&0xff)-0x100;else raw=val&0xff;
 *(f32*)p=*(f32*)p+(f32)raw;
 refs=(void**)(*(u8**)((u8*)arg0+0x2c)+index);
 { void *q=*refs;
 if(!*((u8*)q+9)){
 old=*(s32*)q;
 if((old&mask)!=mask)*(s32*)q=old+arg1;
 q=*(void**)(*(u8**)((u8*)arg0+0x2c)+index); *((u8*)q+9)=1;
 q=*(void**)(*(u8**)((u8*)arg0+0x2c)+index);
 { void *r=*(void**)((u8*)q+0xc); if(r)*(void**)((u8*)q+0xc)=(u8*)r+(s32)arg0; }
 q=*(void**)(*(u8**)((u8*)arg0+0x2c)+index);
 if(!*((u8*)q+8))*(void**)((u8*)q+0x10)=(u8*)*(void**)((u8*)q+0x10)+(s32)arg0;
 }}
 byteIndex++; index+=4;
 }while(byteIndex<*(s32*)((u8*)arg0+0x20));
 }
 osWritebackDCacheAll();
}
