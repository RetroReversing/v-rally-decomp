#define P(p,o) (*(u8 **)((u8*)(p)+(o)))
#define H(p,o) (*(u16 *)((u8*)(p)+(o)))
#define S(p,o) (*(s16 *)((u8*)(p)+(o)))
#define B(p,o) (*(u8 *)((u8*)(p)+(o)))
extern f32 D_8009CEC0[3];
extern f32 D_8009CEC4;
extern s32 D_8009FF30;
extern u8 D_800C7926;
void func_8005639C(u8 **out, u8 *arg)
{
  s32 pad[2];
  s32 i;
  f32 new_var;
  s32 n;
  u8 color;
  u8 c;
  u8 *table;
  u8 *desc;
  u8 *p;
  u8 *t;
  n = H(arg, 0x1c);
  table = P(P(arg, 0x18), 0x14);
  color = 0x8c;
  if (D_800C7926 == 0)
  {
    color = 0x32;
  }
  if (n != 0)
  {
    i = 0;
    desc = table + 4;
    for (; i < ((s32) n); i++, table = table + 8)
    {
      if (H(desc, 2) == 0x23)
      {
        n = H(desc, 0);
        p = P(table, 0);
        i = 0;
        if (n != 0)
        {
          t = p + 2;
          do
          {
            S(*out, 4) = (s32) (((f32) S(P(P(arg, 0x18), 0xc) + (H(p, 0) * 4), 0)) * D_8009CEC0[0]);
            S(*out, 8) = (s32) (((f32) S(P(P(arg, 0x18), 0xc) + (H(p, 0) * 4), 2)) * D_8009CEC0[2]);
            i = 0;
            ;
            S(*out, 6) = (s32) (((f32) S(P(arg, 0x10) + (H(p, 0) * 2), 0)) * D_8009CEC0[1]);
            if (D_8009FF30 != 2)
            {
              c = B(P(arg, 0x14) + H(p, 0), 0);
            }
            else
            {
              c = color;
            }
            B(*out, 0) = c;
            B(*out, 1) = c;
            B(*out, 2) = c;
            B(*out, 3) = 15;
            S(*out, 0x14) = (u32) (((f32) H(t, 2)) * D_8009CEC0[0]);
            S(*out, 0x16) = (u32) (((f32) H(t, 4)) * D_8009CEC4);
            H(*out, 0x12) = H(t, 0);
            t += 8;
            i++;
            *out += 0x18;
          }
          while (i < ((s32) n));
          p += 8;
        }
      }
      desc += 8;
    }

  }
}
