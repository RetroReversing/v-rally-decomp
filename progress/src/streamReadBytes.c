typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
} Five81;
extern u8 gOrderState[];
extern u8 gStreamState[];
extern s32 D_800B7300;
void dmaCopyChunks(s32, void *, s32, s32, Five81);
void func_8008E13C(void *, void *, u32);

/* Copies len bytes from the streamed read buffer into dst. When the current chunk (8 KB) is
 * used up, it is refilled first. Word-aligned blocks are copied a word at a time, backwards if
 * the ranges overlap; the rest goes through func_8008E13C. Returns len. */
u32 streamReadBytes(u8 *dst, u32 len)
{
  u32 remaining = len;
  u32 n;
  u32 words;
  u32 tail;
  u32 count;
  s32 *chunk_left;
  s32 *src_pos;
  u32 *s;
  int src_off;
  u32 *d;
  u32 *e;
  s32 *new_var;
  Five81 *five;
  int new_var3;
  if (len)
  {
    five = (Five81 *) (gOrderState + 0x235c);
    chunk_left = (s32 *) (gStreamState + 0x3092);
    src_pos = chunk_left - 1;
    do
    {
      if ((*chunk_left) <= 0)
      {
        dmaCopyChunks(((*((s32 *) 0x800B7300)) + chunk_left[5]) + 8192, (void *) chunk_left[-2], 8192, ((s32 *) five)[-1], *five);
        *chunk_left = 8192;
        chunk_left[5] += 8192;
        chunk_left[-1] = chunk_left[-2];
      }
      n = remaining;
      if (n >= ((u32) (*chunk_left)))
      {
        n = *chunk_left;
      }
      new_var3 = 0x308E;
      if ((((u32) dst) & 3) || ((*((u32 *) (gStreamState + new_var3))) & 3))
      {
        func_8008E13C(dst, *((void **) (gStreamState + 0x308E)), n);
        dst += n;
        *src_pos += n;
      }
      else
      {
        u8 *src;
        u32 bytes;
        words = n >> 2;
        src = *((u8 **) (gStreamState + 0x308E));
        bytes = words << 2;
        ;
        if ((dst < (src + bytes)) & (src < dst))
        {
          d = (u32 *) (dst + bytes);
          e = (u32 *) (src + bytes);
          count = bytes >> 2;
          while (count)
          {
            e--;
            d--;
            count--;
            *d = *e;
          }

        }
        else
        {
          s = (u32 *) src;
          d = (u32 *) dst;
          count = bytes >> 2;
          while (count)
          {
            *d = *s;
            s++;
            count--;
            d++;
          }

        }
        dst += words * 4;
        *src_pos += words * 4;
        tail = n & 3;
        func_8008E13C(dst, *((void **) (gStreamState + 0x308E)), tail);
        dst += tail;
        *src_pos += tail;
      }
      remaining -= n;
      *(new_var = chunk_left) -= n;
    }
    while (remaining);
  }
  return len;
}
