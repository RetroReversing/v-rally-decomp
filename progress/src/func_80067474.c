typedef struct { u8 pad0[0x228]; u8 unk228; u8 pad229[0x1C]; u8 unk245; u8 pad246[0x42]; void (*unk288)(void); void (*unk28C)(void); } Obj;
typedef struct { u8 pad0[8]; s32 pad8[2]; u8 *unk10; } M;
typedef struct { u8 pad0[4]; s32 unk4; u8 pad8[0x24]; s32 unk2c; } E;
extern Obj *D_800A1468;
extern u8 D_800C02AE[];
extern void func_8005A388(s32, s32);
extern void func_800680F0(s32, s32);
extern void func_800679D8(void);
extern void func_80067AC4(void);
typedef struct { u8 pad0[0x10]; u8 *p10; } Hdr;
typedef struct { u8 pad[8]; u8 *p8; } Row;
s32 func_80067474(s32 arg0, s32 arg1)
{
  s8 count = 0;
  s8 last = -1;
  s8 i = 0;
  u8 *t;
  u16 h;
  u8 *base;
  s32 *e;
  D_800A1468->unk245 = 0;
  t = *(u8 **)(D_800C02AE + 0x32F2) + 0x44;
  h = *(u16 *)(*(u8 **)(D_800C02AE + 0x325A) + 2);
  do {
    if (t[i * 0x28] >= 0x5B) {
      count++;
      if (last < 0) last = i;
    }
    i++;
  } while (i < 4);
  if (count != 0) {
    D_800A1468->unk228 = last;
    func_8005A388(arg0, arg1);
    D_800A1468->unk288 = func_800679D8;
    D_800A1468->unk28C = func_80067AC4;
    base = *(u8 **)(*(u8 **)(D_800C02AE + 0x325A) + 0x10);
    base = *(u8 **)(base + h * 20 + 8);
    e = *(s32 **)(base + arg1 * 12 + 4);
    e[0xB] = 2;
  } else {
    base = *(u8 **)(*(u8 **)(D_800C02AE + 0x325A) + 0x10);
    base = *(u8 **)(base + h * 20 + 8);
    e = *(s32 **)(base + arg1 * 12 + 4);
    e[0xB] = 3;
    func_800680F0(3, 3);
  }
  return 0;
}
