#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define var_s0_2 state.i
#define var_s0_3 state.i
#define var_s0 state.p
#define temp_s0 var_s0
s32 func_80022ED8(void *);
s32 func_8002FA10(s32);
s32 func_80042D20();
s32 func_800494D4(s32);
s32 func_8004E218(void *);
s32 func_8004F3C4();
s32 func_8004FC64();
s32 func_8004FCF8(s32, void *, s32);
s32 func_80050AB8(s32);
s32 func_800804C4(s32, s32 *);
s32 func_800857A0(s32);
extern s32 D_8009D538;
extern s8 D_800A1210;
extern s32 D_800A1234;
extern s32 D_800A1238;
extern s32 D_800A73E0;
extern s32 D_800AE850;
extern s32 D_800C02AE;
extern s32 func_8004E18C;
void func_8004E224(s32 arg0)
{
  s32 temp_a2;
  char *new_var2;
  s32 temp_s1;
  s32 temp_s3;
  s32 temp_v1;
  s32 neg1;
  char *new_var;
  union 
  {
    u32 i;
    void *p;
  } state;
  void **temp_s0_2;
  void *temp_v0;
  void *cfgp;
  temp_s3 = D_800A1234;
  temp_v1 = arg0 & 0xFF;
  var_s0 = *(*((void ***) (((char *) (&D_800AE850)) + 0x73F0)));
  if (temp_v1 == 1)
  {
    var_s0 = *((void **) (((char *) var_s0) + 4));
    if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x1A))) == temp_v1)
    {
      var_s0 = *((void **) (((char *) var_s0) + 4));
    }
  }
  if ((*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x6C)))) + 0x34))) != 0)
  {
    var_s0_2 = 0;
    loop_5:
    func_800857A0(var_s0_2 & 0xFF);

    var_s0_2 += 1;
    if (var_s0_2 < 4U)
    {
      goto loop_5;
    }
  }
  else
  {
    if (!((*((s32 *) (((char *) var_s0) + 0x14))) & 0x80))
    {
      func_80022ED8(var_s0);
    }
    func_8002FA10(*(*((s32 **) (((char *) var_s0) + 0x38))));
    if ((*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x6C)))) + 0x34))) == 0)
    {
      *((s32 *) (((char *) var_s0) + 0x14)) = (s32) ((*((s32 *) (((char *) var_s0) + 0x14))) & (~0x10));
    }
    if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x1A))) == 1)
    {
      temp_s0 = *((void **) (((char *) var_s0) + 4));
      if (!((*((s32 *) (((char *) temp_s0) + 0x14))) & 0x80))
      {
        func_80022ED8(temp_s0);
      }
      func_8002FA10(*(*((s32 **) (((char *) temp_s0) + 0x38))));
      if ((*((s32 *) (((char *) (*((void **) (((char *) temp_s0) + 0x6C)))) + 0x34))) == 0)
      {
        *((s32 *) (((char *) temp_s0) + 0x14)) = (s32) ((*((s32 *) (((char *) temp_s0) + 0x14))) & (~0x10));
      }
      var_s0 = *((void **) (((char *) temp_s0) + 0));
    }
    D_800A1210 = 0;
    func_8004F3C4();
    if ((*((u8 *) (((char *) (&D_800A73E0)) + 0x6C01))) != 0)
    {
      temp_s1 = arg0 & 0xFF;
      new_var2 = ((char *) (temp_s3 + (temp_s1 * 0x44))) + 8;
      if ((*((u16 *) new_var2)) & 0x200)
      {
        func_8004FCF8(D_800A1234, var_s0, temp_s1);
        func_8004E218(var_s0);
        func_80050AB8(temp_s1);
        var_s0_3 = 0;
      }
      else
      {
        goto block_25;
      }
    }
    else
    {
      temp_a2 = arg0 & 0xFF;
      temp_v0 = temp_s3 + (temp_a2 * 0x44);
      *((s16 *) (((char *) temp_v0) + 0xA)) = 3;
      new_var = (char *) (&D_800C02AE);
      neg1 = *((u16 *) (((char *) temp_v0) + 8));
      cfgp = *((void **) (new_var + 0x32F2));
      *((s16 *) (((char *) temp_v0) + 0xC)) = 0;
      neg1 &= 0xFDFF;
      *((u16 *) (((char *) temp_v0) + 8)) = (u16) neg1;
      neg1 = -1;
      *((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x44)))) + 0x28)) = neg1;
      *((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x70)))) + 0x28)) = neg1;
      if ((*((u16 *) (((char *) cfgp) + 0x1A))) == 1)
      {
        var_s0 = *((void **) (((char *) var_s0) + 4));
        func_8004FC64(D_800A1238, (void **) var_s0, temp_a2);
        var_s0 = *((void **) var_s0);
      }
      if ((*((u16 *) (((char *) (*((void **) (new_var + 0x32F2)))) + 0xE))) == 1)
      {
        func_800804C4(neg1 = *((s32 *) (((char *) (&D_800AE850)) + 0x72FC)), &func_8004E18C);
      }
      *((s32 *) (((char *) var_s0) + 0x14)) = (s32) ((*((s32 *) (((char *) var_s0) + 0x14))) | 0x10);
      block_25:
      var_s0_3 = 0;

    }
    do
    {
      func_800857A0(var_s0_3 & 0xFF);
      var_s0_3 += 1;
    }
    while (var_s0_3 < 4U);
    func_80042D20();
    if (D_8009D538 & 0x4000)
    {
      func_800494D4(arg0 & 0xFF);
    }
  }
}

