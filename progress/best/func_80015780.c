s32 func_800153E4();
s32 func_80022184(void *);
s32 func_800221D4(void *, s32 *);
s32 func_80097E30(void *, s32, s32);
extern s32 D_8009BBA4;
extern s16 D_8009BBB4;
extern s16 D_8009BBB6;
extern s32 *D_8009BBB8;
extern s16 D_8009CEBC;
extern s32 D_8009E250;
extern s32 D_8009E254;
extern s32 D_8009E258;
extern s32 D_8009FF30;
extern f32 D_800A1878;
extern f32 D_800A187C;
extern s32 D_800A1884;
extern s32 D_800A188C;
extern s32 D_800A1894;
extern s32 D_800A189C;
extern s32 D_800A18A4;
extern s32 D_800A18AC;
extern s32 D_800A18B4;
extern s32 D_800A18BC;
extern s32 D_800A18C4;
extern s32 D_800A18C8;
extern f64 D_800A4178;
extern s32 D_800A73E0;
extern s32 D_800AE850;
extern s32 D_800C02AE;
extern s32 func_80015E4C;
extern s32 func_8001B880;
static inline int inline_fn(unsigned short arg0)
{
  return arg0 != 0;
}

void func_80015780(s32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4, s32 arg5)
{
  s32 *temp_v1;
  f64 temp_fs0;
  register int var_v0;
  void *temp_a0;
  void *temp_s0;
  temp_s0 = (char *) (&D_800AE850);
  temp_s0 += (s32) 0x7368;
  if (func_80022184(temp_s0) == 0)
  {
    func_800221D4(temp_s0, &func_8001B880);
    D_8009BBB4 = (s16) arg5;
    *((s32 *) (((char *) (&D_800A73E0)) + 0x6BD0)) = 0x1000;
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BEE)) = arg3;
    func_800153E4();
    temp_a0 = (char *) (&D_800C02AE);
    temp_a0 += (s32) 0x7676;
    {
      struct Copy12
      {
        s32 a;
        s32 b;
        s32 c;
      } __attribute__((packed));
      *((struct Copy12 *) temp_a0) = *((struct Copy12 *) (&D_8009BBA4));
    }
    D_8009CEBC = 4;
    var_v0 = 0xC000;
    if (arg0 == 0)
    {
      if (((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x2C))) & 1) || ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x1E))) == 7))
      {
        *((s8 *) (((char *) (&D_800C02AE)) + 0x7678)) = 0;
        var_v0 = *((u8 *) (((char *) (&D_800A73E0)) + 0x6C02));
        if (inline_fn(var_v0))
        {
          var_v0 = 0x8000;
          goto block_15;
        }
        var_v0 = 0x4000;
        do
        {
          *((s8 *) (((char *) (&D_800C02AE)) + 0x7678)) = 0;
          goto block_15;
        }
        while (0);
      }
      if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE))) == 1)
      {
        *((s8 *) (((char *) (&D_800C02AE)) + 0x7678)) = 0;
        var_v0 = 0x8000;
        if ((*((u8 *) (((char *) (&D_800A73E0)) + 0x6C02))) == 0)
        {
          var_v0 = 0x4000;
        }
        goto block_15;
      }
      *((s8 *) (((char *) (&D_800C02AE)) + 0x7680)) = 1;
      if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE))) == 2)
      {
        *((s8 *) (((char *) (&D_800C02AE)) + 0x767B)) = (s8) (*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x12)));
        if (inline_fn(*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x12))))
        {
          *((s8 *) (((char *) (&D_800C02AE)) + 0x7678)) = 2;
          var_v0 = 0xC000;
          goto block_15;
        }
        *((s8 *) (((char *) (&D_800C02AE)) + 0x7678)) = 1;
        var_v0 = 0xC000;
        *((s16 *) (((char *) (&D_800C02AE)) + 0x767E)) = (float) var_v0;
        *((s16 *) (((char *) (&D_800A73E0)) + 0x6BEE)) = (s16) ((arg3 * 2) / 3);
      }
      else
      {
        *((s8 *) (((char *) (&D_800C02AE)) + 0x7678)) = 3;
        var_v0 = 0xF400;
        goto block_15;
      }
    }
    else
    {
      *((s32 *) (((char *) (&D_800AE850)) + 0x72F4)) = 0;
      *((s8 *) (((char *) (&D_800C02AE)) + 0x7678)) = 0;
      block_15:
      *((s16 *) (((char *) (&D_800C02AE)) + 0x767E)) = var_v0;

    }
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BE6)) = 0xFF;
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BE8)) = 0xFF;
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BEA)) = 0xFF;
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BEC)) = 0xFF;
  }
  D_8009E250 = 2;
  D_8009E254 = 2;
  D_8009FF30 = 0;
  D_8009E258 = 7;
  func_80097E30(((u8 *) (&D_800C02AE)) + 0x5A4A, 0, 0x24);
  {
    struct Copy6
    {
      s32 a;
      s16 b;
    } __attribute__((packed, aligned(2)));
    *((struct Copy6 *) (&D_800A18A4)) = *((struct Copy6 *) (&D_800A1884));
  }
  {
    struct Copy6
    {
      s32 a;
      s16 b;
    } __attribute__((packed, aligned(2)));
    *((struct Copy6 *) (&D_800A18AC)) = *((struct Copy6 *) (&D_800A188C));
  }
  temp_fs0 = D_800A4178;
  temp_v1 = *((s32 **) (((char *) (&D_800C02AE)) + 0x7DA6));
  {
    struct Copy6
    {
      s32 a;
      s16 b;
    } __attribute__((packed, aligned(2)));
    *((struct Copy6 *) (&D_800A18B4)) = *((struct Copy6 *) (&D_800A1894));
  }
  {
    struct Copy6
    {
      s32 a;
      s16 b;
    } __attribute__((packed, aligned(2)));
    *((struct Copy6 *) (&D_800A18BC)) = *((struct Copy6 *) (&D_800A189C));
  }
  *((s16 *) (((char *) (&D_800AE850)) + 0x7300)) = 0;
  *((s32 **) (((char *) (&D_800C02AE)) + 0x7DA6)) = &func_80015E4C;
  *((s32 *) (((char *) (&D_800AE850)) + 0x82AC)) = 0;
  D_8009BBB8 = temp_v1;
  D_800A1878 = __cosf((f32) (((f64) D_800A18C4) * temp_fs0));
  D_800A187C = __cosf((f32) (((f64) D_800A18C8) * temp_fs0));
  D_8009BBB6 = 0xA;
}
