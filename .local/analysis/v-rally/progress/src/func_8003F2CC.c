void func_8003F2CC(void *arg0) {
  u8 *temp_a0;
  u8 *temp_v1;
  s32 n;
  s32 mask;
  temp_v1 = (u8 *) 0x180;
  temp_a0 = *((u8 **) ((*((u8 **) (((u8 *)arg0) + 0xA8))) + 0x24));
  if (temp_a0 != NULL)
  {
    *((vs32 *) (((u8 *)arg0) + 0x80)) |= 4;
    if (((*((s32 *) (temp_a0 + 0x14))) & 0x180) == (s32) temp_v1)
    {
      temp_v1 = *((u8 **) (temp_a0 + 0x6C));
      n = *((s32 *) (temp_v1 + 8));
      *((vs32 *) (((u8 *)arg0) + 0x80)) &= ~4;
      *((s16 *) (((u8 *)arg0) + 0x7A)) = n + 1;
    }
    temp_v1 = *((u8 **) ((*((u8 **) (((u8 *)arg0) + 0xA4))) + 4));
    mask = (*((s16 *) (((u8 *)arg0) + 0x7A))) * 4;
    *((s16 *) (((u8 *)arg0) + 0x70)) = -((*((u16 *) ((*((u8 **) ((s32) mask + (s32) temp_v1))) + 6))) >> 1);
  }
}
