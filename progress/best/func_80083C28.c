typedef struct Huff
{
  u8 op;
  u8 bits;
  u16 pad;
  union 
  {
    u32 n;
    struct Huff *t;
  } v;
} Huff;
void *func_8007EAA0(int, int);
void func_80097E30(void *, int, int);
extern u32 D_800C33A4;
int func_80083C28(u32 *b, u32 n, u32 simple, u16 *base, u16 *extra, Huff **root, u32 *bits)
{
  u32 count[18];
  u32 width[18];
  Huff r;
  Huff *tables[16];
  u32 values[288];
  u32 offset[17];
  u32 a;
  u32 f;
  u32 i;
  u32 j;
  u32 k;
  u32 min;
  u32 max;
  u32 code;
  u32 size;
  u32 consumed;
  u32 limit;
  int left;
  int level;
  int __repair_level_1;
  u32 *p;
  Huff *q;
  Huff *entry;
  u32 new_var;
  u32 *ws = width + 1;
  if (n > 256)
  {
    limit = b[256];
  }
  func_80097E30(count, 0, 68);
  p = b;
  i = n;
  do
  {
    count[*(p++)]++;
  }
  while (--i);
  if (count[0] == n)
  {
    *root = 0;
    *bits = 0;
    return 0;
  }
  for (min = 1; min < 17; min++)
  {
    if (count[min])
    {
      break;
    }
  }

  if ((*bits) < min)
  {
    *bits = min;
  }
  for (max = 16; max; max--)
  {
    if (count[max])
    {
      break;
    }
  }

  if (max < (*bits))
  {
    *bits = max;
  }
  left = 1 << min;
  for (k = min; k < max; k++)
  {
    if ((left -= count[k]) < 0)
    {
      return 2;
    }
    left <<= 1;
  }

  if ((left -= count[max]) < 0)
  {
    return 2;
  }
  count[max] += left;
  offset[1] = (j = 0);
  p = count + 1;
  {
    u32 *op = offset + 2;
    i = max - 1;
    if (i)
    {
      do
      {
        j += *(p++);
        *(op++) = j;
      }
      while (--i);
    }
  }
  func_80097E30(values, 0, 1152);
  p = b;
  i = 0;
  do
  {
    j = *(p++);
    if (j)
    {
      values[offset[j]++] = i;
    }
    i++;
  }
  while (i < n);
  level = -1;
  q = 0;
  code = 0;
  p = values;
  __repair_level_1 = -1;
  consumed = 0;
  tables[0] = (size = 0);
  offset[0] = 0;
  new_var = simple;
  n = offset[max];
  (width + 1)[-1] = 0;
  for (k = min; ((s32) k) <= ((s32) max); k++)
  {
    a = count[k] - 1;
    if (a != ((u32) (-1)))
    {
      do
      {
        while (((s32) (consumed + ws[__repair_level_1])) < ((s32) k))
        {
          consumed += width[__repair_level_1 + 1];
          __repair_level_1++;
          j = k - consumed;
          f = 1 << j;
          i = max - consumed;
          if ((*bits) < i)
          {
            i = *bits;
          }
          if ((a + 1) < f)
          {
            f -= a + 1;
            while ((++j) < i)
            {
              f <<= 1;
              if (f <= count[consumed + j])
              {
                break;
              }
              f -= count[consumed + j];
            }

          }
          if ((limit < (consumed + j)) & (consumed < limit))
          {
            j = limit - consumed;
          }
          size = 1 << j;
          width[__repair_level_1 + 1] = j;
          q = func_8007EAA0(6, (size + 1) * 8);
          D_800C33A4 += size + 1;
          *root = q + 1;
          root = &q->v.t;
          q->v.t = 0;
          q++;
          tables[__repair_level_1] = q;
          if (__repair_level_1)
          {
            offset[__repair_level_1] = code;
            r.op = j + 16;
            r.bits = (width + 1)[__repair_level_1 - 1];
            r.v.t = q;
            entry = tables[__repair_level_1 - 1] + ((code & ((1 << consumed) - 1)) >> (consumed - width[__repair_level_1]));
            *entry = r;
          }
        }

        r.bits = k - consumed;
        if (p >= (values + n))
        {
          r.op = 99;
        }
        else
          if ((*p) < simple)
        {
          r.op = ((*p) < 256) ? (16) : (15);
          r.v.n = (u16) (*(p++));
        }
        else
        {
          r.op = extra[(*p) - new_var];
          r.v.n = base[(*p) - new_var];
          p++;
        }
        f = 1 << (k - consumed);
        for (j = code >> consumed; j < size; j += f)
        {
          q[j] = r;
        }

        for (j = 1 << (k - 1); code & j; j >>= 1)
        {
          code ^= j;
        }

        code ^= j;
        while ((code & ((1 << consumed) - 1)) != offset[__repair_level_1])
        {
          consumed -= width[__repair_level_1];
          __repair_level_1--;
        }

      }
      while (a--);
    }
  }

  *bits = (width + 1)[0];
  return (left != 0) && (max != 1);
}
