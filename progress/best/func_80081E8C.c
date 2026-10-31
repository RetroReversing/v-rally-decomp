typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
} Five81;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern s32 D_800B7300;
void func_80081040(s32, void *, s32, s32, Five81);
void func_8008E13C(void *, void *, u32);
u32 func_80081E8C(u8 *dst, u32 len)
{
  u32 rem = len;
  u32 n;
  u32 words;
  u32 bytes;
  u32 tail;
  u8 *end;
  u8 *src;
  u8 *d;
  u32 count;
  s32 *size;
  u8 *new_var2;
  s32 *ptr;
  u8 *new_var;
  if (len)
  {
    size = (s32 *) (D_800C02AE + 0x3092);
    ptr = size - 1;
  }
  if (len)
  {
    do
    {
      new_var2 = D_800AE850 + 0x235c;
      if ((*size) <= 0)
      {
        func_80081040((D_800B7300 + size[5]) + 8192, (void *) size[-2], 8192, *((s32 *) (D_800AE850 + 0x2358)), *((Five81 *) new_var2));
        *size = 8192;
        size[5] += 8192;
        *ptr = size[-2];
      }
      n = rem;
      if (n >= ((u32) (*size)))
      {
        n = *size;
      }
      if ((((u32) dst) & 3) || ((*ptr) & 3))
      {
        func_8008E13C(dst, (void *) (*ptr), n);
        dst += n;
        *ptr += n;
      }
      else
      {
        words = n >> 2;
        bytes = words * 4;
        src = ptr;
        end = ((u8 *) (*src)) + bytes;
        if ((((u32) dst) < ((u32) end)) & (((u32) (*src)) < ((u32) dst)))
        {
          d = dst + bytes;
          src = end;
          count = bytes >> 2;
          if (count)
          {
            do
            {
              src -= 4;
              d -= 4;
              count--;
              *((s32 *) d) = *((s32 *) src);
            }
            while (count);
          }
        }
        else
        {
          src = (u8 *) (*ptr);
          d = dst;
          count = words;
          if (count)
          {
            do
            {
              *((s32 *) d) = *((s32 *) src);
              src += 4;
              count--;
              d += 4;
            }
            while (count);
          }
        }
        new_var = D_800C02AE + 0x308E;
        dst += words * 4;
        *ptr += words * 4;
        tail = n & 3;
        func_8008E13C(dst, *((void **) new_var), tail);
        dst += tail;
        *ptr += tail;
      }
      rem -= n;
      *size -= n;
    }
    while (rem);
  }
  return len;
}
