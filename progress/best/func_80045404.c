#define I(p,o) (*(u32 *)((u8*)(p)+(o)))
#define H(p,o) (*(u16 *)((u8*)(p)+(o)))
#define B(p,o) (*(u8 *)((u8*)(p)+(o)))
void func_80098290(void *, s32, s32);
extern u8 D_8009D544;
extern u8 *D_800C35A0;
void func_80045404(u32 arg0, u8 *arg1, s8 arg2, s32 arg3, u8 arg4, s32 arg5)
{
  u32 sp10[4];
  u8 *var_a0_3;
  u8 *var_a0_4;
  u8 *var_a2;
  u32 new_var;
  u8 *var_a2_3;
  u8 *var_a2_5;
  u8 *var_v1_3;
  u8 *var_v1_5;
  u8 *temp_a1;
  s32 temp_a2;
  s32 temp_v1_5;
  s32 var_a0_5;
  s32 var_a0_6;
  s32 var_a0_7;
  s32 var_a0_8;
  u8 var_s2 = 1;
  s32 var_t1;
  s32 var_t2;
  s32 var_v1;
  s32 var_v1_2;
  u32 temp_s3;
  u8 *temp_a3;
  u8 *var_a0_2;
  u8 *var_a2_2;
  u8 *var_a2_4;
  u8 *var_a2_6;
  u8 *var_t0;
  u8 *var_v1_4;
  u32 temp_v0;
  u32 temp_v0_2;
  u32 temp_v0_3;
  u32 temp_v1_3;
  u32 temp_v1_4;
  u32 var_a0;
  u8 *var_v1_6;
  void *temp_s0;
  void *temp_v1;
  void *temp_v1_2;
  var_a0 = arg0;
  temp_s3 = H(D_800C35A0, 0x22);
  temp_a2 = temp_s3 << 6;
  temp_v1 = arg1 + ((int) (temp_a2 + 0x2C));
  temp_s0 = temp_v1 + 0x30;
  if (H(D_800C35A0, 0x2C) & 0x4000)
  {
    temp_v1_2 = arg1 + temp_a2;
    if (B(temp_v1_2, 0x38) != 0)
    {
      temp_v1_3 = I(temp_v1_2, 0x2C);
      if (temp_v1_3 > (0xBU - 1))
      {
        var_a0 = temp_v1_3 - 3;
      }
    }
    else
    {
      temp_v1_4 = I(temp_v1_2, 0x2C);
      if (temp_v1_4 >= 0x1FU)
      {
        var_a0 = temp_v1_4 - 0xA;
      }
    }
  }
  if (D_8009D544 == 0)
  {
    I(temp_s0, 0) = (u32) (((u32) (var_a0 * 3)) >> 1);
  }
  else
  {
    I(temp_s0, 0) = var_a0;
  }
  func_80098290(temp_s0 + 6, arg3, temp_a2);
  temp_v1_5 = temp_s3 << 6;
  B(temp_s0, 0xC) = 1;
  B(temp_s0, 0x4) = arg2;
  B(temp_s0, 0x5) = arg4;
  B(temp_s0, 0xA) = (s8) arg5;
  B(temp_s0, 0xB) = (u8) B(arg1 + temp_v1_5, 0x37);
  if (var_s2 & 0xFF)
  {
    temp_a1 = arg1 + (temp_v1_5 + 0x2C);
    do
    {
      var_s2 = 0;
      var_t2 = 3;
      var_t0 = temp_a1 + 0x30;
      var_t1 = 0x20;
      loop_15:
      temp_a3 = temp_a1 + var_t1;

      if ((((u32) I(var_t0, 0)) < ((u32) I(temp_a3, 0))) ^ 0)
      {
        var_a0_2 = sp10;
        var_a2 = temp_a3 + 0x10;
        var_s2 = 1;
        if ((((u32) var_a0_2) < ((u32) var_a2)) & (((u32) temp_a3) < ((u32) var_a0_2)))
        {
          var_a0_3 = sp10 + 4;
          var_v1 = 4;
          do
          {
            do
            {
              var_a2 -= 4;
              var_a0_3 -= 4;
              var_v1 -= 1;
              I(var_a0_3, 0) = I(var_a2, 0);
            }
            while (var_v1 != 0);
          }
          while (0);
          var_a0_4 = var_t0 + 0x10;
        }
        else
        {
          var_a2_2 = temp_a3;
          var_v1_2 = 4;
          do
          {
            temp_v0 = I(var_a2_2, 0);
            var_a2_2 += 4;
 do { var_v1_2 -= 1; I(var_a0_2, 0) = temp_v0; var_a0_2 += 4; } while (0);
          }
          while (var_v1_2 != 0);
          var_a0_4 = var_t0 + 0x10;
        }
        var_a2_3 = var_a0_4;
        new_var = (u32) var_t0;
        if ((((u32) temp_a3) < ((u32) var_a0_4)) & (new_var < ((u32) temp_a3)))
        {
          var_v1_3 = temp_a3 + 0x10;
          var_a0_5 = 4;
          do
          {
            var_a2_3 -= 4;
            var_v1_3 -= 4;
            var_a0_5 -= 1;
            I(var_v1_3, 0) = I(var_a2_3, 0);
          }
          while (var_a0_5 != 0);
        }
        else
        {
          var_a2_4 = var_t0;
          var_v1_4 = temp_a3;
          var_a0_6 = 4;
          do
          {
            temp_v0_2 = I(var_a2_4, 0);
            var_a2_4 += 4;
            var_a0_6 -= 1;
            I(var_v1_4, 0) = temp_v0_2;
            var_v1_4 += 4;
          }
          while (var_a0_6 != 0);
        }
        var_v1_5 = sp10 + 4;
        if ((new_var < ((u32) (sp10 + 4))) & (((u32) sp10) < ((u32) var_t0)))
        {
          var_a2_5 = var_t0 + 0x10;
          var_a0_7 = 4;
          do
          {
            if (temp_s3)
            {
              var_v1_5 -= 4;
              var_a2_5 -= 4;
              var_a0_7 -= 1;
              I(var_a2_5, 0) = I(var_v1_5, 0);
            }
            else
            {
              var_v1_5 -= 4;
              var_a2_5 -= 4;
              var_a0_7 -= 1;
              I(var_a2_5, 0) = I(var_v1_5, 0);
            }
          }
          while (var_a0_7 != 0);
          var_t0 -= 0x10;
        }
        else
        {
          var_v1_6 = (u8 *) sp10;
          var_a2_6 = var_t0;
          var_a0_8 = 4;
          do
          {
            do
            {
              temp_v0_3 = I(var_v1_6, 0);
              var_v1_6 += 4;
              var_a0_8 -= 1;
            }
            while (0);
            I(var_a2_6, 0) = temp_v0_3;
            var_a2_6 += 4;
          }
          while (var_a0_8 != 0);
          goto block_36;
        }
      }
      else
      {
        block_36:
        var_t0 -= 0x10;

      }
      var_t2 -= 1;
      var_t1 -= 0x10;
      if (var_t2 != 0)
      {
        goto loop_15;
      }
    }
    while (var_s2 & 0xFF);
  }
}
