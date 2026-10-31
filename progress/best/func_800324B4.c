extern f32 D_8009CEC8;
extern s32 D_8009EB80;
extern s32 D_8009EB84;
extern s32 D_8009EB88;
extern s32 D_8009EB8C;
extern u8 D_8009F42C;
extern u8 D_8009F42D;
extern u16 D_8009F42E;
extern u8 D_8009F430;
extern u8 D_8009F431;
extern u16 D_8009F432;
extern s32 D_800C02AE;
void func_800324B4(void *arg0)
{
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 var_a0_4;
  s32 var_v0_8;
  s32 temp_a0_3;
  s32 temp_a0_4;
  s32 temp_a0_5;
  s32 temp_a3;
  s32 temp_fv1;
  s32 temp_t2;
  int temp_t3;
  s32 temp_t4;
  s32 temp_t5;
  s32 temp_v0_2;
  s32 temp_v1;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a1;
  s32 var_a1_2;
  s32 var_a1_3;
  s32 var_a3;
  s32 var_t0;
  s32 var_t1;
  char *new_var;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_5;
  s32 var_v0_6;
  char *new_var2;
  s32 var_v0_7;
  s32 var_v1_2;
  u16 temp_v1_4;
  s32 var_a0_5;
  u32 var_a0_3;
  u32 var_v0_9;
  u32 var_v1;
  void *temp_v0;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v1_2;
  void *temp_v1_3;
  void *var_a2;
  temp_fv1 = (s32) (D_8009CEC8 * ((f32) (*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x7CD2)))) + 0x12)))));
  var_a0 = temp_fv1 * 0x190;
  temp_t5 = 0;
  var_t1 = 0;
  if (var_a0 < temp_t5)
  {
    var_a0 += 0xFFF;
  }
  var_v0 = temp_fv1 * 0x384;
  temp_t3 = var_a0 >> 0xC;
  if (var_v0 < 0)
  {
    var_v0 += 0xFFF;
  }
  var_a2 = arg0;
  temp_t5 = -temp_t3;
  temp_t2 = var_v0 >> 0xC;
  temp_t4 = -temp_t2;
  do
  {
    var_t0 = 0;
    if (((*((void **) (((char *) var_a2) + 0x58))) != NULL) && ((*((void **) (((char *) var_a2) + 0x5C))) != NULL))
    {
      temp_v0 = *((void **) (((char *) var_a2) + 0x78));
      temp_a0 = *((s16 *) (((char *) temp_v0) + 0x10));
      temp_a1 = *((s16 *) (((char *) temp_v0) + 0x12));
      if (temp_t3 < temp_a0)
      {
        var_v0_2 = temp_a0 < temp_t5;
        if (temp_a1 < temp_t5)
        {
          var_t0 = temp_a0;
          var_t0 = var_t0 - temp_a1;
          var_t1 = ((s32) ((*((u16 *) (((char *) var_a2) + 0x88))) - 1)) / 2;
          goto block_10;
        }
      }
      else
      {
        block_10:
        var_v0_2 = temp_a0 < temp_t5;

      }
      if ((var_v0_2 != 0) && (temp_t3 < temp_a1))
      {
        var_t0 = temp_a1 - temp_a0;
        var_t1 = ((s32) ((*((u16 *) (((char *) var_a2) + 0x88))) - 1)) / 2;
      }
      if (temp_a0 >= 0)
      {
        var_v0_3 = temp_t2 < temp_a0;
        if (temp_a1 < temp_t4)
        {
          var_t0 = temp_a0 - temp_a1;
          var_t1 = ((s32) ((*((u16 *) (((char *) var_a2) + 0x88))) - 1)) / 2;
          goto block_17;
        }
      }
      else
      {
        block_17:
        var_v0_3 = temp_t2 < temp_a0;

      }
      var_v0_4 = temp_a0 < 1;
      if (var_v0_3 & (temp_a1 < 1))
      {
        var_t0 = temp_a0 - temp_a1;
        var_t1 = ((s32) ((*((u16 *) (((char *) var_a2) + 0x88))) - 1)) / 2;
        ;
      }
      var_v1 = ~temp_a1;
      if ((temp_a0 < 1) & (temp_t2 < temp_a1))
      {
        var_t0 = temp_a1 - temp_a0;
        var_t1 = ((s32) ((*((u16 *) (((char *) var_a2) + 0x88))) - 1)) / 2;
        var_v1 = ~temp_a1;
      }
      if ((temp_a0 < temp_t4) & (var_v1 >> 0x1F))
      {
        var_t0 = temp_a1 - temp_a0;
        var_t1 = ((s32) ((*((u16 *) (((char *) var_a2) + 0x88))) - 1)) / 2;
      }
      temp_a0_2 = *((s16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) var_a2) + 0x58)))) + 0x78)))) + 0x12));
      if (temp_t3 < temp_a0_2)
      {
        var_v0_5 = temp_a0_2 < temp_t5;
        if (temp_a0 < temp_t5)
        {
          var_t0 = temp_a0_2 - temp_a0;
          var_t1 = 0;
          goto block_27;
        }
      }
      else
      {
        block_27:
        var_v0_5 = temp_a0_2 < temp_t5;

      }
      if ((var_v0_5 != 0) && ((var_a0 >> 0xC) < temp_a0))
      {
        var_t0 = temp_a0 - temp_a0_2;
        var_t1 = 0;
      }
      if (temp_a0_2 >= 0)
      {
        var_v0_6 = temp_t2 < temp_a0_2;
        if (temp_a0 < temp_t4)
        {
          var_t0 = temp_a0_2 - temp_a0;
          var_t1 = 0;
          goto block_34;
        }
      }
      else
      {
        block_34:
        ;

        ;
      }
      if ((temp_t2 < temp_a0_2) & (temp_a0 < 1))
      {
        var_t0 = temp_a0_2 - temp_a0;
        var_t1 = 0;
      }
      new_var2 = (char *) var_a2;
      if ((temp_a0_2 < 1) & (temp_t2 < temp_a0))
      {
        var_t0 = temp_a0 - temp_a0_2;
        var_t1 = 0;
      }
      if ((temp_a0_2 < temp_t4) & (((u32) (~temp_a0)) >> 0x1F))
      {
        var_t0 = temp_a0 - temp_a0_2;
        var_t1 = 0;
      }
      if (var_t1 == 0)
      {
        if (((*((u16 *) (new_var2 + 0xA))) & 0x800) && ((*((u16 *) (((char *) (*((void **) (new_var2 + 0x58)))) + 0xA))) & 0x800))
        {
          var_v0_7 = (*((u16 *) (((char *) (*((void **) (new_var2 + 0x5C)))) + 0xA))) & 0x800;
          goto block_46;
        }
      }
      else
      {
        var_v0_7 = (*((u16 *) (new_var2 + 0xA))) & 0x800;
        block_46:
        var_t0 &= -(var_v0_7 == 0);

      }
    }
    temp_v0_2 = *((s32 *) (new_var2 + 8));
    var_a1 = ((temp_v0_2 & 0x402) == 0x402) * 2;
    var_a0_2 = 0;
    if ((temp_v0_2 & 0x201) == 0x201)
    {
      var_a1 = 1;
    }
    temp_v0_3 = *((void **) (new_var2 + 0x5C));
    var_v1_2 = 0 ^ 1;
    if (temp_v0_3 != NULL)
    {
      temp_v1 = *((s32 *) (((char *) temp_v0_3) + 8));
      if ((temp_v1 & 0x402) == 2)
      {
        var_a0_2 = 2;
      }
      if ((temp_v1 & 0x201) == 1)
      {
        var_a0_2 = 1;
      }
      var_v1_2 = var_a0_2 ^ 1;
    }
    if ((var_v1_2 == 0) & (var_a1 == 1))
    {
      var_v0_8 = *((s16 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 4));
      var_a0_3 = ((u32) ((*((s16 *) (((char *) (*((void **) (((char *) (*((void **) (new_var2 + 0x5C)))) + 0x78)))) + 4))) * (*((s32 *) (((char *) (&D_8009EB8C)) + (D_8009EB80 * 0x18)))))) >> 0xC;
      goto block_59;
    }
    var_a3 = 0;
    if ((var_a0_2 == 2) & (var_a1 == 2))
    {
      var_v0_8 = *((s16 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 6));
      var_a0_3 = ((u32) ((*((s16 *) (((char *) (*((void **) (((char *) (*((void **) (new_var2 + 0x5C)))) + 0x78)))) + 6))) * (*((s32 *) (((char *) (&D_8009EB8C)) + (D_8009EB80 * 0x18)))))) >> 0xC;
      block_59:
      var_a3 = var_v0_8 + var_a0_3;

    }
    temp_v0_4 = *((void **) (new_var2 + 0x78));
    var_a0_4 = *((s16 *) (((char *) temp_v0_4) + 4));
    temp_a1_2 = *((s16 *) (((char *) temp_v0_4) + 6));
    if (var_a0_4 < temp_a1_2)
    {
      var_a0_4 = temp_a1_2;
    }
    var_a1_2 = 0;
    if (var_a3 >= 0x12D)
    {
      new_var = (char *) (&D_8009EB88);
      var_v0_9 = var_a3 * (*((s32 *) (new_var + (D_8009EB80 * 0x18))));
      var_a1_2 = 1;
      goto block_68;
    }
    if (var_a0_4 < 0x12D)
    {
      var_a0_5 = 0x2EE0;
    }
    else
    {
      var_v0_9 = var_a0_4 * (*((s32 *) (((char *) (&D_8009EB88)) + (D_8009EB80 * 0x18))));
      block_68:
      temp_a0_3 = 0x2EE0 - (var_v0_9 >> 0xC);

      var_a0_5 = temp_a0_3 & (((s32) (~temp_a0_3)) >> 0x1F);
    }
    if (var_t0 != 0)
    {
      *((u8 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 0x1A)) = (u8) var_t1;
      *((u8 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 0x1B)) = 2U;
      temp_a0_4 = var_a0_5 - (((u32) (var_t0 * (*((s32 *) (((char *) (&D_8009EB84)) + (D_8009EB80 * 0x18)))))) >> 0xC);
      var_a0_5 = temp_a0_4 & (((s32) (~temp_a0_4)) >> 0x1F);
      *((u16 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 0x18)) = var_a0_5;
      *((u16 *) (((char *) (*((void **) (((char *) (*((void **) (new_var2 + 0x58)))) + 0x78)))) + 0x18)) = var_a0_5;
      temp_v1_2 = *((void **) (new_var2 + 0x58));
      *((s8 *) (((char *) (*((void **) (((char *) temp_v1_2) + 0x78)))) + 0x1A)) = (s8) ((*((u8 *) (((char *) temp_v1_2) + 0x89))) - 2);
      *((s8 *) (((char *) (*((void **) (((char *) (*((void **) (new_var2 + 0x58)))) + 0x78)))) + 0x1B)) = 0;
    }
    if (var_a1_2 != 0)
    {
      *((u16 *) (((char *) (*((void **) (((char *) (*((void **) (new_var2 + 0x5C)))) + 0x78)))) + 0x18)) = var_a0_5;
      *((s8 *) (((char *) (*((void **) (((char *) (*((void **) (new_var2 + 0x5C)))) + 0x78)))) + 0x1A)) = 0;
      *((u8 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 0x1A)) = (u8) ((*((u8 *) (new_var2 + 0x89))) - 2);
    }
    temp_v1_3 = *((void **) (new_var2 + 0x78));
    if ((*((u16 *) (((char *) temp_v1_3) + 0x18))) == 0)
    {
      *((u16 *) (((char *) temp_v1_3) + 0x18)) = var_a0_5;
      do
      {
      }
      while (0);
    }
    var_a1_3 = 0;
    loop_76:
    temp_a3 = var_a1_3 * 8;

    temp_a0_5 = temp_a3 + (D_8009EB80 * 0x18);
    temp_v1_4 = *((u16 *) (((char *) (&D_8009F42E)) + temp_a0_5));
    if (temp_v1_4 != 0)
    {
      if (temp_v1_4 != (*((u16 *) (new_var2 + 0x8C))))
      {
        var_a1_3 += 1;
      }
      else
      {
        var_a1_3 += 1;
        if (((*((&D_8009F42C) + temp_a0_5)) == (*((u8 *) (new_var2 + 0x92)))) && ((*((&D_8009F42D) + temp_a0_5)) == (*((u8 *) (new_var2 + 0x93)))))
        {
          *((u16 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 0x18)) = (u16) (*((u16 *) (((char *) (&D_8009F432)) + temp_a0_5)));
          *((u8 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 0x1A)) = (u8) (*((&D_8009F430) + temp_a0_5));
          *((u8 *) (((char *) (*((void **) (new_var2 + 0x78)))) + 0x1B)) = (u8) (*((&D_8009F431) + (temp_a3 + (D_8009EB80 * 0x18))));
        }
      }
      if (var_a1_3 < 3)
      {
        goto loop_76;
      }
    }
    var_a2 = *((void **) (((char *) var_a2) + 0x5C));
  }
  while ((((s32) var_a2) != ((s32) arg0)) & (var_a2 != NULL));
  goto loop_76;
}
