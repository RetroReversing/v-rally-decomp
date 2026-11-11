typedef struct
{
  u8 b[0x18];
} SortRec;
extern u8 gOrderState[];
extern SortRec *D_800B7020;
#define SORT_KEY(i) (*((u16 *) (D_800B7020[i].b + 0x12)))

/* Hoare partition step of a quicksort over D_800B7020[l..r], keyed on the u16 at +0x12
 * of each 24-byte record. Swaps records around the pivot key (the key of l) and returns the
 * split index j. */
s32 sort_partition(s32 l, s32 r)
{
  s32 i;
  s32 j;
  s32 key;
  i = l - 1;
  j = r + 1;
  key = SORT_KEY(l);
  for (;;)
  {
    do
    {
      j--;
    }
    while (key < SORT_KEY(j));
    do
    {
      i++;
    }
    while (SORT_KEY(i) < key);
    if (i >= j)
    {
      return j;
    }
    *((SortRec *) (gOrderState + 0x1220)) = D_800B7020[i];
    D_800B7020[i] = D_800B7020[j];
    D_800B7020[j] = *((SortRec *) (gOrderState + 0x1220));
  }
}
