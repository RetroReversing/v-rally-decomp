/* Copies 4 words (one 16-byte record). Copies backwards when the ranges overlap
   with dst above src, so the copy is safe either way. */
static inline void copy_record16(u32 *dst, u32 *src, u32 *src_end)
{
  s32 i;
#ifdef PORT
  if ((dst < src_end) & (src < dst))
#else
  if (((u32)dst < (u32)src_end) & ((u32)src < (u32)dst))
#endif
  {
    u32 *s = src_end;
    u32 *d = dst + 4;
    for (i = 4; i != 0; --i) { s--; d--; *d = *s; }
  }
  else
  {
    u32 *s = src;
    u32 *d = dst;
    for (i = 4; i != 0; --i) { *d++ = *s++; }
  }
}

/* Bubble-sorts the four 16-byte records at times+0x00..0x3F by their first word,
   ascending. Byte 0xB is copied to byte 0x3B first. */
void sort_split_times(void *times)
{
  u8 *base = times;
  u32 *cur, *prev;
  s32 i;
  u8 swapped;
  u32 tmp[4];
  u32 *tmp_end = tmp + 4;
  base[0x3b] = base[0xb];
  swapped = 0;
  do
  {
    swapped = 0;
    i = 3;
    do
    {
      u32 off = (i & 255) << 4;
      cur = (u32 *)(base + off);
      off -= 16;
      prev = (u32 *)(base + off);
      if (*cur < *prev)
      {
        swapped = 1;
        copy_record16(tmp, prev, prev + 4);
        copy_record16(prev, cur, cur + 4);
        copy_record16(cur, tmp, tmp_end);
      }
      i--;
    } while ((i & 255) != 0);
  } while ((swapped & 255) != 0);
}
