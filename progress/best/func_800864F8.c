#define D_800C328A ((char *)&D_800C3538)
extern int D_800C3648;
extern int D_800C782C;
extern int D_800B6160;
extern int D_800A9930;
extern int D_800B68EC;
extern int D_800B5C70;
extern int D_800C7824;
extern int D_800B68F0;
extern unsigned char D_800C3580;
extern int D_800C34D4;
extern int D_800A9934;
extern int D_800B0100;
extern int D_800B65E8;
extern int D_800B4130;
extern int D_800C353C;
extern int D_800C3538;
extern int D_800B4138;
extern int D_800B4134;
extern char D_800B0B54[];
extern int D_800C80C0;
extern s32 *D_800A1B90;
s32 MusSetMasterVolume(s32, s32);
s32 alHeapDBAlloc(s32, s32, void *, s32, s32);
s32 alHeapInit(void *, s32, s32);
s32 alSynAddPlayer(void *, void *);
s32 alSynAllocVoice(void *, s32, s16 *);
s32 func_80087594();
s32 func_800885CC();
s32 func_800896DC();
s32 func_80089704();
extern s32 func_800864C0;
extern s32 func_800882B0;
typedef struct 
{
  s16 a;
  s16 b;
  s8 c;
  s8 pad[3];
} Vc;
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
  void *f;
  s32 g;
  s8 h;
  s8 pad[11];
} SA;
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
} SB;
s32 func_800864F8(char *arg0)
{
  int __repair_literal;
  Vc vc;
  SA sa;
  SB sb;
  char *new_var;
  s32 off2;
  s32 off;
  s32 i;
  s32 t0;
  s32 new_var2;
  u8 v;
  {
    s32 w0 = *((s32 *) (arg0 + 0));
    s32 w1 = *((s32 *) (arg0 + 4));
    s32 w2 = *((s32 *) (arg0 + 0x1C));
    s32 w3 = *((s32 *) (arg0 + 0x20));
    D_800C3648 = w0;
    D_800C782C = w1;
    D_800B6160 = w2;
    D_800A9930 = w3;
  }
  new_var2 = *((s32 *) (arg0 + 0x10));
  v = *((u8 *) (arg0 + 0x3D));
  D_800B68EC = v;
  D_800B5C70 = 1000000 / v;
  func_800896DC(*((s32 *) (arg0 + 0xC)), 0, new_var2);
  alHeapInit(D_800C328A, *((s32 *) (arg0 + 0xC)), *((s32 *) (arg0 + 0x10)));
  D_800C7824 = alHeapDBAlloc(0, 0, D_800C328A, 1, D_800C782C * 0x1C);
  D_800B68F0 = alHeapDBAlloc(0, 0, D_800C328A, 1, D_800C782C * 0x134);
  func_800896DC(D_800C7824, 0, D_800C782C * 0x1C);
  func_800896DC(D_800B68F0, 0, D_800C782C * 0x134);
  D_800C3580 = *((u8 *) (arg0 + 0x3C));
  func_80089704(*((s32 *) (arg0 + 0x14)), *((s32 *) (arg0 + 0x18)));
  sa.b = (sa.a = D_800C782C);
  t0 = *((s32 *) (arg0 + 0x14));
  sa.e = 0;
  sa.h = 2;
  sa.g = 0;
  sa.f = D_800C328A;
  sa.c = *((s32 *) (arg0 + 0x24));
  sb.a = *((s32 *) (arg0 + 0x28));
  sb.b = *((s32 *) (arg0 + 0x30));
  sb.c = *((s32 *) (arg0 + ((unsigned long long) 0x2C)));
  func_80087594(&sa, *((s32 *) (arg0 + 8)), &sb, *((s32 *) (arg0 + 0x34)), (D_800C34D4 = (D_800A9934 = t0), *((s32 *) (arg0 + 0x38))), D_800B68EC);
  MusSetMasterVolume(3, 0x7FFF);
  D_800B0100 = 1;
  D_800B65E8 = 0x12345678;
  D_800B4130 = 0;
  D_800B4138 = (int) (&func_800882B0);
  D_800B4134 = (int) (&D_800B4130);
  alSynAddPlayer(D_800B0B54, &D_800B4130);
  i = 0;
  __repair_literal = 0;
  if (D_800C782C > __repair_literal)
  {
    off2 = 0;
    off = 0;
    do
    {
      *((s8 *) ((off + D_800B68F0) + 0xC1)) = 0;
      i++;
      new_var = arg0 + 8;
      func_800885CC(D_800B68F0 + off);
      vc.c = 0;
      vc.b = 0;
      vc.a = *((s32 *) new_var);
      alSynAllocVoice(D_800B0B54, D_800C7824 + off2, &vc.a);
      off += 0x134;
      off2 += 0x1C;
    }
    while (i < D_800C782C);
  }
  {
    s32 *p = (s32 *) D_800C80C0;
    D_800C80C0 = (int) (&func_800864C0);
    D_800A1B90 = p;
  }
  return D_800C353C - D_800C3538;
}
