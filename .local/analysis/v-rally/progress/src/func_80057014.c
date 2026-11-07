typedef struct
{
  u8 b[0x18];
} Rec;
extern u8 D_800AE850[];
extern Rec *D_800B7020;
#define KEY(i) (*((u16 *) (D_800B7020[i].b + 0x12)))
s32 func_80057014(s32 l, s32 r)
{
  s32 i;
  s32 j;
  s32 key;
  i = l - 1;
  j = r + 1;
  key = KEY(l);
  for (;;)
  {
    do
    {
      j--;
    }
    while (key < KEY(j));
    do
    {
      i++;
    }
    while (KEY(i) < key);
    if (i >= j)
    {
      return j;
    }
    *((Rec *) (D_800AE850 + 0x1220)) = D_800B7020[i];
    D_800B7020[i] = D_800B7020[j];
    D_800B7020[j] = *((Rec *) (D_800AE850 + 0x1220));
  }
}
