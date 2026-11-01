void *func_80041530(u16, u16);
s32 func_8004D4D8(void *, void *);
void *func_8004D784(s32);
s32 func_8004D7D4(s32, s32, u16);
s32 func_8004DB30(void *, u16);
extern s32 D_800A73E0;
extern s32 D_800AE850;
extern s32 D_800C02AE;
static inline static char *inline_fn(void *arg0, int arg1)
{
  return ((char *) arg0) + arg1;
}

void func_8004DC50(void *arg0, s32 arg2)
{
  unsigned int __repair_literal;
  s32 sp14;
  s16 temp_a0;
  int new_var;
  s32 var_a0;
  s32 var_a2;
  s32 var_a3;
  s32 var_s1;
  u16 var_s2;
  s32 var_s4;
  s32 var_s5;
  s32 var_s7;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v1;
  u16 temp_a2;
  u16 temp_a2_2;
  u16 temp_v0_4;
  u16 var_s3;
  u32 temp_a1;
  u32 temp_v0;
  void *temp_a0_2;
  int new_var2;
  void *temp_s1;
  void *temp_s4;
  void *temp_s4_2;
  void *temp_v0_2;
  void *temp_v0_3;
  void *var_s0;
  var_a2 = arg2;
  var_s4 = 0;
  temp_v0 = *((u32 *) (((char *) arg0) + 0x50));
  var_s3 = 1;
  var_s7 = 2;
  if (temp_v0 != 0)
  {
    var_s5 = 0;
    var_a3 = 0;
    sp14 = *((s32 *) (((char *) arg0) + 0x68));
    __repair_literal = 0U;
    if (temp_v0 > __repair_literal)
    {
      new_var = var_a3;
      do
      {
        temp_a1 = var_s5 & 0xFFFF;
    temp_v0_2 = ((temp_a1) * 8) + sp14;
        temp_a0 = *((s16 *) (((char *) temp_v0_2) + 4));
        if (temp_a0 == 0)
        {
          new_var2 = 0xFF;
          temp_s1 = *((void **) (((char *) temp_v0_2) + 0));
          var_s2 = 0;
          var_s0 = temp_s1 + 0x1C;
          if ((((u32) temp_a0) < ((u16) (*((u16 *) (((char *) temp_s1) + 0x18))))) & (!(new_var & new_var2)))
          {
            do
            {
              if ((*((u16 *) (((char *) var_s0) + 0))) == 1)
              {
                func_8004D4D8(arg0, temp_s1);
                var_a2 = 0;
                var_a3 = 1;
                *((s16 *) (((char *) var_s0) + 8)) = 0;
                *((s16 *) (((char *) var_s0) + 0xA)) = (s16) (*((u8 *) (((char *) (&D_800AE850)) + 0x87A2)));
                var_v0 = 0 & 0xFFFF;
                var_v1 = var_a2 & 0xFFFF;
                do
                {
                  var_a0 = 0;
                  temp_a1 = ((var_v0 * 2) | 1) & 0xFFFF;
                  var_v1 = 1;
                  if (temp_a1 > __repair_literal)
                  {
                    var_v0_2 = 1 & 0xFFFF;
                    do
                    {
                      var_v1 = 2;
                      var_v1 = var_v0_2 * var_v1;
                      var_a0 += 1;
                      new_var = var_v1 & 0xFFFF;
    var_v0_2 = new_var;
                    }
                    while (((u32) (var_a0 & 0xFFFF)) < temp_a1);
                  }
                  var_a2 += 1;
                  new_var = var_a2 & 0xFFFF;
                  *((u16 *) (((char *) temp_s1) + 0x1A)) = (u16) ((*((u16 *) (((char *) temp_s1) + 0x1A))) | ((var_v1 & 0xFFFF) * 2));
                  var_v0 = new_var;
                }
                while (((u32) var_v1) < 5U);
              }
              var_s2 += 1;
              var_s0 += (*((s32 *) (((char *) var_s0) + 4))) + 8;
            }
            while ((((u32) (var_s2 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s1) + 0x18))))) & (!(var_a3 & new_var2)));
          }
        }
        var_s5 += 1;
      }
      while ((((u32) (var_s5 & 0xFFFF)) < ((u32) (*((u32 *) (((char *) arg0) + 0x50))))) & (!(new_var & 0xFF)));
    }
  }
  var_s1 = *((s32 *) (((char *) arg0) + 0x5C));
  if ((var_s1 != ((s32) arg0)) & (var_s1 != 0))
  {
    do
    {
      temp_v0_3 = func_8004D784(var_s1);
      if (temp_v0_3 != NULL)
      {
        temp_v0_4 = *((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) - (-0x32F2))))) + 0x1E));
        temp_a0_2 = *((void **) (((char *) temp_v0_3) + 0x28));
        if (((temp_v0_4 == 0) | (temp_v0_4 == 5)) != 0)
        {
          temp_a2 = var_s3;
          if (var_s7 == 0x14)
          {
            var_s3 += 1;
            func_8004D7D4(var_s1, *((s32 *) (((char *) (*((void **) (((char *) temp_a0_2) + 0x180)))) + 0xC)), temp_a2);
          }
          else
            if (((*((s16 *) (((char *) temp_a0_2) + 0x170))) != (-1)) && ((*((s32 *) (((char *) temp_v0_3) + 0x10))) & 8))
          {
            func_8004D7D4(var_s1, *((s32 *) (((char *) (*((void **) (((char *) temp_a0_2) + 0x180)))) + 0xC)), var_s3);
            var_s3 += 1;
            *((s32 *) (((char *) temp_v0_3) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v0_3) + 0x10))) & (~8));
          }
          *((s32 *) (((char *) temp_v0_3) + 0x10)) = (s32) ((*((s32 *) inline_fn(temp_v0_3, 0x10))) & (~8));
          goto block_26;
        }
        var_s4 = var_s1;
        if ((*((s16 *) inline_fn(temp_a0_2, 0x170))) != (-1))
        {
          temp_a2_2 = var_s3;
          if ((*((s32 *) inline_fn(temp_v0_3, 0x10))) & 8)
          {
            var_s3 += 1;
            func_8004D7D4(var_s1, *((s32 *) inline_fn(*((void **) inline_fn(temp_a0_2, 0x180)), 0xC)), temp_a2_2);
            goto block_26;
          }
        }
      }
      else
      {
        block_26:
        var_s4 = var_s1;

      }
      var_s1 = *((s32 *) (((char *) var_s4) + 0x5C));
      var_s7 += 1;
    }
    while ((var_s1 != ((s32) arg0)) & (var_s1 != 0));
  }
  *((s8 *) inline_fn(&D_800A73E0, 0x6C01)) = 1;
  if (var_s1 == 0)
  {
    if ((*((u16 *) inline_fn(*((void **) inline_fn(&D_800C02AE, 0x32F2)), 0x1E))) != 0)
    {
      *((s8 *) inline_fn(&D_800A73E0, 0x6C00)) = 2;
    }
    *((s8 *) inline_fn(&D_800A73E0, 0x6C01)) = 0;
    temp_s4 = *((void **) inline_fn(*((void **) (((char *) var_s4) + 0x58)), 0x58));
    if (temp_s4 != NULL)
    {
      if (!(func_8004DB30(temp_s4, var_s3) & 0xFF))
      {
        temp_s4_2 = *((void **) inline_fn(temp_s4, 0x5C));
        if (!(func_8004DB30(temp_s4_2, var_s3) & new_var2))
        {
          func_8004DB30(*((void **) inline_fn(temp_s4_2, 0x5C)), var_s3);
        }
      }
      var_s3 += 1;
    }
  }
  *((u16 *) inline_fn(&D_800A73E0, 0x6BFC)) = var_s3;
  *((s16 *) inline_fn(&D_800A73E0, 0x6C04)) = (s16) ((*((u8 *) inline_fn(&D_800AE850, 0x87A2))) + (*((u8 *) inline_fn(&D_800AE850, 0x87A5))));
  *((s16 *) inline_fn(func_80041530(*((u16 *) inline_fn(*((void **) inline_fn(&D_800C02AE, 0x32F2)), 0x1E)), *((u16 *) inline_fn(*((void **) inline_fn(&D_800C02AE, 0x32F2)), 0x20))), 0x12)) = (s16) ((*((u16 *) inline_fn(&D_800A73E0, 0x6BFC))) - 1);
}
