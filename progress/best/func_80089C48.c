extern void func_80038E9C(void);
extern void func_80038ED4(void);
extern void func_80038F0C(void);
static inline static s32 *inline_fn(u8 *arg0)
{
  return (s32 *) arg0;
}

int func_80089C48(u8 *arg0, u8 *arg1, unsigned int arg2, u8 arg3, s16 *arg4, u8 *arg5, u8 *arg6, s32 arg7)
{
  u8 a;
  u8 b;
  u8 c;
  s32 d;
  s32 e;
  s32 f;
  int new_var;
  s32 g;
  s32 h;
  u8 *p;
  u8 *q;
  u8 *r;
  s32 (*fn)(s32, s32);
  s8 typ;
  u8 x37 = 0;
  u8 x27 = 0;
  u8 x2f = 0;
  u8 x3f = 0;
  s16 ret = -1;
  *arg4 = -1;
  *arg5 = 0;
  arg6[20] = 0;
  q = arg1 + 8;
  c = 0;
  a = 0;
  b = 0;
  p = arg1;
  while (((u8) c) < arg3)
  {
    if ((*inline_fn(p)) & arg2)
    {
      *arg5 |= 1;
      if (!(b & 255))
      {
        d = *inline_fn(p);
        if (d == 1)
        {
          b = 1;
          func_80038E9C();
        }
        else
          if (d == 2)
        {
          b = 1;
          func_80038ED4();
        }
        else
          if (d != 0x10000)
        {
          b = 1;
          func_80038F0C();
        }
      }
      typ = *((s8 *) (q - 4));
      if (((u32) (typ == 0)) & ((u32) (a == 0)))
      {
        fn = *((s32 (**)(s32, s32)) q);
        e = -1;
        if (fn)
        {
          if (x27)
          {
            d = -2;
            f = 0;
          }
          else
            if ((unsigned int) x2f)
          {
            d = -1;
            f = 0;
          }
          else
          {
            d = arg7;
            f = arg0[13];
            f = d - f;
          }
          e = fn(d, f);
        }
        if (arg6[20])
        {
          *arg5 = 1;
          ret = e;
        }
      }
      else
        if (typ == 1)
      {
        u8 *node;
        r = p;
        for (;;)
        {
          d = arg0[13];
          new_var = *inline_fn(p);
          e = *inline_fn(r + 8);
          arg0 = *((u8 **) (arg0 + 8));
          node = arg0 + ((e - d) * 12);
          if (node[9])
          {
            r = arg0 + ((arg0[14] - d) * 12);
            if (node != r)
            {
              ret = e;
              x3f = 1;
            }
            else
            {
              a = 1;
              *arg5 = 0;
              break;
            }
          }
          else
          {
            f = node[8];
            d = 0;
            while (((u8) d) < ((u8) f))
            {
              ;
              if ((!((*inline_fn((*((u8 **) (node + 4))) + ((d & 255) * 12))) & new_var)) || ((*((s8 *) (((*((u8 **) (node + 4))) + ((d & 255) * 12)) + 4))) != 1))
              {
                d++;
              }
              else
              {
                break;
              }
            }

            d &= 255;
            if (d != ((u8) node[8]))
            {
              r = (*((u8 **) (node + 4))) + (d * 12);
              continue;
            }
            a = 1;
            *arg5 = 0;
          }
          break;
        }

      }
      else
        if ((((typ == 2) && (!x3f)) && ((*inline_fn(q)) != (-1))) && (!x37))
      {
        d = *((s32 *) p);
        if (d & 0x10000)
        {
          x2f = 1;
        }
        else
          if (d & 0x20)
        {
          x27 = 1;
        }
        x37 = 1;
        *arg4 = *((s16 *) q);
      }
    }
    ++c;
    p += 12;
    q += 12;
  }

  return ret;
}
