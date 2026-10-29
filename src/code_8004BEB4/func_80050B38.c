#include "snapshot29_0433f7af8f6d.h"

extern void *D_800C35A0;
extern char D_800B5B70;
extern unsigned char D_800C81FC;
extern unsigned char D_800C7FA0;
extern int D_800B6B00;
extern short D_800B0D68;
extern short D_800C5CE8;
extern signed char D_800B0D6C;
extern signed char D_800C5CEC;
extern unsigned char D_800B6818;
s32 func_80022184(void *);
void func_8002283C(void);
s32 func_80022BE8(void *, s32);
s32 func_80022F78(void *);
s32 func_800239CC(void *, void *, void *);
s32 func_8004F3C4(void);
s32 func_8004F55C(s32 *);
short func_8004FD5C(s32 *, s32);
extern s32 D_8009D540;
extern s32 *D_800A1234;
extern s32 *D_800A1238;
extern u8 D_800A17F0;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_80050B38(void)
{
  s32 *temp_a0;
  short temp_v0_2;
  char *new_var2;
  u8 var_a1;
  int new_var;
  s32 var_v1;
  u16 temp_a0_2;
  u16 temp_v1;
  u8 temp_v0;
  void *var_s0;
  if (func_80022184(D_800AE850 + 0x7320) == 0)
  {
    func_8002283C();
  }
  func_8004F3C4();
  temp_v1 = *((u16 *) (D_800C35A0 + 0x1E));
  new_var2 = D_800AE850;
  if (temp_v1 != 7)
  {
    if ((temp_v1 == 8) && (D_800A17F0 == 0))
    {
      if (D_800C81FC != 0)
      {
        func_80022F78(*((void ***) (D_800AE850 + 0x73F0)));
        var_s0 = *(*((void ***) (new_var2 + 0x73F0)));
        temp_v0_2 = (double) (*D_800A1234);
        if (D_800C7FA0 == 1)
        {
          var_s0 = *((void **) (((u8 *) var_s0) + 4));
        }
        func_80022BE8(var_s0, *D_800A1234);
        {
          void *p = *((void **) (((u8 *) var_s0) + 0x54));
          void *r = D_800C35A0;
          ;
          *((s32 *) 0x800B6B00) = 5;
          *((s32 *) (((u8 *) p) + 0x50)) = 0;
          func_800239CC(var_s0, r + (((*((u8 *) (r + 0x32))) * 0x28) + 0x44), r);
        }
      }
    }
    else
      if (func_80022184((void *) (&D_800B5B70)) != 0)
    {
      temp_a0 = (s32 *) (D_800AE850 + 0x2408);
      D_800A1234 = temp_a0;
      D_800A1238 = (s32 *) (D_800C02AE + 0x592A);
      func_8004F55C(temp_a0);
      func_8004F55C(D_800A1238);
      temp_v0 = *((u8 *) (D_800C35A0 + 0xF));
      *((s16 *) (D_800AE850 + 0x2518)) = (s16) temp_v0;
      *((s16 *) (D_800C02AE + 0x5A3A)) = (s16) temp_v0;
      temp_a0_2 = *((u16 *) (D_800C35A0 + 0x1E));
      if (temp_a0_2 == 0)
      {
        if ((*((u16 *) (D_800C35A0 + 0x1A))) != 0)
        {
          *((s8 *) (D_800AE850 + 0x251C)) = 0;
          *((s8 *) (D_800C02AE + 0x5A3E)) = 0;
          func_8004FD5C(D_800A1234, D_8009D540 * 0x1C2);
          func_8004FD5C(D_800A1238, D_8009D540 * 0x1C2);
          var_a1 = 0;
          do
          {
            if (D_800C7FA0)
            {
              temp_v0_2 = var_a1 * 0x44;
              *((u16 *) ((D_800AE850 + 0x2410) + temp_v0_2)) |= 0x100;
              *((u16 *) ((D_800C02AE + 0x5932) + temp_v0_2)) |= 0x100;
              var_a1++;
            }
            else
            {
              temp_v0_2 = var_a1 * 0x44;
              *((u16 *) ((D_800AE850 + 0x2410) + temp_v0_2)) |= 0x100;
              *((u16 *) ((D_800C02AE + 0x5932) + temp_v0_2)) |= 0x100;
              var_a1++;
            }
          }
          while (var_a1 < 4);
          return;
        }
        goto block_18;
      }
      if ((temp_a0_2 == 5) && ((*((u8 *) (D_800AE850 + 0x7FC8))) == 0))
      {
        func_8004F3C4();
      }
      block_18:
      *((s8 *) (D_800AE850 + 0x251C)) = 0;

      func_8004FD5C(D_800A1234, D_8009D540 * 0x1C2);
    }
  }
}
