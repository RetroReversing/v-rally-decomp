#include "common.h"

typedef struct 
{
  u8 pad0[0x22C];
  u8 current;
  u8 frame;
} VRQueueHead;
typedef struct 
{
  u8 pad0[0x44];
  s32 count;
  u8 pad1[0x94];
  s32 x;
  u8 pad2[0x48];
  s32 y;
} VRItem;
typedef struct 
{
  u8 pad0[0xE4];
  s32 results[256];
} VRResultBlock;
typedef struct 
{
  u8 pad0[0x134];
  s32 values[256];
} VRValueBlock;
extern VRQueueHead *D_800A1468;
extern u8 D_800A5260;
s32 func_80081540(u8 *);
s32 func_80081664(s32, void *);
s32 func_8000BF2C(s32);
void func_8000C200(s32, f32, f32, f32);
void func_8000C1EC(s32, s32, s32);
void func_8000C22C(s32, s32, s32, s32, s32);
void func_80058C04(VRItem *arg0)
{
  s32 var_s1;
  s32 temp_v0;
  s32 temp_s0;
  unsigned int a1;
  temp_v0 = arg0->count;
  var_s1 = 0;
  if (temp_v0 > 0)
  {
    s32 limit = temp_v0;
    do
    {
      var_s1 += 3;
    }
    while (((u8) var_s1) < limit);
  }
  func_80081540(&D_800A5260);
  var_s1 = 0;
  *((u8 *) ((((u8 *) D_800A1468) + 0xD0) - (-(D_800A1468->frame * 2)))) = D_800A1468->current;
  *((s8 *) ((((u8 *) D_800A1468) + 0xD1) - (-(D_800A1468->frame * 2)))) = arg0->count / 3;
  if ((arg0->count / 3) > 0)
  {
    do
    {
      temp_s0 = ((u8) var_s1) * 0xE4;
      a1 = temp_s0 + 0x4C;
      ((VRValueBlock *) D_800A1468)->values[D_800A1468->current] = func_80081664(6, ((u8 *) arg0) + a1);
      ((VRResultBlock *) D_800A1468)->results[D_800A1468->current] = func_8000BF2C(((VRValueBlock *) D_800A1468)->values[D_800A1468->current]);
      func_8000C200(((VRResultBlock *) D_800A1468)->results[D_800A1468->current], 1.0f, 1.0f, 1.0f);
      var_s1++;
      func_8000C1EC(((VRResultBlock *) D_800A1468)->results[D_800A1468->current], *((s32 *) ((temp_s0 + ((s32) arg0)) + 0xDC)), *((s32 *) ((temp_s0 + ((s32) arg0)) + 0x128)));
      func_8000C22C(((VRResultBlock *) D_800A1468)->results[D_800A1468->current], 200, 200, 200, 255);
      D_800A1468->current++;
    }
    while (((u8) var_s1) < (arg0->count / 3));
  }
  D_800A1468->frame++;
}
