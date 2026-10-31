typedef struct 
{
  u8 pad[0x48];
} Obj48;
typedef struct 
{
  u8 pad[0x178];
  void *data;
} Obj178;
extern u8 D_800C02AE;
extern void *D_800C35A0;
extern void *D_800C7F84;
extern void *func_8003BA9C;
extern s32 func_80034FF0(s32, s32);
extern void *func_80040260(s32, s16, s16, s32, void *, s32);
extern void *func_8004240C(s32);
void func_8003970C(s32 arg0, s32 arg1, s32 arg2)
{
  u8 *base = &D_800C02AE;
  void *q;
  u32 i;
  s32 j;
  s32 k;
  u32 x;
  s32 y;
  s32 result;
  u16 n;
  s32 a;
  s32 b;
  s32 c;
  if ((*((u16 *) (D_800C35A0 + 0x1E))) == 7)
  {
    return;
  }
  switch (*((u16 *) (D_800C35A0 + 0xE)))
  {
    case 1:
    {
      u8 *r = (u8 *) D_800C35A0;
      i = r[0x32];
      r += i * 0x28;
      if (!(r[0x48] & 2))
      {
        return;
      }
      q = func_8004240C(1);
      q = *((void **) (((u8 *) q) + 0x178));
      a = *((s16 *) (((u8 *) q) + 0xC));
      b = *((s16 *) (((u8 *) q) + 0xE));
      n = 0xffff;
      n = arg2 & n;
      D_800C7F84 = q;
      result = func_80040260(arg0, a - 0x32, b - 0x10, n, func_8003BA9C, 0);
      *((s32 *) (((u8 *) result) + 0xA4)) = func_80034FF0(arg1 + 0x4c, 0);
      *((void **) (((u8 *) result) + 0xA8)) = D_800C7F84;
      result = func_80040260(arg0, a - 0x46, b - 0x20, n, 0, 0);
      *((s32 *) (((u8 *) result) + 0xA4)) = func_80034FF0(arg1 + 0x4c, 0);
      *((s16 *) (((u8 *) result) + 0x7A)) = 2;
      break;
    }

    case 2:
    {
      n = arg2 & ((unsigned short) 0xffff);
      j = arg1;
      j += 0x4c;
      k = 1;
      for (i = 1; i < 3; i++, k += 2)
      {
        u8 *r = (u8 *) D_800C35A0;
        r += r[i + 0x31] * 0x28;
        if (r[0x48] & 2)
        {
          q = func_8004240C(k);
          D_800C7F84 = q;
          q = *((void **) (((u8 *) q) + 0x178));
          a = *((s16 *) (((u8 *) q) + 0xC));
          b = *((s16 *) (((u8 *) q) + 0xE));
          c = *((s16 *) (((u8 *) q) + 8));
          k = *((s16 *) (((u8 *) q) + 0xA));
          x = a - 0x10;
 do { y = 0; } while (0);
          if (!((*((u16 *) (D_800C35A0 + 0x12))) & 1))
          {
            x = a - 0x20;
            if ((*((s32 *) (((u8 *) q) + 0xC))) == 1)
            {
              y = 0x14;
            }
          }
          x = 0xA4;
          result = func_80040260(arg0, (((c + 0x14) + x) - 0x1A) + y, ((k + b) - 2) - 0xA, n, func_8003BA9C, 0);
          *((s32 *) (((u8 *) result) + x)) = func_80034FF0(j, 0);
          *((s16 *) (((u8 *) result) + 0x7A)) = 4;
          *((void **) (((u8 *) result) + 0xA8)) = D_800C7F84;
          result = func_80040260(arg0, (((c + 0x14) + x) - 0x28) + y, ((k + b) - 2) - 0x15, n, 0, 0);
          *((s32 *) (((u8 *) result) + 0xA4)) = func_80034FF0(j, 0);
          *((s16 *) (((u8 *) result) + 0x7A)) = 3;
        }
      }

    }

  }

}
