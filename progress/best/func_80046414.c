void func_8003F2CC(u8 *arg0) {
 u8 *a,*v,*tbl; s32 n,mask;
 mask=0x180; a=*(u8 **)(*(u8 **)(arg0+0xA8)+0x24);
 if(a) {
 *(vs32 *)(arg0+0x80)|=4;
 if ((*(s32 *)(a+0x14)&0x180)==mask) {
 v=*(u8 **)(a+0x6C); n=*(s32 *)(v+8);
 *(vs32 *)(arg0+0x80)&=~4; *(s16 *)(arg0+0x7A)=n+1;
 }
 tbl=*(u8 **)(*(u8 **)(arg0+0xA4)+4);
 mask=*(s16 *)(arg0+0x7A)*4;
 *(s16 *)(arg0+0x70)=-(*(u16 *)(*(u8 **)(tbl+mask)+6)>>1);
 }
}
void func_80038AE4(s32);
void func_80046414(s32 a, s32 b) {
 s32 v;
 if(b==1) {
 if(a==b) v=6;
 else if(a==0) v=2;
 else if(a==2) v=4;
 else return;
 } else if(b==2) {
 if(a==1) v=5;
 else if(a==0) v=1;
 else if(a==b) v=3;
 else return;
 } else if(a==6) { if(b!=8) return; v=0x12; }
 else { if(a!=3) return; v=0; }
 func_80038AE4(v);
}
s32 func_800415A8(s32 arg0,s32 arg1) {
 s32 cur=arg0; u16 *p;
 if(arg1) {
 p=(u16 *)(arg0+0x10);
 do {
 if (!(*p & 1)) { *p |= 1; return cur; }
 p=(u16 *)((u8 *)p+0x2C4); cur+=0x2C4;
 } while(--arg1);
 }
 return 0;
}
