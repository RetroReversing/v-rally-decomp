typedef struct 
{
  u8 b[0x18];
} Rec;
extern u8 D_800AE850[];
extern u8 *D_800B7020;
s32 func_80057014(s32 arg0, s32 arg1)
{
  u8 *tmp;
  s32 lo;
  s32 hi;
  s32 lop;
  s32 hip;
  u8 *base;
  u8 *new_var;
  s32 key;
  Rec *a;
  Rec *b;
  lo = arg0 - 1;
  hi = arg1 + 1;
  tmp = D_800AE850 + 0x1220;
  lop = lo * 24;
  hip = hi * 24;
  base = D_800B7020;
  hi = arg0 * 24;
  key = *((u16 *) ((base + hi) + 18));
  for (;;)
  {
    base = D_800B7020;
    a = (Rec *) (base + hip);
    do
    {
      hip -= 24;
      a--;
      hi--;
    }
    while (key < (*((u16 *) (((u8 *) a) + 18))));
    base = D_800B7020;
    b = (Rec *) (base + lop);
    do
    {
      b++;
      lop += 24;
      lo++;
    }
    while ((*((u16 *) (((u8 *) b) + 18))) < key);
    if (lo >= hi)
    {
      return hi;
    }
    ;
    *((Rec *) tmp) = *((Rec *) (D_800B7020 + lop));
    base = D_800B7020;
    new_var = base + hip;
    *((Rec *) (base + lop)) = *((Rec *) new_var);
    base = D_800B7020;
    *((Rec *) (base + hip)) = *((Rec *) tmp);
  }

}
