extern u8 gOrderState[];
extern s32 gOrderSlot;

/* Flips the 0/1 order slot and copies the entry at the old slot's mirror into the new one. */
void func_80009E7C(void)
{
  s32 *slot;
  s32 v;
  s32 off;
  s32 tmp;
  ((void (*)(void)) (*((void **) (gOrderState + 0x11F4))))();
  slot = &gOrderSlot;
  v = *slot;
  *slot = 1 - v;
  off = gOrderSlot * 4;
  tmp = *((s32 *) ((((u8 *) slot) - (-off)) - 0x10));
  slot -= 2;
  *((s32 *) (((u8 *) slot) + off)) = tmp;
}
