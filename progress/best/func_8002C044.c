#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} Vec;
extern char *D_800B5C40;
void func_8002D8A0(void *, void *, void *);
int func_80028E94(void *, void *, int);
char *func_80028D74(void *, void *);
void func_80029AA8(void *, void *, void *, int);
void func_8002A4C4(void *, void *, int, int);
void func_80029EAC(void *, void *, int);
void func_8002D7E4(int, int *);
void func_8002E778(void *, void *);
void func_8002C6EC(void *, void *);
void func_8002B7D4(void *);
void func_8002C044(char *a)
{
  int v[4];
  int q[4];
  Vec pos;
  Vec save;
  int shift[5];
  unsigned i = 0;
  long long new_var6;
  int *new_var4;
  int dst = 256;
  int src = 16;
  int *new_var2;
  char *new_var;
  int off = 0;
  char *g;
  int new_var3;
  char *old;
  char *b;
  char *c;
  int result;
  int row;
  int col;
  int oldrow;
  int oldcol;
  int *new_var5;
  int oldresult;
  int k;
  for (i = 0; i < 12; i++, dst += 20, src += 20, off += 20)
  {
    func_8002D8A0(P(a, 0x5c) + 64, P(a, 0x80) + src, P(a, 0x80) + dst);
    b = (P(a, 0x80) + off) + 256;
    c = (P(a, 0x80) + off) + 496;
    {
      char *trans = P(a, 0x58);
      W(c, 0) = W(b, 0) + W(trans, 12);
      W(c, 4) = W(b, 4) + W(trans, 16);
      W(c, 8) = W(b, 8) + W(trans, 20);
    }
  }

  for (i = 0; i < 12; i++)
  {
    new_var4 = v;
    {
      char *p = (char *) ((i * 20) + ((int) P(a, 0x80)));
      int x = W(p, 496);
      int y = W(p, 500);
      int z = W(p, 504);
      v[0] = x;
      do
      {
      }
      while (0);
      v[1] = y;
      v[2] = z;
    }
    g = P(P(a, 0x8c), i * 4);
    new_var = g;
    pos.x = (*((volatile int *) (&v[0]))) - W(new_var, 36);
    pos.y = (*((volatile int *) (&v[1]))) - W(new_var, 40);
    pos.z = (*((volatile int *) (&v[2]))) - W(new_var, 44);
    result = func_80028E94(a, &pos, i);
    ;
    if (result > 0)
    {
      col = 0;
      row = 0;
      oldcol = W(P(a, 0x60), (i * 4) + 48);
      new_var3 = (i * 4) + 48;
      oldrow = W(P(a, 0x60), i * 4);
      save = pos;
      old = new_var;
      g = func_80028D74(g, new_var4);
      oldresult = result;
      if (g != old)
      {
        switch (result)
        {
          case 1:

          case 4:

          case 5:

          case 6:

          case 7:

          case 8:
            row = -1;
            col = -1;
            break;

          case 2:
            row = 0;
            col = oldcol - (W(old, 76) - W(g, 76));
            break;

          case 3:
            row = U(g, 136) - 2;
            col = oldcol - (W(old, 76) - W(g, 76));
            break;

        }

        do
        {
          if (!U(P(g, 112), ((row * (U(g, 138) - 1)) + col) * 2))
          {
            col = -1;
          }
        }
        while (0);
        if ((((row >= 0) && (col >= 0)) && (row < (U(g, 136) - 1))) && (col < (U(g, 138) - 1)))
        {
          W(P(a, 96), (i * 4) + 48) = col;
          W(P(a, 96), i * 4) = row;
          P(P(a, 140), i * 4) = g;
          pos.x = (*(&v[0])) - W(g, 36);
          pos.y = v[1] - W(g, 40);
          pos.z = v[2] - W(g, 44);
          result = func_80028E94(a, &pos, i);
          if (result)
          {
            result = -result;
          }
        }
        else
        {
          W(P(a, 96), new_var3) = oldcol;
          W(P(a, 96), i * 4) = oldrow;
          g = old;
          P(P(a, 140), i * 4) = g;
          pos = save;
          result = -oldresult;
        }
      }
      else
      {
        do
        {
          result = -result;
        }
        while (0);
      }
    }
    if (i < 4)
    {
      func_8002D8A0(P(a, 88) + 252, (P(a, 128) + 16) + (i * 20), v);
      v[0] <<= 2;
      v[1] <<= 2;
      new_var6 = 2;
      v[2] <<= 2;
      v[0] += W(P(a, 88), 232);
      v[1] += W(P(a, 88), 236);
      v[new_var6] += W(P(a, 88), 240);
      new_var5 = v;
      q[0] = v[0] - (W(g, 36) << 4);
      q[1] = v[1] - (W(g, 40) << 4);
      q[2] = new_var5[2] - (W(g, 44) << 4);
      if (result < 0)
      {
        if (i == 0)
        {
          k = 11;
        }
        if (i == 1)
        {
          k = 10;
        }
        if (i == 2)
        {
          k = 5;
        }
        if (i == 3)
        {
          k = 4;
        }
        W(P(a, 96), (i * 4) + 48) = W(P(a, 96), (k * 4) + 48);
        W(P(a, 96), i * 4) = W(P(a, 96), k * 4);
        P(P(a, 140), i * 4) = P(P(a, 140), k * 4);
      }
      func_80029AA8(a, q, &pos, i);
    }
    else
      if (result < 0)
    {
      func_8002A4C4(a, &pos, i, result);
    }
    else
    {
      func_80029EAC(a, &pos, i);
    }
  }

  for (b = P(D_800B5C40, 0); b; b = P(b, 4))
  {
    if (((b == a) || (W(b, 20) & 64)) || (W(a, 20) & 64))
    {
      continue;
    }
    v[0] = W(P(a, 92), 84) - W(P(b, 92), 84);
    v[1] = W(P(a, 92), 88) - W(P(b, 92), 88);
    v[2] = W(P(a, 92), 92) - W(P(b, 92), 92);
    func_8002D7E4(v[0], shift);
    func_8002D7E4(v[1], shift + 1);
    func_8002D7E4(v[2], shift + 2);
    if (((shift[0] < 17) || (shift[1] < 17)) || (shift[2] < 17))
    {
      if (shift[0] > shift[1])
      {
        shift[0] = shift[1];
      }
      if (shift[0] > shift[2])
      {
        shift[0] = shift[2];
      }
      shift[0] = 17 - shift[0];
      v[0] >>= shift[0];
      v[1] >>= shift[0];
      v[2] >>= shift[0];
    }
    func_8002E778(v, v);
    v[0] += v[1] + v[2];
    if (v[0] <= 0x4e1ff)
    {
      func_8002C6EC(a, b);
    }
  }

  func_8002B7D4(a);
}
