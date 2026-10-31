extern u8 *D_800A1468; extern u8 D_800C02AE[];
extern u8 *func_800592AC(s32); extern void func_800592F4(s32, s32, u8 *); extern void func_80068E5C(s32); extern void func_8008A0D8(void *,s32,s32);
s32 func_80068D9C(s32 arg0) {
 u8 *rec, *hdr, *p, *obj; u8 v;
 obj=D_800A1468;
 rec=*(u8 **)(D_800C02AE+0x32F2)+*(s8 *)(obj+0x22A)*0x28;
 v=rec[0x48];
 if(v&0x10) {
  hdr=*(u8 **)(obj+0xC);
  rec[0x48]=v&0xEF;
  obj=hdr+4;
  hdr=obj;
  func_8008A0D8(*(void **)(D_800C02AE+0x325A),0x17,1);
  p=func_800592AC(6);
  p[0xF]=hdr[0xB]; p[0x10]=hdr[0xC]; p[0x11]=hdr[0xD];
  func_800592F4(arg0,0,p);
 } else func_80068E5C(arg0);
 return 0;
}
