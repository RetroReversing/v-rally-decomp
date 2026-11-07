typedef struct { s32 w[6]; } Pkt6;
void func_80081040(s32 arg0, s32 arg1, u32 arg2, Pkt6 arg3);
extern s32 D_800AE850, D_800C02AE;
#define G(o) (*(s32*)((u8*)&D_800C02AE+(o)))
#define H(o) (*(s32*)((u8*)&D_800AE850+(o)))
void func_800848A0(s32 arg0) {
 s32 s0; s32 a2; s32 original=arg0;
 s0=arg0/8192;
 arg0=original;
 s0=arg0-(s0<<13); a2=arg0-s0;
 if(a2!=G(0x30A6)) {
 G(0x30A6)=a2;
 G(0x3092)=8192;
 func_80081040(H(0x8AB0)+a2,G(0x308A),8192,*(Pkt6*)((u8*)&D_800AE850+0x2358));
 G(0x308E)=G(0x308A)+s0;
 G(0x3092)-=s0;
 } else {
 G(0x3092)+=(G(0x308E)-G(0x308A))-s0;
 G(0x308E)=G(0x308A)+s0;
 }
}
