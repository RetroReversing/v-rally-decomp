#include "common.h"

extern s32 D_8009FF30;
extern s32 D_800A73E0;
extern s32 D_800C02AE;
void func_8001CE94(void *arg0)
{
  register s32 var_v0;
  if ((D_8009FF30 == 2) && (((var_v0 = (*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE)))) == D_8009FF30)))
  {
    var_v0 = 0x82;
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BE6)) = var_v0;
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BE8)) = var_v0;
  }
  else
  {
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BE6)) = (s16) (*((s32 *) (((char *) arg0) + 0x90)));
    *((s16 *) (((char *) (&D_800A73E0)) + 0x6BE8)) = (s16) (*((s32 *) (0xDC + ((char *) arg0))));
    var_v0 = *((s32 *) (((char *) arg0) + 0x128));
  }
  *((s16 *) (((char *) (&D_800A73E0)) + 0x6BEA)) = (s16) var_v0;
}
