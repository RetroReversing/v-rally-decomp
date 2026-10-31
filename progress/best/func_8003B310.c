s32 func_8003AC30();
extern s32 D_8009D538;
extern u8 D_8009FE24[];
extern char D_800AE850[];
extern char D_800C02AE[];
void func_8003B310(void *arg0)
{
  s32 temp_v1;
  s32 var_a1;
  void *var_s0;
  void *var_s1;
  var_s0 = arg0;
  if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E))) == 0)
  {
    var_s1 = *((void **) (((char *) (*((void **) (((char *) var_s0) + 0xA8)))) + 0x24));
    if ((*(*((s32 **) (((char *) var_s1) + 0x70)))) == 1)
    {
      var_s1 = NULL;
      *((s32 *) (((char *) var_s0) + 0x80)) = (s32) ((*((s32 *) (((char *) var_s0) + 0x80))) | 4);
    }
    goto block_7;
  }
  var_s1 = *(*((void ***) (D_800AE850 + 0x73F0)));
  if (var_s1 != NULL)
  {
    do
    {
      loop_5:
      if ((*((u16 *) (((char *) var_s0) + 0x76))) != (*((s32 *) (((char *) (*((void **) (((char *) var_s1) + 0x6C)))) + 8))))
      {
        var_s1 = *((void **) (((char *) var_s1) + 4));
        if (var_s1 != NULL)
        {
          goto loop_5;
        }
      }

    }
    while (0);
    block_7:
    if (var_s1 != NULL)
    {
      var_a1 = *((s32 *) (((char *) (*((void **) (((char *) var_s1) + 0x6C)))) + 0xC));
      if (((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E))) == 0) && (var_a1 & 0xFF000000))
      {
        var_a1 = -var_a1;
      }
      if ((*((u16 *) (((char *) var_s0) + 0x78))) == 0)
      {
        u32 digit;
        func_8003AC30(var_a1, &D_8009FE24);
        digit = D_8009FE24[*((u16 *) (((char *) var_s0) + 0x78))];
        *((s32 *) (((char *) var_s0) + 0x80)) = (s32) ((*((s32 *) (((char *) var_s0) + 0x80))) & (~4));
        *((u8 *) (((char *) var_s0) + 0x94)) = 0U;
        *((s16 *) (((char *) var_s0) + 0x7A)) = digit - 0x30;
      }
      else
      {
        u32 digitIndex;
        *((s32 *) (((char *) var_s0) + 0x80)) = (s32) ((*((s32 *) (((char *) var_s0) + 0x80))) & (~4));
        if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E))) == 0)
        {
          if (((u32) (var_a1 - 0x7531)) < 0x752FU)
          {
            *((u8 *) (((char *) var_s0) + 0x94)) = 1U;
          }
          else
          {
            *((u8 *) (((char *) var_s0) + 0x94)) = 0U;
          }
          digitIndex = *((u16 *) (((char *) var_s0) + 0x78));
        }
        else
        {
          digitIndex = *((u16 *) (((char *) var_s0) + 0x78));
          *((u8 *) (((char *) var_s0) + 0x94)) = 0U;
        }
        *((s16 *) (((char *) var_s0) + 0x7A)) = D_8009FE24[digitIndex] - 0x30;
      }
      if (var_s1 != NULL)
      {
        temp_v1 = *((s32 *) (((char *) (*((void **) (((char *) var_s1) + 0x6C)))) + 0xC));
        if (temp_v1 != 0)
        {
          if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E))) == 0)
          {
            if (temp_v1 > 0)
            {
              *((u8 *) (((char *) var_s0) + 0x91)) = 0xC8;
              *((s8 *) (((char *) var_s0) + 0x90)) = 0xA;
              *((s8 *) (((char *) var_s0) + 0x92)) = 0xA;
              *((u8 *) (((char *) var_s0) + 0x93)) = 0xFF;
              if (!(D_8009D538 & 2))
              {
                *((u8 *) (((char *) var_s0) + 0x94)) = (u8) ((*((u8 *) (((char *) var_s0) + 0x94))) - 1);
              }
            }
            else
            {
              *((u8 *) (((char *) var_s0) + 0x90)) = 0xFA;
              *((s8 *) (((char *) var_s0) + 0x91)) = 0x32;
              var_a1 = 0xA;
              *((s8 *) (((char *) var_s0) + 0x92)) = var_a1;
              goto block_32;
            }
          }
          else
          {
            goto block_28;
          }
        }
        else
        {
          block_28:
          if ((*((s32 *) (((char *) (*((void **) (((char *) var_s1) + 0x6C)))) + 0x20))) == 0)
          {
            var_s1 = *((void **) (((char *) (*((void **) (((char *) var_s0) + 0xA8)))) + 0x24));
            if ((*((s32 *) (((char *) (*((void **) (((char *) var_s1) + 0x6C)))) + 8))) == (*((u16 *) (((char *) var_s0) + 0x76))))
            {
              *((u8 *) (((char *) var_s0) + 0x90)) = 0xFE;
              *((u8 *) (((char *) var_s0) + 0x91)) = 0xD5;
              *((s8 *) (((char *) var_s0) + 0x92)) = 0x1E;
            }
            else
            {
              *((u8 *) (((char *) var_s0) + 0x90)) = 0xFF;
              *((u8 *) (((char *) var_s0) + 0x91)) = 0xFF;
              *((u8 *) (((char *) var_s0) + 0x92)) = 0xFF;
            }
            block_32:
            *((u8 *) (((char *) var_s0) + 0x93)) = 0xFF;

          }

        }
      }
    }

  }
}
