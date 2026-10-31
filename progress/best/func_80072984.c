extern unsigned char D_800B6819;
extern int D_800C35A0;
void *func_800592D0();
s32 func_80059618();
s32 func_800596F4();
s32 func_80099DF8();
extern s32 D_800A1468;
extern char D_800A5D30[];
extern char D_800A5D38[];
extern char D_800A5D40[];
extern char D_800AE850[];
extern char D_800C02AE[];
void func_80072984(void)
{
  char sp18[44];
  s32 sp4C;
  u32 sp54;
  s32 sp5C;
  s32 temp_fp;
  s32 temp_s2;
  s32 var_s0;
  s32 var_s2;
  s32 var_s2_2;
  u8 var_s3;
  u8 var_s4;
  u32 temp_s0;
  s32 savedp;
  s32 root;
  s32 index;
  s32 offset;
  void *temp_s1;
  void *temp_s7;
  temp_fp = D_800A1468 + 0x24F;
  if (D_800B6819 != 0)
  {
    var_s0 = 4;
    var_s2 = 8;
  }
  else
  {
    var_s0 = 8;
    var_s2 = 0;
  }
  temp_s1 = func_800592D0(0);
  temp_s7 = func_800592D0(1);
  var_s4 = 0;
  temp_s0 = var_s0 & 0xFF;
  sp54 = temp_s0;
  sp5C = temp_s0 != 0;
  sp4C = var_s2 & 0xFF;
  do
  {
    var_s2_2 = var_s4;
    var_s0 = temp_fp + var_s2_2;
    func_80099DF8(&sp18, &D_800A5D30, *((u16 *) ((D_800AE850 + 0x7DB2) + (var_s2_2 * 4))));
    func_80059618(temp_s1, 0xFFU, 0xFFU, 0x40U, (s32) (*((u8 *) (((char *) temp_s1) + 0xE))));
    func_800596F4(temp_s7, *((s16 *) (((char *) temp_s7) + 6)), (s16) ((*((u16 *) (((char *) temp_s7) + 8))) + ((*((u8 *) (((char *) var_s0) + 1))) << 5)), &sp18);
    root = D_800C35A0;
    index = *((u8 *) (((char *) (root + var_s2_2)) + 0x32));
    offset = index * 0x28;
    offset += 0x44;
    func_80099DF8(&sp18, &D_800A5D38, (*((u8 *) (((char *) var_s0) + 1))) + 1, root + offset);
    func_800596F4(temp_s1, *((s16 *) (((char *) temp_s1) + 6)), (s16) ((*((u16 *) (((char *) temp_s1) + 8))) + ((*((u8 *) (((char *) var_s0) + 1))) << 5)), &sp18);
    var_s3 = 0;
    if (sp5C != 0)
    {
      temp_s2 = var_s2_2;
      savedp = var_s0;
      do
      {
        var_s2_2 = var_s3 & 0xFF;
        if ((*((u16 *) (((sp4C + var_s2_2) * 2) + (D_800AE850 + 0x7DC0)))) != 0)
        {
          func_80099DF8(&sp18, &D_800A5D40, (u16) (*((u8 *) (((char *) (((var_s2_2 * 4) + temp_fp) + temp_s2)) + 9))));
          func_80059618(temp_s1, *((u8 *) (((char *) temp_s1) + 0xB)), *((u8 *) (((char *) temp_s1) + 0xC)), *((u8 *) (((char *) temp_s1) + 0xD)), (s32) (*((u8 *) (((char *) temp_s1) + 0xE))));
          func_800596F4(temp_s1, (s16) ((((u16) (*((s16 *) (((char *) temp_s1) + 6)))) + (var_s2_2 * 0x2A)) + 0x44), (s16) ((*((u16 *) (((char *) temp_s1) + 8))) + ((*((u8 *) (((char *) savedp) + 1))) << 5)), &sp18);
        }
        var_s3 += 1;
      }
      while (((u32) (var_s3 & 0xFF)) < sp54);
    }
    var_s4 += 1;
  }
  while (((u32) (var_s4 & 0xFF)) < 4U);
}
