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
s32 func_80082930(Huft *tl, Huft *td, u32 bl, u32 bd)
{
  u32 b;
  u32 k;
  u32 w;
  u32 e;
  u32 n;
  u32 d;
  u32 ml;
  u32 md;
  Huft *t;
  b = *((u32 *) (D_800C02AE + 0x310E));
  k = *((u32 *) (D_800C02AE + 0x3112));
  w = *((u32 *) (D_800C02AE + 0x310A));
  ml = MASK(bl);
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
        u8 *dst = (w + D_800AE850) + 0x8AE8;
        u8 *src = (d + D_800AE850) + 0x8AE8;
        if ((!(((u32) dst) & 3)) && (!(((u32) src) & 3)))
        {
          u32 words = chunk >> 2;
          u32 bytes = words * 4;
          u32 cnt;
          u32 *to = (u32 *) dst;
          u32 *from = (u32 *) src;
          u32 *end = (u32 *) (src + bytes);
          if ((((u32) to) < ((u32) end)) & (((u32) from) < ((u32) to)))
          {
            chunk = bytes >> 2;
            from = end;
            cnt = chunk;
            to = (u32 *) (dst + bytes);
            while (cnt)
            {
              *(--to) = *(--from);
              cnt--;
            }

          }
          else
          {
            cnt = chunk;
            while (cnt)
            {
              *(to++) = *(from++);
              cnt--;
            }

          }
          w += words * 4;
          d += words * 4;
          ;
          src = (d + D_800AE850) + 0x8AE8;
          chunk &= 3;
        }
        func_8008E13C((w + D_800AE850) + 0x8AE8, src, chunk);
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
  *((u32 *) (D_800C02AE + 0x3112)) = k;
  return 0;
}
