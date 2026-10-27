#include "common.h"

extern void *D_8009B5AC;
extern void *D_800C7F84;
s32 func_80005C48();
s32 func_8000E8B8();
s32 func_8000EB58();
void *func_8004240C();
s32 func_800489D8();
void func_80048ADC(void)
{
  void *temp;
  void *q;
  s32 v;

  temp = func_8004240C(0);
  q = *(void **) ((char *) temp + 0x178);
  D_800C7F84 = temp;
  func_8000E8B8(q);
  v = func_80005C48(D_8009B5AC);
  q = *(void **) ((char *) D_800C7F84 + 0x178);
  func_8000EB58(q, v, (char *) q + 8);
  func_800489D8();
}
