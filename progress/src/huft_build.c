typedef struct huft
{
  u8 e;
  u8 b;
  union 
  {
    u16 n;
    struct huft *t;
  } v;
} Huff;
void *poolAlloc(int, int);
void memset(void *, int, int);
extern u32 D_800C33A4;
/* Builds an inflate Huffman decoding table from the code lengths in lengths[0..num_codes-1]. The first simple_count symbols are direct values; the rest index base_vals/extra_vals. Returns 0 on success, 2 for an over-subscribed code. */
int huft_build(u32 *lengths, u32 num_codes, u32 simple_count, u16 *base_vals, u16 *extra_vals, Huff **result, int *max_bits)
{
  u32 count;
  u32 bl_count[17];
  u32 eob_bits;
  u32 fill;
  int max_len;
  int level;
  u32 sym;
  u32 len;
  int min_len;
  int bit_limits[17];
  int *lim = bit_limits + 1;
  u32 *ptr;
  Huff *cur_table;
  Huff entry;
  Huff *level_tables[16];
  u32 sorted[288];
  int bits_used;
  u32 offs[17];
  int literal_limit;
  u32 *offs_ptr;
  int left;
  u32 table_size;
  eob_bits = (num_codes > 256) ? (lengths[256]) : (16);
  memset(bl_count, 0, sizeof(bl_count));
  ptr = lengths;
  sym = num_codes;
  do
  {
    bl_count[*ptr]++;
    ptr++;
  }
  while (--sym);
  if (bl_count[0] == num_codes)
  {
    *result = 0;
    *max_bits = 0;
    return 0;
  }
  for (len = 1; len <= 16; len++)
  {
    if (bl_count[len])
    {
      break;
    }
  }

  min_len = len;
  if (((u32) (*max_bits)) < len)
  {
    *max_bits = len;
  }
  for (sym = 16; sym; sym--)
  {
    if (bl_count[sym])
    {
      break;
    }
  }

  max_len = sym;
  if (((u32) (*max_bits)) > sym)
  {
    *max_bits = sym;
  }
  for (left = 1 << len; len < sym; len++, left <<= 1)
  {
    if ((left -= bl_count[len]) < 0)
    {
      return 2;
    }
  }

  if ((left -= bl_count[sym]) < 0)
  {
    return 2;
  }
  bl_count[sym] += left;
  offs[1] = (len = 0);
  ptr = bl_count + 1;
  offs_ptr = offs + 2;
  while (--sym)
  {
    *(offs_ptr++) = (len += *(ptr++));
  }

  memset(sorted, 0, sizeof(sorted));
  ptr = lengths;
  sym = 0;
  do
  {
    if ((len = *(ptr++)) != 0)
    {
      sorted[offs[len]++] = sym;
    }
  }
  while ((++sym) < num_codes);
  num_codes = offs[max_len];
  offs[0] = (sym = 0);
  ptr = sorted;
  level = -1;
  bits_used = (lim[-1] = 0);
  level_tables[0] = 0;
  cur_table = 0;
  table_size = 0;
  literal_limit = 256;
  for (; min_len <= max_len; min_len++)
  {
    count = bl_count[min_len];
    while (count--)
    {
      while (min_len > (bits_used + lim[level]))
      {
        bits_used += lim[level++];
        table_size = ((table_size = max_len - bits_used) > ((u32) (*max_bits))) ? (*max_bits) : (table_size);
        if ((fill = 1 << (len = min_len - bits_used)) > (count + 1))
        {
          fill -= count + 1;
          offs_ptr = bl_count + min_len;
          while ((++len) < table_size)
          {
            if ((fill <<= 1) <= (*(++offs_ptr)))
            {
              break;
            }
            fill -= *offs_ptr;
          }

        }
        if (((((u32) bits_used) + len) > eob_bits) && (((u32) bits_used) < eob_bits))
        {
          len = eob_bits - bits_used;
        }
        table_size = 1 << len;
        lim[level] = len;
        cur_table = (Huff *) poolAlloc(6, (table_size + 1) * (sizeof(Huff)));
        D_800C33A4 += table_size + 1;
        *result = cur_table + 1;
        *(result = &cur_table->v.t) = 0;
        level_tables[level] = ++cur_table;
        if (level)
        {
          offs[level] = sym;
          entry.b = (u8) lim[level - 1];
          entry.e = (u8) (16 + len);
          entry.v.t = cur_table;
          len = (sym & ((1 << bits_used) - 1)) >> (bits_used - lim[level - 1]);
          level_tables[level - 1][len] = entry;
        }
      }

      entry.b = (u8) (min_len - bits_used);
      if (ptr >= (sorted + num_codes))
      {
        entry.e = 99;
      }
      else
        if ((*ptr) < simple_count)
      {
        entry.e = (u8) (((*ptr) < literal_limit) ? (16) : (15));
        entry.v.n = (u16) (*(ptr++));
      }
      else
      {
        entry.e = (u8) extra_vals[(*ptr) - simple_count];
        entry.v.n = base_vals[(*(ptr++)) - simple_count];
      }
      fill = 1 << (min_len - bits_used);
      for (len = sym >> bits_used; len < table_size; len += fill)
      {
        cur_table[len] = entry;
      }

      for (len = 1 << (min_len - 1); sym & len; len >>= 1)
      {
        sym ^= len;
      }

      sym ^= len;
      while ((sym & ((1 << bits_used) - 1)) != offs[level])
      {
        level--;
        bits_used -= lim[level];
      }

    }

  }

  *max_bits = lim[0];
  return (left != 0) && (max_len != 1);
}
