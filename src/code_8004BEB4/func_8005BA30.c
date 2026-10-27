#include "common.h"

extern s32 D_8009B5A4; extern u8 *D_800C7F84;
s32 func_80005718(s32,s32); s32 func_80005ACC(void); s32 func_8000E8B8(s32); s32 func_8000E8FC(s32,s32,s32); s32 func_8007F4E4(s32,s32,s32); s32 func_8007F634(s32); s32 func_8007F6E0(s32);
void func_8005BA30(void) {
 s32 result, copy, v; u8 counter;
 counter=0;
 result=func_8007F4E4(6,2,1);
 copy=func_8007F4E4(9,2,8);
 do {
  func_8000E8B8(*(s32 *)(D_800C7F84+0x178));
  func_8000E8FC(*(s32 *)(D_800C7F84+0x178),D_8009B5A4,0);
  func_80005718(D_8009B5A4,*(s32 *)(D_800C7F84+0x178));
  func_8007F6E0(copy); func_80005ACC(); func_8007F6E0(result);
  v=++counter;
 } while (v!=2);
 func_8007F634(result); func_8007F634(copy);
}
