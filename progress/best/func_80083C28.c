typedef struct huft {
  u8 e;
  u8 b;
  union {
    u16 n;
    struct huft *t;
  } v;
} Huff;
void *func_8007EAA0(int, int);
void func_80097E30(void *, int, int);
extern u32 D_800C33A4;
int func_80083C28(u32 *b, u32 n, u32 s, u16 *d, u16 *e, Huff **t, int *m)
{
  u32 a;
  u32 c[17];
  u32 el;
  u32 f;
  int g;
  int h;
  u32 i;
  u32 j;
  int k;
  int lx[17];
  int *l = lx + 1;
  u32 *p;
  Huff *q;
  Huff r;
  Huff *u[16];
  u32 v[288];
  int w;
  u32 x[17];
  u32 *xp;
  int y;
  u32 z;

  el = n > 256 ? b[256] : 16;
  func_80097E30(c, 0, sizeof(c));
  p = b;
  i = n;
  do {
    c[*p]++;
    p++;
  } while (--i);
  if (c[0] == n) {
    *t = 0;
    *m = 0;
    return 0;
  }
  for (j = 1; j <= 16; j++)
    if (c[j])
      break;
  k = j;
  if ((u32)*m < j)
    *m = j;
  for (i = 16; i; i--)
    if (c[i])
      break;
  g = i;
  if ((u32)*m > i)
    *m = i;
  for (y = 1 << j; j < i; j++, y <<= 1)
    if ((y -= c[j]) < 0)
      return 2;
  if ((y -= c[i]) < 0)
    return 2;
  c[i] += y;
  x[1] = j = 0;
  p = c + 1;
  xp = x + 2;
  while (--i) {
    *xp++ = (j += *p++);
  }
  func_80097E30(v, 0, sizeof(v));
  p = b;
  i = 0;
  do {
    if ((j = *p++) != 0)
      v[x[j]++] = i;
  } while (++i < n);
  n = x[g];
  x[0] = i = 0;
  p = v;
  h = -1;
  w = l[-1] = 0;
  u[0] = 0;
  q = 0;
  z = 0;
  for (; k <= g; k++) {
    a = c[k];
    while (a--) {
      while (k > w + l[h]) {
        w += l[h++];
        z = (z = g - w) > (u32)*m ? *m : z;
        if ((f = 1 << (j = k - w)) > a + 1) {
          f -= a + 1;
          xp = c + k;
          while (++j < z) {
            if ((f <<= 1) <= *++xp)
              break;
            f -= *xp;
          }
        }
        if ((u32)w + j > el && (u32)w < el)
          j = el - w;
        z = 1 << j;
        l[h] = j;
        q = (Huff *)func_8007EAA0(6, (z + 1) * sizeof(Huff));
        D_800C33A4 += z + 1;
        *t = q + 1;
        *(t = &(q->v.t)) = 0;
        u[h] = ++q;
        if (h) {
          x[h] = i;
          r.b = (u8)l[h - 1];
          r.e = (u8)(16 + j);
          r.v.t = q;
          j = (i & ((1 << w) - 1)) >> (w - l[h - 1]);
          u[h - 1][j] = r;
        }
      }
      r.b = (u8)(k - w);
      if (p >= v + n)
        r.e = 99;
      else if (*p < s) {
        r.e = (u8)(*p < 256 ? 16 : 15);
        r.v.n = (u16)*p++;
      } else {
        r.e = (u8)e[*p - s];
        r.v.n = d[*p++ - s];
      }
      f = 1 << (k - w);
      for (j = i >> w; j < z; j += f)
        q[j] = r;
      for (j = 1 << (k - 1); i & j; j >>= 1)
        i ^= j;
      i ^= j;
      while ((i & ((1 << w) - 1)) != x[h])
        w -= l[h--];
    }
  }
  *m = l[0];
  return y != 0 && g != 1;
}
