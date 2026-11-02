extern int D_800AE858;
s32 func_80038A8C(s32);
s32 func_8003BE44(void *);
extern s32 D_8009BA30;
extern s32 D_8009D538;
extern void *D_800A0384;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_8003BEBC(void *arg0)
{
  f32 temp_ft0;
  f32 x;
  f32 y;
  s32 var_v0;
  char *new_var;
  u16 temp_v1;
  void *temp_v1_2;
  if (((*((s32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x24))) != 0) && ((*((u8 *) (((char *) D_800A0384) + 0x384))) == 0))
  {
    if (!(D_8009D538 & 2))
    {
      temp_v1 = *((u16 *) (((char *) arg0) + 0x78));
      *((s32 *) (((char *) arg0) + 0x80)) = (s32) ((*((s32 *) (((char *) arg0) + 0x80))) & (~4));
      if (temp_v1 != 0)
      {
        *((u16 *) (((char *) arg0) + 0x78)) = (u16) (temp_v1 - 1);
        *((s32 *) (((char *) arg0) + 0x80)) = (s32) ((*((s32 *) (((char *) arg0) + 0x80))) | 4);
        if ((*((u16 *) (((char *) arg0) + 0x78))) == 0)
        {
          if (D_800AE858 == 0)
          {
            func_80038A8C(((*((u8 *) (((char *) arg0) + 0x7B))) + 7) & 0xFF);
            D_800AE858 = 4;
            D_8009BA30 = 0;
          }
          var_v0 = (*((s32 *) (((char *) arg0) + 0x80))) & (~4);
          goto block_20;
        }
      }
      else
      {
        if ((*((s16 *) (((char *) arg0) + 0x7A))) == 3)
        {
          *((u16 *) (((char *) arg0) + 0x98)) -= 0x20;
        }
        else
        {
          *((u16 *) (((char *) arg0) + 0x98)) = (*((u16 *) (((char *) arg0) + 0x98))) + 0x20;
        }
        *((u8 *) (((char *) arg0) + 0x93)) = (u8) ((*((u8 *) (((char *) arg0) + 0x93))) - 4);
        if ((*((s16 *) (((char *) arg0) + 0x7A))) == 3)
        {
          if (((s16) (*((u16 *) (((char *) arg0) + 0x98)))) < 0x201)
          {
            func_8003BE44(arg0);
          }
        }
        else
          if (((s16) (*((u16 *) (((char *) arg0) + 0x98)))) >= 0x400)
        {
          func_8003BE44(arg0);
          if ((*((s16 *) (((char *) arg0) + 0x7A))) == 3)
          {
            *((u16 *) (((char *) arg0) + 0x98)) = 0x400;
          }
          else
          {
            *((u16 *) (((char *) arg0) + 0x98)) = 0x100;
          }
        }
        temp_ft0 = 1024.0f;
        temp_ft0 = temp_ft0 / ((f32) ((s16) (*((u16 *) (((char *) arg0) + 0x98)))));
        temp_v1_2 = *(*((void ***) (((char *) (*((void **) (((char *) arg0) + 0xA4)))) + 4)));
        {
        f32 w = (f32) (*((u16 *) (((char *) temp_v1_2) + 6)));
        x = temp_ft0 * w;
        }
        y = (f32) (*((u16 *) (((char *) temp_v1_2) + 8)));
        temp_ft0 = temp_ft0 * y;
        x *= 0.5f;
        temp_ft0 *= 0.5f;
        y = temp_ft0;
        *((u16 *) (((char *) arg0) + 0x9A)) = *((volatile s16 *) (((char *) arg0) + 0x98));
        *((s16 *) (((char *) arg0) + 0x70)) = -x;
        *((s16 *) (((char *) arg0) + 0x72)) = -y;
      }
    }
  }
  else
  {
    var_v0 = (*((s32 *) (((char *) arg0) + 0x80))) | 4;
    block_20:
    *((s32 *) (((char *) arg0) + 0x80)) = var_v0;

  }
}
