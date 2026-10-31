void func_80017FA4(void *);
void func_80028740(void *);
void func_800307C8(void *);
void func_80030A0C(void *);
void func_80033370(void *);
s32 func_8007EAA0(s32, s32);
void func_80097E30(s32, s32, s32);
void func_80015460(void *, s32);
extern void *D_8009C230;
extern s32 (*D_8009C234[])(void *);
extern f32 D_8009CEC0[];
extern u8 D_800A73E0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
static inline static static s32 inline_fn(s32 arg0)
{
  return (s32) (arg0 + (*((s32 *) (D_800AE850 + 0x6E9C))));
}

void *func_800180FC(void *arg0)
{
  int __repair_literal;
  volatile char frame_padding[64];
  void (*temp_v0_9)(void *);
  s32 temp_a2;
  s32 temp_lo;
  s32 temp_s4;
  s32 temp_v0_10;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s8 *new_var;
  s32 var_s2;
  s32 var_s3;
  int new_var2;
  s32 var_v1;
  u16 temp_a0;
  s32 temp_v0;
  s32 temp_v0_2;
  void *temp_a0_2;
  void *temp_a0_3;
  void *temp_s6;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_7;
  void *temp_v0_8;
  void *temp_v1_5;
  void *temp_v1_6;
  void *var_a0;
  void *var_a0_2;
  void *var_a0_3;
  void *var_a0_4;
  void *var_a1;
  void *header;
  void *var_s0;
  void *var_s0_2;
  f32 new_var3;
  u16 *new_var4;
  void *var_s0_3;
  void *var_s1;
  void *var_v0;
  if ((*((u16 *) (((s8 *) arg0) + 4))) != 0)
  {
    func_80015460(arg0, 1);
    header = arg0;
    temp_s6 = *((void **) arg0);
    D_800A73E0[0x6C01] = 1U;
    var_s3 = 0;
    __repair_literal = 0;
    if (((s32) (*((u16 *) (((s8 *) header) + 4)))) > __repair_literal)
    {
      var_a1 = temp_s6;
      do
      {
        temp_v1 = *((s32 *) (((s8 *) var_a1) + 0x5C));
        if (temp_v1 != (-1))
        {
          *((s32 *) (((s8 *) temp_s6) + 0x5C)) = (s32) (temp_s6 + (temp_v1 * 0x94));
        }
        else
        {
          *((s32 *) (((s8 *) temp_s6) + 0x5C)) = 0;
          D_800A73E0[0x6C01] = 0U;
        }
        temp_v1_2 = *((s32 *) (((s8 *) var_a1) + 0x58));
        if (temp_v1_2 != (-1))
        {
          *((s32 *) (((s8 *) temp_s6) + 0x58)) = (s32) (temp_s6 + (temp_v1_2 * 0x94));
        }
        else
        {
          *((s32 *) (((s8 *) var_a1) + 0x58)) = 0;
          D_800A73E0[0x6C01] = 0U;
        }
        temp_v1_3 = *((s32 *) (((s8 *) var_a1) + 0x64));
        if (temp_v1_3 != (-1))
        {
          *((s32 *) (((s8 *) var_a1) + 0x64)) = (s32) (temp_s6 + (temp_v1_3 * 0x94));
        }
        else
        {
          *((s32 *) (((s8 *) var_a1) + 0x64)) = 0;
        }
        temp_a2 = *((s32 *) (((s8 *) var_a1) + 0x6C));
        *((s32 *) (((s8 *) var_a1) + 0x54)) = inline_fn(*((s32 *) (((s8 *) var_a1) + 0x54)));
        *((s32 *) (((s8 *) var_a1) + 0x70)) = inline_fn(*((s32 *) (((s8 *) var_a1) + 0x70)));
        if (temp_a2 != 0)
        {
          *((s32 *) (((s8 *) temp_s6) + 0x6C)) = inline_fn(temp_a2);
        }
        var_s3 += 1;
        var_a1 = ((s8 *) var_a1) + 0x94;
      }
      while (var_s3 < ((s32) (*((u16 *) (((s8 *) header) + 4)))));
    }
    if (D_800A73E0[0x6C02] == 0)
    {
      temp_v0 = *((u16 *) (((s8 *) header) + 4));
      var_s3 = 0;
      if (((s32) temp_v0) > 0)
      {
        var_a0 = temp_s6;
        loop_18:
        D_8009C230 = var_a0;

        if ((!((*((s32 *) (((s8 *) var_a0) + 0x60))) & 1)) || (var_a0 == (temp_s6 + ((*((u16 *) (((s8 *) (*((void **) (D_800C02AE + 0x7CD2)))) + 0x10))) * 0x94))))
        {
          var_s3 += 1;
          var_a0 = ((s8 *) var_a0) + 0x94;
          if (var_s3 < ((s32) temp_v0))
          {
            goto loop_18;
          }
        }
      }
      *((s32 *) (D_800C02AE + 0x3262)) = var_s3;
      D_8009C230 = ((s8 *) temp_s6) + ((*((u16 *) (((s8 *) (*((void **) (D_800C02AE + 0x7CD2)))) + 0x10))) * 0x94);
    }
    else
    {
      temp_v0_2 = *((u16 *) (((s8 *) header) + 4));
      var_s3 = 0;
      new_var = (s8 *) (*((void **) (D_800C02AE + 0x7CD2)));
      if (((s32) temp_v0_2) > 0)
      {
        var_a0_2 = temp_s6;
        loop_24:
        D_8009C230 = var_a0_2;

        if ((!((*((s32 *) (((s8 *) var_a0_2) + 0x60))) & 1)) || (var_a0_2 == (temp_s6 + ((*((u16 *) (new_var + 0x10))) * 0x94))))
        {
          var_s3 += 1;
          var_a0_2 = ((s8 *) var_a0_2) + 0x94;
          if (var_s3 < ((s32) temp_v0_2))
          {
            goto loop_24;
          }
        }
      }
      temp_a0 = *((u16 *) (((s8 *) (*((void **) (D_800C02AE + 0x7CD2)))) + 0x10));
      *((u16 *) (((s8 *) (*((void **) (D_800C02AE + 0x7CD2)))) + 0x10)) = (u16) var_s3;
      D_8009C230 = ((s8 *) temp_s6) + ((var_s3 & 0xFFFF) * 0x94);
      *((s32 *) (D_800C02AE + 0x3262)) = (s32) temp_a0;
      var_s3 = 0;
      if (((s32) (*((u16 *) (((s8 *) header) + 4)))) > 0)
      {
        var_a0_3 = temp_s6;
        do
        {
          temp_v1_4 = *((s32 *) (((s8 *) var_a0_3) + 0x5C));
          *((s32 *) (((s8 *) var_a0_3) + 0x5C)) = (s32) (*((s32 *) (((s8 *) var_a0_3) + 0x58)));
          *((s32 *) (((s8 *) var_a0_3) + 0x58)) = temp_v1_4;
          var_s3 += 1;
          var_a0_3 = ((s8 *) var_a0_3) + 0x94;
        }
        while (var_s3 < ((s32) (*((u16 *) (((s8 *) header) + 4)))));
      }
    }
    if (D_800A73E0[0x6C01] == 1)
    {
      temp_v1_5 = ((s8 *) temp_s6) + ((*((s32 *) (D_800C02AE + 0x3262))) * 0x94);
      new_var4 = (u16 *) (((s8 *) (*((void **) (D_800C02AE + 0x7CD2)))) + 0x10);
      *((s32 *) (((s8 *) temp_v1_5) + 0x60)) = (s32) ((((*((s32 *) (((s8 *) temp_v1_5) + 0x60))) & (~2)) & (~1)) & (~0x10));
      temp_v0_3 = ((s8 *) temp_s6) + ((*new_var4) * 0x94);
      *((s32 *) (((s8 *) temp_v0_3) + 0x60)) = (s32) ((*((s32 *) (((s8 *) temp_v0_3) + 0x60))) & (~2));
      var_v0 = ((s8 *) temp_s6) + ((*new_var4) * 0x94);
      var_v1 = (*((s32 *) (((s8 *) var_v0) + 0x60))) | 1;
    }
    else
    {
      temp_v1_6 = ((s8 *) temp_s6) + ((*((s32 *) (D_800C02AE + 0x3262))) * 0x94);
      *((s32 *) (((s8 *) temp_v1_6) + 0x60)) = (s32) (((((*((s32 *) (((s8 *) temp_v1_6) + 0x60))) | 2) & (~1)) & (~4)) | 0x10);
      temp_v0_4 = ((s8 *) temp_s6) + ((*new_var4) * 0x94);
      *((s32 *) (((s8 *) temp_v0_4) + 0x60)) = (s32) ((*((s32 *) (((s8 *) temp_v0_4) + 0x60))) & (~2));
      temp_v0_5 = ((s8 *) temp_s6) + ((*new_var4) * 0x94);
      *((s32 *) (((s8 *) temp_v0_5) + 0x60)) = (s32) ((*((s32 *) (((s8 *) temp_v0_5) + 0x60))) | 1);
      var_v0 = ((s8 *) temp_s6) + ((*new_var4) * 0x94);
      var_v1 = (*((s32 *) (((s8 *) var_v0) + 0x60))) | 4;
    }
    temp_lo = var_v1;
    *((s32 *) (((s8 *) var_v0) + 0x60)) = temp_lo;
    temp_v0_6 = ((s8 *) temp_s6) + ((*new_var4) * 0x94);
    *((s32 *) (((s8 *) temp_v0_6) + 0x60)) = (s32) ((*((s32 *) (((s8 *) temp_v0_6) + 0x60))) | 0x10);
    if (D_800A73E0[0x6C01] == 0)
    {
      temp_v0_7 = ((s8 *) temp_s6) + ((*new_var4) * 0x94);
      *((s32 *) (((s8 *) temp_v0_7) + 0x60)) = (s32) ((*((s32 *) (((s8 *) temp_v0_7) + 0x60))) | 4);
    }
    var_s3 = 0;
    if (((s32) (*((u16 *) (((s8 *) header) + 4)))) > 0)
    {
      var_s0 = temp_s6;
      do
      {
        func_80017FA4(var_s0);
        var_s3 += 1;
        var_s0 = ((s8 *) var_s0) + 0x94;
      }
      while (var_s3 < ((s32) (*((u16 *) (((s8 *) header) + 4)))));
    }
    var_s3 = 0;
    if (((s32) (*((u16 *) (((s8 *) header) + 4)))) > 0)
    {
      var_s1 = temp_s6;
      do
      {
        temp_v0_8 = *((void **) (((s8 *) var_s1) + 0x68));
        if (temp_v0_8 != NULL)
        {
          temp_a0_2 = ((s8 *) temp_v0_8) + (*((s32 *) (D_800AE850 + 0x6E9C)));
          *((void **) (((s8 *) var_s1) + 0x68)) = temp_a0_2;
          func_80015460(temp_a0_2, *((s32 *) (((s8 *) var_s1) + 0x50)));
          var_s0_2 = *((void **) (((s8 *) var_s1) + 0x68));
          if (var_s0_2 != NULL)
          {
            if (D_8009CEC0)
            {
              temp_s4 = *((s32 *) (((s8 *) var_s1) + 0x50));
              var_s2 = 0;
            }
            else
            {
              temp_s4 = *((s32 *) (((s8 *) var_s1) + 0x50));
              var_s2 = 0;
            }
            if (temp_s4 > 0)
            {
              do
              {
                temp_a0_3 = var_s0_2;
                temp_v0_9 = (void (*)(void *)) D_8009C234[*((s16 *) (((s8 *) var_s0_2) + 4))];
                var_s0_2 = ((s8 *) var_s0_2) + 8;
                var_s2 += 1;
                temp_v0_9(temp_a0_3);
              }
              while (var_s2 < temp_s4);
            }
          }
        }
        temp_v0_10 = func_8007EAA0(1, 0x28);
        *((s32 *) (((s8 *) var_s1) + 0x74)) = temp_v0_10;
        func_80097E30(temp_v0_10, 0, 0x28);
        *((s32 *) (((s8 *) var_s1) + 0x7C)) = 0;
        *((s32 *) (((s8 *) var_s1) + 0x34)) = (s32) ((*((s32 *) (((s8 *) var_s1) + 0x34))) - 0x190);
        *((s32 *) (((s8 *) var_s1) + 0x38)) = (s32) ((*((s32 *) (((s8 *) var_s1) + 0x38))) - 0x190);
        new_var2 = 0x3C;
        *((s32 *) (((s8 *) var_s1) + 0x44)) = (s32) ((*((s32 *) (((s8 *) var_s1) + 0x44))) - 0x190);
        *((s32 *) (((s8 *) var_s1) + new_var2)) = (s32) ((*((s32 *) (((s8 *) var_s1) + new_var2))) + 0x190);
        *((s32 *) (((s8 *) var_s1) + 0x40)) = (s32) ((*((s32 *) (((s8 *) var_s1) + 0x40))) + 0x190);
        *((s32 *) (((s8 *) var_s1) + 0x48)) = (s32) ((*((s32 *) (((s8 *) var_s1) + 0x48))) + 0x190);
        *((s32 *) (((s8 *) var_s1) + 0x34)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + 0x34)))) * D_8009CEC0[0]);
        new_var3 = (f32) (*((s32 *) (((s8 *) var_s1) + 0x38)));
        *((s32 *) (((s8 *) var_s1) + 0x38)) = (s32) (new_var3 * D_8009CEC0[1]);
        *((s32 *) (((s8 *) var_s1) + 0x44)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + 0x44)))) * D_8009CEC0[2]);
        *((s32 *) (((s8 *) var_s1) + 0x3C)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + new_var2)))) * D_8009CEC0[0]);
        *((s32 *) (((s8 *) var_s1) + 0x40)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + 0x40)))) * D_8009CEC0[1]);
        *((s32 *) (((s8 *) var_s1) + 0x48)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + 0x48)))) * D_8009CEC0[2]);
        *((s32 *) (((s8 *) var_s1) + 0x24)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + 0x24)))) * D_8009CEC0[0]);
        *((s32 *) (((s8 *) var_s1) + 0x28)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + 0x28)))) * D_8009CEC0[1]);
        temp_lo = (*((u16 *) (((s8 *) var_s1) + 0x8A))) * (*((u16 *) (((s8 *) var_s1) + 0x88)));
        *((s32 *) (((s8 *) var_s1) + 0x2C)) = (s32) (((f32) (*((s32 *) (((s8 *) var_s1) + 0x2C)))) * D_8009CEC0[2]);
        var_s2 = 0;
        if (temp_lo > 0)
        {
          var_s0_3 = *((void **) (((s8 *) var_s1) + 0x54));
          var_a0_4 = (void *) var_s0_3;
          do
          {
            *((s16 *) (((s8 *) var_a0_4) + 0)) = (s16) ((s32) (((f32) (*((s16 *) (((s8 *) var_a0_4) + 0)))) * D_8009CEC0[0]));
            *((s16 *) (((s8 *) var_a0_4) + 2)) = (s16) ((s32) (((f32) (*((s16 *) (((s8 *) var_a0_4) + 2)))) * D_8009CEC0[1]));
            var_s2 += 1;
            *((s16 *) (((s8 *) var_a0_4) + 4)) = (s16) ((s32) (((f32) (*((s16 *) (((s8 *) var_a0_4) + 4)))) * D_8009CEC0[2]));
            var_a0_4 = ((s8 *) var_a0_4) + 6;
          }
          while (var_s2 < temp_lo);
        }
        var_s3 += 1;
        var_s1 = ((s8 *) var_s1) + 0x94;
      }
      while (var_s3 < ((s32) (*((u16 *) (((s8 *) header) + 4)))));
    }
    var_s3 = 0;
    func_80028740(D_8009C230);
    if (((s32) (*((u16 *) (((s8 *) header) + 4)))) > 0)
    {
      var_s0_3 = temp_s6;
      do
      {
        func_800307C8(var_s0_3);
        var_s3 += 1;
        var_s0_3 = ((s8 *) var_s0_3) + 0x94;
      }
      while (var_s3 < ((s32) (*((u16 *) (((s8 *) header) + 4)))));
    }
    func_80030A0C(D_8009C230);
    func_80033370(D_8009C230);
  }
  return arg0;
}
