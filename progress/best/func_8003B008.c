extern char D_800AE850[];
extern char D_800C02AE[];
static inline static static s32 inline_fn(void *arg0)
{
  return *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x6C)))) + 8));
}

void func_8003B008(void *arg0)
{
  void *temp_v1;
  void *var_a1;
  void *temp_v0;
  char *new_var2;
  s32 a2;
  char *new_var;
  if ((*((u16 *) (((char *) (*((void **) (D_800C02AE - (-0x32F2))))) + 0x1E))) == 0)
  {
    temp_v1 = *((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x24));
    var_a1 = (void *) temp_v1;
    goto block_7;
  }
  var_a1 = *(*((void ***) (D_800AE850 + 0x73F0)));
  if (var_a1 != NULL)
  {
    a2 = *((u16 *) (((char *) arg0) + 0x76));
    loop_4:
    temp_v1 = *((void **) (((char *) var_a1) + 0x6C));

    if ((a2 != (*((s32 *) (((char *) temp_v1) + 8)))) || ((*((s32 *) (((char *) temp_v1) + 0x20))) != 0))
    {
      var_a1 = *((void **) (((char *) var_a1) + 4));
      if (var_a1 != NULL)
      {
        goto loop_4;
      }
    }
    block_7:
    if (var_a1 != NULL)
    {
      *((s32 *) (((char *) arg0) + 0x80)) |= 4;
      if ((*((s32 *) (((char *) (*((void **) (((char *) var_a1) + 0x6C)))) + 0xC))) != 0)
      {
        temp_v0 = *((void **) (D_800C02AE + 0x32F2));
        *((s16 *) (((char *) arg0) + 0x7A)) = 0xB;
        if ((*((u16 *) (((char *) temp_v0) + 0x1E))) == 0)
        {
          if ((*((s32 *) (((char *) (*((void **) (((char *) var_a1) + 0x6C)))) + 0xC))) < 0)
          {
            *((u8 *) (((char *) arg0) + 0x90)) = 0xFA;
            *((s8 *) (((char *) arg0) + 0x91)) = 0x32;
            new_var = (char *) arg0;
            *((s8 *) (new_var + 0x92)) = 0xA;
            *((s16 *) (((char *) arg0) + 0x7A)) = 0xB;
          }
          else
          {
            *((s16 *) (((char *) arg0) + 0x7A)) = (*((s8 *) (((char *) arg0) + 0x92)) = 0xA);
            *((u8 *) (((char *) arg0) + 0x91)) = 0xC8;
          }
          *((u8 *) (((char *) arg0) + 0x92)) = 0xFF;
          *((u8 *) (((char *) arg0) + 0x90)) = 0xA;
          goto block_17;
        }
        if ((*((s32 *) (((char *) (*((void **) (((char *) var_a1) + 0x6C)))) + 0x20))) == 0)
        {
          var_a1 = *((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x24));
          if (inline_fn(var_a1) == (*((u16 *) (((char *) arg0) + 0x76))))
          {
            *((u8 *) (((char *) arg0) + 0x90)) = 0xFE;
            *((u8 *) (((char *) arg0) + 0x91)) = 0xD5;
            *((s8 *) (((char *) arg0) + 0x92)) = 0x1E;
          }
          else
          {
            *((u8 *) (((char *) arg0) + 0x90)) = 0xFF;
            *((u8 *) (((char *) arg0) + 0x91)) = 0xFF;
            *((u8 *) (((char *) arg0) + 0x92)) = 0xFF;
          }
          block_17:
          *((u8 *) (((char *) arg0) + 0x93)) = 0xFF;

        }
        new_var2 = D_800C02AE + 0x32F2;
        if (((*((u16 *) (((char *) (*((void **) new_var2))) + 0x1E))) != 0) || ((*(*((s32 **) (((char *) var_a1) + 0x70)))) >= 2))
        {
          *((s32 *) (((char *) arg0) + 0x80)) &= ~4;
        }
      }
    }

  }
}
