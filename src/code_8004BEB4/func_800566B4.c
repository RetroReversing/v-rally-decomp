#include "common.h"

extern u8 D_800AE850[];
void func_80008CB8(void *, u16, u8, u8, s32);
void func_80008DBC(void *, u16, u8, u8);
void func_80008E80(void *, void *, s32, u16 *);
void func_80009164(void *, s32, u8);
void func_80009920(void *, u16, u16, u16);
void func_80009C90(void *, s32);
typedef struct
{
  u8 w[4];
  s16 h;
} Elem6;
void func_800566B4(void *arg0, u8 *arg1, Elem6 *arg2)
{
  u16 out[3];
  Elem6 e[3];
  u8 *s0;
  u8 *v1;

  *((u32 *) (((u8 *) arg0) + 0x84)) = (*((u32 *) (((u8 *) arg0) + 0x84)) & 0xFCFFFFFF) | 0x1000000;
  s0 = arg1;
  v1 = *((u8 **) (D_800AE850 + 0x237C)) + (*((u16 *) (s0 + 0x20))) * 0x14;
  func_80009164(arg0, **((s32 **) (*((u8 **) (v1 + 0x10))) + 1), v1[0xF]);
  func_80009C90(arg0, 0);
  e[0] = arg2[*((u16 *) (s0 + 0x14))];
  e[1] = arg2[*((u16 *) (s0 + 0x10))];
  e[2] = arg2[*((u16 *) (s0 + 0x12))];
  func_80008E80(arg0, e, 3, out);
  func_80008CB8(arg0, out[0], s0[8], s0[9], s0[0xA]);
  func_80008CB8(arg0, out[1], s0[0], s0[1], s0[2]);
  func_80008CB8(arg0, out[2], s0[4], s0[5], s0[6]);
  func_80008DBC(arg0, out[0], s0[0x1C], s0[0x1D]);
  func_80008DBC(arg0, out[1], s0[0x18], s0[0x19]);
  func_80008DBC(arg0, out[2], s0[0x1A], s0[0x1B]);
  func_80009920(arg0, out[2], out[1], out[0]);
}
