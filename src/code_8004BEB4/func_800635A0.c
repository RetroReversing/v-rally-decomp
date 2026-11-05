#include "decompdecomp_snapshot_800635a0.h"
#line 1 "func.c"
typedef struct 
{
  s32 w[177];
} Block635;
extern u8 D_800C02AE[];
extern u8 D_800AE850[];
extern u8 *D_800A1468;
extern u16 D_800D061E;
extern Block635 *D_800D0634;
void func_8005BC60(void);
void func_8005BB5C(void);
void func_80063328(void);
void func_8005937C(s32, s32);
void func_8005A05C(s32);void func_8005A6E0(u32);
void func_80061740(Block635);
void func_800635A0(void)
{
  Block635 b;
  s32 i;
  s32 j;
  u8 *mgr;
  u8 *obj;
  int new_var;
  short new_var2;
  u8 *row;
  func_8005BC60();
  func_8005BB5C();
  func_80063328();
  obj = *((u8 **) (D_800C02AE + 0x32F2));
  mgr = *((u8 **) (D_800C02AE + 0x325A));
  *((s16 *) (obj + 0x20)) = 0;
  *((s16 *) (obj + 0x22)) = 0;
  new_var = (new_var2 = 0);
  if ((*((s16 *) (mgr + 2))) == 1)
  {
    i = new_var2;
    if (D_800D061E > new_var2)
    {
      j = new_var2;
      do
      {
        func_8005937C(i + 6, *((u16 *) ((j + (int)D_800D0634) + 0x14)));
        i += 1;
        j += 0x2C4;
      }
      while (i < D_800D061E);
    }
    func_8005A05C(0);
    func_8005A6E0(19);
    func_8005A6E0(20);
    func_8005A6E0(21);
    func_8005A6E0(22);
  }
  else
  {
    i = new_var2;
    if (D_800D061E > new_var)
    {
      j = 0;
      do
      {
        func_8005937C(i + 15, *((u16 *) ((j + (int)D_800D0634) + 0x14)));
        i += 1;
        j += 0x2C4;
      }
      while (i < D_800D061E);
    }
  }
  b = *D_800D0634;
  func_80061740(b);
  row = (*((u8 **) ((*((u8 **) (D_800C02AE + 0x325A))) + 16))) + ((*((s16 *) ((*((u8 **) (D_800C02AE + 0x325A))) + 2))) * 20);
  row[14] = row[13] + D_800A1468[0x23B];
  *((s32 *) (D_800AE850 + 0x5550)) = 0;
}

