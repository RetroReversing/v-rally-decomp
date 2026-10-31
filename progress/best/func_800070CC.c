s32 func_8000665C();
s32 func_800070CC(void *arg0)
{
  int new_var;
  s32 temp_a0;
  unsigned char temp_a0_2;
  s32 temp_a2;
  s32 temp_a3;
  s32 temp_v0;
  temp_v0 = func_8000665C(arg0, 4);
  temp_v0 &= 0xFFFF;
  temp_a0 = temp_v0 * 16;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 6)) = 0;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x16)) = 0;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x26)) = 0;
  *((s16 *) (((char *) (temp_a0 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x36)) = 0;
  *((u8 *) (((char *) ((temp_v0 * 16) + (*((s32 *) (((char *) arg0) + 0x70))))) + 0xF)) = 255;
  *((u8 *) (((char *) ((temp_v0 * 16) + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x1F)) = 255;
  *((u8 *) (((char *) ((temp_v0 * 16) + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x2F)) = 255;
  temp_a2 = temp_v0 & 31;
  temp_a3 = temp_a2 << 17;
  *((u8 *) (((char *) ((temp_v0 * 16) + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x3F)) = 255;
  arg0 = *((void **) (((char *) arg0) + 20));
  temp_a0_2 = (temp_a2 + 2) * 2;
  new_var = (temp_a2 + 1) << 9;
  *((void **) (((char *) arg0) + 20)) = arg0 + 8;
  *((s32 *) arg0) = ((temp_a3 | new_var) | temp_a0_2) | 0x07000000;
  *((s32 *) (((char *) arg0) + 4)) = ((temp_a0_2 << 8) | temp_a3) | ((temp_a2 + 3) * 2);
  return temp_v0;
}
