extern s32 D_800A1468; extern s32 D_800C35A0; extern s32 D_800C3508;
extern s32 func_8005A388(s32,s32,s32,s32); extern s32 func_800680F0(s32,s32,s32,s32); extern void func_800679D8(void); extern void func_80067AC4(void);
s32 func_80067474(s32 arg0,s32 arg1) {
 s32 count=0; s32 last=-1; s8 i=0; u16 temp_s1; s32 ptr; u8 *p;
 *(u8*)(D_800A1468+0x245)=0;
 p=(u8*)(D_800C35A0+0x44); temp_s1=*(u16*)(D_800C3508+2);
 do { if(p[(s32)i*0x28]>=0x5b){count++;if((s8)last<0)last=(u8)i;} i++; } while(i<4);
 if((s8)count!=0) { *(u8*)(D_800A1468+0x228)=last; func_8005A388(arg0,arg1,count,last);
 { s32 d=D_800A1468; s32 m=D_800C3508;
 *(s32*)(d+0x288)=(s32)func_800679D8; *(s32*)(d+0x28c)=(s32)func_80067AC4;
 ptr = *(s32*)(m+0x10); ptr = *(s32*)(temp_s1*0x14+ptr+8); ptr=*(s32*)(arg1*0xC+ptr+4); *(s32*)(ptr+0x2c)=2; }
 } else { ptr = *(s32*)(D_800C3508+0x10); ptr = *(s32*)(temp_s1*0x14+ptr+8); ptr=*(s32*)(arg1*0xC+ptr+4); *(s32*)(ptr+0x2c)=3; func_800680F0(3,3,count,last); }
 return 0;
}
