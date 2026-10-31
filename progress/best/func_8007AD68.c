extern void *D_800C3508;
extern void *D_800C35A0;
extern void *D_800A1468;
extern s32 func_800407D0(void);
extern s32 func_800595EC(void *, void *);
extern s32 func_8005A388(s32, s32);
extern s32 func_8006F0E0(u8, void *);
extern s32 func_8007A688(void);
extern s32 D_800A5FB8;
extern s32 D_800A5FC4;
extern s32 D_800A5FD0;
extern s32 func_800635A0;
extern s32 func_80063790;
extern s32 func_8006556C;
extern s32 func_80065860;
extern s32 func_80070C34;
extern s32 func_8007159C;
extern s32 func_8007A29C;
extern s32 func_8007A9A8;
extern s32 func_8007AA94;
s32 func_8007AD68(s32 arg0, s32 arg1)
{
  char *entry;
  s8 temp_v1;
  s8 new_var;
  s32 mode;
  u8 temp_s1;
  *(((s8 *) D_800A1468) + 0x245) = 0;
  func_8007A688();
  entry = ((char *) D_800C35A0) + ((*(((u8 *) (((char *) D_800C35A0) + (*(((s8 *) D_800A1468) + 0x228)))) + 0x32)) * 0x28);
  *((s16 *) (entry + 0x4E)) = (s16) (*(((u8 *) D_800A1468) + 0x237));
  func_8006F0E0(*(((u8 *) D_800A1468) + 0x228), D_800A1468);
  temp_v1 = *(((s8 *) D_800A1468) + 0x228);
  temp_s1 = *(((u8 *) D_800C3508) + 3);
  if (temp_v1 < ((*((u16 *) (((char *) D_800C35A0) + 0xE))) - 1))
  {
    new_var = (s8) (temp_v1 + 1);
    *(((s8 *) D_800A1468) + 0x228) = new_var;
    func_8005A388(arg0, arg1);
    *(((s32 *) D_800A1468) + 0xA2) = (s32) (&func_8007A29C);
    *(((s32 *) D_800A1468) + 0xA3) = (s32) (&func_8007A9A8);
    *(((s32 *) D_800A1468) + 0xA4) = (s32) (&func_8007AA94);
    mode = *((u16 *) (((char *) D_800C35A0) + 0x1E));
    switch (mode)
    {
      case 1:

      case 2:

      case 3:

      case 4:
        *((s32 *) (((char *) (*((void **) (((char *) ((arg1 * 0xC) + (*((s32 *) (((char *) ((temp_s1 * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 8))))) + 4)))) + 0x2C)) = 5;
        break;

      case 0:
        *((s32 *) (((char *) (*((void **) (((char *) ((arg1 * 0xC) + (*((s32 *) (((char *) ((temp_s1 * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 8))))) + 4)))) + 0x2C)) = 5;
        break;

      case 5:
        *((s32 *) (((char *) (*((void **) (((char *) ((arg1 * 0xC) + (*((s32 *) (((char *) ((temp_s1 * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 8))))) + 4)))) + 0x2C)) = 7;
        break;

      default:
        return 0;

    }

  }
  else
  {
    *(((s8 *) D_800A1468) + 0x228) = 0;
    *(((s8 *) D_800A1468) + 0x22B) = -1;
    mode = *((u16 *) (((char *) D_800C35A0) + 0x1E));
    switch (mode)
    {
      case 1:

      case 2:

      case 3:

      case 4:
        *((s32 *) (((char *) (*((void **) (((char *) ((arg1 * 0xC) + (*((s32 *) (((char *) ((temp_s1 * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 8))))) + 4)))) + 0x2C)) = 2;
        *(((s32 *) D_800A1468) + 0xA2) = (s32) (&func_8006556C);
        *(((s32 *) D_800A1468) + 0xA3) = (s32) (&func_80065860);
        break;
        func_800595EC(&D_800A5FC4, D_800A1468);

      case 0:
        *((s32 *) (((char *) (*((void **) (((char *) ((arg1 * 0xC) + (*((s32 *) (((char *) ((temp_s1 * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 8))))) + 4)))) + 0x2C)) = 2;
        func_800595EC(&D_800A5FB8, D_800A1468);
        *(((s32 *) D_800A1468) + 0xA2) = (s32) (&func_800635A0);
        *(((s32 *) D_800A1468) + 0xA3) = (s32) (&func_80063790);
        break;

      case 5:
        if (D_800A1468 || arg1)
      {
        *((s32 *) (((char *) (*((void **) (((char *) ((arg1 * 0xC) + (*((s32 *) (((char *) ((temp_s1 * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 8))))) + 4)))) + 0x2C)) = 3;
        func_800595EC(&D_800A5FD0, D_800A1468);
        *(((s32 *) D_800A1468) + 0xA2) = (s32) (&func_80070C34);
        *(((s32 *) D_800A1468) + 0xA3) = (s32) (&func_8007159C);
        func_800407D0();
        break;
      }
      else
      {
        *((s32 *) (((char *) (*((void **) (((char *) ((arg1 * 0xC) + (*((s32 *) (((char *) ((temp_s1 * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 8))))) + 4)))) + 0x2C)) = 3;
        func_800595EC(&D_800A5FD0, D_800A1468);
        *(((s32 *) D_800A1468) + 0xA2) = (s32) (&func_80070C34);
        *(((s32 *) D_800A1468) + 0xA3) = (s32) (&func_8007159C);
        func_800407D0();
        break;
      }

      default:
        if (1)
      {
        return 0;
      }

    }

  }
  return 0;
}
