#include "common.h"

extern char D_800C02AE[];
extern char D_800AE850[];
extern char D_800A73E0[];
extern char D_15DB10[];
extern char D_BB9470[];
void func_80035438();
void func_80035A10();
void func_80038DF8();
void func_80022214();
void func_80005DEC();
void func_80005948();
void func_8004BFEC();
void func_800506D8();
void func_80022484();
void func_80080478();
void func_8001BAF4();
void func_80015C74();
void func_80081514();
void func_80081B28();

void func_80010128(void)
{
  func_80035438(*((s32 *) (D_800C02AE + 0x103B2)));
  func_80035438(*((s32 *) (D_800C02AE + 0x103B6)));
  func_80081B28(*((s32 *) (D_800C02AE + 0x103BA)));
  func_80081B28(*((s32 *) (D_800AE850 + 0x72F8)));
  func_80038DF8();
  func_80035A10();
  func_80022214();
  func_80005DEC();
  func_80005948();
  func_8004BFEC();
  func_800506D8();
  func_80022484(*((s32 *) (D_800AE850 + 0x87F0)));
  func_80080478(*((s32 *) (D_800AE850 + 0x87F0)));
  func_8001BAF4(*((s32 *) (D_800C02AE + 0x80C6)));
  func_80015C74(D_800A73E0 + 0x6BD0, 0);
  func_80081514(D_15DB10, D_BB9470 - D_15DB10, 1);
}
