#include "common.h"

typedef struct 
{
  unsigned char pad[6];
  u16 x;
  u16 y;
} T7310;
typedef struct 
{
  unsigned char pad[4];
  void *base;
} A7310;
extern u32 D_800A1748;
void *func_80006008(void);
void func_80006014(s32, void *);
void func_80006298(s32);
s32 func_800070CC(s32);
void func_800075BC(s32, void *, s32);
void func_800068C0(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_80008B28(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_800072F4(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_80073108(s32 arg0, s16 arg1, s16 arg2, A7310 *arg3, u8 arg4)
{
  s32 temp_s0;
  s32 temp_s5;
  void *temp_v0;
  temp_v0 = func_80006008();
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((u8 *) temp_v0) + 4)) = &D_800A1748;
  func_80006014(arg0, ((u8 *) temp_v0) + 8);
  temp_s0 = arg4 * 4;
  func_800075BC(arg0, *((void **) (((u8 *) arg3->base) + (arg4 * 4))), 0);
  temp_s5 = func_800070CC(arg0) & 0xffff;
  func_800068C0(arg0, temp_s5, arg1, arg2, 0, (s16) (arg1 + ((T7310 *) (*((void **) (((u8 *) arg3->base) + (arg4 * 4)))))->x), arg2, 0, (s16) (arg1 + ((T7310 *) (*((void **) (temp_s0 + (int)arg3->base))))->x), (s16) (arg2 + ((T7310 *) (*((void **) (((u8 *) arg3->base) + (arg4 * 4)))))->y), 0, arg1, (s16) (arg2 + ((T7310 *) (*((void **) (((u8 *) arg3->base) + (arg4 * 4)))))->y), 0);
  func_80008B28(arg0, temp_s5, 0, 0, ((T7310 *) (*((void **) (((u8 *) arg3->base) + (arg4 * 4)))))->x, 0, ((T7310 *) (*((void **) (((u8 *) arg3->base) + (arg4 * 4)))))->x, ((T7310 *) (*((void **) (((u8 *) arg3->base) + (arg4 * 4)))))->y, 0, ((T7310 *) (*((void **) (((u8 *) arg3->base) + (arg4 * 4)))))->y);
  func_800072F4(arg0, temp_s5, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x7d);
  func_80006298(arg0);
}
