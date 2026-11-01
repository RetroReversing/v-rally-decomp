#ifndef M2C_DEFINES
#define M2C_DEFINES
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
s32 func_800056FC();
s32 func_80005C48();
void *func_80006008();
s32 func_80006014();
s32 osVirtualToPhysical(s32, void *);
extern void *D_800A1108;
void func_8000EC94(s32 arg0, void *arg1, void *arg2)
{
  void *__repair_cached_pointer = D_800A1108;
  s32 temp_s5;
  s32 __repair_temp_s5_1;
  s32 temp_v0;
  void *temp_s0;
  void *temp_s0_2;
  int new_var2;
  void *temp_s0_3;
  void *temp_s0_4;
  void *temp_s0_5;
  void *temp_s0_6;
  void *temp_s0_7;
  void *temp_v0_2;
  volatile unsigned int new_var;
  temp_s5 = func_80005C48(D_800A1108);
  temp_v0 = func_800056FC(arg0);
  temp_v0_2 = func_80006008(temp_v0);
  *((s32 *) (((char *) temp_v0_2) + 0)) = (s32) (((((s32) (((f32) (*((s16 *) (((char *) arg1) + 0)))) * 4.0f)) & 0xFFF) << 0xC) | ((((s32) (((f32) (*((s16 *) (((char *) arg1) + 2)))) * 4.0f)) & 0xFFF) | 0xED000000));
  temp_s0 = temp_v0_2 + 8;
  temp_s0_2 = temp_s0 + 8;
  new_var = (((s32) (((f32) (*((s16 *) (((char *) arg1) + 4)))) * 4.0f)) & 0xFFF) << 0xC;
  new_var = new_var | (((s32) (((f32) (*((s16 *) (((char *) arg1) + 6)))) * 4.0f)) & 0xFFF);
  temp_s0_3 = temp_s0_2 + 8;
  temp_s0_4 = temp_s0_3 + 8;
  *((s32 *) (((char *) temp_v0_2) + 4)) = (s32) new_var;
  *((s32 *) (((char *) temp_v0_2) + 8)) = 0xE7000000;
  *((s32 *) (((char *) temp_s0) + 4)) = 0;
  *((s32 *) (((char *) temp_s0) + 8)) = 0xE3000A01;
  *((s32 *) (((char *) temp_s0_2) + 4)) = 0x300000;
  *((s32 *) (((char *) temp_s0_2) + 8)) = (s32) ((((*((s16 *) (((char *) __repair_cached_pointer) + 4))) - 1) & 0xFFF) | 0xFF100000);
  temp_s0_5 = temp_s0_4 + 8;
  *((s32 *) (((char *) temp_s0_3) + 4)) = osVirtualToPhysical(temp_s5, temp_s0_2);
  *((s32 *) (((char *) temp_s0_3) + 8)) = 0xF7000000;
  temp_s0_6 = temp_s0_5 + 8;
  new_var2 = (((u8) (*((u8 *) (((char *) arg2) + 2)))) >> 2) & 0x3E;
  __repair_temp_s5_1 = ((((*((u8 *) (((char *) arg2) + 0))) << 8) & 0xF800) | (((*((u8 *) (((char *) arg2) + 1))) * 8) & 0x7C0)) | new_var2;
  *((s32 *) (((char *) temp_s0_4) + 4)) = (s32) ((((__repair_temp_s5_1 | 1) << 0x10) | 1) | __repair_temp_s5_1);
  temp_s0_7 = temp_s0_6 + 8;
  *((s32 *) (((char *) temp_s0_4) + 8)) = (s32) (((((*((s16 *) (((char *) arg1) + 4))) - 1) & 0x3FF) << 0xE) | (((((*((s16 *) (((char *) arg1) + 6))) - 1) & 0x3FF) * 4) | 0xF6000000));
  *((s32 *) (((char *) temp_s0_5) + 4)) = (s32) (((((u16) (*((s16 *) (((char *) arg1) + 0)))) & 0x3FF) << 0xE) | ((((u16) (*((s16 *) (((char *) arg1) + 2)))) & 0x3FF) * 4));
  *((s32 *) (((char *) temp_s0_5) + 8)) = 0xE7000000;
  *((s32 *) (((char *) temp_s0_6) + 4)) = 0;
  do
  {
  }
  while (0);
  *((s32 *) (((char *) temp_s0_6) + 8)) = 0xE3000A01;
  *((s32 *) (((char *) temp_s0_7) + 4)) = 0;
  func_80006014(temp_v0, temp_s0_7 + 8);
}

