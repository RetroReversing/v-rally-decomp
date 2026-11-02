extern s32 D_800AE850;
extern s32 D_800C02AE;
s32 func_80049DB0(void)
{
  u8 *root = *(*((u8 ***) (((u8 *) (&D_800AE850)) + 0x73F0)));
  u8 *game = *((u8 **) (((u8 *) (&D_800C02AE)) + 0x32F2));
  s32 p = (s32) *((s32 **) ((*((u8 **) (root + 0x6C))) + 0x24));
  
  s32 value;
  if ((*((u16 *) (game + 0xE))) == 2)
  {
    root = *((u8 **) (root + 4));
    if ((*((u16 *) (game + 0x1A))) == 1)
    {
      root = *((u8 **) (root + 4));
    }
    game = root;
    p=*(s32*)p;
    root = (u8*) *((s32 **) ((*((u8 **) (game + 0x6C))) + 0x24));
    if (p != 0x3A98)
    {
      return 1;
    }
    value = *(s32*)root ^ 0x3A98;
    goto done;
  }
  p=(s32)((u32)p ^(u32)root); p=(s32)((u32)p ^(u32)root);
  p=(s32)((u32)p ^(u32)root); p=(s32)((u32)p ^(u32)root);
  value=*(s32*)p;
  value = value ^ 0x3A98;
  done:
  return value != 0;

}
