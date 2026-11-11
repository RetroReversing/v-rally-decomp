extern s32 gStreamState[];
extern s32 gOrderState[];

/* Returns 1 when no voice record in the active list (stride 0x134, key at +0x40) has the same key as the request's word 1. */
s32 voiceKeyIsFree(s32 *request)
{
  s32 i;
  s32 isFree;
  s32 count;
  int zero;

  s32 *entry;
  s32 **new_var;
  isFree = 1;
  count = *((s32 *) (((u8 *) gStreamState) + 0x757E));
  entry = *(new_var = &(*((s32 **) (((u8 *) gOrderState) + 0x80A0))));
  zero = 0;
  i = 0;
  if (count > zero)
  {
    s32 key = request[1];
    do
    {
      i++;
      isFree &= -(((*((s32 *) (((u8 *) entry) + 0x40))) ^ key) != 0);
      entry = (s32 *) (((u8 *) entry) + 0x134);
    }
    while ((i < count) && (isFree != 0));
  }
  return isFree;
}
