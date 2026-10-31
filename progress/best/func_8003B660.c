s32 func_8003A6D4();
s32 func_8003AB38();
extern s32 D_8009D534;
extern u8 D_8009D544;
extern unsigned char D_8009FE00[];
extern u32 D_800AFA6C;
void func_8003B660(void *p, s32 x, s32 y, u32 z)
{
  u8 b[4];
  s32 new_var2;
  s32 a;
  s32 c;
  s32 d;
  s32 e;
  s32 f;
  u32 q;
  void *n;
  unsigned char new_var;
  a = z;
  n = *((void **) ((*((char **) (((char *) p) + 0xA8))) + 0x24));
  if (n)
  {
    d = *((s32 *) (((char *) p) + 0x80));
    f = D_8009D534;
    c = *((s32 *) (*((char **) ((*((char **) (((char *) n) + 0x6C))) + 0x24))));
    new_var2 = f;
    e = d & (~4);
    *((s32 *) (((char *) p) + 0x80)) = e;
    if (c == new_var2)
    {
      a = e | 4;
      goto L;
    }
    if ((!((*((s32 *) (((char *) n) + 0x14))) & 0x10)) && ((*((s16 *) (((char *) p) + 0x96))) != c))
    {
      *((u8 *) (((char *) p) + 0x94)) = 100;
    }
    *((s16 *) (((char *) p) + 0x96)) = c;
    if ((*((u16 *) (((char *) p) + 0x78))) == 0)
    {
      new_var2 = c * 2;
      q = new_var2;
      if (D_8009D544 == 0)
      {
        q = q / 3;
        a = q;
        func_8003AB38(a, D_8009FE00, c);
      }
      else
      {
        func_8003AB38(c, D_8009FE00, c);
      }
    }
    if ((*((u8 *) (((char *) p) + 0x94))) && (!((((u32) D_800AFA6C) >> 3) & 1)))
    {
      d = *((s32 *) (((char *) p) + 0x80));
      if (d & 4)
      {
        a = d & (~4);
      }
      else
      {
        a = d | 4;
      }
      L:
      *((s32 *) (((char *) p) + 0x80)) = a;

    }
  }
  b[0] = 200;
  b[1] = 200;
  b[2] = 10;
  b[3] = 255;
  func_8003A6D4(p, b);
  a = D_8009FE00[*((u16 *) (((char *) p) + 0x78))] - 48;
  *((s16 *) (((char *) p) + 0x7A)) = (s16) a;
}
