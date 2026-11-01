typedef struct { int field_0; int field_4; int field_8; } __repair_record_arg0;
void *func_80008500(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15)
{
  s32 temp_a0;
  s32 temp_a1;
  int new_var;
  s32 var_a0;
  s32 var_t5;
  s32 var_v0;
  s32 var_v1;
  void *temp_t3;
  void *temp_t3_2;
  void *temp_t3_3;
  void *temp_t3_4;
  void *temp_t3_5;
  void *temp_t3_6;
  temp_t3_2 = arg0 + 8;
  temp_t3_3 = temp_t3_2 + 8;
  temp_t3_4 = temp_t3_3 + 8;
  temp_t3_5 = temp_t3_4 + 8;
  temp_a0 = (arg2 & 7) << 0x15;
  ((__repair_record_arg0*)arg0)->field_0 = (s32) (temp_a0 | 0xFD100000);
  ((__repair_record_arg0*)arg0)->field_4 = (s32) (arg1 + (((s32) (arg6 * arg3)) / 2));
  ((__repair_record_arg0*)arg0)->field_8 = (s32) (temp_a0 | 0xF5100000);
  new_var = 0x07000000;
  *((s32 *) (((char *) temp_t3_2) + 4)) = (s32) (((((((arg11 & 3) << 0x12) | (((arg13 & 0xF) << 0xE) | new_var)) | ((arg15 & 0xF) << 0xA)) | ((arg10 & 3) << 8)) | ((arg12 & 0xF) * 0x10)) | (arg14 & 0xF));
  *((s32 *) (((char *) temp_t3_2) + 8)) = 0xE6000000;
  *((s32 *) (((char *) temp_t3_3) + 4)) = 0;
  *((s32 *) (((char *) temp_t3_3) + 8)) = 0xF3000000;
  var_t5 = arg3;
  if (arg3 < 0)
  {
    var_t5 = arg3 + 0xF;
  }
  temp_a1 = var_t5 >> 4;
  var_v1 = 0x800;
  if (temp_a1 > 0)
  {
    var_v1 = temp_a1 + 0x7FF;
  }
  var_a0 = (((s32) ((arg3 * arg8) + 3)) >> 2) - 1;
  if (var_a0 >= 0x800)
  {
    var_a0 = 0x7FF;
  }
  if (temp_a1 > 0)
  {
    var_v0 = (var_v1 / temp_a1) & 0xFFF;
  }
  else
  {
    var_v0 = var_v1 & 0xFFF;
  }
  *((s32 *) (((char *) temp_t3_4) + 4)) = (s32) ((((var_a0 & 0xFFF) << 0xC) | 0x07000000) | var_v0);
  temp_t3_6 = temp_t3_5 + 8;
  temp_t3 = temp_t3_6 + 8;
  *((s32 *) (((char *) temp_t3_4) + 8)) = 0xE7000000;
  *((s32 *) (((char *) temp_t3_5) + 4)) = 0;
  *((s32 *) (((char *) temp_t3_6) + 4)) = (s32) ((((((((arg9 & 0xF) << 0x14) | ((arg11 & 3) << 0x12)) | ((arg13 & 0xF) << 0xE)) | ((arg15 & 0xF) << 0xA)) | ((arg10 & 3) << 8)) | ((arg12 & 0xF) * 0x10)) | (arg14 & 0xF));
  *((s32 *) (((char *) temp_t3_5) + 8)) = (s32) (((arg2 & 7) << 0x15) | ((((((s32) ((arg3 >> 1) + 7)) >> 3) & 0x1FF) << 9) | 0xF5000000));
  *((s32 *) (((char *) temp_t3_6) + 8)) = 0xF2000000;
  *((s32 *) (((char *) temp_t3) + 4)) = (s32) (((((arg3 - 1) * 4) & 0xFFF) << 0xC) | (((arg8 - 1) * 4) & 0xFFF));
  return temp_t3 + 8;
}

