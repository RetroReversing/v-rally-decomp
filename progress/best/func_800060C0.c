void func_800060C0(void *arg0)
{
  s32 var_a0;
  s32 var_a1;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_5;
  char *new_var;
  void *temp_v1_6;
  void *temp_v1_7;
  void *temp_v1_8;
  void *var_v1;
  new_var = (char *) arg0;
  if (!((*((u16 *) (new_var + 0x78))) & 1))
  {
    temp_v1 = *((void **) (new_var + 0x14));
    *((void **) (new_var + 0x14)) = (void *) (temp_v1 + 8);
    *((s32 *) (((char *) temp_v1) + 0)) = 0xD9C0F9FA;
    *((s32 *) (((char *) temp_v1) + 4)) = 0;
    temp_v1_2 = *((void **) (new_var + 0x14));
    *((void **) (new_var + 0x14)) = (void *) (temp_v1_2 + 8);
    *((s32 *) (((char *) temp_v1_2) + 0)) = 0xD9FFFFFF;
    *((s32 *) (((char *) temp_v1_2) + 4)) = 5;
    temp_v1_3 = *((void **) (new_var + 0x14));
    var_a1 = 0xFCFFFFFF;
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_3 + 8);
    *((s32 *) (((char *) temp_v1_3) + 0)) = 0xD7000000;
    *((s32 *) (((char *) temp_v1_3) + 4)) = 0;
    var_v1 = *((void **) (new_var + 0x14));
    var_a0 = 0xFFFE793C;
    *((void **) (temp_v1 = new_var + 0x14)) = (void *) (var_v1 + 8);
  }
  else
  {
    temp_v1 = *((void **) (new_var + 0x14));
    *((void **) (new_var + 0x14)) = (void *) (temp_v1 + 8);
    *((s32 *) (((char *) temp_v1) + 0)) = 0xE7000000;
    *((s32 *) (((char *) temp_v1) + 4)) = 0;
    temp_v1_5 = *((void **) (new_var + 0x14));
    *((void **) (0x14 + ((char *) arg0))) = (void *) (temp_v1_5 + 8);
    *((s32 *) (((char *) temp_v1_5) + 0)) = 0xE3000A01;
    *((s32 *) (((char *) temp_v1_5) + 4)) = 0;
    temp_v1_6 = *((void **) (new_var + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_6 + 8);
    *((s32 *) (((char *) temp_v1_6) + 0)) = 0xD7000000;
    *((s32 *) (((char *) temp_v1_6) + 4)) = 0;
    temp_v1_7 = *((void **) (new_var + 0x14));
    *((void **) (new_var + 0x14)) = (void *) (temp_v1_7 + 8);
    *((s32 *) (((char *) temp_v1_7) + 0)) = 0xFCFFFFFF;
    temp_v1 = new_var + 0x14;
    *((s32 *) (((char *) temp_v1_7) + 4)) = 0xFFFE793C;
    temp_v1_8 = *((void **) (new_var + 0x14));
    *((void **) (new_var + 0x14)) = (void *) (temp_v1_8 + 8);
    *((s32 *) (((char *) temp_v1_8) + 0)) = 0xD9E0F9FA;
    *((s32 *) (((char *) temp_v1_8) + 4)) = 0;
    var_a1 = 0xD9FFFFFF;
    var_v1 = *((void **) (new_var + 0x14));
    var_a0 = 0x200005;
    *((void **) (new_var + 0x14)) = (void *) (var_v1 + 8);
  }
  *((s32 *) (((char *) var_v1) + 0)) = var_a1;
  *((s32 *) (((char *) var_v1) + 4)) = var_a0;
}
