s32 func_800056FC(s32);
s32 func_800376C8(s32, s32);
void *func_8004240C(s32);
extern void *D_800C35A0;
extern u8 D_800C34D0;
extern u8 D_800C7926;
extern void *D_800C7F84;
extern void *D_800C811C;
static inline static u8 *inline_fn(void *arg0)
{
  return (u8 *) arg0;
}

void func_800354F4(void)
{
  char *__repair_addr;
  s32 i;
  u16 n;
  u16 v;
  void *tmp;
  s32 s0;
  s32 s1;
  s32 s2;
  s32 r;
  s32 arg;
  n = *((u16 *) (inline_fn(D_800C35A0) + 0xE));
  if (n != 2)
  {
    if (((u8) n) != 0)
    {
      i = 1;
      do
      {
        if (D_800C34D0 == 0)
        {
          n = *((u16 *) (((u8 *) D_800C811C) + 4));
          v = n;
          if (v == 0)
          {
            if (D_800C7926 == 0)
            {
              s0 = (((u8) i) - 1) * 2;
              tmp = func_8004240C(s0 + 3);
              arg = *((s32 *) (inline_fn(tmp) + 0x178));
              D_800C7F84 = tmp;
              i++;
              r = func_800056FC(arg);
              func_800376C8(r, func_8004240C(s0 + 2));
              continue;
            }
          }
          else
          {
            switch (v)
            {
              case 0:

              case 1:

              case 2:
                break;

              case 3:

              case 4:
              {
                s2 = ((u8) i) - 1;
                s1 = s2 * 2;
                tmp = func_8004240C(s1 + 2);
                arg = *((s32 *) (((u8 *) tmp) + 0x178));
                D_800C7F84 = tmp;
                r = func_800056FC(arg);
                (*((void (**)(s32, s32, u8)) (inline_fn(D_800C811C) + 0x34)))(*((s32 *) ((((u8 *) D_800C811C) - (-(((u8) i) * 4))) + 0xC)), r, (u8) (i - 1));
                __repair_addr = (char *) ((inline_fn(D_800C811C) + (s2 * 12)) + 0x18);
                *((f32 *) __repair_addr) = *((f32 *) (((u8 *) D_800C7F84) + 0x118));
                *((f32 *) ((inline_fn(D_800C811C) + ((s2 * 2) * 6)) + 0x1C)) = *((f32 *) (((u8 *) D_800C7F84) + 0x11C));
                *((f32 *) ((inline_fn(D_800C811C) + (s2 * 12)) + 0x20)) = *((f32 *) (((u8 *) D_800C7F84) + 0x120));
              }

            }

          }
        }
        i++;
      }
      while (((u8) n) >= ((u8) i));
    }
  }
}
