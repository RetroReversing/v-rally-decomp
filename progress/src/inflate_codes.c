#define MASK(x) (*(u16 *)(mask_bits+(x)*2))
#define NEED(x) while(bitcnt<(x)){s32 c;if(--*(s32 *)(stream_state+0x3092)>=0)c=*(*(u8 **)((s32 *)(stream_state+0x3092)-1))++;else c=order_stream_next_byte();if(c==-1)return 1;bitbuf|=(u32)c<<bitcnt;bitcnt+=8;}
#define DUMP(x) bitbuf>>=(x);bitcnt-=(x)
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
extern s32 order_stream_next_byte(void);
extern void func_800821A4(void *, s32, s32);
extern void memcpy(void *, void *, u32);
extern u8 stream_state[];
extern u8 gOrderState[];
extern u8 mask_bits[];
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

/* Inflate (DEFLATE) compressed-block decoder: decodes literal/length and
 * distance codes from the bit buffer kept in the global decoder state, writes
 * the output into the 32 KB sliding window at gOrderState+0x8AE8 (flushing it
 * through func_800821A4 when full), and saves the state back. Returns 0 at end
 * of block, 1 on a bad code. */
s32 inflate_codes(Huft *lit_tbl, Huft *dist_tbl, u32 lit_bits, u32 dist_bits)
{
  u32 bitbuf;
  int new_var2;
  u32 bitcnt;
  u32 wpos;
  u32 extra;
  u32 copy_len;
  u32 dist;
  int new_var3;
  u32 lit_mask;
  u8 *new_var;
  u32 dist_mask;
  Huft *t;
  bitbuf = *((u32 *) (stream_state + 0x310E));
  bitcnt = *((u32 *) (stream_state + 0x3112));
  wpos = *((u32 *) (stream_state + 0x310A));
  lit_mask = MASK(lit_bits);
  new_var3 = 0x3112;
  new_var = stream_state + new_var3;
  dist_mask = MASK(dist_bits);
  for (;;)
  {
    NEED(lit_bits);
    t = lit_tbl + (bitbuf & lit_mask);
    extra = t->e;
    while (extra > 16)
    {
      if (extra == 99)
      {
        return 1;
      }
      DUMP(t->b);
      extra -= 16;
      NEED(extra);
      t = t->v.t + (bitbuf & MASK(extra));
      extra = t->e;
    }

    DUMP(t->b);
    if (extra == 16)
    {
      ((u8 *) (gOrderState + 0x8AE8))[wpos++] = t->v.n;
      if (wpos == 0x8000)
      {
        func_800821A4(gOrderState + 0x8AE8, 0x8000, 0);
        wpos = 0;
      }
      continue;
    }
    if (extra == 15)
    {
      break;
    }
    NEED(extra);
    copy_len = t->v.n + (bitbuf & MASK(extra));
    DUMP(extra);
    NEED(dist_bits);
    t = dist_tbl + (bitbuf & dist_mask);
    extra = t->e;
    while (extra > 16)
    {
      if (extra == 99)
      {
        return 1;
      }
      DUMP(t->b);
      extra -= 16;
      NEED(extra);
      t = t->v.t + (bitbuf & MASK(extra));
      extra = t->e;
    }

    DUMP(t->b);
    NEED(extra);
    dist = (wpos - t->v.n) - (bitbuf & MASK(extra));
    DUMP(extra);
    dist &= 0x7fff;
    do
    {
      u32 chunk;
      if (wpos < dist)
      {
        chunk = 0x8000 - dist;
      }
      else
      {
        chunk = 0x8000 - wpos;
      }
      {
        u32 amount = chunk;
        if (copy_len < amount)
        {
          amount = copy_len;
        }
        chunk = amount;
      }
      copy_len -= chunk;
      if ((wpos - dist) >= chunk)
      {
        u32 *to = (u32 *) ((wpos + gOrderState) + 0x8AE8);
        u8 *src0;
#ifdef PORT
        if ((!(((uintptr_t) to) & 3)) && (!(((uintptr_t) ((dist + gOrderState) + 0x8AE8)) & 3)))
#else
        if ((!(((u32) to) & 3)) && (!(((u32) ((dist + gOrderState) + 0x8AE8)) & 3)))
#endif
        {
          u32 words = chunk >> 2;
          {
            u32 *from = (u32 *) ((dist + gOrderState) + 0x8AE8);
            u32 len = words * 4;
            u32 *end = (u32 *) ((u8 *) from + len);
            u32 n2;
            u32 *s;
            if ((to < end) & (from < to))
            {
              s = end;
              n2 = len >> 2;
              to = (u32 *) ((u8 *) to + len);
              for (; n2; n2--)
                *(--to) = *(--s);
            }
            else
            {
              s = from;
              n2 = len >> 2;
              for (; n2; n2--)
                *(to++) = *(s++);
            }
          }
          wpos += words * 4;
          dist += words * 4;
          to = (u32 *) ((wpos + gOrderState) + 0x8AE8);
          src0 = (dist + gOrderState) + 0x8AE8;
          chunk &= 3;
        }
        else
          src0 = (dist + gOrderState) + 0x8AE8;
        memcpy(to, src0, chunk);
        wpos += chunk;
        dist += chunk;
      }
      else
      {
        u8 *dst = (wpos + gOrderState) + 0x8AE8;
        u8 *src = (dist + gOrderState) + 0x8AE8;
        do
        {
          *(dst++) = *(src++);
          dist++;
          wpos++;
          chunk--;
        }
        while (chunk);
      }
      if (wpos == 0x8000)
      {
        func_800821A4(gOrderState + 0x8AE8, 0x8000, 0);
        wpos = 0;
      }
      dist &= 0x7fff;
    }
    while (copy_len);
  }

  *((u32 *) (stream_state + 0x310A)) = wpos;
  *((u32 *) (stream_state + 0x310E)) = bitbuf;
  *((u32 *) new_var) = bitcnt;
  return 0;
}