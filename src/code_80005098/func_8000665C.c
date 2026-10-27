#include "common.h"

typedef struct 
{
  u8 pad0[0x14];
  u32 *dl;
  u8 pad1[0x70 - 0x18];
  s32 base;
  u8 pad2[0x7A - 0x74];
  u16 pos;
} Obj8000665C;
s32 osVirtualToPhysical();
extern u16 D_8009B5C0;
s32 func_8000665C(Obj8000665C *arg0, s32 arg1)
{
  s32 var_v0;
  s32 temp_v1;
  s32 temp_s2;
  u16 temp_s3;
  u16 temp_a1;
  u32 temp_a0;
  u32 *temp_s0;
  ;
  temp_s2 = arg1;
  temp_s3 = temp_s2;
  if (!(arg0->pos & 0x1F))
  {
    temp_s0 = arg0->dl;
    arg0->dl = temp_s0 + 2;
    temp_s0[0] = 0x01020040;
    temp_s0[1] = osVirtualToPhysical(arg0->base + (arg0->pos << 4));
  }
  temp_a1 = arg0->pos;
  temp_a0 = temp_a1;
  temp_v1 = temp_a0 + (temp_s3 & 0xFFFF);
  var_v0 = 1;
  var_v0 = temp_v1 - var_v0;
  if (var_v0 < 0)
  {
    var_v0 = temp_v1 + 0x1E;
  }
  if ((var_v0 >> 5) == ((s32) (temp_a0 >> 5)))
  {
    arg0->pos = temp_a1 + arg1;
  }
  else
  {
    temp_s0 = arg0->dl;
    arg0->dl = temp_s0 + 2;
    temp_s0[0] = 0x01020040;
    D_8009B5C0 = (temp_a0 >> 5) + 1;
    temp_s0[1] = osVirtualToPhysical(arg0->base + (D_8009B5C0 << 9));
    arg0->pos = (D_8009B5C0 << 5) + arg1;
  }
  return (u16)(arg0->pos - temp_s3);
}
