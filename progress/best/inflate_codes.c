#define MASK(x) (*(u16 *)(D_800A19F0+(x)*2))
#define NEED(x) while(k<(x)){s32 c;if(--*(s32 *)(D_800C02AE+0x3092)>=0)c=*(*(u8 **)((s32 *)(D_800C02AE+0x3092)-1))++;else c=func_80082094();if(c==-1)return 1;b|=(u32)c<<k;k+=8;}
#define DUMP(x) b>>=(x);k-=(x)
typedef struct Huft
{
  u8 e;
  u8 b;
  u16 pad;
  union 
  {
    u16 n;
    struct Huft *t;
  } v;
} Huft;
extern s32 func_80082094(void);
extern void func_800821A4(void *, s32, s32);
extern void func_8008E13C(void *, void *, u32);
extern u8 D_800C02AE[];
extern u8 D_800AE850[];
extern u8 D_800A19F0[];
static inline void wcopy(u32 *to, u32 *from, u32 len)
{
  u32 *end = (u32 *) ((u8 *) from + len);
  u32 n;
  u32 *s;
  if ((to < end) & (from < to))
  {
    s = end;
    n = len >> 2;
    to = (u32 *) ((u8 *) to + len);
    for (; n; n--)
    {
      *(--to) = *(--s);
    }
  }
  else
  {
    s = from;
    n = len >> 2;
    for (; n; n--)
    {
      *(to++) = *(s++);
    }
  }
}
s32 inflate_codes(Huft *tl, Huft *td, u32 bl, u32 bd)
{
  u32 b;
  int new_var2;
  u32 k;
  u32 w;
  u32 e;
  u32 n;
  u32 d;
  int new_var3;
  u32 ml;
  u8 *new_var;
  u32 md;
  Huft *t;
  b = *((u32 *) (D_800C02AE + 0x310E));
  k = *((u32 *) (D_800C02AE + 0x3112));
  w = *((u32 *) (D_800C02AE + 0x310A));
  ml = MASK(bl);
  new_var3 = 0x3112;
  new_var = D_800C02AE + new_var3;
  md = MASK(bd);
  for (;;)
  {
    NEED(bl);
    t = tl + (b & ml);
    e = t->e;
    while (e > 16)
    {
      if (e == 99)
      {
        return 1;
      }
      DUMP(t->b);
      e -= 16;
      NEED(e);
      t = t->v.t + (b & MASK(e));
      e = t->e;
    }

    DUMP(t->b);
    if (e == 16)
    {
      ((u8 *) (D_800AE850 + 0x8AE8))[w++] = t->v.n;
      if (w == 0x8000)
      {
        func_800821A4(D_800AE850 + 0x8AE8, 0x8000, 0);
        w = 0;
      }
      continue;
    }
    if (e == 15)
    {
      break;
    }
    NEED(e);
    n = t->v.n + (b & MASK(e));
    DUMP(e);
    NEED(bd);
    t = td + (b & md);
    e = t->e;
    while (e > 16)
    {
      if (e == 99)
      {
        return 1;
      }
      DUMP(t->b);
      e -= 16;
      NEED(e);
      t = t->v.t + (b & MASK(e));
      e = t->e;
    }

    DUMP(t->b);
    NEED(e);
    d = (w - t->v.n) - (b & MASK(e));
    DUMP(e);
    d &= 0x7fff;
    do
    {
      u32 chunk;
      if (w < d)
      {
        chunk = 0x8000 - d;
      }
      else
      {
        chunk = 0x8000 - w;
      }
      {
        u32 amount = chunk;
        if (n < amount)
        {
          amount = n;
        }
        chunk = amount;
      }
      n -= chunk;
      if ((w - d) >= chunk)
      {
        if ((!(((u32) ((w + D_800AE850) + 0x8AE8)) & 3)) && (!(((u32) ((d + D_800AE850) + 0x8AE8)) & 3)))
        {
          u32 words = chunk >> 2;
          wcopy((u32 *) ((w + D_800AE850) + 0x8AE8), (u32 *) ((d + D_800AE850) + 0x8AE8), words * 4);
          w += words * 4;
          d += words * 4;
          chunk &= 3;
        }
        func_8008E13C((w + D_800AE850) + 0x8AE8, (d + D_800AE850) + 0x8AE8, chunk);
        w += chunk;
        d += chunk;
      }
      else
      {
        u8 *dst = (w + D_800AE850) + 0x8AE8;
        u8 *src = (d + D_800AE850) + 0x8AE8;
        do
        {
          *(dst++) = *(src++);
          d++;
          w++;
          chunk--;
        }
        while (chunk);
      }
      if (w == 0x8000)
      {
        func_800821A4(D_800AE850 + 0x8AE8, 0x8000, 0);
        w = 0;
      }
      d &= 0x7fff;
    }
    while (n);
  }

  *((u32 *) (D_800C02AE + 0x310A)) = w;
  *((u32 *) (D_800C02AE + 0x310E)) = b;
  *((u32 *) new_var) = k;
  return 0;
}

