extern u8 gStreamState[];
extern u8 gOrderState[];
extern u16 D_8009BBB6;

s32 func_80022668(s32,s32);
s32 poolAlloc(s32,s32);
s32 memset(s32,s32,s32);

/* Builds the per-object sprite record for obj from the car state in car:
 * a fixed record for mode 1, otherwise positions taken from the car's fields.
 * Copies the sprite's header words into obj's output block and stores the record. */
void func_800201E4(s32 *car, s32 *obj) {
 s32 sprite, out, rec, half, off, px, w;
 s32 w_size, h_size;

 sprite = *(s32*)(gStreamState+0x5dce);

 *(u16*)(sprite+0x24)+=0x46;
*(u16*)(sprite+0x26)+=0x46;
*(u16*)(sprite+0x2a)+=0x46;

 *(u16*)(sprite+0x24)+=0x46;
*(u16*)(sprite+0x26)+=0x46;
*(u16*)(sprite+0x2a)+=0x46;

 out=*(s32*)(obj+0x22);
*(s32*)out=sprite;

 *(s32*)(*(s32*)(obj+0x22)+4)=*(s32*)(*(s32*)(sprite+0x10));

 *(s32*)(*(s32*)(obj+0x22)+8)=*(s32*)(*(s32*)(sprite+0x10)+4);

 *(s32*)(*(s32*)(obj+0x22)+0xc)=*(s32*)(*(s32*)(sprite+0x10)+8);

 *(s32*)(*(s32*)(obj+0x22)+0x10)=*(s32*)(*(s32*)(sprite+0x10)+0xc);

 *(s32*)(*(s32*)(obj+0x22)+0x14)=*(s32*)(*(s32*)(sprite+0x10)+0x10);

 *(s32*)(*(s32*)(obj+0x22)+0x68)=func_80022668(*(s32*)((u32)gOrderState+0x87f4),0);

 rec=poolAlloc(1,0x20);
memset(rec,0,0x20);

 if(*(s32*)((u8*)car+0x44)==1){
  w_size=0x4b;
h_size=10;

  *(s16*)rec=w_size;
*(s16*)(rec+2)=h_size;
  *(s16*)(rec+4)=0xfa;
*(s16*)(rec+0xc)=-0xfa;

  *(s16*)(rec+0x10)=0x50;
*(s16*)(rec+0x16)=0x50;
*(s16*)(rec+0x12)=0x50;
*(s16*)(rec+0x18)=0x50;

  *(s16*)(rec+8)=w_size;
*(s16*)(rec+0xa)=h_size;

  *(s16*)(rec+0x14)=0x28;
*(s16*)(rec+0x1a)=0x28;

 }else{
  w=*(s32*)((u8*)car+0x90);
half=*(s32*)((u32)gOrderState+0x82ac);
*(s16*)rec=w;
px=*(s32*)((u8*)car+0xdc);
half=half/2;
off=D_8009BBB6-10;

  px+=half;
px+=off;
*(s16*)(rec+2)=px;
*(s16*)(rec+4)=*(s32*)((u8*)car+0x128);
*(s16*)(rec+8)=*(s32*)((u8*)car+0x174);

  *(s16*)(rec+0xa)=*(s32*)((u8*)car+0x1c0)+half+off;
*(s16*)(rec+0xc)=*(s32*)((u8*)car+0x20c);

  *(s16*)(rec+0x10)=*(s32*)((u8*)car+0x258);
*(s16*)(rec+0x16)=*(s32*)((u8*)car+0x258);

  *(s16*)(rec+0x12)=*(s32*)((u8*)car+0x2a4);
*(s16*)(rec+0x18)=*(s32*)((u8*)car+0x2a4);

  *(s16*)(rec+0x14)=*(s32*)((u8*)car+0x2f0);
*(s16*)(rec+0x1a)=*(s32*)((u8*)car+0x2f0);

  if(*(s32*)((u8*)car+0x44)==11){*(s16*)(rec+0x1c)=*(s32*)((u8*)car+0x33c);
*(s16*)(rec+0x1e)=*(s32*)((u8*)car+0x388)+half+off;
}
  else{*(s16*)(rec+0x1c)=*(u16*)(rec+8)-10;
*(s16*)(rec+0x1e)=*(u16*)(rec+0xa);
}
 }
 *(s32*)(*(s32*)(obj+0x22)+0x7c)=rec;

}
