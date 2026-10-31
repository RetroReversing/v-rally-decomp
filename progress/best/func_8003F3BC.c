void *func_80034FF0();
void *func_80040260();
void *func_8004240C();
extern char D_800C02AE[];
extern void *D_800C35A0;
extern void *D_800C7F84;
extern s32 func_8003EFF8;
extern s32 func_8003F05C;
void func_8003F3BC(s32 arg0, u32 arg1, void **arg2)
{
  int __repair_literal;
  s32 var_s3;
  void *new_var4;
  s32 sp1C;
  s16 var_v0_3;
  s32 temp_v1;
  char *new_var3;
  s32 var_a0;
  u16 temp_v0_3;
  u16 var_a2_2;
  u16 var_s0;
  u32 temp_fp;
  u32 var_a1;
  u32 var_s2;
  u32 var_v0_2;
  u32 temp_v0;
  void **var_a2;
  void **var_v0;
  void *temp_a3;
  s16 new_var;
  void *vec;
  s16 *new_var2;
  void *temp_s0;
  void *temp_v0_2;
  void *temp_v0_4;
  void *var_s1;
  new_var3 = D_800C02AE + 0x7CD6;
  var_a1 = arg1;
  var_a2 = arg2;
  temp_fp = var_a1;
  var_s3 = 0;
  var_s1 = NULL;
  if (((*((u16 *) (((char *) D_800C35A0) + 0x1E))) != 7) || (((u16) (*((u16 *) (((char *) D_800C35A0) + 0xE)))) >= 3U))
  {
    temp_v0 = *((u8 *) (((char *) D_800C35A0) + 0xF));
    temp_v1 = temp_v0 < 3U;
    if (temp_v1)
    {
      var_s2 = 1;
      if (temp_v0 != 0)
      {
        var_a0 = 0;
        do
        {
          __repair_literal = 2;
          temp_v0_2 = func_8004240C((var_a0 * 2) | 1);
          temp_a3 = *((void **) (((char *) temp_v0_2) + 0x178));
          *((void **) new_var3) = temp_v0_2;
          var_s0 = *((u16 *) (((char *) temp_a3) + 8));
          var_a2_2 = *((u16 *) (((char *) temp_a3) + 0xA));
          sp1C = temp_v1;
          vec = (char *) ((u8 *) temp_a3);
          vec = vec + ((s32) 8);
          switch (temp_v0)
          {
            case 0:
              break;

            case 1:
              temp_v0_3 = *((u16 *) (((char *) temp_a3) + 0xC));
              var_s3 = 0x4C;
              var_s0 = ((s16) temp_v0_3) / 2;
              var_a2_2 = (((s16) (*((u16 *) (((char *) temp_a3) + 0xE)))) / 5) - 0x10;
              break;

            case 2:
              if ((*((u16 *) (((char *) D_800C35A0) + 0x12))) & 1)
            {
              var_s3 = 0x20;
              var_s0 += ((s16) (*((u16 *) (((char *) temp_a3) + 0xC)))) / 2;
              var_a2_2 = (var_a2_2 + (((s16) (*((u16 *) (((char *) temp_a3) + 0xE)))) / 3)) - 0x14;
            }
            else
            {
              var_s3 = 0x5C;
              var_s0 += ((s16) (*((u16 *) (((char *) temp_a3) + 0xC)))) / 2;
              var_a2_2 = (var_a2_2 + (((s16) (*((u16 *) (((char *) temp_a3) + 0xE)))) / 5)) + 0xC;
            }
              break;

          }

          if ((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + var_s2)) + 0x31))) * 0x28))) + 0x48))) & 8)
          {
            var_s1 = func_80040260(arg0, (s16) var_s0, (s16) (var_a2_2 + 0xA), 8, &func_8003F05C, 1);
            *((void **) (((char *) var_s1) + 0xA4)) = func_80034FF0(temp_fp + 0x4C, 0);
            *((s32 *) (((char *) var_s1) + 0xA0)) = 2;
            *((u8 *) (((char *) var_s1) + 0x93)) = 0xB4;
            *((void **) (((char *) var_s1) + 0xA8)) = (void *) (*((void **) new_var3));
          }
          temp_s0 = func_80040260(arg0, (s16) var_s0, (s16) ((*((u16 *) (((char *) vec) + 2))) + var_s3), 8, &func_8003EFF8, 1);
          *((void **) (((char *) temp_s0) + 0xA4)) = func_80034FF0(temp_fp + 0x4C);
          new_var4 = temp_s0;
          *((s16 *) (((char *) temp_s0) + 0x7A)) = 5;
          var_a2 = *((void ***) (((char *) (*((void **) (((char *) temp_s0) + 0xA4)))) + 4));
          new_var2 = (s16 *) (((char *) var_s1) + 0x9A);
          *((void **) (((char *) temp_s0) + 0xA8)) = (void *) (*((void **) new_var3));
          temp_v0_4 = var_a2[*((s16 *) (((char *) temp_s0) + 0x7A))];
          var_a1 = (u16) (*((u16 *) (((char *) temp_v0_4) + 6)));
          var_a1 = var_a1 >> 1;
          new_var = (s16) (((u16) (*((u16 *) (((char *) temp_v0_4) + 8)))) >> 1);
          if (temp_v0 < 2U)
          {
            *((s16 *) (((char *) temp_s0) + 0x70)) = (s16) (-((s16) var_a1));
            *((s16 *) (((char *) temp_s0) + 0x72)) = (s16) (-new_var);
            if ((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + var_s2)) + 0x31))) * 0x28))) + 0x48))) & 8)
            {
              var_v0 = &(*((void ***) (((char *) (*((void **) (((char *) temp_s0) + 0xA4)))) + 4)))[*((s16 *) (((char *) var_s1) + 0x7A))];
              goto block_27;
            }
          }
          else
            if (sp1C != 0)
          {
            if ((*((u16 *) (((char *) D_800C35A0) + 0x12))) & 1)
            {
              *((s16 *) (((char *) temp_s0) + 0x98)) = 0x480;
              *((s16 *) (((char *) temp_s0) + 0x9A)) = 0x480;
              if ((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + var_s2)) + 0x31))) * 0x28))) + 0x48))) & 8)
              {
                *((s16 *) (((char *) var_s1) + 0x98)) = 0x480;
                *new_var2 = 0x480;
              }
              var_v0_2 = var_a1;
              if (((s32) var_a1) < 0)
              {
                var_v0_2 = var_a1 + 3;
              }
              var_v0_3 = (((s32) var_v0_2) >> 2) - var_a1;
            }
            else
            {
              var_v0_3 = -((s16) (((u16) (*((u16 *) (((char *) (*var_a2)) + 6)))) >> 1));
            }
            *((s16 *) (((char *) temp_s0) + 0x70)) = var_v0_3;
            *((s16 *) (((char *) temp_s0) + 0x72)) = (s16) (-((s16) (((u16) (*((u16 *) (((char *) (*(*((void ***) (((char *) (*((void **) (((char *) new_var4) + 0xA4)))) + 4))))) + 8)))) >> 1)));
            if ((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + var_s2)) + 0x31))) * 0x28))) + 0x48))) & 8)
            {
              if (1)
              {
                var_v0 = *((void ***) (((char *) (*((void **) (((char *) temp_s0) + 0xA4)))) + 4));
                block_27:
                *((s16 *) (((char *) var_s1) + 0x72)) = (s16) (-((s16) (((u16) (*((u16 *) (((char *) (*var_v0)) + 8)))) >> 1)));

              }
            }
          }
          else
          {
            *((s16 *) (((char *) temp_s0) + 0x98)) = 0x800;
            *((s16 *) (((char *) temp_s0) + 0x9A)) = 0x800;
          }
          var_s2 += 1;
          var_a0 = var_s2 - 1;
        }
        while (temp_v0 >= var_s2);
      }
    }
  }
  if (1)
  {
  }
}
