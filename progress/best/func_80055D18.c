extern s32 D_8009FF30;
extern u8 D_800C7926;
typedef struct 
{
  u16 x;
  u16 y;
  u16 z;
  s8 n[6];
  u16 flag;
} Rec;
void func_80055D18(u8 **dst, Rec **info, s32 add, u8 *tbl)
{
  u8 unused[8];
  Rec *p;
  s32 n;
  s32 i;
  u8 fb;
  u8 c;
  s8 *d;
  s32 a;
  s32 b;
  p = *info;
  n = *((u16 *) (((u8 *) info) + 4));
  fb = 0x8C;
  if (D_800C7926 == 0)
  {
    fb = 0x32;
  }
  i = 0;
  if (n != 0)
  {
    do
    {
      ((u16 *) (*dst))[8] = p->x + add;
      c = add;
      ((u16 *) (*dst))[9] = p->y + c;
      ((u16 *) (*dst))[10] = p->z + c;
      ((u16 *) (*dst))[11] = 0;
      if (D_8009FF30 != 2)
      {
        c = tbl[p->x];
      }
      else
      {
        c = fb;
      }
      if (info)
      {
        (*dst)[0] = fb;
        (*dst)[1] = c;
        (*dst)[2] = c;
        (*dst)[3] = 6;
        c = fb;
      }
      else
      {
        (*dst)[0] = fb;
        (*dst)[1] = c;
        (*dst)[2] = c;
        (*dst)[3] = 6;
        c = fb;
      }
      if (D_8009FF30 != 2)
      {
        c = tbl[p->y];
      }
      (*dst)[4] = c;
      (*dst)[5] = c;
      (*dst)[6] = c;
      (*dst)[7] = 0;
      c = fb;
      if (D_8009FF30 != 2)
      {
        c = tbl[p->z];
      }
      (*dst)[8] = c;
      (*dst)[9] = c;
      (*dst)[10] = c;
      (*dst)[11] = 0;
      (*dst)[12] = 0;
      (*dst)[13] = 0;
      (*dst)[14] = 0;
      (*dst)[15] = 0;
      d = (s8 *) (*dst);
      a = p->n[0];
      b = p->n[1];
      d[0x18] = a;
      d[0x19] = b;
      d = (s8 *) (*dst);
      a = p->n[2];
      b = p->n[3];
      d[0x1A] = a;
      d[0x1B] = b;
      d = (s8 *) (*dst);
      a = p->n[4];
      b = p->n[5];
      d[0x1C] = a;
      d[0x1D] = b;
      (*dst)[0x1E] = 0;
      (*dst)[0x1F] = 0;
      ((u16 *) (*dst))[16] = p->flag;
      p += 1;
      i += 1;
      *dst += 0x22;
    }
    while (i < n);
  }
}
