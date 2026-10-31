extern int D_800B6880;
s32 func_8001FEE8();
s32 func_80022374();
s32 func_800347A4();
s32 func_80042F40();
s32 func_80085778();
extern s32 D_800A1234;
extern char D_800A4DFC[];
extern char D_800AE850[];
extern char D_800C02AE[];
typedef struct 
{
  s8 x;
  u8 b1;
  u8 b2;
  u8 b3;
  u8 b4;
  u8 b5;
} Input43;
void func_80043A78(void *arg0, Input43 *arg1)
{
  s16 var_a3;
  s32 *var_s1;
  u32 *timer;
  s32 temp_a0;
  s32 temp_a2;
  s32 temp_v1;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s32 temp_v1_6;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_5;
  s32 var_v1_2;
  u16 temp_v0;
  u32 var_a1;
  u32 temp_s6;
  u32 temp_v1_2;
  u32 temp_v1_5;
  s32 var_v0;
  char var_v1;
  u32 temp_v1_8;
  void *temp_a1;
  void *temp_s4;
  void *temp_v1_7;
  void *var_a0;
  temp_a1 = *((void **) (((char *) arg0) + 0x70));
  var_v0_2 = 0;
  temp_s4 = *((void **) (((char *) (*((void **) (((char *) arg0) + 0x8C)))) + 0x28));
  temp_s6 = *((u32 *) (((char *) (*((void **) (((char *) arg0) + 0x60)))) + 0x58));
  var_s1 = temp_a1 + 0x20;
  if (!((*var_s1) & 0x20))
  {
    timer = temp_a1 + 0x24;
    var_v0_2 = func_8001FEE8(arg0, temp_a1);
    if (!((*((s32 *) (((char *) arg0) + 0x14))) & 0x80))
    {
      if ((*(*((s32 **) (((char *) arg0) + 0x48)))) < 4)
      {
        var_a0 = *(*((void ***) (D_800AE850 + 0x72FC)));
        if (var_a0 != NULL)
        {
          loop_4:
          if ((*((s32 *) (((char *) var_a0) + 0x24))) != arg0)
          {
            var_a0 = *((void **) (((char *) var_a0) + 4));
            if (var_a0 != NULL)
            {
              goto loop_4;
            }
          }

        }
        func_80022374(var_a0 + 0x28, &D_800A4DFC, 2);
      }
      *((s32 *) (((char *) arg0) + 0x14)) = (s32) ((*((s32 *) (((char *) arg0) + 0x14))) | 0x80);
      temp_v1_4 = *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x6C)))) + 8));
      *timer = 0xFAU;
      if (temp_v1_4 == 2)
      {
        var_v0_2 = 0xEE;
        goto block_12;
      }
      if (temp_v1_4 == 3)
      {
        var_v0_2 = 0xE1;
        goto block_12;
      }
      var_v0_2 = 0xD2;
      if (temp_v1_4 == 4)
      {
        block_12:
        *timer = var_v0_2;

      }
      *((void **) (((char *) (*((void **) (((char *) arg0) + 0x60)))) + 0x150)) = temp_s4;
      *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x60)))) + 0x578)) = 0x1B58;
    }
    temp_v1_2 = *timer;
    if (temp_v1_2 != 0)
    {
      if (temp_v1_2 >= 0xC8U)
      {
        if (temp_v1_2 == 0xC8)
        {
          *timer = 0xCU;
          temp_v1_3 = *var_s1;
          *var_s1 = (s32) (temp_v1_3 | 1);
          var_v0_2 = temp_v1_3 | 5;
          if (temp_s6 >= ((u32) ((*((s32 *) (((char *) temp_s4) + 0x4C))) - 1)))
          {
            var_v0_2 = temp_v1_3 | 3;
          }
          goto block_36;
        }
        func_800347A4(arg0, arg1);
      }
      else
      {
        if ((*var_s1) & 4)
        {
          arg1->x = 0x7F;
        }
        if ((*var_s1) & 2)
        {
          arg1->x = -0x7F;
        }
        arg1->b4 = 0;
        temp_v1_4 = *var_s1;
        var_v0_2 = temp_v1_4 | 1;
        if (!(temp_v1_4 & 8))
        {
          if (temp_v1_4 & 0x10)
          {
            var_v0_3 = (*((s32 *) (((char *) temp_s4) + 0x4C))) - temp_s6;
            if (var_v0_3 < 0)
            {
              var_v0_3 = -var_v0_3;
            }
            temp_v1_5 = 4 - var_v0_3;
            if (temp_v1_5 != 0)
            {
              var_v0_2 = ((u32) (var_v0_2 + 0x1B)) / temp_v1_5;
              var_v1 = var_v0_2;
            }
            else
            {
              var_v1 = 0;
            }
            if (arg1->x > 0)
            {
              arg1->x = (s8) var_v1;
            }
            else
            {
              arg1->x = -var_v1;
            }
            arg1->b4 = 0xFF;
            if (var_v0_2 >= 0x79)
            {
              var_v0_2 = (*var_s1) & (~0x10);
              goto block_36;
            }
          }
        }
        else
        {
          block_36:
          *var_s1 = var_v0_2;

        }
      }
      *timer = (u32) ((*timer) - 1);
    }
    else
    {
      temp_v1_6 = *var_s1;
      var_v0_4 = temp_v1_6 | 0x20;
      if (!(temp_v1_6 & 8))
      {
        if (!(temp_v1_6 & 4))
        {
          var_v0_5 = temp_v1_6 | 4;
          var_v1_2 = -3;
        }
        else
        {
          var_v0_5 = temp_v1_6 | 2;
          var_v1_2 = -5;
        }
        *var_s1 = (s32) (var_v0_5 & var_v1_2);
        *timer = 0x32U;
        var_v0_4 = (*var_s1) | 8;
      }
      *var_s1 = var_v0_4;
    }
    if ((*var_s1) & 0x20)
    {
      goto block_47;
    }
  }
  else
  {
    block_47:
    if ((*(*((s32 **) (((char *) arg0) + 0x48)))) < 4)
    {
      arg1->b1 = 0U;
      arg1->b5 = 0;
      *((s8 *) (&arg1->b2)) = -1;
      arg1->b3 = (u8) arg1->b1;
      temp_v0 = *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E));
      if ((temp_v0 != 0) & (temp_v0 != 5))
      {
        { char *__repair_store_address = (char *)D_800A1234; __repair_store_address += ((*(*((s32 **) (((char *) arg0) + 0x48)))) * 0x44); *(s16 *)(__repair_store_address + 0xA) = 2; }
        var_a0 = *(*((void ***) (D_800AE850 + 0x73F0)));
        var_a1 = *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE));
        var_a3 = 0;
        if (var_a0 != NULL)
        {
          do
          {
            if ((*(*((s32 **) (((char *) var_a0) + 0x48)))) < 4)
            {
              temp_v1_7 = *((void **) (((char *) var_a0) + 0x70));
              temp_a2 = *((s32 *) (((char *) var_a0) + 0x14));
              var_s1 = temp_v1_7 + 0x20;
              if (temp_a2 & 0x100)
              {
                if ((*((s32 *) (((char *) temp_v1_7) + 0x20))) & 0x20)
                {
                  var_a1 -= 1;
                }
              }
              else
                if (((((u32) (var_v0_2 + 5)) < 0xBU) && ((*((s32 *) (((char *) (*((void **) (((char *) var_a0) + 0x6C)))) + 0x10))) == 0)) && (temp_a2 & 0x200))
              {
                var_a3 += 1;
                var_a1 -= 1;
              }
            }
            var_a0 = *((void **) (((char *) var_a0) + 4));
          }
          while (var_a0 != NULL);
        }
        if (((var_a1 << 0x10) == 0) && (var_a3 != (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE)))))
        {
          goto block_70;
        }
      }
      else
      {
        temp_a0 = *(*((s32 **) (((char *) arg0) + 0x48)));
        if (temp_a0 < 4)
        {
          *((s16 *) (((char *) (D_800A1234 + (temp_a0 * 0x44))) + 0xA)) = 2;
        }
        var_a0 = *(*((void ***) (D_800AE850 + 0x73F0)));
        var_a1 = 1;
        if (var_a0 != NULL)
        {
          do
          {
            if ((*(*((s32 **) (((char *) var_a0) + 0x48)))) < 4)
            {
              var_a1 &= -(((*((s32 *) (((char *) var_a0) + 0x14))) & 0x100) != 0);
            }
            var_a0 = *((void **) (((char *) var_a0) + 4));
          }
          while (var_a0 != NULL);
        }
        if ((var_a1 << 0x10) != 0)
        {
          block_70:
          *((s32 *) (D_800AE850 + 0x8030)) = 0;

          func_80042F40();
          func_80085778(0, 0x1000);
          func_80085778(0, 0x8000);
        }
      }
    }

  }
  if ((*var_s1) & 1)
  {
    arg1->b1 = (u8) (arg1->b1 | 0x10);
  }
  temp_v1_8 = (arg1->b2 | (~arg1->b1)) | 0x10;
  arg1->b2 = temp_v1_8;
  arg1->b3 = (u8) (arg1->b1 & temp_v1_8);
}
