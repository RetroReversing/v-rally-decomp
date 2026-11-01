void *func_80034FF0();
void *func_80040260();
void *func_8004240C();
s32 func_800556C4();
s32 func_80055738();
extern volatile int D_800C02AE[];
extern void *D_800C7F84;
extern s32 func_8003BB6C;
extern s32 func_8003C864;
void func_8003BBDC(s32 arg0, s32 arg1, s32 arg2)
{
  char *__repair_addr;
  s32 sp1C;
  u32 sp24;
  s32 lower;
  s32 temp_a3;
  char *new_var;
  s32 var_a1;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_s1;
  s32 var_s2;
  s32 var_s3;
  s32 var_s4;
  s32 var_s6;
  s32 var_s7;
  u32 temp_a2;
  int new_var2;
  u32 temp_t1;
  u32 temp_v1;
  u32 var_s5;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  temp_v0 = (char *) D_800C02AE;
  temp_v0 += (s32) 0x32F2;
  temp_v0 = *((void **) (D_800C02AE + 0x32F2));
  temp_v0 = (void *) temp_v0;
  var_s7 = arg2;
  temp_a2 = *((u16 *) (((char *) temp_v0) + 0x1E));
  var_s3 = arg0;
  if ((temp_a2 != 7) && ((temp_a2 != 0) & (temp_a2 != 5)))
  {
    temp_v0_2 = func_80034FF0(arg1 + 0x4C, 0, temp_a2);
    func_80055738(temp_v0_2);
    temp_t1 = *((u16 *) (((char *) temp_v0) + 0xE));
    new_var2 = temp_t1 != 0;
    sp24 = (u32) temp_t1;
    var_s5 = 1;
    sp1C = (s32) (*((u16 *) (((char *) (*(*((void ***) (((char *) temp_v0_2) + 4))))) + 6)));
    if (new_var2)
    {
      var_s6 = var_s7 & 0xFFFF;
      var_s4 = 1;
      do
      {
        temp_v0 = func_8004240C(var_s4);
        temp_v0_2 = *((void **) (((char *) temp_v0) + 0x178));
        new_var = (char *) temp_v0_2;
        temp_v1 = *((u16 *) (((char *) temp_v0) + 0xE));
        D_800C7F84 = temp_v0;
        temp_a3 = *((s16 *) (new_var + 8));
        var_s1 = *((s16 *) (new_var + 0xC));
        var_s2 = *((s16 *) (new_var + 0xA));
        lower = (*((s16 *) (new_var + 0xE))) - 8;
        var_a2 = temp_a3 + 0x14;
        switch (temp_v1)
        {
          case 1:
            *((void **) (((char *) func_80040260(var_s3, (s16) (((var_s1 - 0x10) - sp1C) - 0x18), 0x1B, var_s6, &func_8003BB6C)) + 0xA4)) = temp_v0_2;
            func_800556C4(temp_v0_2);
            __repair_addr = (char *) ((*((void **) (D_800C02AE + 0x32F2))) + ((*((u8 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x32))) * 0x28));
            if ((*((u8 *) (((char *) __repair_addr) + 0x48))) & 1)
          {
            temp_v0_3 = func_80040260(var_s3, (s16) (var_s1 - 0x66), (s16) (var_s2 + 7), var_s6, &func_8003C864);
            *((void **) (((char *) temp_v0_3) + 0xA4)) = temp_v0_2;
            *((void **) (((char *) temp_v0_3) + 0xA8)) = D_800C7F84;
            block_15:
            func_800556C4(temp_v0_2);

          }
            break;

          case 2:
            if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x12))) & 1)
          {
            var_a1 = var_s1 - 0x12;
            var_a2_2 = var_s2 + 7;
          }
          else
          {
            if ((*((s32 *) (((char *) temp_v0) + 0xC))) == 3)
            {
              var_a2 = temp_a3 + 6;
            }
            var_a1 = var_a2;
            var_a2_2 = 0xFFF7;
            var_a2_2 = lower + var_a2_2;
          }
            *((void **) (((char *) func_80040260(var_s3, (s16) var_a1, (s16) var_a2_2, var_s7 & 0xFFFF, &func_8003BB6C, 0)) + 0xA4)) = temp_v0_2;
          {
            func_800556C4(temp_v0_2);
            break;
          }

        }

        var_s5 += 1;
        var_s4 += 2;
      }
      while (sp24 >= var_s5);
    }
  }
}

