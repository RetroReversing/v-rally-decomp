void func_8004CEB4(s32, void *, u16 *, s32, s32, s32, s32, s32, s32);
void func_800596F4(void *, s16, s16, void *);
typedef struct 
{
  u8 p[6];
  u16 x;
  u16 y;
} I;
typedef struct 
{
  I *image;
} B;
typedef struct 
{
  s32 p;
  B *b;
} T;
typedef struct N
{
  struct N *next;
  u8 p[0x24];
  I *img;
} N;
typedef struct 
{
  u8 p[12];
  N *list;
  u8 z[0x21a];
  s8 ix;
} A;
typedef struct { u8 f; u8 pad[39]; } E40;
typedef struct { u8 pad[0x48]; E40 e[4]; } RS;
extern A *D_800A1468;
extern u8 D_800A167C[];
extern u8 D_800A1681;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern RS *D_800C35A0;
extern u8 D_800A57B4[];
void func_80069158(void)
{
  u8 i = 0;
  char new_var2;
  N *n = D_800A1468->list;
  u8 *indices = D_800A167C;
  T **t = (T **) (D_800AE850 + 0x87f8);
  I *im;
  short sel;
  u16 r[4];
  T **p;
  short new_var;
  do
  {
    im = n->img;
    if (((i & 255) == 6) && (D_800C35A0->e[D_800A1468->ix].f & 16))
    {
      sel = D_800A1681;
      goto draw;
    }
    if (((i & 255) == 5) && (D_800C35A0->e[D_800A1468->ix].f & 16))
    {
      sel = indices[0];
      r[0] = (im->x + t[indices[new_var2 = 5]]->b->image->x) + 16;
      r[1] = im->y;
      p = (T **)(sel * 4 + (u32)t);
      r[2] = (*p)->b->image->x;
      new_var = (*p)->b->image->y;
      r[3] = new_var;
      func_800596F4(((unsigned char *)n + 4), r[0] - 12, im->y + 6, D_800A57B4);
      func_8004CEB4(*((s32 *) (D_800C02AE + 0x1032a)), (*p)->b->image, r, 0, 255, 255, 255, 255, 0);
      sel = indices[5];
    }
    else
    {
      sel = D_800A167C[i & 255];
    }
    draw:
    r[0] = im->x;

    r[1] = im->y;
    r[2] = t[sel]->b->image->x;
    r[3] = t[sel]->b->image->y;
    func_8004CEB4(*((s32 *) (D_800C02AE + 0x1032a)), t[sel]->b->image, r, 0, 255, 255, 255, 255, 0);
    n = n->next;
    i++;
  }
  while ((i & 255) < 8);
}
