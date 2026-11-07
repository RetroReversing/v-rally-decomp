typedef struct { s32 w[61]; } Blk;
typedef struct { u8 pad0[0xE]; s16 e; u8 pad1[2]; s16 x12; u8 pad2[0xA]; u16 x1E; u8 pad3[0xC]; u16 x2C; } Obj;
extern Obj *D_800C35A0;
extern s32 D_800A123C;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern Blk D_800C8214;
extern void func_8007C694(void);
extern void func_8007EA64(void);
extern s32 func_80084BF0(s32);
extern s32 func_80084DD4(s32);
void func_800516BC(void)
{
  s32 s0 = 0;
  s32 s1;
  s32 a0;
  s32 v0;
  if (D_800C35A0->x1E != 7) return;
  s1 = func_80084BF0(0);
  if (func_80084DD4(1) != 0) s0 = func_80084BF0(1);
  func_8007C694();
  if ((D_800C35A0->x2C & 0x20) == 0) {
    a0 = 0;
    if ((s0 & 0x1000) == 0 && (s1 & 0x1000) == 0) {
      v0 = D_800A123C++;
      if (v0 != 0x8CA && *(u16 *)(D_800AE850 + 0x2416) - 0x64 != *(u16 *)(D_800AE850 + 0x2414)) goto done;
    }
    a0 = 1;
  } else {
    a0 = 0;
    if ((s1 & 0x1000) == 0) {
      v0 = D_800A123C++;
      if (v0 != 0x19) goto done;
    }
    a0 = 1;
  }
  done:
  if (a0 == 0) return;
  D_800A123C = 0;
  *(Blk *)D_800C35A0 = D_800C8214;
  D_800C02AE[0x7E72] = 0;
  D_800C35A0->e = 1;
  func_8007EA64();
  D_800C35A0->x12 = D_800C02AE[0x38F2];
  a0 = D_800C02AE[0x38F0];
  *(s32 *)(D_800AE850 + 0x8030) = 5;
  D_800C35A0->x1E = 0;
  D_800C35A0->e = a0;
}
