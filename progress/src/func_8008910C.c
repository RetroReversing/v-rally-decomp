extern unsigned short D_800C730C;
extern unsigned short D_800C34F8;
extern int D_800C7824;
extern int D_800B68EC;
s32 alSynSetPan(void *, s32, u8);
s32 alSynSetVol(void *, s32, s16, s32);
extern char gOrderState[];
extern char gStreamState[];

/* Refreshes the synth volume and pan of one voice (arg0 is the voice record, arg1 its index).
 * Volume is the product of the voice's level fields, scaled by the master volume of the voice's
 * bank and clamped to 0x7FFF. Only calls alSynSetVol / alSynSetPan when the value has changed. */
void func_8008910C(void *arg0, s32 arg1)
{
  u32 master;
  u32 level;
  u8 temp_a1_2;
  u8 pan;
  level = ((u32) ((((*((u8 *) (((char *) arg0) + 0xB4))) * (*((u8 *) (((char *) arg0) + 0xBC)))) * (*((u8 *) (((char *) arg0) + 0xB3)))) * (*((s16 *) (((char *) arg0) + 0x96))))) >> 0xD;
  if (level > 0x7FFFU)
  {
    level = 0x7FFF;
  }
  if ((*((u16 *) (((char *) arg0) + 0x9E))) == 0)
  {
    master = D_800C730C; }
  else
  {
    master = D_800C34F8;
  }
  level = (u32) (level * master);
  level = level >> 0xF;
  if ((*((s32 *) (((char *) arg0) + 0xC))) != (-1))
  {
    *((s32 *) (((char *) arg0) + 0x18)) = 0;
  }
  if (level != (*((u16 *) (((char *) arg0) + 0x98))))
  {
    if (D_800B68EC)
    {
      *((u16 *) (((char *) arg0) + 0x98)) = level;
      alSynSetVol(gOrderState + 0x2304, D_800C7824 + (arg1 * 0x1C), (s16) level, 0xF4240 / ((s32) D_800B68EC));
    }
    else
    {
      *((u16 *) (((char *) arg0) + 0x98)) = level;
      alSynSetVol(gOrderState + 0x2304, D_800C7824 + (arg1 * 0x1C), (s16) level, 0xF4240 / ((s32) D_800B68EC));
    }
  }
  pan = *((u8 *) (((char *) arg0) + 0xB5));
  if (pan != (*((u8 *) (((char *) arg0) + 0xB6))))
  {
    if (D_800C730C)
    {
      level = (((s32) (pan * (*((s16 *) (((char *) arg0) + 0xA8))))) >> 7) & 0x7F;
      *((u8 *) (((char *) arg0) + 0xB6)) = level;
      alSynSetPan(gOrderState + 0x2304, D_800C7824 + (arg1 * 0x1C), (u8) level);
    }
    else
    {
      level = (((s32) (pan * (*((s16 *) (((char *) arg0) + 0xA8))))) >> 7) & 0x7F;
      *((u8 *) (((char *) arg0) + 0xB6)) = level;
      alSynSetPan(gOrderState + 0x2304, D_800C7824 + (arg1 * 0x1C), (u8) level);
    }
  }
  level = (u16) level;
}
