void func_8002DA98(void *, void *);
void func_8002E514(void *, s16 *, s16 *);
extern f32 __builtin_sqrtf(f32);
extern s32 D_800A1860;
extern s32 D_800A1864;
extern s32 D_800A1868;
extern s32 D_800A186C;
extern s32 D_800A1870;
extern s32 D_800A1874;
extern f32 D_800A1878;
extern f32 D_800A187C;
extern u8 D_800A73E0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
void func_8007B4A4(void *arg0)
{
  s16 p[4];
  s16 q[4];
  u8 mat[48];
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fa0_3;
  f32 temp_fs0;
  f32 temp_fs0_2;
  f32 temp_ft0;
  f32 temp_ft0_2;
  f32 temp_ft0_3;
  f32 temp_ft1;
  f32 temp_ft1_2;
  f32 temp_ft1_3;
  f32 temp_ft1_4;
  f32 temp_ft2;
  f32 temp_ft2_2;
  f32 temp_ft3;
  f32 temp_ft3_2;
  f32 temp_ft3_3;
  f32 new_var3;
  f32 temp_ft4;
  f32 temp_ft4_2;
  f32 temp_ft5;
  f32 temp_ft5_2;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 var_fv1;
  s16 *var_a2;
  s16 temp_a3;
  s16 temp_a3_2;
  s32 *var_a1_2;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a3;
  s32 var_a3_2;
  s32 var_v1;
  s32 var_v1_2;
  u16 temp_t0;
  u16 temp_t0_2;
  int var_v0;
  int var_v0_2;
  void *temp_t4;
  int new_var2;
  s32 new_var;
  void *temp_v0;
  void *var_a1;
  void *var_a2_2;
  void *var_t3;
  func_8002DA98(D_800AE850 + 0x6E78, mat);
  p[0] = D_800A1860 - (*((s32 *) (((char *) D_800AE850) + 0x6E8C)));
  p[1] = D_800A1864 - (*((s32 *) (((char *) D_800AE850) + 0x6E90)));
  p[2] = D_800A1868 - (*((s32 *) (((char *) D_800AE850) + 0x6E94)));
  func_8002E514(mat, &p[0], &p[0]);
  q[0] = D_800A186C - (*((s32 *) (((char *) D_800AE850) + 0x6E8C)));
  q[1] = D_800A1870 - (*((s32 *) (((char *) D_800AE850) + 0x6E90)));
  ;
  q[2] = D_800A1874 - (*((s32 *) (((char *) D_800AE850) + 0x6E94)));
  func_8002E514(mat, &q[0], &q[0]);
  temp_fs0 = (f32) (p[0] - q[0]);
  temp_ft5 = (f32) (p[1] - q[1]);
  temp_ft4 = (f32) (p[2] - q[2]);
  temp_fa0 = __builtin_sqrtf(((temp_fs0 * temp_fs0) + (temp_ft5 * temp_ft5)) + (temp_ft4 * temp_ft4));
  temp_fs0_2 = temp_fa0;
  temp_fs0_2 = temp_fs0 / temp_fs0_2;
  temp_ft5_2 = temp_ft5 / temp_fa0;
  temp_t4 = D_800A73E0 + 0x6BE6;
  var_t3 = arg0;
  arg0 = arg0;
  temp_v0 = D_800C02AE + 0x5D32;
  *((s32 *) (((char *) D_800C02AE) + 0x5D32)) = (s32) p[0];
  *((s32 *) (((char *) D_800C02AE) + 0x5D36)) = (s32) p[1];
  *((s32 *) (((char *) D_800C02AE) + 0x5D3A)) = (s32) p[2];
  *((s32 *) (((char *) D_800C02AE) + 0x5D3E)) = (s32) q[0];
  *((s32 *) (((char *) D_800C02AE) + 0x5D42)) = (s32) q[1];
  new_var3 = D_800A187C;
  *((s32 *) (((char *) D_800C02AE) + 0x5D46)) = (s32) q[2];
  *((f32 *) (((char *) D_800C02AE) + 0x5D4E)) = (f32) new_var3;
  *((f32 *) (((char *) D_800C02AE) + 0x5D4A)) = (f32) D_800A1878;
  temp_ft4_2 = temp_ft4 / temp_fa0;
  new_var2 = 0xFF;
  do
  {
    temp_t0 = *((u16 *) (((char *) var_t3) + 0x90));
    var_a2 = *((s16 **) (((char *) arg0) + 0x60));
    var_a3 = 0;
    if (temp_t0 != 0)
    {
      var_a1 = ((u8 *) var_a2) + 0xC;
      do
      {
        temp_ft3 = (f32) ((*((s32 *) (((char *) D_800C02AE) + 0x5D32))) - (*var_a2));
        temp_ft1 = (f32) ((*((s32 *) (((char *) temp_v0) + 4))) - (*((s16 *) (((char *) var_a1) + (-0xA)))));
        temp_ft0 = (f32) ((*((s32 *) (((char *) temp_v0) + 8))) - (*((s16 *) (((char *) var_a1) + (-8)))));
        temp_fa0_2 = __builtin_sqrtf(((temp_ft3 * temp_ft3) + (temp_ft1 * temp_ft1)) + (temp_ft0 * temp_ft0));
        temp_ft1_2 = (((temp_ft3 / temp_fa0_2) * temp_fs0_2) + ((temp_ft1 / temp_fa0_2) * temp_ft5_2)) + ((temp_ft0 / temp_fa0_2) * temp_ft4_2);
        var_v0 = 0xFF;
        if ((*((f32 *) (((char *) temp_v0) + 0x18))) < temp_ft1_2)
        {
          var_a0 = 0xFF << 8;
          var_v1 = (new_var2 << 0x10) + 1;
        }
        else
        {
          temp_fv1 = *((f32 *) (((char *) temp_v0) + 0x1C));
          if (temp_fv1 < temp_ft1_2)
          {
            temp_ft2 = (f32) (*((u16 *) (((char *) D_800A73E0) + 0x6BE6)));
            var_fv1 = (temp_ft1_2 - temp_fv1) / (1.0f - temp_fv1);
            if (temp_fa0_2 < 1200.0f)
            {
              if (temp_ft1)
              {
                var_fv1 = (temp_fa0_2 * var_fv1) * 0.00083333335f;
              }
              else
              {
                var_fv1 = (temp_fa0_2 * var_fv1) * 0.00083333335f;
              }
            }
            temp_fv1_2 = (var_fv1 * (255.0f - temp_ft2)) + temp_ft2;
            var_v0 = (u8) ((u32) temp_fv1_2);
            var_a0 = var_v0 << 8;
            var_v1 = (var_v0 << 0x10) + 2;
          }
          else
          {
            var_v0 = *((u8 *) (((char *) temp_t4) + 1));
            var_a0 = var_v0 << 8;
            var_v1 = (var_v0 << 0x10) + 4;
          }
        }
        *((s32 *) (((char *) var_a1) + 0)) = (s32) ((var_a0 + var_v1) + (var_v0 << 0x18));
        var_a1 += 0x10;
        var_a3 += 1;
      }
      while (var_a3 < ((s32) temp_t0));
    }
    var_a2 += 8;
    temp_t0_2 = *((u16 *) (((char *) var_t3) + 0xA8));
    var_a1_2 = *((s32 **) (((char *) arg0) + 0x30));
    var_a3_2 = 0;
    if (temp_t0_2 != 0)
    {
      var_a2_2 = ((u8 *) var_a1_2) + 8;
      do
      {
        temp_ft3_2 = (f32) ((*((s32 *) (((char *) D_800C02AE) + 0x5D32))) - (*((s16 *) (((char *) var_a2_2) + (-4)))));
        temp_ft1_3 = (f32) ((*((s32 *) (((char *) temp_v0) + 4))) - (*((s16 *) (((char *) var_a2_2) + (-2)))));
        temp_ft0_2 = (f32) ((*((s32 *) (((char *) temp_v0) + 8))) - (*((s16 *) (((char *) var_a2_2) + 0))));
        temp_fa0_3 = __builtin_sqrtf(((temp_ft3_2 * temp_ft3_2) + (temp_ft1_3 * temp_ft1_3)) + (temp_ft0_2 * temp_ft0_2));
 do { temp_ft1_4 = (((temp_ft3_2 / temp_fa0_3) * temp_fs0_2) + ((temp_ft1_3 / temp_fa0_3) * temp_ft5_2)) + ((temp_ft0_2 / temp_fa0_3) * temp_ft4_2); temp_fv1_3 = *((f32 *) (((char *) temp_v0) + 0x18)); var_v0_2 = new_var2; if (temp_fv1_3 < temp_ft1_4) { var_a0_2 = new_var2 << 8; var_v1_2 = (new_var2 << 0x10) + 1; } else { temp_ft3_3 = *((f32 *) (((char *) temp_v0) + 0x1C)); if (temp_ft3_3 < temp_ft1_4) { temp_ft2_2 = (f32) (*((u16 *) (((char *) D_800A73E0) + 0x6BE6))); temp_ft0_3 = 255.0f - temp_ft2_2; temp_fv1_4 = (temp_ft0_3 - (((temp_fv1_3 - temp_ft1_4) * temp_ft0_3) / (temp_fv1_3 - temp_ft3_3))) + temp_ft2_2; var_v0_2 = (u8) ((u32) temp_fv1_4); var_a0_2 = var_v0_2 << 8; var_v1_2 = (var_v0_2 << 0x10) + 2; } else { var_v0_2 = *((u8 *) (((char *) temp_t4) + 1)); var_a0_2 = var_v0_2 << 8; var_v1_2 = (var_v0_2 << 0x10) + 4; } } if (temp_t0) { *var_a1_2 = (var_a0_2 + var_v1_2) + (var_v0_2 << 0x18); var_a2_2 += 0x18; var_a3_2 += 1; var_a1_2 += 6; } else { *var_a1_2 = (var_a0_2 + var_v1_2) + (var_v0_2 << 0x18); var_a2_2 += 0x18; var_a3_2 = var_a3_2 + 1; var_a1_2 += 6; } } while (0);
      }
      while (var_a3_2 < ((s32) temp_t0_2));
    }
    arg0 += 4;
    var_t3 += 2;
  }
  while (((s32) arg0) < ((s32) (arg0 + 0x30)));
}
