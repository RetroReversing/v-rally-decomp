extern unsigned short D_800C730C;
extern unsigned short D_800C34F8;
extern int D_800C7824;
extern int D_800B68EC;
s32 alSynSetPan(void *, s32, u8);
s32 alSynSetVol(void *, s32, s16, s32);
extern char D_800AE850[];
extern char D_800C02AE[];
void func_8008910C(void *arg0, s32 arg1)
{
  u16 var_v0;
  u32 temp_a1;
  u8 temp_a1_2;
  u8 temp_v1;
  temp_a1 = ((u32) ((((*((u8 *) (((char *) arg0) + 0xB4))) * (*((u8 *) (((char *) arg0) + 0xBC)))) * (*((u8 *) (((char *) arg0) + 0xB3)))) * (*((s16 *) (((char *) arg0) + 0x96))))) >> 0xD;
  if (temp_a1 > 0x7FFFU)
  {
    temp_a1 = 0x7FFF;
  }
  if ((*((u16 *) (((char *) arg0) + 0x9E))) == 0)
  {
    var_v0 = D_800C730C; }
  else
  {
    var_v0 = D_800C34F8;
  }
  temp_a1 = (u32) (var_v0 * temp_a1);
  temp_a1 = temp_a1 >> 0xF;
  if ((*((s32 *) (((char *) arg0) + 0xC))) != (-1))
  {
    *((s32 *) (((char *) arg0) + 0x18)) = 0;
  }
  if (temp_a1 != (*((u16 *) (((char *) arg0) + 0x98))))
  {
    if (D_800B68EC)
    {
      *((u16 *) (((char *) arg0) + 0x98)) = temp_a1;
      alSynSetVol(D_800AE850 + 0x2304, D_800C7824 + (arg1 * 0x1C), (s16) temp_a1, 0xF4240 / ((s32) D_800B68EC));
    }
    else
    {
      *((u16 *) (((char *) arg0) + 0x98)) = temp_a1;
      alSynSetVol(D_800AE850 + 0x2304, D_800C7824 + (arg1 * 0x1C), (s16) temp_a1, 0xF4240 / ((s32) D_800B68EC));
    }
  }
  temp_v1 = *((u8 *) (((char *) arg0) + 0xB5));
  if (temp_v1 != (*((u8 *) (((char *) arg0) + 0xB6))))
  {
    if (D_800C730C)
    {
      temp_a1 = (((s32) (temp_v1 * (*((s16 *) (((char *) arg0) + 0xA8))))) >> 7) & 0x7F;
      *((u8 *) (((char *) arg0) + 0xB6)) = temp_a1;
      alSynSetPan(D_800AE850 + 0x2304, D_800C7824 + (arg1 * 0x1C), (u8) temp_a1);
    }
    else
    {
      temp_a1 = (((s32) (temp_v1 * (*((s16 *) (((char *) arg0) + 0xA8))))) >> 7) & 0x7F;
      *((u8 *) (((char *) arg0) + 0xB6)) = temp_a1;
      alSynSetPan(D_800AE850 + 0x2304, D_800C7824 + (arg1 * 0x1C), (u8) temp_a1);
    }
  }
  temp_a1 = (u16) temp_a1;
}
