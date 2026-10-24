#include "common.h"

void func_800071EC(void *arg0, s32 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 arg10, u8 arg11, u8 arg12, u8 arg13)
{
  int new_var;
  s32 temp_a1;
  temp_a1 = (arg1 & 0xFFFF) * 0x10;
  *((s8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0xC)) = arg2;
  *((s8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0xD)) = arg3;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0xE)) = arg4;
  new_var = 0xFF;
  *((s8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0xF)) = new_var;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x1C)) = arg5;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x1D)) = arg6;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x1E)) = arg7;
  *((s8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x1F)) = new_var;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x2C)) = arg8;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x2D)) = arg9;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x2E)) = arg10;
  *((s8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x2F)) = new_var;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x3C)) = arg11;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x3D)) = arg12;
  *((u8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x3E)) = arg13;
  *((s8 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x3F)) = new_var;
}
