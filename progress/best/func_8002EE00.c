void *func_80006008();
s32 func_80006014();
s32 func_800061FC();
s32 func_800075BC();
s32 func_80010BFC();
s32 func_80019C90();
s32 func_8001BD1C();
s32 guMtxIdentF();
extern char D_8009EAB0[];
extern f64 D_800A4A50;
extern f64 D_800A4A58;
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800C02AE[];
void func_8002EE00(void *arg0, u16 *arg1, u32 arg2, s32 arg3, s32 arg4, u8 arg5)
{
  f32 sp18[16];
  struct 
  {
    s8 a;
    s8 b;
    s16 c;
    s16 d;
    u16 e;
    u16 f;
    u16 g;
  } draw;
  u8 sp6F;
  f32 temp_ft0;
  f64 temp_fs0;
  s32 temp_s1;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_fp;
  s32 var_s3_2;
  s32 var_s6;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v1;
  s32 var_v1_2;
  s32 var_v1_3;
  s32 var_v1_4;
  char *var_s2;
  u16 temp_v1;
  s32 var_s3;
  void *temp_a0;
  void *temp_a2;
  void *temp_a2_2;
  f64 new_var;
  void *temp_a2_3;
  void *temp_a3;
  void *temp_s5;
  void *temp_v0;
  void *temp_v0_2;
  void *var_a1;
  void *var_a2;
  void *var_a2_2;
  void *var_s0;
  var_s2 = arg1;
  var_s3 = arg2;
  var_s6 = 0;
  var_fp = 0;
  sp6F = arg5;
  if (arg5 != 0)
  {
    var_s3 = ((u32) var_s3) >> 1;
  }
  if ((var_s3--) != 0)
  {
    temp_s5 = D_800A73E0 + 0x6BE6;
    temp_fs0 = D_800A4A50;
    var_s0 = var_s2 + 0x20;
    loop_4:
    if ((*((u16 *) var_s2)) != 0)
    {
      var_v0 = var_s6 & 0xFF;
      if (!(var_fp & 0xFF))
      {
        {
          u32 *dl;
          u32 *p;
          s32 r;
          s32 g;
          s32 b;
          dl = func_80006008(arg3);
          temp_a0 = *((void **) (D_800C02AE + 0x7E6E));
          p = dl;
          dl += 2;
          p[0] = 0xDE000000;
          p[1] = (u32) D_8009EAB0;
          var_fp = 1;
          temp_v1 = *((u16 *) (((char *) temp_a0) + 4));
          if (temp_v1 != 1)
          {
            if (temp_v1 == 2)
            {
              p = dl;
              dl += 2;
              p[0] = 0xFA000000;
              p[1] = -1;
              p = dl;
              dl += 2;
              p[0] = 0xFB000000;
              r = (*((u16 *) temp_s5)) * 2;
              if (r >= 256)
              {
                if (var_s2)
                {
                  r = 255;
                }
                else
                {
                  r = 255;
                }
              }
              g = (*((u16 *) (((char *) temp_s5) + 2))) * 2;
              if (g >= 256)
              {
                g = 255;
              }
              b = (*((u16 *) (((char *) temp_s5) + 4))) * 2;
              if (b >= 256)
              {
                b = 255;
              }
              p[1] = (((r << 24) | ((g & 255) << 16)) | ((b & 255) << 8)) | (*((u8 *) (((char *) var_s0) + (-2))));
            }
            else
            {
              goto plain_color;
            }
          }
          else
          {
            p = dl;
            dl += 2;
            p[0] = 0xFA000000;
            p[1] = -1;
            p = dl;
            dl += 2;
            p[0] = 0xFB000000;
            r = (*((u16 *) temp_s5)) * 2;
            if (r >= 256)
            {
              r = 255;
            }
            g = (*((u16 *) (((char *) temp_s5) + 2))) * 2;
            if (g >= 256)
            {
              g = 255;
            }
            b = (*((u16 *) (((char *) temp_s5) + 4))) * 2;
            if (b >= 256)
            {
              b = 255;
            }
            p[1] = (((r << 24) | ((g & 255) << 16)) | ((b & 255) << 8)) | (*((u8 *) (((char *) var_s0) + (-2))));
            plain_color:
            p = dl;

            dl = (dl += 2);
            p[0] = 0xFB000000;
            p[1] = (*((u8 *) (((char *) var_s0) + (-2)))) | (~255);
            p = dl;
            p[0] = 0xFA000000;
            p[1] = -1;
          }
          func_80006014(arg3, dl, dl);
        }
        var_v0 = var_s6 & 0xFF;
      }
      if (var_v0 == 0)
      {
        var_s6 = 1;
        temp_s1 = func_8001BD1C();
        guMtxIdentF(sp18);
        temp_a0 = *((void **) (((char *) arg0) + 0x5C));
        temp_ft0 = (f32) (*((s32 *) (((char *) temp_a0) + 0x54)));
        var_v0_2 = (s32) (temp_ft0 - (*((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x118))));
        new_var = D_800A4A58;
        if (var_v0_2 < 0)
        {
          var_v0_2 = -var_v0_2;
        }
        if (((f64) var_v0_2) < temp_fs0)
        {
          var_v0_3 = (s32) (((f32) (*((s32 *) (((char *) temp_a0) + 0x58)))) - (*((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x11C))));
          if (var_v0_3 < 0)
          {
            var_v0_3 = -var_v0_3;
          }
          if (((f64) var_v0_3) < new_var)
          {
            var_v0_4 = (s32) (((f32) (*((s32 *) (((char *) temp_a0) + 0x5C)))) - (*((f32 *) (((char *) (*((void **) (D_800C02AE + 0x7CD6)))) + 0x120))));
            if (var_v0_4 < 0)
            {
              var_v0_4 = -var_v0_4;
            }
            if (((f64) var_v0_4) < temp_fs0)
            {
              sp18[12] = temp_ft0;
              sp18[13] = (f32) (*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x5C)))) + 0x58)));
              sp18[14] = (f32) (*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x5C)))) + 0x5C)));
              func_80010BFC(temp_s1, (*((void **) (D_800C02AE + 0x7CD6))) + 0x38, &sp18);
              func_800061FC(arg3, temp_s1);
              goto block_35;
            }
          }
        }
      }
      else
      {
        block_35:
        if (var_s6 == 1)
        {
          *((s32 *) (D_800AE850 + 0x123C)) = (s32) ((*((s32 *) (D_800AE850 + 0x123C))) + 1);
          func_800075BC(arg3, *(((*((u16 *) (((char *) var_s0) + (-0xE)))) * 4) + (*((void ***) (((char *) (*((void **) (((char *) var_s0) + 0)))) + 4)))), 0);
          draw.a = 3;
          draw.b = 0;
          draw.c = (*((u16 *) (((char *) var_s0) + (-8)))) * 2;
          draw.d = (*((u16 *) (((char *) var_s0) + (-8)))) * 2;
          draw.e = *((u16 *) (((char *) var_s0) + (-0x1C)));
          draw.f = *((u16 *) (((char *) var_s0) + (-0x1A)));
          draw.g = *((u16 *) (((char *) var_s0) + (-0x18)));
          temp_v0_2 = *(*((void ***) (((char *) (*((void **) (((char *) var_s0) + 0)))) + 4)));
          func_80019C90(arg3, (*((void **) (D_800C02AE + 0x7CD6))) + 0x38, &draw, *((u16 *) (((char *) temp_v0_2) + 6)), (s32) (*((u16 *) (((char *) temp_v0_2) + 8))));
        }

        goto block_37;
      }
    }
    else
    {
      block_37:
      var_s0 += 0x24;

      var_s2 += 0x24;
      if (sp6F != 0)
      {
        var_s0 += 0x24;
        var_s2 += 0x24;
      }
      if ((var_s3--) != 0)
      {
        goto loop_4;
      }
    }

  }
}
