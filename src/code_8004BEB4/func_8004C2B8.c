#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  s32 pad10[4];
  s32 w20;
  s32 w24;
  s32 w28;
  s32 w2C;
  s32 w30;
  s32 w34;
  s32 w38;
  s32 w3C;
  s32 w40;
  s32 w44;
  s32 w48;
  s32 w4C;
  u8 b50[12];
  u8 b5C[4];
  s32 pad60[2];
} FuncBuf;
void func_8004C370(s32, FuncBuf *, s32, s32);
void func_8004C2B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, u8 arg5)
{
  FuncBuf buf;
  u16 a1 = arg1;
  u16 a2 = arg2;
  u16 a3 = arg3;
  u16 v1 = arg4;
  buf.w20 = a1;
buf.w40 = 0;
  buf.w30 = a2;
  buf.w24 = a3;
  buf.w44 = 0;
  buf.w28 = a3 + 1;
  buf.w2C = a1 + 1;
  buf.w48 = 0;
  buf.w3C = a2 + 1;
  buf.w4C = 0;
  buf.b50[0] = 0xFF;
  buf.b50[4] = 0xFF;
  buf.b50[8] = 0xFF;
  buf.b50[1] = 0xFF;
  buf.b50[5] = 0xFF;
  buf.b50[9] = 0xFF;
  buf.b50[2] = 0xFF;
  buf.b50[6] = 0xFF;
  buf.b50[10] = 0xFF;
  buf.b50[3] = 0xFF;
  buf.b50[7] = 0xFF;
  buf.b50[11] = 0xFF;
  buf.w34 = v1;
  buf.w38 = v1 + 1;
  buf.b5C[0] = arg5;
  buf.b5C[1] = arg5;
  buf.b5C[2] = arg5;
  buf.b5C[3] = arg5;
  func_8004C370(arg0, &buf, a2 + 1, a3 + 1);
}


