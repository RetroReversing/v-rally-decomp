s32 func_8001FEDC();
s32 func_8002D2A0();
s32 func_8002E778();
extern char D_800AE850[];
void func_80034134(void *arg0, void *arg1)
{
  char pad[4];
  s32 vector[9];
  s32 sp44;
  void *sp4C;
  s16 temp_a1;
  s16 temp_a2;
  s16 temp_t1;
  s16 temp_t2;
  s32 temp_fp;
  s32 temp_lo;
  s32 temp_s7;
  s32 temp_v1_2;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s32 var_s6;
  s32 var_v0;
  u32 temp_s4;
  u32 temp_s5;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v1;
  void *var_s0;
  void *var_s2;
  temp_v1 = *((void **) (((char *) arg1) + 0x60));
  var_s0 = *(*((void ***) (D_800AE850 + 0x73F0)));
  temp_s7 = *((s32 *) (((char *) temp_v1) + 0x17C));
  sp44 = *((s32 *) (((char *) temp_v1) + 0x14));
  var_s6 = 0;
  sp4C = *(*((void ***) (((char *) arg1) + 0x8C)));
  *((s32 *) (((char *) arg0) + 0x84)) = 0;
  *((s32 *) (((char *) arg0) + 0x98)) = 0;
  *((s32 *) (((char *) arg0) + 0)) = 0;
  if (var_s0 != NULL)
  {
    var_s2 = arg0;
    do
    {
      if (((var_s0 != arg1) && (((*((s32 *) (((char *) var_s2) + 4)) = (s32) (*(*((s32 **) (((char *) var_s0) + 0x8C)))), *((s32 *) (((char *) var_s2) + 0x14)) = (s32) (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x60)))) + 0x14))), *((s32 *) (((char *) var_s2) + 0x24)) = (s32) (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x60)))) + 0x28))), temp_v1_2 = *((s32 *) (((char *) var_s2) + 4)), *((s32 *) (((char *) var_s2) + 0x34)) = (s32) (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x60)))) + 0x30))), temp_v1_2 == sp4C)) || (temp_v1_2 == (*((s32 *) (((char *) sp4C) + 0x5C)))))) && (((temp_v0 = *((void **) (((char *) arg1) + 0x80)), temp_t2 = (*((s32 *) (((char *) temp_v0) + 0x2B8))) - (*((s32 *) (((char *) temp_v0) + 0x2CC))), temp_v0_2 = *((void **) (((char *) arg1) + 0x80)), temp_t1 = (*((s32 *) (((char *) temp_v0_2) + 0x2C0))) - (*((s32 *) (((char *) temp_v0_2) + 0x2D4))), temp_v0_3 = *((void **) (((char *) arg1) + 0x80)), temp_v0_4 = *((void **) (((char *) arg1) + 0x80)), temp_a2 = (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x80)))) + 0x254))) - (*((s32 *) (((char *) (*((void **) (((char *) arg1) + 0x80)))) + 0x2CC))), temp_a1 = (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x80)))) + 0x25C))) - (*((s32 *) (((char *) (*((void **) (((char *) arg1) + 0x80)))) + 0x2D4))), temp_lo = ((s16) ((*((s32 *) (((char *) temp_v0_4) + 0x248))) - (*((s32 *) (((char *) temp_v0_4) + 0x25C))))) * ((s16) ((*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x80)))) + 0x2CC))) - (*((s32 *) (((char *) (*((void **) (((char *) arg1) + 0x80)))) + 0x254))))), temp_s5 = (temp_t2 * temp_a1) - (temp_t1 * temp_a2), temp_s4 = (((s16) ((*((s32 *) (((char *) temp_v0_3) + 0x240))) - (*((s32 *) (((char *) temp_v0_3) + 0x254))))) * ((s16) ((*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x80)))) + 0x2D4))) - (*((s32 *) (((char *) (*((void **) (((char *) arg1) + 0x80)))) + 0x25C)))))) - temp_lo, temp_fp = (temp_t2 * temp_a2) + (temp_t1 * temp_a1), ((*((s32 *) (((char *) var_s2) + 0x24))) < sp44) == 0)) || ((*((s32 *) (((char *) var_s2) + 4))) == (*((s32 *) (((char *) sp4C) + 0x5C))))))
      {
        *((s32 *) (((char *) var_s2) + 0x44)) = func_8001FEDC(var_s0, temp_a1, temp_a2);
        *((void **) (((char *) var_s2) + 0x74)) = var_s0;
        *((s32 *) (((char *) var_s2) + 0x64)) = (s32) (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x60)))) + 0x17C)));
        vector[0] = (*((s32 *) (((char *) (*((void **) (((char *) arg1) + 0x58)))) + 0xC))) - (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x58)))) + 0xC)));
        vector[2] = (*((s32 *) (((char *) (*((void **) (((char *) arg1) + 0x58)))) + 0x14))) - (*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x58)))) + 0x14)));
        func_8002E778(&vector[0], &vector[0]);
        *((s32 *) (((char *) var_s2) + 0x54)) = func_8002D2A0(vector[0] + vector[2]);
        if (((temp_s5 >> 0x1F) & (temp_s4 >> 0x1F)) && ((temp_v1_3 = *((s32 *) (((char *) var_s2) + 0x64)), (temp_v1_3 < (temp_s7 + 0x14)) != 0)))
        {
          var_v0 = ((s32) temp_s5) > 0;
          if ((temp_s7 - 0x14) < temp_v1_3)
          {
            *((s32 *) (((char *) (((*((s32 *) (((char *) arg0) + 0x84))) * 4) + arg0)) + 0x88)) = var_s6;
            *((s32 *) (((char *) arg0) + 0x84)) = (s32) ((*((s32 *) (((char *) arg0) + 0x84))) + 1);
            goto block_11;
          }
        }
        else
        {
          block_11:
          var_v0 = ((s32) temp_s5) > 0;

        }
        if (var_v0 & (temp_s4 >> 0x1F))
        {
          if (arg0)
          {
            temp_v1_4 = *((s32 *) (((char *) var_s2) + 0x64));
          }
          else
          {
            temp_v1_4 = *((s32 *) (((char *) var_s2) + 0x64));
          }
          if ((temp_v1_4 < (temp_s7 + 0x19)) && ((temp_s7 - 0x19) < temp_v1_4))
          {
            *((s32 *) (((char *) (var_s2 = ((*((s32 *) (((char *) arg0) + 0x98))) * 4) + arg0)) + 0x9C)) = var_s6;
            if (temp_fp < 0)
            {
              *((s32 *) (((char *) (((*((s32 *) (((char *) arg0) + 0x98))) * 4) + arg0)) + 0xAC)) = 0;
            }
            else
            {
              *((s32 *) (((char *) (((*((s32 *) (((char *) arg0) + 0x98))) * 4) + arg0)) + 0xAC)) = 1;
            }
            *((s32 *) (((char *) arg0) + 0x98)) = (s32) ((*((s32 *) (((char *) arg0) + 0x98))) + 1);
          }
        }
        var_s2 += 4;
        temp_s4 += 0;
        var_s6 += 1;
        *((s32 *) (((char *) arg0) + 0)) = (s32) ((*((s32 *) (((char *) arg0) + 0))) + 1);
      }
      var_s0 = *((void **) (((char *) var_s0) + 4));
    }
    while (var_s0 != NULL);
  }
}
