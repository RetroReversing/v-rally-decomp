typedef struct Header
{
  struct Header *next;
  struct Header *prev;
  u8 b8;
  u8 b9;
  u8 used;
  u8 init;
  s32 tag;
  s32 value;
} Header;
void func_8007F828(void *, s32);
void func_80097DC4(void *, void *, s32);
extern u8 *D_800B5B40;
extern void (*D_800C8090)(void *);
extern u32 D_800C33D0[];
static inline s8 range_free(u8 *p, s32 size, s32 shift, s32 mask)
{
  u32 i = ((u32) (p - 0x80000000)) >> shift;
  u32 end = ((u32) ((p + size) - 0x80000000)) >> shift;
  for (; i <= end; i++)
  {
    if (D_800C33D0[i] & mask)
    {
      return 0;
    }
  }

  return 1;
}

static inline u8 *fit(Header *h, s32 avail, s32 size, s32 shift, s32 mask, s32 *mode)
{
  u8 *start = (u8 *) (h + 1);
  u32 gran;
  s32 n;
  u8 *base;
  u8 *end;
  s32 off;
  gran = 1 << shift;
  if (range_free(start, size, shift, mask))
  {
    *mode = 1;
    return start;
  }
  if (range_free(start + (avail - size), size, shift, mask))
  {
    *mode = 2;
    return start + (avail - size);
  }
  n = 0;
  if (gran < ((u32) avail))
  {
    base = (u8 *) (((s32) start) & (-gran));
    for (;;)
    {
      n++;
      if (range_free(base + gran, size, shift, mask) && ((start + avail) >= (base + (gran * n + size))))
      {
        break;
      }
    }

    *mode = 3;
    return ((u8 *) (((s32) start) & (-gran))) + (gran * n);
  }
  *mode = 0;
  return NULL;
}

/* First-fit/best-fit heap allocator. Blocks are chained by Header; a block
 * with used == 0 is free. Returns a pointer to 'size' bytes aligned to 'align',
 * placed so the range avoids granules whose bits in D_800C33D0 overlap 'mask'
 * (granule = 1 << shift). Splits the chosen free block around the result. */
void *func_800808DC(Header *arg0, s32 size, s32 align, s32 shift, s32 mask)
{
  Header *first;
  Header *h;
  Header *bestH;
  Header *next;
  Header *nh;
  Header *s;
  u8 *res;
  u8 *p;
  s32 best;
  s32 avail;
  s32 mode;
  u32 bestMode;
  u32 i;
  int zero;
  u32 e;
  u8 *pm1;
  s32 k;
  u32 *t;
  u32 m;
  arg0--;
  first = arg0;
  size = (size + (align - 1)) & (-align);
  if (size == 0)
  {
    D_800C8090(D_800B5B40 - 4);
    for (;;)
    {
    }

  }
  bestH = NULL;
  res = NULL;
  zero = 0;
  bestMode = zero;
  if (first->init == 0)
  {
    e = ((u8 *) first->next) - ((u8 *) (first + 1));
    if (((u32) (size + 0x1C)) < e)
    {
      first->init = 1;
      h = first + 1;
      func_8007F828(h, e);
    }
    else
    {
      h = NULL;
    }
  }
  else
  {
    h = first + 1;
  }
  best = 0x7FFFFFFF;
  first = h;
  if (mask != 1)
  {
    t = D_800C33D0;
    k = 16;
    do
    {
      *t = 0;
      k--;
      t++;
    }
    while (k != 0);
    D_800C33D0[0] = 0x400;
    for (; h != NULL; h = h->next)
    {
      if ((h->used != 0) && (h->next != NULL))
      {
        i = ((u32) (((u8 *) (h + 1)) - 0x80000000)) >> shift;
        m = ((u32) (((u8 *) h->next) - 0x80000000)) >> shift;
        for (; i <= m; i++)
        {
          D_800C33D0[i] |= 1 << h->tag;
        }

      }
    }

  }
  for (h = first; h != NULL; h = h->next)
  {
    if (h->used == 0)
    {
      avail = ((((s32) h->next) & (-align)) - ((((s32) h) + (align + 0x13)) & (-align))) & (-align);
      if (avail >= size)
      {
        p = fit(h, avail, size, shift, mask, &mode);
        if ((p != NULL) && ((avail < best) | (bestH == NULL)))
        {
          best = avail;
          bestH = h;
          if (mode != 2)
          {
            res = (u8 *) (((s32) ((pm1 = p - 1) + align)) & (-align));
          }
          else
          {
            res = (u8 *) (((s32) p) & (-align));
          }
          bestMode = mode;
        }
      }
    }
  }

  if (bestMode != 0)
  {
    next = bestH->next;
    switch (bestMode)
    {
      case 1:
        nh = ((Header *) res) - 1;
        if (bestH != nh)
      {
        func_80097DC4(nh, bestH, 0x14);
        bestH = nh;
        nh = 0;
        if (bestH->prev != NULL)
        {
          bestH->prev->next = bestH;
        }
        if (bestH->next != NULL)
        {
          bestH->next->prev = bestH;
        }
      }
        if (((u32) best) >= ((u32) (size + 0x14)))
      {
        nh = (Header *) (res + size);
        next->prev = nh;
        nh->next = next;
        nh->prev = bestH;
        nh->b8 = 0;
        nh->b9 = 0;
        nh->used = 0;
        nh->init = 0;
        nh->value = 0;
        bestH->next = nh;
      }
        bestH->used = 1;
        bestH->value = 0;
        break;

      case 2:
        nh = ((Header *) res) - 1;
        next->prev = nh;
        nh->next = next;
        nh->prev = bestH;
        nh->b8 = 0;
        nh->b9 = 0;
        nh->used = 1;
        nh->init = 0;
        nh->value = 0;
        bestH->next = nh;
        break;

      case 3:
        nh = (Header *) (res + size);
        s = ((Header *) res) - 1;
        s->used = 1;
        s->prev = bestH;
        s->next = nh;
        s->b8 = 0;
        s->b9 = 0;
        s->init = 0;
        s->value = 0;
        bestH->next = s;
        next->prev = nh;
        nh->next = next;
        nh->prev = s;
        nh->b8 = 0;
        nh->b9 = 0;
        nh->used = 0;
        nh->init = 0;
        nh->value = 0;
        break;

      default:
        return res;

    }

  }
  return res;
}
