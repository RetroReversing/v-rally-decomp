typedef struct SceneState
{
  u8 pad0[0xE];
  u16 unkE;
  u8 pad10[0xE];
  u16 unk1E;
  u16 unk20;
  u16 unk22;
  u8 pad24[0xA];
  u8 unk2E;
} SceneState;
typedef struct WorldObj
{
  u8 pad[0x228];
  u8 unk228;
  u8 pad229[0x13];
  u8 unk23C;
  u8 pad23D[0x4F];
  void (*unk28C)(void);
} WorldObj;
typedef struct S41
{
  u8 pad[0x41];
  u8 unk41;
} S41;
extern WorldObj *D_800A1468;
extern SceneState *D_800C35A0;
extern void *D_800C3508;
extern u8 *D_800D0634[];
extern u8 D_800A16D4;
extern u8 D_8009E260;
extern u8 D_800A14D6;
extern u8 D_800A14D7;
extern u8 D_800A14D8;
void func_80066384(void);
s32 func_8006A24C(void);
void func_80061F34(void *sc, void *base);
void func_8008A270(void *p, s32 a, s32 b);
void func_8008A290(void *p, s32 a, s32 b, s32 fn);
void func_8006A25C(void);
void func_8008A0D8(s32 p, s32 a, char b);
void *func_800592AC(u32);
void func_8005C0E8(s32, u32, u32);
void func_800603B4(void);
void func_80057B40(s32, u16, u8, u8);
inline static u16 inline_fn(SceneState *arg0)
{
  return arg0->unk22;
}

inline static u16 inline_fn23(SceneState *arg0)
{
  return arg0->unk1E;
}

void func_8006603C(void)
{
  int new_var;
  SceneState *sc;
  u8 *base;
  u8 *row;
  u16 savedE;
  u16 saved1E;
  u16 saved22;
  u8 new_var2;
  s32 one;
  s32 limit;
  u8 new_var3;
  D_800A1468->unk228 = 0;
  D_800A1468->unk23C = D_800C35A0->unk1E;
  sc = D_800C35A0;
  base = D_800D0634[inline_fn23(sc)];
  row = (u8 *)(sc->unk20 * 0x2C4 + (u32)base);
  sc->unk2E = *((row + ((inline_fn(sc) << 1) << 5)) + 0x37);
  func_80061F34(sc, base);
  D_800A1468->unk28C = func_80066384;
  func_8008A270(D_800C3508, 3, 0x14);
  func_8008A290(D_800C3508, 3, 0x10000, (s32)func_8006A24C);
  func_8006A25C();
  if ((*D_800C35A0).unkE < 2)
  {
    S41 *p;
    func_8008A0D8((s32)D_800C3508, 0x10, 0);
    p = func_800592AC(2);
    p->unk41 = 0;
    func_8005C0E8(2, 1, 4);
  }
  func_800603B4();
  limit = 3;
  if (D_800A16D4 < limit)
  {
    new_var = D_800A16D4 == 0;
    if (new_var)
    {
      if (D_800A16D4 == 0)
      {
        sc = D_800C35A0;
        savedE = sc->unkE;
        saved1E = sc->unk1E;
        saved22 = sc->unk22;
        D_8009E260 = 4;
        one = 1;
        new_var3 = (u8) saved1E;
        sc->unkE = one;
        new_var2 = (u8) saved22;
        if (((u16)saved1E) != 2) goto alternate;
        if (((u16)saved22) != 4) goto alternate;

        {
          sc->unk1E = 5;
          sc->unk20 = one;
          sc->unk22 = 2;
        }
        goto finished_selection;
alternate:
        {
          SceneState *alt;
          alt = D_800C35A0;
          if ((inline_fn23(alt) == 3) && (inline_fn(alt) == 5))
          {
            alt->unk1E = 5;
            alt->unk20 = 6;
            alt->unk22 = 0;
          }
        }
finished_selection:;
        D_800A14D6 = D_800C35A0->unk1E;
        D_800A14D7 = D_800C35A0->unk20;
        D_800A14D8 = inline_fn(D_800C35A0);
        func_800416EC();
        D_8009E260 = 1;
        ;
        D_800C35A0->unk1E = new_var3;
        D_800C35A0->unk20 = 0;
        D_800C35A0->unk22 = new_var2;
        D_800C35A0->unkE = savedE;
      }
    }
  }
  func_80057B40(0x12, 2, 0, 0);
}

