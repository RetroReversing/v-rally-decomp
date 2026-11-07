extern u8 D_800C02AE[];
typedef struct
{
  u16 b15 : 1;
  u16 b14 : 1;
  u16 b13 : 1;
  u16 b12 : 1;
  u16 b10 : 2;
  u16 b8 : 2;
  u16 b4 : 4;
  u16 b0 : 4;
} Flags;
typedef struct
{
  Flags f;
  u16 h2;
  s16 h4;
} State;
typedef struct
{
  u32 hi : 4;
  u32 f24 : 4;
  u32 lo : 24;
} Word;
void func_8006FA8C(void);
#define WD (*(Word *)(D_800C02AE + 0x6E76))
#define OBJ (*(u8 **)(D_800C02AE + 0x32F2))
void func_8006ECB4(void)
{
  f32 scale = 8.0f;
  State *s = (State *)(D_800C02AE + 0x6E5E);
  Word w = WD;
  w.f24 = (s32)(*(f32 *)(D_800C02AE + 0x3332) * scale);
  s->f.b4 = (s32)(*(f32 *)(D_800C02AE + 0x333A) * scale);
  s->f.b0 = (s32)(*(f32 *)(D_800C02AE + 0x332E) * scale);
  WD = w;
  s->f.b12 = *(u16 *)(OBJ + 0x50);
  s->h2 = *(u16 *)(OBJ + 0x2A);
  if (*(u16 *)(OBJ + 0x38))
    s->f.b15 = 1;
  else
    s->f.b15 = 0;
  s->h4 = OBJ[0x2F];
  s->f.b14 = *(u16 *)(D_800C02AE + 0x32A8);
  s->f.b13 = *(u16 *)(OBJ + 0x12);
  s->f.b10 = *(u16 *)(OBJ + 0x16);
  s->f.b8 = *(u32 *)(D_800C02AE + 0x32AA);
  func_8006FA8C();
}
