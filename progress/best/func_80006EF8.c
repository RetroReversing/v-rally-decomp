unsigned short func_8000665C();
static inline char *inline_fn(s32 arg0, void *arg1, int arg2)
{
  return ((char *) (arg0 + (*((s32 *) (((char *) arg1) + arg2))))) + 6;
}

s32 func_80006EF8(void *arg0, s16 arg1, s32 arg2)
{
  s32 var_a2;
  s32 temp_a0;
  s32 temp_a0_2;
  void **new_var;
  s32 temp_a2;
  s32 temp_v0;
  u16 temp_a3;
  void *temp_t0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  void *temp_v1_5;
  int new_var2;
  var_a2 = arg2;
  temp_a3 = *((u16 *) (((char *) arg0) + 0x78));
  if (!(temp_a3 & 1))
  {
    temp_v1 = *((void **) (((char *) arg0) + 0x14));
    var_a2 = 0xFC119BFF;
    *((u16 *) (((char *) arg0) + 0x78)) = (u16) (temp_a3 | 1);
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1 + 8);
    *((s32 *) (((char *) temp_v1) + 0)) = 0xE7000000;
    *((s32 *) (((char *) temp_v1) + 4)) = 0;
    temp_v1_2 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_2 + 8);
    *((s32 *) (((char *) temp_v1_2) + 0)) = 0xE3000A01;
    *((s32 *) (((char *) temp_v1_2) + 4)) = 0x100000;
    temp_v1_3 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_3 + 8);
    *((s32 *) (((char *) temp_v1_3) + 0)) = 0xFC119BFF;
    *((s32 *) (((char *) temp_v1_3) + 4)) = 0xFFFEFE38;
    temp_v1_4 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_4 + 8);
    *((s32 *) (((char *) temp_v1_4) + 0)) = 0xD9E0F9FA;
    new_var = (void **) (((char *) arg0) + 0x14);
    *((s32 *) (((char *) temp_v1_4) + 4)) = 0;
    temp_v1_5 = *((void **) (((char *) arg0) + 0x14));
    *new_var = (void *) (temp_v1_5 + 8);
    *((s32 *) (((char *) temp_v1_5) + 0)) = 0xD9FFFFFF;
    *((s32 *) (((char *) temp_v1_5) + 4)) = 0x200005;
  }
  temp_v0 = func_8000665C(arg0, 4, var_a2, temp_a3) & 0xFFFF;
  temp_a0 = temp_v0 * 0x10;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 4)) = arg1;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x14)) = arg1;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x24)) = arg1;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x34)) = arg1;
  new_var2 = 0x70;
  *((s16 *) inline_fn(temp_a0, arg0, new_var2)) = 0;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + new_var2))))) + 0x16)) = 0;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + new_var2))))) + 0x26)) = 0;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + new_var2))))) + 0x36)) = 0;
  *((u8 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + new_var2))))) + 0xF)) = 0xFF;
  *((u8 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x1F)) = 0xFF;
  *((u8 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x2F)) = 0xFF;
  temp_a2 = temp_v0 & 0x1F;
  temp_a2 = temp_a2 << 0x11;
  *((u8 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + new_var2))))) + 0x3F)) = 0xFF;
  temp_t0 = *((void **) (((char *) arg0) + 0x14));
  temp_a0_2 = temp_a2 + 2;
  temp_a0_2 = temp_a0_2 * 2;
  *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_t0 + 8);
  *((s32 *) (((char *) temp_t0) + 0)) = (s32) (((temp_a2 | ((temp_a2 + 1) << 9)) | temp_a0_2) | 0x07000000);
  *((s32 *) (((char *) temp_t0) + 4)) = (s32) ((temp_a2 | (temp_a0_2 << 8)) | ((temp_a2 + 3) * 2));
  return temp_v0;
}
