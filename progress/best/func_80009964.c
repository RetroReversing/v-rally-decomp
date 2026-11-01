s32 func_80009964(void *arg0, s8 arg1)
{
  s32 temp_a1_2;
    s32 __repair_temp_a1_2_1;
  s32 temp_a1_5;
  s32 temp_a3;
  
  void *new_var;
  s32 temp_v1_5;
  s32 var_v0;
  u32 temp_a0;
  u32 temp_a0_2;
  u32 temp_a0_3;
  u32 temp_a1;
  u32 temp_v0_2;
  u32 temp_v0_4;
  u32 temp_v0_6;
  u32 temp_v0_8;
  void *temp_v0_3;
  void *temp_v0_5;
  int new_var2;
  void *temp_v0_7;
  void *temp_v0_9;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  void *temp_v1_6;
  temp_a3 = arg1 & 0xFF;
  if (temp_a3 == 1)
  {
    *((s32 *) (((char *) arg0) + 0x7C)) = 0;
    *((s32 *) (((char *) arg0) + 0x80)) = 0;
  }
  temp_a0 = *((u32 *) (((char *) arg0) + 0x84));
  temp_a1 = temp_a0 >> 0x1F;
  if (((((temp_a0 >> 0x15) & 1) ^ temp_a1) | (temp_a3 == 1)) != 0)
  {
    temp_a1_2 = (temp_a0 & 0xFFDFFFFF) | (temp_a1 << 0x15);
    *((u32 *) (((char *) arg0) + 0x84)) = (u32) temp_a1_2;
    new_var2 = 0x80008000;
    if (temp_a1_2 < 0)
    {
      temp_v1 = *((void **) (((char *) arg0) + 0x14));
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1 + 8);
      *((s32 *) (((char *) temp_v1) + 0)) = 0xD7000002;
    }
    else
    {
      temp_v1_2 = *((void **) (((char *) arg0) + 0x14));
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_2 + 8);
      *((s32 *) (((char *) temp_v1_2) + 0)) = 0xD7000000;
    }
    new_var = *((void **) (((char *) arg0) + 0x14));
    *((s32 *) (((char *) new_var) + 4)) = new_var2;
  }
  temp_a1_2 = ((*((u32 *) (((char *) arg0) + 0x84))) >> 0x1B) & 0xF;
  if (((((*((u32 *) (((char *) arg0) + 0x84))) >> 0x11) & 0xF) != temp_a1_2) | ((arg1 & 0xFF) == 1))
  {
    temp_v0_2 = ((*((u32 *) (((char *) arg0) + 0x84))) & 0xFFE1FFFF) | (temp_a1_2 << 0x11);
    *((u32 *) (((char *) arg0) + 0x84)) = temp_v0_2;
    if (!((temp_v0_2 >> 0x1B) & 0xF))
    {
      temp_v0_3 = *((void **) (((char *) arg0) + 0x14));
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v0_3 + 8);
      *((s32 *) (((char *) temp_v0_3) + 0)) = 0xE3001201;
      *((s32 *) (((char *) temp_v0_3) + 4)) = 0;
    }
    else
    {
      temp_v1_3 = *((void **) (((char *) arg0) + 0x14));
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_3 + 8);
      *((s32 *) (((char *) temp_v1_3) + 0)) = 0xE3001201;
      *((s32 *) (((char *) temp_v1_3) + 4)) = 0x2000;
    }
  }
  temp_a0_2 = *((u32 *) (((char *) arg0) + 0x84));
  __repair_temp_a1_2_1 = (temp_a0_2 >> 0x1A) & 1;
  if (((((temp_a0_2 >> 0x10) & 1) ^ __repair_temp_a1_2_1) | ((arg1 & 0xFF) == 1)) != 0)
  {
    temp_v0_4 = (temp_a0_2 & 0xFFFEFFFF) | (__repair_temp_a1_2_1 << 0x10);
    *((u32 *) (((char *) arg0) + 0x84)) = temp_v0_4;
    if (temp_v0_4 & 0x04000000)
    {
      temp_v1_4 = *((void **) (((char *) arg0) + 0x14));
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_4 + 8);
      *((s32 *) (((char *) temp_v1_4) + 0)) = 0xE3000C00;
      *((s32 *) (((char *) temp_v1_4) + 4)) = 0x80000;
    }
    else
    {
      temp_v0_5 = *((void **) (((char *) arg0) + 0x14));
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v0_5 + 8);
      *((s32 *) (((char *) temp_v0_5) + 0)) = 0xE3000C00;
      *((s32 *) (((char *) temp_v0_5) + 4)) = 0;
    }
  }
  temp_a1_2 = ((*((u32 *) (((char *) arg0) + 0x84))) >> 0x16) & 3;
  if ((((((*((u32 *) (((char *) arg0) + 0x84))) >> 0xC) & 3) != temp_a1_2) | ((arg1 & 0xFF) == 1)) != 0)
  {
    temp_v0_6 = ((*((u32 *) (((char *) arg0) + 0x84))) & (~0x3000)) | (temp_a1_2 << 0xC);
    *((u32 *) (((char *) arg0) + 0x84)) = temp_v0_6;
    temp_v1_5 = (temp_v0_6 >> 0x16) & 3;
    switch (temp_v1_5)
    {
      case 0:
        temp_v0_7 = *((void **) (((char *) arg0) + 0x14));
        *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v0_7 + 8);
        *((s32 *) (((char *) temp_v0_7) + 0)) = 0xE3001001;
        *((s32 *) (((char *) temp_v0_7) + 4)) = 0;
        break;

      case 2:
        *((void **) (((char *) arg0) + 0x14)) = (void *) ((*((void **) (((char *) arg0) + 0x14))) + 8);
        var_v0 = 0xC000;
        goto block_30;

      case 1:
        *((void **) (((char *) arg0) + 0x14)) = (void *) ((*((void **) (((char *) arg0) + 0x14))) + 8);
        var_v0 = 0x8000;
        block_30:
      *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x14)))) + 0)) = 0xE3001001;

        *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x14)))) + 4)) = var_v0;
        break;

    }

  }
  temp_a0_3 = *((u32 *) (((char *) arg0) + 0x84));
  temp_a1_5 = (temp_a0_3 >> 0x18) & 3;
  if (((((temp_a0_3 >> 0xE) & 3) != temp_a1_5) | ((arg1 & 0xFF) == 1)) != 0)
  {
    temp_v0_8 = (temp_a0_3 & 0xFFFF3FFF) | (temp_a1_5 << 0xE);
    *((u32 *) (((char *) arg0) + 0x84)) = temp_v0_8;
    if (!((temp_v0_8 >> 0x18) & 3))
    {
      temp_v0_9 = new_var;
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v0_9 + 8);
      *((s32 *) (((char *) temp_v0_9) + 0)) = 0xD9DFFFFF;
      *((s32 *) (((char *) temp_v0_9) + 4)) = 0;
    }
    else
    {
      temp_v1_6 = *((void **) (((char *) arg0) + 0x14));
      *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_6 + 8);
      *((s32 *) (((char *) temp_v1_6) + 0)) = 0xD9FFFFFF;
      *((s32 *) (((char *) temp_v1_6) + 4)) = 0x200000;
    }
  }
  return 1;
}

