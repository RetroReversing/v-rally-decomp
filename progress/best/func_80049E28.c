extern s32 D_8009D538, D_8009F640;
extern char D_800AE850[], D_800C02AE[];
extern char *D_800A0384;
extern void func_80042F40(), func_80049450(), func_80054838();
extern s32 func_80049DB0(int, void *);
s32 func_80049E28(void) {
 int a;
 char *p = *(char **)(D_800C02AE+0x32F2);
 a=*(u16 *)(p+0x1e);
 D_8009F640=(D_8009F640|3)&~8;
 *(u16 *)(p+0x36)=0;
 if ((a==5)|(a==0)) {
  *(s32 *)(D_800AE850+0x8030)=2;
  if (*(u16 *)(p+0x1e)==0 && (func_80049DB0(a,p)&255)==1) {
   func_80042F40(); func_80054838();
   D_800A0384[0x384]=0;
   return 0;
  }
 } else if ((u16)a == a) {
  *(s32 *)(D_800AE850+0x8030)=2;
  if (*(u16 *)(p+0x1e)==0 && (func_80049DB0(a,p)&255)==1) {
   func_80042F40(); func_80054838();
   D_800A0384[0x384]=0;
   return 0;
  }
 } else *(s32 *)(D_800AE850+0x8030)=5;
 D_800A0384[0x384]=0;
 if (D_8009D538 & 0x4000) func_80049450();
 *(u8 *)(D_800C02AE+0x7E72)=0;
 return 1;
}
