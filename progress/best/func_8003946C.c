#define G D_800C35A0
#define P D_800C7F84
#define H(p,o) (*(s16 *)((u8*)(p)+(o)))
#define U(p,o) (*(u16 *)((u8*)(p)+(o)))
#define W(p,o) (*(s32 *)((u8*)(p)+(o)))
#define B(p,o) (*((u8*)(p)+(o)))
#define A(p,o) (*(u8 **)((u8*)(p)+(o)))
extern u8 *D_800C35A0;
extern u8 *D_800C7F84;
extern u8 *func_8004240C(s32);
extern u8 *func_80040260(s32, s32, s32, u16, void *, s32);
extern u8 *func_80034FF0(void *, s32);
extern void func_8003B980(void);
void func_8003946C(s32 a, u8 *b, s32 c)
{
  int new_var;
  u8 *g = G;
  u8 *p;
  u8 *q;
  u8 *r;
  u8 *o;
  s32 x;
  s32 y;
  s32 z;
  s32 sum;
  s32 off;
  s32 n;
  u32 i;
  char *row;
  char *lrow;
  if (U(g, 0x1e) != 7)
  {
    if (U(g, 0xe) == 1)
    {
      row = (char *) g;
      row += B(g, 0x32) * 40;
      if (row[0x48] & 2)
      {
        q = A(func_8004240C(1), 0x178);
        x = H(q, 0xc);
        y = H(q, 0xe);
        P = (u8 *) 0;
        o = func_80040260(a, 0, 0, (u16) c, func_8003B980, 1);
        H(o, 0x9c) = x - 63;
        H(o, 0x9e) = y - 42;
        r = func_80034FF0(b + 0x4c, 0);
        A(o, 0xa4) = r;
        H(o, 0xe) = -3;
        W(o, 0xa0) |= 0x20;
        A(o, 0xa8) = P;
        H(o, 0xc) = -(U(A(A(r, 4), 0), 6) >> 1);
      }
    }
    else
    {
      i = 1;
      if (U(g, 0xe) == 2)
      {
        n = 1;
        do
        {
          lrow = (char *) G;
          lrow += B(((u8 *) G) + i, 0x31) * 40;
          if (lrow[0x48] & 2)
          {
            p = func_8004240C(n);
            q = A(p, 0x178);
            off = 0;
            P = p;
            x = H(q, 0xc);
            new_var = 1;
            z = H(q, 8);
            sum = H(q, 0xa) + H(q, 0xe);
            if (!(U(G, 0x12) & new_var))
            {
              x -= 16;
              off = (-(W(p, 0xc) == new_var)) & 20;
            }
            o = func_80040260(a, 0, 0, (u16) c, func_8003B980, 1);
            r = func_80034FF0(b + 0x4c, 0);
            A(o, 0xa4) = r;
            H(o, 0x9c) = ((z + x) + off) - 35;
            H(o, 0x9e) = sum - 32;
            H(o, 0xe) = -2;
            W(o, 0xa0) |= 0x20;
            A(o, 0xa8) = P;
            H(o, 0x7a) = 1;
            H(o, 0xc) = -(U(A(A(A(o, 0xa4), 4), 0), 6) >> 1);
          }
          i++;
          n += 2;
        }
        while (U(g, 0xe) >= i);
      }
    }
  }
}
