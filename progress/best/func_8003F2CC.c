void func_8003F2CC(u8 *arg0)
{
  u8 *temp_a0;
  u8 *temp_v1;
  u8 *tbl;
  s32 n;
  s32 mask;
  mask = 0x180;
  temp_a0 = *((u8 **) ((*((u8 **) (arg0 + 0xA8))) + 0x24));
  if (temp_a0 != NULL)
  {
    *((vs32 *) (arg0 + 0x80)) |= 4;
    if (((*((s32 *) (temp_a0 + 0x14))) & 0x180) == mask)
    {
      temp_v1 = *((u8 **) (temp_a0 + 0x6C));
      n = *((s32 *) (temp_v1 + 8));
      *((vs32 *) (arg0 + 0x80)) &= ~4;
      *((s16 *) (arg0 + 0x7A)) = n + 1;
    }
    tbl = *((u8 **) ((*((u8 **) (arg0 + 0xA4))) + 4));
    mask = (*((s16 *) (arg0 + 0x7A))) * 4;
    *((s16 *) (arg0 + 0x70)) = -((*((u16 *) ((*((u8 **) (tbl + mask))) + 6))) >> 1);
  }
}
