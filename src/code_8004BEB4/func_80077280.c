#include "snapshot29_0433f7af8f6d.h"

#define H(p,o) (*(u16*)((p)+(o)))
#define W(p,o) (*(s32*)((p)+(o)))
#define P(p,o) (*(u8**)((p)+(o)))
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 D_800A5E9C[];
extern u8 *D_800A1234;
extern u8 *D_800A17F4[];
extern u8 *D_800C35A0;
extern int func_80022184(void *);
extern void func_8002283C(void);
extern void func_80081540(void *);
extern u8 *func_80081664(int, void *);
extern u8 *func_8007EAA0(int, int);
extern void func_8007EE9C(void *);
extern void func_8008E13C(void *, void *, int);
extern void func_80098290(void *, void *, int);
typedef struct 
{
  u32 w[61];
} SaveState;
void func_80077280(void)
{
  u8 *file = 0;
  u8 *src;
  u8 *dst;
  u8 *state;
  u8 *allocation;
  u8 i;
  int k;
  long car;
  if (!func_80022184(D_800AE850 + 0x7320))
  {
    func_8002283C();
  }
  if (func_80022184(D_800AE850 + 0x7320))
  {
    dst = D_800A1234;
    func_80081540(D_800A5E9C);
    file = func_80081664(1, D_800A17F4[H(D_800C35A0, 0x22)]);
    src = file;
    __builtin_memcpy(dst, src, 0x118);
    allocation = func_8007EAA0(1, 6000);
    state = dst;
    P(state, 4) = allocation;
    P(state, 0) = func_8007EAA0(1, (W(state, 16) + 3) & (~3));
    H(state, 8) |= 1;
    src += 0x118;
    __builtin_memcpy(P(state, 4), src, 6000);
    src += 6000;
    H(state, 12) = 0;
    func_8008E13C(P(state, 0), src, (W(state, 16) + 3) & (~3));
    src += (W(state, 16) + 3) & (~3);
    *((SaveState *) (D_800C02AE + 0x7f66)) = *((SaveState *) D_800C35A0);
    __builtin_memcpy(D_800C35A0, src, 0xf4);
    H(D_800C35A0, 0x1e) = 8;
    for (i = 0; i < 4; i++)
    {
      k = i * 40;
      car = H(D_800C02AE, k + 0x7fb4);
      H(k + D_800C35A0, 0x4e) = car;
      func_80098290(D_800C35A0 + (k + 0x44), (D_800C02AE + k) + 0x7faa, car);
    }

    if ((D_800C02AE[0x7f4f] != 5) && (!(H(D_800C02AE, 0x7f92) & 0x800)))
    {
      switch (D_800C02AE[0x7f4f])
      {
        case 2:
          H(D_800C35A0, 0x20) = 0;
          H(D_800C35A0, 0x22) = 3;
          break;

        case 4:
          H(D_800C35A0, 0x20) = 0;
          H(D_800C35A0, 0x22) = 6;
          break;

        case 3:

        case 8:
          H(D_800C35A0, 0x20) = 0;
          H(D_800C35A0, 0x22) = 1;
          break;

      }

    }
  }
  func_8007EE9C(file);
  {
  u8 *tail = D_800C35A0;
  if (H(tail, 0x1e) != 8)
  {
    H(tail, 0x1e) = 8;
    H(tail, 0x20) = 0;
    H(tail, 0x22) = 0;
    D_800C02AE[0x7f4e] = 0;
  }
  }
}
