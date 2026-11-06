extern s32 D_800A5E24;
s32 func_800056FC(s32);
void *func_80006008(s32);
s32 func_80006014(s32, s32);
s32 func_800061FC(s32, s32);
void func_8000C22C(void *, s32, s32, s32, u8);
s32 func_8000C244();
s32 func_8000C9B0(void *, void *, u8, f32, u8);
u16 func_8000CC04(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
s32 func_8001BD1C();
s32 *func_80057918(s32, s32);
s32 func_80073108(s32, s16, s32, s32, s32);
s32 func_80073320(s32, s32, s32, s32, s32);
s32 func_80073B64(void *, s32);
s32 func_80074BF8(void *, s32);
s32 func_800754D4(void *, s32);
s32 func_80084BF0(s32);
s32 func_80085778(s32, s32);
s32 guMtxF2L(s32 *, s32);
s32 guMtxIdent(void *);
void guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
extern s32 D_8009D538;
extern u32 D_800A1740;
extern u8 D_800A17E8;
extern s32 D_800A5E1C;
extern char D_800AE850[];
extern char D_800C02AE[];
static __inline__ char *read_config(void)
{
  return *((char **) (D_800C02AE + 0x32F2));
}

static __inline__ s32 read_handle(void)
{
  return *((s32 *) (D_800C02AE + 0x807A));
}

void func_80076060(void *arg0)
{
 u16 saved_field;
 void * context_flag;
 s32 first_dl;
 s16 padding;
 s16 coordinate;
  s32 draw_one;
  f32 sp28[16];
  s32 *var_v0_5;
  s16 temp_s0_12;
  s16 temp_s0_13;
  s16 temp_s0_14;
  s16 temp_s0_15;
  s16 temp_s0_9;
  s16 var_a2_3;
  s16 var_a3;
  s16 var_a3_2;
  s16 var_a3_4;
  s16 var_s6;
  s16 fixed_draw_y;
  s32 temp_s0_10;
  s32 temp_s0_11;
  s32 temp_s0_2;
  s32 temp_s0_5;
  s32 temp_s0_8;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 temp_v0;
  s32 temp_v0_2;
  u16 var_a1;
  s32 var_a1_2;
  s32 var_a2;
  s32 var_a2_2;
  s16 var_a3_3;
  s16 var_a3_5;
  s32 var_s0;
  s32 var_s0_2;
  s32 var_v0;
  s32 var_v0_2;
  s8 var_v0_3;
  s8 var_v0_4;
  u16 temp_s1;
  u16 temp_s1_2;
  u16 temp_v0_4;
  u16 temp_v0_5;
  s32 temp_v0_6;
  u16 temp_v0_7;
  void *temp_s0;
  void *temp_s0_3;
  void *temp_s0_4;
  void *temp_s0_6;
  void *temp_s0_7;
  void *temp_s1_3;
  void *temp_s2;
  void *temp_s5;
  void *temp_v0_3;
  void *var_a0;
  void *var_a0_2;
  void *var_a0_3;
  temp_v0 = ((u32) D_800A1740) < 5U;
  D_800A1740 += 1;
  if (temp_v0 == 0)
  {
    temp_s0 = D_800C02AE + 0x80D2;
    guMtxIdent(temp_s0);
    temp_v0_2 = func_800056FC(*((s32 *) (((char *) (*((char **) (D_800C02AE + 0x7CD6)))) + 0x178)));
    temp_v0_3 = func_80006008(temp_v0_2);
    *((s32 *) (((char *) temp_v0_3) + 0x0)) = 0xDA380003;
    *((s32 *) (((char *) temp_v0_3) + 0x4)) = temp_s0;
    func_80006014(temp_v0_2, temp_v0_3 + 8);
    temp_s0_2 = func_8001BD1C();
    guOrthoF(&sp28, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
    guMtxF2L(&sp28, temp_s0_2);
    func_800061FC(temp_v0_2, temp_s0_2);
    func_8000C22C((void *)(*((s32 *) (((char *) arg0) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    if (D_8009D538 & 1)
    {
      if ((*((s32 *) (((char *) arg0) + 0x3C))) == 2)
      {
        D_8009D538 &= ~1;
      }
      var_s0 = func_80084BF0(0);
      func_80085778(0, var_s0);
      if ((*((u16 *) (((char *) read_config()) + 0xE))) == 2)
      {
        var_s0 |= func_80084BF0(1);
        func_80085778(1, func_80084BF0(1));
      }
      temp_v0_4 = *((u16 *) (((char *) read_config()) + 0x1E));
      if ((temp_v0_4 != 0) & (temp_v0_4 < 5U))
      {
        if ((*((s32 *) (D_800AE850 + 0x8030))) == 2)
        {
          if ((*((s32 *) (((char *) arg0) + 0x48))) != 0)
          {
            var_s0 = 0x1000;
          }
        }
      }
      var_v0_2 = var_s0 & 0x8000;
      if (var_s0 & 0x1000)
      {
        if ((*((s32 *) (((char *) arg0) + 0x48))) != 0)
        {
          if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
          {
            *((u8 *) (D_800C02AE + 0x8076)) = 1;
          }
          else
          {
            *((u8 *) (D_800C02AE + 0x8076)) = 3;
          }
          *((s32 *) (((char *) arg0) + 0x48)) = 0;
        }
        else
        {
          temp_v0_5 = *((u16 *) (((char *) read_config()) + 0x1E));
          if ((((temp_v0_5 == 0) | (temp_v0_5 >= 5U)) != 0) || ((*((s32 *) (D_800AE850 + 0x8030))) != 2))
          {
            if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
            {
              *((u8 *) (D_800C02AE + 0x8076)) = 1;
            }
            else
            {
              if (func_80084BF0(0) & 0x1000)
              {
                *((u8 *) (D_800C02AE + 0x8076)) = 1;
              }
              if (func_80084BF0(1) & 0x1000)
              {
                *((u8 *) (D_800C02AE + 0x8076)) = 2;
              }
            }
          }
        }
        *((s32 *) (((char *) arg0) + 0x3C)) = 1;
      }
      if ((var_s0 & 0x8000) || (D_800A1740 == 0x1D4C))
      {
        func_80085778(0, var_s0);
        *((s32 *) (((char *) arg0) + 0x3C)) = 2;
      }
    }
    if ((*((s32 *) (((char *) arg0) + 0x3C))) == 0)
    {
      temp_v0_6 = *((u16 *) (((char *) read_config()) + 0x1E));
      switch (temp_v0_6)
      {
        case 0:
          if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
        {
          func_80074BF8(arg0, temp_v0_2);
        }
        else
        {
          func_800754D4(arg0, temp_v0_2);
        }
          break;

        case 1:

        case 2:

        case 3:

        case 4:

        case 5:
          func_80073B64(arg0, temp_v0_2);
          break;

      }

    }
    else
    {
      if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
      {
        if ((((u32) (*((s32 *) (D_800AE850 + 0x121C)))) >> 3) & 1)
        {
          func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), temp_v0_2, 0x104, 5, func_80057918(read_handle(), 0xC1), 1);
          func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), temp_v0_2, 0x113, 0xF, read_config() + (((*((u8 *) (((char *) read_config()) + 0x32))) * 0x28) + 0x44), 1);
        }
      }
      else
        if ((((u32) (*((s32 *) (D_800AE850 + 0x121C)))) >> 3) & 1)
      {
        coordinate = 0x1E;
        if ((*((u16 *) (((char *) read_config()) + 0x12))) == 1)
        {
          coordinate = 0x118;
          var_s6 = 5;
          if (((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((*((u16 *) (((char *) read_config()) + 0x1A))) == 1))
          {
            temp_s0_3 = arg0 + 0x40;
            func_8000CC04((void *)(temp_s0_3), (void *)(temp_v0_2), (s16)(-0x118), (s16)(5), (void *)(func_80057918(read_handle(), 0xC1)), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
            var_v0_5 = func_80057918(read_handle(), 0xD2);
            func_8000CC04((void *)(temp_s0_3), (void *)(temp_v0_2), (s16)(-0x118), (s16)(0xF), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          }
          else
            {
            var_v0_5 = func_80057918(read_handle(), 0xC1);
if (var_v0_5){
            context_flag = (void *)(arg0 + 0x40);}else{
            context_flag = (void *)(arg0 + 0x40);}
            var_a0_2 = ((void *)context_flag); first_dl=temp_v0_2;
            {s32 x;void *secondctx;s32 seconddl,secondx;s16 secondy;x=(s32)coordinate;x=-(s16)x;func_8000CC04((void *)(var_a0_2),(void *)(first_dl),(s16)(x),(s16)(var_s6),(void *)(var_v0_5),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));secondctx=((void *)context_flag);seconddl=temp_v0_2;secondx=x;secondy=var_s6+10;func_8000CC04((void *)(secondctx),(void *)(seconddl),(s16)(secondx),(s16)(secondy),(void *)(read_config()+((*((u8 *)(read_config()+0x32)))*40+0x44)),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));}
          }
        }
        else
          if (var_s6 = 5, ((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((temp_s1 = *((u16 *) (((char *) read_config()) + 0x1A)), temp_s1 == 1)))
        {
          temp_s0_4 = arg0 + 0x40;
          func_8000CC04((void *)(temp_s0_4), (void *)(temp_v0_2), (s16)(0x1E), (s16)(5), (void *)(func_80057918(read_handle(), 0xC1)), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          var_v0_5 = func_80057918(read_handle(), 0xD2);
          func_8000CC04((void *)(temp_s0_4), (void *)(temp_v0_2), (s16)(0x1E), (s16)(0xF), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
        }
        else
        {
          var_v0_5 = func_80057918(read_handle(), 0xC1);
if (var_v0_5){
          context_flag = (void *)(arg0 + 0x40);}else{
          context_flag = (void *)(arg0 + 0x40);}
          var_a0_2 = ((void *)context_flag); first_dl=temp_v0_2;
          {s32 x;void *secondctx;s32 seconddl,secondx;s16 secondy;x=(s32)coordinate;x=(s16)x;func_8000CC04((void *)(var_a0_2),(void *)(first_dl),(s16)(x),(s16)(var_s6),(void *)(var_v0_5),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));secondctx=((void *)context_flag);seconddl=temp_v0_2;secondx=x;secondy=var_s6+10;func_8000CC04((void *)(secondctx),(void *)(seconddl),(s16)(secondx),(s16)(secondy),(void *)(read_config()+((*((u8 *)(read_config()+0x32)))*40+0x44)),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));}
        }
        context_flag = (void *)(1);
        coordinate = 0x128;
        if ((*((u16 *) (((char *) read_config()) + 0x12))) == ((s32)context_flag))
        {
          coordinate = 0x118;
          var_s6 = 0x7D;
          if (((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((*((u16 *) (((char *) read_config()) + 0x1A))) == ((s32)context_flag)))
          {
            temp_s0_6 = arg0 + 0x40;
            func_8000CC04((void *)(temp_s0_6), (void *)(temp_v0_2), (s16)(-0x118), (s16)(0x7D), (void *)(func_80057918(read_handle(), 0xC1)), (u8)(((s32)context_flag)), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(((s32)context_flag)));
            var_v0_5 = func_80057918(read_handle(), 0xD2);
            func_8000CC04((void *)(temp_s0_6), (void *)(temp_v0_2), (s16)(-0x118), (s16)(0x87), (void *)(var_v0_5), (u8)(((s32)context_flag)), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(((s32)context_flag)));
          }
          else
          {
            goto block_60;
          }
        }
        else
        {
          var_s6 = 5;
          if (((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((temp_s1_2 = *((u16 *) (((char *) read_config()) + 0x1A)), temp_s1_2 == ((s32)context_flag))))
          {
saved_field=temp_s1_2;
            temp_s0_7 = arg0 + 0x40;
            func_8000CC04((void *)(temp_s0_7), (void *)(temp_v0_2), (s16)(-0x128), (s16)(5), (void *)(func_80057918(read_handle(), 0xC1)), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
            var_v0_5 = func_80057918(read_handle(), 0xD2);
            func_8000CC04((void *)(temp_s0_7), (void *)(temp_v0_2), (s16)(-0x128), (s16)(0xF), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          }
          else
          {
            block_60:
            var_v0_5 = func_80057918(read_handle(), 0xC1);

            temp_s2 = arg0 + 0x40;
            temp_s0_8 = ((s32) (-(((s32)coordinate) << 0x10))) >> 0x10;
            func_8000CC04((void *)(temp_s2), (void *)(temp_v0_2), (s16)(temp_s0_8), (s16)(var_s6), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
            var_a0_3 = temp_s2;
            var_a2_2 = temp_s0_8;
            var_a3_2 = var_s6 + 0xA;
            ;
            func_8000CC04((void *)(var_a0_3), (void *)(temp_v0_2), (s16)(var_a2_2), (s16)(var_a3_2), (void *)((s32 *) (read_config() + (((*((u8 *) (read_config() + 0x33))) * 40) + 0x44))), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          }
        }
      }
      temp_v0_7 = *((u16 *) (((char *) read_config()) + 0x1E));
      if (((temp_v0_7 != 0) & (temp_v0_7 < 5U)) && ((*((s32 *) (D_800AE850 + 0x8030))) == 2))
      {
        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
        {
          var_a3_3 = (D_800A17E8 + func_8000C9B0((void *)(arg0 + 0x40), (void *)(func_80057918(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0xF;
        }
        else
        {
          var_a3_3 = (D_800A17E8 + func_8000C9B0((void *)(arg0 + 0x40), (void *)(func_80057918(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0x23;
        }
        coordinate = 0x140 - var_a3_3;
        var_s6 = 0xDC;
        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 2)
        {
          var_a1 = ((s16)coordinate) & 0xFFFF;
          var_a3_3 -= 0x23;
          func_80073320(temp_v0_2, var_a1, var_s6, var_a3_3 & 0xFFFF, 0x11);
        }
        else
        {
          var_a1 = ((s16)coordinate) & 0xFFFF;
          func_80073320(temp_v0_2, var_a1, var_s6, var_a3_3 & 0xFFFF, 0x11);
        }
        var_s6 -= 2;
        func_80073108(temp_v0_2, ((s16)coordinate), (s16) var_s6, *((s32 *) (D_800C02AE + 0x103B6)), 0);
        var_s6 += 2;
        temp_s0_9 = ((s16)coordinate) + D_800A17E8;
        var_v0_5 = func_80057918(read_handle(), 0xD7);
        var_a2_3 = temp_s0_9;
        var_a3_4 = var_s6;
        func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), temp_v0_2, var_a2_3, var_a3_4, var_v0_5, 1);
      }
      else
      {

        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
        {
          temp_s0_10 = func_8000C9B0((void *)(arg0 + 0x40), (void *)(&D_800A5E1C), (u8)(1), (f32)(1.0f), (u8)(1));
          temp_s2_2 = func_8000C9B0((void *)(arg0 + 0x40), (void *)(func_80057918(read_handle(), 0xE2)), (u8)(1), (f32)(1.0f), (u8)(1));
          var_a3_5 = ((D_800A17E8 + (((D_800A17E8 + temp_s0_10) + (D_800A17E8 + 5)) + temp_s2_2)) + func_8000C9B0((void *)(arg0 + 0x40), (void *)(func_80057918(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0xF;
        }
        else
        {
          temp_s0_11 = func_8000C9B0((void *)(arg0 + 0x40), (void *)(&D_800A5E1C), (u8)(1), (f32)(1.0f), (u8)(1));
          temp_s2_3 = func_8000C9B0((void *)(arg0 + 0x40), (void *)(func_80057918(read_handle(), 0xE2)), (u8)(1), (f32)(1.0f), (u8)(1));
          var_a3_5 = ((D_800A17E8 + (((D_800A17E8 + temp_s0_11) + (D_800A17E8 + 5)) + temp_s2_3)) + func_8000C9B0((void *)(arg0 + 0x40), (void *)(func_80057918(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0x19;
        }
        coordinate = 0x140 - var_a3_5;
        var_s6 = 0xDC;
        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 2)
        {
          var_a3_5 -= 0x23;
          var_a1_2 = ((u16)coordinate) & 0xFFFF;
          func_80073320(temp_v0_2, var_a1_2, var_s6, var_a3_5 & 0xFFFF, 0x11);
        }
        else
        {
          var_a1_2 = ((u16)coordinate) & 0xFFFF;
          func_80073320(temp_v0_2, var_a1_2, var_s6, var_a3_5 & 0xFFFF, 0x11);
        }
        func_80073108(temp_v0_2, ((u16)coordinate), var_s6, *((s32 *) (D_800C02AE + 0x103B6)), 3);
        padding=D_800A17E8;
        var_s6+=2;
        coordinate = (s16)(((u16)coordinate)+padding);
        if ((*((s32 *) (D_800C02AE + 0x32AA))) == 3)
        {
          func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), temp_v0_2, ((s16)coordinate), (s16) var_s6, &D_800A5E24, 1);
        }
        else
        {
          func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), temp_v0_2, ((s16)coordinate), var_s6, &D_800A5E1C, 1);
        }
        temp_s5 = arg0 + 0x40;
        temp_s0_12 = ((s16)coordinate) + func_8000C9B0((void *)(temp_s5), (void *)(&D_800A5E1C), (u8)(1), (f32)(1.0f), (u8)(1));
        var_s6 -= 2;
        fixed_draw_y = var_s6;
        func_80073108(temp_v0_2, temp_s0_12, fixed_draw_y, *((s32 *) (D_800C02AE + 0x103B6)), 2);
        temp_s0_13 = temp_s0_12 + D_800A17E8;
        var_s6 += 2;
        func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), temp_v0_2, temp_s0_13, (s16) var_s6, func_80057918(read_handle(), 0xD3), 1);
        temp_s0_14 = temp_s0_13 + func_8000C9B0((void *)(temp_s5), (void *)(func_80057918(read_handle(), 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
        func_80073108(temp_v0_2, temp_s0_14, fixed_draw_y, *((s32 *) (D_800C02AE + 0x103B6)), 0);
        temp_s0_15 = temp_s0_14 + D_800A17E8;
        var_v0_5 = func_80057918(read_handle(), 0xD7);
        var_a2_3 = temp_s0_15;
        var_a3_4 = var_s6;
        func_8000C244(*((s32 *) (((char *) arg0) + 0x40)), temp_v0_2, var_a2_3, var_a3_4, var_v0_5, 1);
      }
    }
  }
}

