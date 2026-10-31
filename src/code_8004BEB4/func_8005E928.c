#include "snapshot31_verified.h"

typedef struct { s32 pad10[4]; s32 w20,w24,w28,w2C,w30,w34,w38,w3C,w40,w44,w48,w4C; u8 b50[12]; u8 b5C[4]; s32 pad60[2]; } FuncBuf;
void func_8004C370(s32, FuncBuf *, s32, s32);
void func_8004C2B8(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,u8 arg5) ;
















extern int D_800C3558;
extern int D_800C8328;
s32 func_80038F64();
s32 func_80057810();
s32 func_800578E0();
s32 func_8005A360();
s32 func_8006ECB4();
s32 func_8006F75C();
s32 func_8006FA8C();
extern u8 *D_800A1468;
extern s32 D_800A14C0;
extern u8 D_800C02AE[];
extern s32 func_8005DC40;
extern s32 func_8005DD2C;
s32 func_8005E928(s32 arg0, s32 arg1)
{
  u8 *new_var;
  char *new_var2;
  char *new_var3;
  new_var3 = D_800C02AE + 0x32AA;
  func_8006FA8C();
  new_var = (u8 *) (((char *) new_var3) + 3);
  func_80038F64(*new_var);
  func_8006ECB4();
  func_8006F75C();
  if (*(s32 *)new_var3 == 0)
  {
    new_var2 = D_800C02AE;
    if (new_var2)
    {
      func_800578E0(D_800C8328);
      D_800C8328 = func_80057810(D_800A14C0);
    }
    else
    {
      func_800578E0(D_800C8328);
      D_800C8328 = func_80057810(D_800A14C0);
    }
  }
  func_8005A360(arg0, arg1);
  *((s32 **) (((char *) D_800A1468) + 0x288)) = &func_8005DC40;
  new_var = &func_8005DD2C;
  *((s32 **) (((char *) D_800A1468) + 0x28C)) = new_var;
  return 0;
}



extern u8 *D_800A1468;
extern u8 D_800C02AE[];
extern void func_8008A0D8(void *, int, int);
extern u8 *func_800592AC(int);
extern void func_800592F4(int, int, u8 *);
extern void func_80068E5C(int);
int func_80068D9C(int arg0)
;



























void func_8006F3C0(void) ;
