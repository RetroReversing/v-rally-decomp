#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern s32 D_8009CE8C;
extern s32 D_8009CE90;
extern s32 D_8009CE94;
extern s32 D_8009CE98;
extern s32 D_8009CE9C;
extern s32 D_8009CEA0;
extern char D_800C02AE[];
void func_80011058(void *arg0, s32 arg1, s32 arg2)
{
  s32 var_v0;
  s32 temp_v1;
  s32 idx;
  char *temp;
  idx = arg2 & 0xFFFF;
  do
  {
    if (arg1 != 0)
    {
      temp = (char *) (((arg2 & 0xFFFF) * 0x4C) + arg1);
      *((s32 *) (((char *) arg0) + 0x10)) = *((s32 *) (temp + 0x90));
      *((s32 *) (((char *) arg0) + 0x14)) = *((s32 *) (temp + 0xDC));
      temp_v1 = *((s32 *) (temp + 0x128));
      *((s16 *) (((char *) arg0) + 0x6A)) = 0x1000;
      *((s32 *) (((char *) arg0) + 0x30)) = 2;
      *((s32 *) (((char *) arg0) + 0x18)) = temp_v1;
    }
    else
    {
      *((s32 *) (((char *) arg0) + 0x10)) = 0x80;
      *((s32 *) (((char *) arg0) + 0x14)) = 0x14;
      *((s32 *) (((char *) arg0) + 0x18)) = 5;
      *((s16 *) (((char *) arg0) + 0x6A)) = 0x1000;
      *((s32 *) (((char *) arg0) + 0x30)) = 2;
    }
    arg0 = *((void **) (D_800C02AE + 0x32F2));
  }
  while (0);
  temp_v1 = *((u16 *) (((char *) arg0) + 0xE));
  switch (temp_v1)
  {
    case 1:
      var_v0 = -0x87;
      D_8009CE90 = var_v0;
      D_8009CE8C = 0;
      var_v0 = 0x2B;
      break;
    case 2:
      if ((*((u16 *) (((char *) arg0) + 0x12))) & 1)
      {
        var_v0 = -0x56;
        D_8009CE9C = var_v0;
        D_8009CE90 = var_v0;
        var_v0 = 0x34;
      }
      else
      {
        var_v0 = -0x87;
        D_8009CE9C = var_v0;
        D_8009CE90 = var_v0;
        var_v0 = 0x2B;
      }
      D_8009CE98 = 0;
      D_8009CE8C = 0;
      D_8009CEA0 = var_v0;
      break;
    default: return;
  }

  D_8009CE94 = var_v0;
}

