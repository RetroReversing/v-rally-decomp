#define D_800B7300 (*(s32 *)(&D_800AE850+0x8AB0))
#define sp32 (sp28+10)
#define sp34 (sp28+12)
#define sp38 (sp28+16)
#define PKT (*(Pkt6 *)((&D_800AE850) + 0x2358))
extern u32 D_800C3338;
extern u32 D_800C333C;
extern s32 D_800C3340;
extern s32 D_800C3354;
extern u8 D_800C02AE;
extern u8 D_800AE850;
typedef struct 
{
  s32 w[6];
} Pkt6;
extern void func_80081040(s32, s32, s32, Pkt6);
extern void func_80081E8C(void *, s32);
extern s16 func_800822D4(void *);
extern s32 func_800822E8(void *);
extern s32 func_80098400(s32, void *, s32);
static inline int inline_fn(s32 *arg0, int arg1, s32 *arg2)
{
  return arg0[arg1] - arg2[-1];
}

s32 func_80084350(s32 arg0)
{
  u8 sp28[0x16];
  s32 *base = (s32 *) ((&D_800C02AE) + 0x30A2);
  s32 t = *base;
  s32 rem;
  s32 n;
  s32 i;
  s32 found = 0;
  s32 *p;
  int new_var;
  if (t < 0x2001)
  {
    func_80081040(D_800B7300, D_800C3338, *base, PKT);
    D_800C3340 = *base;
    D_800C333C = (D_800C3338 + (*base)) - 0x16;
    if (D_800C333C >= D_800C3338)
    {
      base = (s32 *) (((u8 *) base) - 0x14);
      p = base;
      for (;;)
      {
        if (((*(*((u8 **) ((&D_800C02AE) + 0x308E)))) == 0x50) && (func_80098400(p[0], ((u8 *) p) + 0x26, 4) == 0))
        {
          p[1] -= inline_fn(p, 0, p);
          break;
        }
        p[0]--;
        if (((u32) p[0]) < ((u32) p[-1]))
        {
          break;
        }
      }

    }
  }
  else
  {
    rem = t % 0x2000;
    if (rem >= 0x13)
    {
      func_80081040((D_800B7300 + t) - rem, D_800C3338, rem, PKT);
      D_800C3340 = rem;
      D_800C3354 = (*base) - rem;
      D_800C333C = (D_800C3338 + rem) - 0x16;
      if (D_800C333C >= D_800C3338)
      {
        new_var = 0x50;
        base = (s32 *) (((u8 *) base) - 0x14);
        p = base;
        for (;;)
        {
          if (((*(*((u8 **) ((&D_800C02AE) + 0x308E)))) == new_var) && (func_80098400(p[0], ((u8 *) p) + 0x26, 4) == 0))
          {
            found = 1;
            p[1] -= inline_fn(p, 0, p);
            break;
          }
          p[0]--;
          if (((u32) p[0]) < ((u32) p[-1]))
          {
            break;
          }
        }

      }
    }
    else
    {
      D_800C3354 = (*base) - rem;
    }
    n = ((arg0 - rem) + 0x1fff) / 0x2000;
    if ((!found) && (n > 0))
    {
      for (i = 1; (!found) & (i <= n); i++)
      {
        s32 *q = (s32 *) ((&D_800C02AE) + 0x30A6);
        *q -= 0x2000;
        func_80081040(D_800B7300 + (*q), *((s32 *) (((u8 *) ((s32 *) ((&D_800C02AE) + 0x30A6))) - 0x1c)), 0x2000, PKT);
        *((s32 *) (((&D_800C02AE) + 0x30A6) - 0x18)) = (*((s32 *) (((&D_800C02AE) + 0x30A6) - 0x1c))) + 0x1fff;
        p = (s32 *) (((&D_800C02AE) + 0x30A6) - 0x18);
        if (((u32) p[0]) >= ((u32) p[-1]))
        {
          for (;;)
          {
            if (((*(*((u8 **) ((&D_800C02AE) + 0x308e)))) == 0x50) && (func_80098400(p[0], ((u8 *) p) + 0x26, 4) == 0))
            {
              found = 1;
              p[1] -= inline_fn(p, 0, p);
              break;
            }
            p[0]--;
            if (((u32) p[0]) < ((u32) p[-1]))
            {
              break;
            }
          }

        }
      }

    }
  }
  func_80081E8C(sp28, 0x16);
  *((s16 *) ((&D_800C02AE) + 0x30de)) = func_800822D4(sp32);
  *((s32 *) ((&D_800C02AE) + 0x30e6)) = func_800822E8(sp38);
  *((s32 *) ((&D_800C02AE) + 0x30e2)) = func_800822E8(sp34);
  return 0;
}
