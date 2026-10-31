extern u8 D_800AE850[], D_800C02AE[];
void func_80022BE8(void *, s32);
void func_800239CC(void *, void *);
void func_800234E0(void *);
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
#define W(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
void func_8004F89C(u8 *arg0) {
u8 *node = 0, *obj, *next;
u16 mode = H(P(D_800C02AE,0x32F2),0x1E);
u8 index = arg0[0x114];
u8 i;
u32 a = index & 255;
if (mode != 7) {
 if (mode == 0) {
  u16 type = H(P(D_800C02AE,0x32F2),0x1A);
  if (type == 1) {
   if (H(arg0+a*0x44,8)&0x800) {
    if(a==0) node=P(P(D_800AE850,0x73F0),0);
    else if(a==type) node=P(P(P(D_800AE850,0x73F0),4),0);
    obj=arg0+index*0x44;
    func_80022BE8(node,W(obj,0)); func_800239CC(node,obj+0x1C);
    W(P(node,0x88),0)=W(obj,0x18);
    if(W(P(node,0x48),0)!=7) W(D_800C02AE,0x80BE)=1;
    H(obj,8)=(H(obj,8)|0x400)&0xFDFF;
    next=P(node,4); W(P(next,0x5C),0x6C)=0; W(P(next,0x30),0x6C)=0;
    return;
   }
   if(a==0) node=P(P(P(D_800AE850,0x73F0),0),4);
   else if(a==type) node=P(P(D_800AE850,0x73F0),4);
   obj=arg0+index*0x44;
   func_80022BE8(node,W(obj,0)); func_800239CC(node,obj+0x1C);
   W(P(node,0x88),0)=W(obj,0x18);
   W(node,0x14)&=~0x10; H(obj,8)|=0x400;
   W(P(node,0x5C),0x6C)=1; W(P(node,0x30),0x6C)=1;
  } else {
   if (a == 0) {
    node=P(P(D_800AE850,0x73F0),0);
    for(i=0; i<H(arg0,0x110); i++) {
     obj=arg0+i*0x44;
     func_80022BE8(node,W(obj,0)); func_800239CC(node,obj+0x1C);
     H(obj,8)=(H(obj,8)|0x400)&0xFDFF;
     node=P(node,4);
    }
   }
  }
 } else if(index==0) {
  node=P(P(D_800AE850,0x73F0),0);
  i=0; do {
   obj=arg0+i*0x44; func_80022BE8(node,W(obj,0)); func_800239CC(node,obj+0x1C);
   i++; H(obj,0xA)=4; W(obj,0xC)=0; H(obj,8)=(H(obj,8)|0x400)&0xFDFF;
   node=P(node,4);
  } while(i<4U);
 }
} else {
 if(a==0) {
  node=P(P(D_800AE850,0x73F0),0);
  for(i=0;i<H(arg0,0x110);i++) {
   obj=arg0+i*0x44; func_80022BE8(node,W(obj,0)); func_800239CC(node,obj+0x1C);
   H(obj,0xA)=4; W(obj,0xC)=0; H(obj,8)=(H(obj,8)|0x400)&0xFDFF;
   a=(u32)P(node,0x6C); W(node,0x14)&=~0x3F0; W((u8 *)a,0x34)=0; node=P(node,4);
  }
 }
 func_800234E0((void *)a);
}
}
