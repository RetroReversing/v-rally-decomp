typedef struct 
{
  s32 w[4];
} S4;
typedef struct 
{
  u32 w[5];
} S52;
typedef struct 
{
  s32 v;
} __attribute__((packed)) P32;
extern u8 D_800AE850[];
extern u8 *D_800C35A0;
void func_80052CF4(S52 *a, P32 *b)
{
  u32 i;
  s32 changed;
  P32 tmp;
  u32 x;
  u32 y;
  *((S4 *) a) = *((S4 *) (D_800AE850 + 0x7DB0));
  a->w[4] = 0;
  for (i = 0; i < 4; i++)
  {
    b[i] = *((P32 *) ((D_800C35A0 + (*(D_800C35A0 + i + 0x32) * 40)) + 0x44));
  }

  do
  {
    changed = 0;
    for (i = 4; i != 0; i--)
    {
      x = a->w[i];
      y = a->w[i - 1];
      if (y < x)
      {
        a->w[i] = y;
        a->w[i - 1] = x;
        tmp = b[i];
        b[i] = b[i - 1];
        b[i - 1] = tmp;
        changed = 1;
      }
    }

  }
  while (changed);
}

