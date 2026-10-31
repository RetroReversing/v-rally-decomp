extern u8 D_800C02AE[];
extern char *D_800C35A0;
extern s32 D_800D0634;
s32 func_8005946C(s32, s32, s32);
s32 func_80063C60(s32 arg0)
{
  u8 *st;
  u8 *hold;
  s32 found;
  s32 bit;
  s32 tries;
  s32 base;
  u8 *rec;
  s32 limit;
  s32 shifted;
  u16 id;
  s32 mask;
  st = (u8 *) D_800C35A0;
  found = -1;
  base = D_800D0634;
  rec = (u8 *) (((*((u16 *) (st + 0x20))) * 0x2C4) + base);
  bit = st[0x23];
  tries = 0;
  ;
  if (((*((u16 *) (rec + 0x14))) - 1) > 0)
  {
    hold = st;
    do
    {
      shifted = bit << 24;
      bit -= 1;
      if (shifted <= 0)
      {
        rec = (u8 *) (((*((u16 *) (hold - -0x20))) * 0x2C4) + base);
        bit = rec[0x15] - 1;
      }
      id = *((u16 *) (hold + 0x20));
      mask = 1 << bit;
      tries += 1;
      if ((D_800C02AE[0x327E + id] & mask) == mask)
      {
        found = bit;
        break;
      }
      base = D_800D0634;
      rec = (u8 *) (base + (id * 0x2C4));
      limit = *((u16 *) (rec + 0x14));
      limit = limit - 1;
    }
    while (((s8) tries) < ((*((u16 *) (rec + 0x14))) - 1));
  }
  if (((s8) found) != (-1))
  {
    *((s16 *) (D_800C35A0 + 0x22)) = (s8) found;
    func_8005946C(arg0, (s16) ((s8) found), bit);
  }
  return 0;
}
