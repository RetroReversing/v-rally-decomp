#include "common.h"

extern s32 D_800AE850;
extern s32 D_800C02AE;
void func_80081E0C(void)
{
  s32 *new_var;
  if ((*((s32 *) (((char *) (&D_800C02AE)) + 0x3092))) > (*((s32 *) (((char *) (&D_800AE850)) + 0x8ACC))))
  {
    new_var = (s32 *) (((char *) (&D_800AE850)) + 0x8ACC);
    if ((*((s32 *) (((char *) (&D_800AE850)) + 0x8ACC))) < 0)
    {
      *((s32 *) (((char *) (&D_800AE850)) + 0x8ACC)) = 0;
    }
    *((s32 *) (((char *) (&D_800C02AE)) + 0x311A)) = (s32) ((*((s32 *) (((char *) (&D_800C02AE)) + 0x308E))) + (*((s32 *) (((char *) (&D_800AE850)) + 0x8ACC))));
    *((s32 *) (((char *) (&D_800C02AE)) + 0x3116)) = (s32) ((*((s32 *) (((char *) (&D_800C02AE)) + 0x3092))) - (*((s32 *) (((char *) (&D_800AE850)) + 0x8ACC))));
    *((s32 *) (((char *) (&D_800C02AE)) + 0x3092)) = (s32) (*new_var);
  }
  else
  {
    *((s32 *) (((char *) (&D_800C02AE)) + 0x3116)) = 0;
  }
  *((s32 *) (((char *) (&D_800AE850)) + 0x8ACC)) = (s32) ((*((s32 *) (((char *) (&D_800AE850)) + 0x8ACC))) - (*((s32 *) (((char *) (&D_800C02AE)) + 0x3092))));
}
