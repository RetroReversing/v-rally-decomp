#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define H(p,o) (*(s16 *)((u8*)(p)+(o)))
#define U(p,o) (*(u16 *)((u8*)(p)+(o)))
#define A(p,o) (*(u8 **)((u8*)(p)+(o)))
typedef struct Blob
{
  s32 words[177];
} Blob;
extern u8 *D_800A1468;
extern u8 *D_800C3508;
extern u8 *D_800C35A0;
extern u8 D_800A161C[];
extern u8 D_800A1620;
extern s32 D_800AFA58;
extern Blob *D_800D0634[];
extern void func_8005BC60(void);
extern void func_8005BB5C(void);
extern void func_80065860(void);
extern void func_80065C04(void);
extern void func_80062304(void *, s16);
extern void func_8005937C(s32, u16);
extern void func_8008A0D8(void *, u16, s32);
extern void func_8008A1CC(void *, u16, s32, void *);void *func_800592AC(u32);
extern void func_80061740(Blob);
void func_8006556C(void)
{
  Blob blob;
  s32 i;
  s32 k;
  s32 val;
  s16 sel;
  u8 *p;
  u8 *q;
  func_8005BC60();
  func_8005BB5C();
  {
    u8 *g = D_800C35A0;
    u8 *h = D_800A1468;
    U(g, 0x20) = 0;
    h[0x23c] = D_800A1620;
  }
  {
    u8 *c = D_800C3508;
    sel = H(c, 2);
    if (sel == 2)
    {
      A(c, 0x10)[(2 * 20) + 0xE] = D_800C35A0[0x21] + 9;
    }
    else
    {
      u8 *e = A(c, 0x10);
      e[(sel * 20) + 0xE] = 4 + D_800C35A0[0x21];
      func_80062304(e, sel);
    }
  }
  i = 0;
  val = 80;
  D_800AFA58 = U(D_800C35A0, 0x20);
  do
  {
    if (H(D_800C3508, 2) == 2)
    {
      func_8005937C(i + 9, U(D_800D0634[D_800A161C[i + 4]], 0x14));
    }
    else
    {
      func_8005937C(i + 4, U(D_800D0634[D_800A161C[i + 4]], 0x14));
    }
    if ((i != 0) && ((U(D_800C35A0, 0x2a) & (0x1000 << (i - 1))) != (0x1000 << (i - 1))))
    {
      func_8008A0D8(D_800C3508, i + 9, 0);
      func_8008A0D8(D_800C3508, i + 4, 0);
      p = func_800592AC(i);
      if (i != 3)
      {
        p[0xf] = 80;
        p[0x10] = 80;
        p[0x11] = 80;
      }
      else
      {
        k = 3;
        q = p + 6;
        do
        {
          q[0x41] = 0;
          q -= 2;
        }
        while ((--k) >= 0);
      }
    }
    func_8008A1CC(D_800C3508, (H(D_800C3508, 2) == 2) ? (i + 9) : (i + 4), 16, func_80065C04);
    i++;
  }
  while (i < 4);
  if (H(D_800C3508, 2) == 1)
  {
    *((void **) (D_800A1468 + 0x28c)) = func_80065860;
  }
  blob = *D_800D0634[D_800A1468[0x23c]];
  func_80061740(blob);
}

