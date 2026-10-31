extern float D_800C35E8;
extern float D_800C35E4;
extern unsigned char D_800C35C8;
extern int D_800C81D4;
extern unsigned char D_800B6818;
extern float D_800C35E0;
s32 func_8001FEE8();
void *func_8004240C();
s32 func_80086AD8();
s32 func_80086B34();
s32 func_80086D34();
s32 func_80086D90();
s32 func_80086E8C(void *, f32);
extern s32 D_8009F640;
extern f64 D_800A4AC8;
extern f64 D_800A4AD0;
extern f64 D_800A4AD8;
extern unsigned char D_800AE850[];
extern char D_800C02AE[];
static inline static static static static static static static static static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

static inline static static static static static static s32 inline_fn2()
{
  return (s32) D_800C35E4;
}

static inline static static static static static char *inline_fn23(void *arg0)
{
  return inline_fn(arg0) + 4;
}

static inline static static static static float inline_fn234(void *arg0)
{
  return (*((f32 *) inline_fn23(arg0))) * 80.0f;
}

void func_80037E28(void)
{
  f32 temp_fs0;
  f32 var_fs1;
  f32 var_fs1_2;
  f32 var_fv0;
  f64 var_fv1;
  f32 var_fv1_2;
  int new_var5;
  f64 temp_fs2;
  f64 var_fv1_3;
  int new_var;
  s32 temp_a0_2;
  s32 temp_a1;
  int new_var4;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s4;
  s32 temp_s5;
  s32 temp_s6;
  s32 temp_v0_3;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s32 var_a0_3;
  s32 var_a1;
  unsigned int new_var6;
  u8 var_v0;
  s32 var_v0_2;
  char *new_var7;
  s32 var_v0_3;
  u16 temp_v1;
  u32 temp_v0_2;
  u32 temp_v1_2;
  u32 var_s0_2;
  u8 var_s1;
  void *temp_a0;
  void *temp_a2;
  void *temp_s0;
  void *temp_s0_4;
  void *temp_s0_5;
  void *temp_s1;
  void *temp_s1_2;
  char *new_var3;
  void *temp_s2;
  void *temp_s7;
  void *temp_v0;
  void *var_a0;
  void *var_a0_2;
  void ***new_var2;
  void *var_s0;
  void *var_s3;
  var_v0 = 0;
  if (!(D_8009F640 & 1))
  {
    var_v0 = 1;
  }
  else
    if ((*((u16 *) (inline_fn(*((void **) (D_800C02AE + 0x32f2))) + 0xe))) == 2)
  {
    if (!(D_8009F640 & 2))
    {
      var_v0 = 1;
    }
  }
  if (var_v0 != 0)
  {
    new_var2 = (void ***) (D_800AE850 + 0x73F0);
    var_s3 = *(*new_var2);
    new_var7 = (char *) D_800C02AE;
    if (var_s3 != NULL)
    {
      temp_fs2 = D_800A4AC8;
      temp_a2 = new_var7;
      temp_a2 += (s32) 0x3336;
      do
      {
        temp_s0 = *((void **) (inline_fn(var_s3) + 0x4C));
        temp_a0 = (void *) temp_s0;
        temp_s7 = *((void **) (inline_fn(var_s3) + 0x68));
        temp_s4 = *((s32 *) inline_fn23(temp_a0));
        temp_s2 = *((void **) (inline_fn(temp_s7) + 0));
        temp_a0_2 = *((s32 *) (inline_fn(temp_a0) + 0));
        temp_s5 = *((s32 *) inline_fn23(*((void **) (inline_fn(var_s3) + 0x94))));
        temp_s6 = (*((s32 *) (inline_fn(*((void **) (inline_fn(var_s3) + 0x48))) + 0xC))) / 5;
        switch (temp_a0_2)
        {
          case 0:
            break;

          case 1:
            if (temp_s5 == 1)
          {
            temp_s0 = temp_s2 + 0x30;
            if ((!(D_8009F640 & 4)) && (func_80086D34(temp_s0) != 0))
            {
              D_8009F640 |= 4;
              func_80086B34(temp_s0);
              var_fv1 = D_800C35E8 * 150.0f;
 do { var_a0 = temp_s0; } while (0);
              block_74:
              func_80086D90(var_a0, (s32) var_fv1);

            }
          }
            break;

          case 2:
            new_var3 = inline_fn(temp_s7) + 0x1C;
            var_fs1 = (f32) (*((s32 *) new_var3));
            if (var_fs1 > 12000.0f)
          {
            var_fs1 = 12000.0f;
          }
            temp_v1 = *((u16 *) (inline_fn(*((void **) (D_800C02AE + 0x32F2))) + 0x1E));
            var_fs1_2 = (100.0f - (var_fs1 * 0.008333334f)) * 0.01f;
            if (((u32) (temp_v1 - 6)) < 2U)
          {
            D_800C35E4 = 0.0f;
            var_a1 = 0;
            if (D_800C35C8 != 0xFF)
            {
              var_a0_2 = D_800C81D4 + (D_800C35C8 * 0xC);
              goto block_36;
            }
          }
          else
          {
            temp_v1_2 = temp_v1 & 0xFFFF;
            if (temp_s5 != 1)
            {
              if (((temp_v1_2 == 5) && (D_800B6818 == 0)) || (((*((u16 *) (inline_fn(*((void **) (D_800C02AE + 0x32F2))) + 0xE))) == temp_a0_2) && ((temp_v1_2 == 5) || ((temp_v1_2 != 0) & (temp_v1_2 < 5U)))))
              {
                var_fs1_2 = 0.0f;
              }
              if (temp_s5 == 1)
              {
                goto block_28;
              }
            }
            else
            {
              block_28:
              var_fv1_2 = (f32) func_8001FEE8(var_s3);

              if (var_fv1_2 < 0.0f)
              {
                var_fv1_2 = -var_fv1_2;
              }
              if (var_fv1_2 > 100.0f)
              {
                var_fv1_2 = 100.0f;
              }
              new_var4 = 0xFF;
              D_800C35E4 = (f32) (D_800C35E0 * ((1.0f - (var_fv1_2 * 0.004f)) * 112.0f));
              temp_v0 = (*((void **) (D_800C02AE + 0x7CD6)) = func_8004240C(1));
              if ((*((s32 *) (inline_fn(temp_v0) + 0x20))) & 0x880000)
              {
                D_800C35E4 = (f32) (D_800C35E4 * 0.6666667f);
              }
              if (D_800C35C8 != new_var4)
              {
                var_a0_2 = D_800C81D4 + (D_800C35C8 * 0xC);
                var_a1 = inline_fn2();
                block_36:
                func_80086D90(var_a0_2, var_a1);

              }
            }
          }
            if (temp_s5 != 2)
          {
            new_var = func_80086D34(temp_s2) != 0;
            if ((func_80086D34(temp_s2 + 0x30) != 0) && ((((*((u16 *) (inline_fn(*((void **) (D_800C02AE + 0x32F2))) + 0xE))) != 2) | (temp_s5 == 1)) != 0))
            {
              var_s0 = temp_s2 + 0xC;
              if (new_var)
              {
                func_80086B34(temp_s2);
                var_s0 = temp_s2 + 0xC;
              }
              if (func_80086D34(var_s0) != 0)
              {
                func_80086B34(var_s0);
              }
            }
            if ((*((s32 *) inline_fn23(temp_s2))) != 0)
            {
              temp_fs0 = (f32) ((((f64) (temp_s4 * 0xC)) * D_800A4AD0) - D_800A4AD8);
              func_80086E8C(temp_s2, temp_fs0);
              temp_s1 = temp_s2 + 0xC;
              func_80086E8C(temp_s1, temp_fs0);
              if (temp_s4 < 0xFA0)
              {
                func_80086D90(temp_s2, (s32) (var_fs1_2 * ((*((f32 *) inline_fn23(temp_a2))) * 120.0f)));
                var_v0_2 = temp_s6 + 0x1E;
                goto block_52;
              }
              if (temp_s4 < 0x157C)
              {
                temp_v1_3 = temp_s4 - 0xFA0;
                temp_s0_2 = (temp_v1_3 * 0x28) / 1500;
                func_80086D90(temp_s2, (s32) ((((f32) (0x78 - temp_s0_2)) * var_fs1_2) * (*((f32 *) inline_fn23(temp_a2)))));
                temp_s0_3 = temp_s0_2 + (temp_s6 + 0x1E);
                var_fv1_3 = (f64) temp_s0_3;
                if (temp_s0_3 < 0)
                {
                  var_fv1_3 += temp_fs2;
                }
              }
              else
              {
                func_80086D90(temp_s2, (s32) (var_fs1_2 * inline_fn234(temp_a2)));
                var_v0_2 = temp_s6 + 0x50;
                block_52:
                var_fv1_3 = (f64) var_v0_2;

                if (new_var5 = var_v0_2 < 0)
                {
                  var_fv1_3 += temp_fs2;
                }
              }
              func_80086D90(temp_s1, (s32) ((((f32) var_fv1_3) * var_fs1_2) * (*((f32 *) inline_fn23(temp_a2)))));
              if (temp_s5 == 1)
              {
                var_s1 = *((u8 *) (inline_fn(*((void **) (inline_fn(var_s3) + 0x8C))) + 0x337));
                temp_v0_2 = var_s1 & new_var4;
                if (temp_v0_2 != 0)
                {
                  if (temp_v0_2 >= 3U)
                  {
                    var_s1 = 2;
                  }
                  new_var6 = 0;
                  temp_s0_4 = temp_s2 + 0x3C;
                  if (func_80086D34(temp_s0_4) != new_var6)
                  {
                    func_80086B34(temp_s0_4);
                    func_80086D90(temp_s0_4, (s32) (((f32) (var_s1 & new_var4)) * (D_800C35E8 * 56.0f)));
                  }
                }
                temp_v0_3 = *(*((s32 **) (inline_fn(var_s3) + 0x50)));
                temp_s0_5 = temp_s2 + 0x24;
                if (temp_v0_3 != (*((s32 *) inline_fn23(temp_s7))))
                {
                  *((s32 *) inline_fn23(temp_s7)) = temp_v0_3;
                  func_80086B34(temp_s0_5);
                  func_80086D90(temp_s0_5, (s32) (*((f32 *) inline_fn23(temp_a2))));
                  func_80086D90(temp_s2, (s32) inline_fn234(temp_a2));
                  func_80086D90(temp_s2 + 0xC, (s32) inline_fn234(temp_a2));
                }
                var_s0_2 = new_var6;
                var_a0_3 = 0;
                temp_a1 = *((s32 *) (inline_fn(var_s3) + 0x80));
                var_v0_3 = new_var6 & new_var4;
                do
                {
                  temp_v1_4 = var_v0_3 * 4;
                  var_a0_3 += 1;
                  if ((*((s32 *) (((char *) (temp_v1_4 + temp_a1)) + 0x310))) < 0)
                  {
                    var_s0_2 += *((s32 *) (inline_fn(temp_v1_4 + (*((void **) (inline_fn(var_s3) + 0x68)))) + 8));
                  }
                  var_v0_3 = var_a0_3 & new_var4;
                }
                while (((u32) (var_a0_3 & 0xFF)) < 4U);
                if (var_s0_2 >= 0x7D1U)
                {
                  temp_s1_2 = temp_s2 + 0x18;
                  if (func_80086D34(temp_s1_2) != 0)
                  {
                    func_80086B34(temp_s1_2);
                  }
                  if (var_s0_2 > 8000U)
                  {
                    var_fv1 = D_800C35E8 * 140.0f;
                    goto block_73;
                  }
                  if (var_s0_2 >= 0x1771U)
                  {
                    var_fv1 = D_800C35E8 * 120.0f;
                    block_73:
                    var_a0 = temp_s1_2;

                    {
                      func_80086D90(var_a0, (s32) var_fv1);
                      break;
                    }
                  }
                  if (var_s0_2 >= 0xFA1U)
                  {
                    var_fv0 = D_800C35E8 * 100.0f;
                  }
                  else
                  {
                    var_fv0 = D_800C35E8 * 80.0f;
                  }
                  func_80086D90(temp_s1_2, (s32) var_fv0);
                }
                else
                {
                  func_80086AD8(temp_s2 - (-0x18));
                }
              }
            }
          }
            break;

        }

        var_s3 = *((void **) inline_fn23(var_s3));
      }
      while (var_s3 != NULL);
    }
  }
}
