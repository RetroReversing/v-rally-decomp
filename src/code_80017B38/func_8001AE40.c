#include "common.h"

extern char D_800AE850[];
extern char *D_800C3518;
extern char D_15DB10[];
extern char D_BB9470[];
extern s32 D_8009CE70;
extern s32 D_8009CE74;
extern s32 D_8009D4E8;
extern s32 D_8009D4EC;
void func_8001AE40(char *arg0)
{
  s32 pad[2];
  char *var_s3;
  s32 var_s2;
  s32 *var_s1;
  s32 temp_s0;
  s32 temp_a1;
  s32 count;
  var_s3 = *((char **) arg0);
  var_s2 = 0;
  count = *((u16 *) (arg0 + 4));
  if (count > 0)
  {
    var_s1 = (s32 *) (var_s3 + 0x10);
    do
    {
      temp_s0 = *var_s1;
      if (temp_s0 & 1)
      {
        *var_s1 = temp_s0 | 2;
      }
      func_8001AAB4((s32) var_s3);
      *var_s1 = temp_s0;
      var_s1 = (s32 *) (((char *) var_s1) + 0x3C);
      var_s2 += 1;
      var_s3 += 0x3C;
    }
    while (var_s2 < (*((u16 *) (arg0 + 4))));
  }
  temp_a1 = *((u16 *) ((*((char **) (D_800AE850 + 0x72F4))) + 0x7A));
  D_8009CE70 = ((*((s32 *) ((*((char **) (D_800AE850 + 0x72F4))) + 0x14))) - (*((s32 *) ((*((char **) (D_800AE850 + 0x72F4))) + 0x10)))) >> 3;
  D_8009CE74 = temp_a1;
  func_80005D98(*((char **) (D_800AE850 + 0x72F4)));
  func_8004DC50(*((s32 *) (D_800C3518 + 0x24)));
  func_8004EF40(*((s32 *) (D_800C3518 + 0x24)));
  func_80081B28(D_8009D4EC);
  func_80081B28(D_8009D4E8);
  var_s2 = D_BB9470 - D_15DB10;
  func_80081514(D_15DB10, var_s2, 1);
}
