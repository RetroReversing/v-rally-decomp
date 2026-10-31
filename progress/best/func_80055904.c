typedef struct 
{
  u8 *p;
  u16 n;
} H559;
s32 func_80098180(s32, void *);
extern u8 D_800A1300[];
extern u8 D_800A1308[];
extern u8 D_800AE850[];
void func_80055904(void **arg0, H559 *arg1)
{
  u8 *var_s5;
  u8 *var_s2;
  u16 temp_s6;
  s32 var_s4;
  s32 temp_s1;
  int new_var2;
  u8 *temp_v0_2;
  u8 *temp_v0_3;
  u16 *new_var;
  s32 pad[2];
  temp_s6 = arg1->n;
  var_s5 = arg1->p;
  var_s4 = 0;
  if (temp_s6 == 0)
  {
    goto end;
  }
  {
    u8 fill;
    s32 b = *((s8 *) (var_s2 - 5));
    fill = 0xFF;
    var_s2 = var_s5 + 0x18;
    do
    {
      do
      {
        *((u16 *) (((u8 *) (*arg0)) + 0x10)) = *((u16 *) (var_s2 - 0xC));
        *((u16 *) (((u8 *) (*arg0)) + 0x12)) = *((u16 *) (var_s2 - 0xA));
        *((u16 *) (((u8 *) (*arg0)) + 0x14)) = *((u16 *) (var_s2 - 0x8));
        *((s16 *) (((u8 *) (*arg0)) + 0x16)) = 0;
        __builtin_memcpy((u8 *) (*arg0), var_s5, 4);
        ((u8 *) (*arg0))[3] = 6;
        __builtin_memcpy(((u8 *) (*arg0)) + 4, var_s2 - 0x14, 4);
        __builtin_memcpy(((u8 *) (*arg0)) + 8, var_s2 - 0x10, 4);
        ((u8 *) (*arg0))[0xC] = 0;
        ((u8 *) (*arg0))[0xD] = 0;
        ((u8 *) (*arg0))[0xE] = 0;
        ((u8 *) (*arg0))[0xF] = 0;
        var_s2 = (u8 *) (*arg0);
        {
          s32 a = *((s8 *) (var_s2 + -6));
          var_s2[0x18] = a;
          var_s2[0x19] = b;
        }
        temp_v0_2 = (u8 *) (*arg0);
        {
          s32 a = *((s8 *) (var_s2 - 4));
          s32 b = *((s8 *) (var_s2 - 3));
          temp_v0_2[0x1A] = a;
          temp_v0_2[0x1B] = b;
        }
        temp_v0_3 = (u8 *) (*arg0);
        {
          s32 a = *((s8 *) (var_s2 - 2));
          s32 b = *((s8 *) (var_s2 - 1));
          temp_v0_3[0x1C] = a;
          temp_v0_3[0x1D] = b;
        }
        ((u8 *) (*arg0))[0x1E] = 0;
        ((u8 *) (*arg0))[0x1F] = (new_var2 = 0);
        new_var = (u16 *) var_s2;
        *((u16 *) (((u8 *) (*arg0)) + 0x20)) = *new_var;
        temp_s1 = (*((s32 *) (D_800AE850 + 0x237C))) + ((*new_var) * 0x14);
        if ((func_80098180(temp_s1, D_800A1300) == 0) || (func_80098180(temp_s1, D_800A1308) == 0))
        {
          ((u8 *) (*arg0))[0] = fill;
          ((u8 *) (*arg0))[1] = fill;
          ((u8 *) (*arg0))[2] = fill;
          ((u8 *) (*arg0))[4] = fill;
          ((u8 *) (*arg0))[5] = fill;
          ((u8 *) (*arg0))[6] = fill;
          ((u8 *) (*arg0))[7] = fill;
          ((u8 *) (*arg0))[8] = fill;
          ((u8 *) (*arg0))[9] = fill;
          ((u8 *) (*arg0))[0xA] = fill;
          ((u8 *) (*arg0))[0xB] = fill;
        }
        var_s2 += 0x1A;
        var_s4 += 1;
        *arg0 = (void *) (((u8 *) (*arg0)) + 0x22);
        var_s5 = var_s2 - 0x18;
      }
      while (0);
    }
    while (var_s4 < ((s32) temp_s6));
  }
  end:
  ;

  ;
}
