#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern s8 D_800A16D4;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 *D_800C3508;
extern void *D_800C35A0;
extern void func_80057B40();
extern void *func_800592AC(s32);
extern void func_8005937C(s32, u16);
extern void func_8005A6BC(s32);
extern void func_8005A6E0(s32);
extern void func_8005BB5C();
extern void func_8005BC60();
typedef struct 
{
  u32 w[177];
} CarRecord;
extern void func_80061740(CarRecord);
extern void func_80062304(void);
extern void func_8008A0D8(void *, u16, s32);
extern void func_8008A104(void *, u16, s32, s32);
void func_80070C34(void)
{
  int __repair_literal;
  CarRecord record;
  s32 s3;
  s32 s0;
  s32 s7 = 3;
  s32 s6;
  s32 s2;
  s32 s5;
  s32 s1;
  char *new_var;
  s32 s4;
  s32 result;
  func_8005BC60();
  s3 = -1;
  func_8005BB5C();
  s0 = 0;
  __repair_literal = 0;
  s7 = __repair_literal;
  if (((s32) (*((u16 *) (D_800C02AE + 0x1037a)))) > s7)
  {
    s7 = 3;
    s6 = 0x50;
    s2 = 0x15;
    s5 = 0;
    s1 = 9;
    s4 = 0;
    do
    {
      if ((*((s16 *) (D_800C3508 + 2))) == s7)
      {
        func_8005937C(s2, *(u16 *)((u8 *)&(*((CarRecord **) (D_800C02AE + 0x1039a)))[s0] + 0x14));
      }
      else
      {
        func_8005937C(s1, *(u16 *)((u8 *)&(*((CarRecord **) (D_800C02AE + 0x1039a)))[s0] + 0x14));
      }
      if ((*((s16 *) (D_800C3508 + 2))) == 2)
      {
        func_8008A104(D_800C3508, s1, 1, 1);
      }
      if ((((*((u16 *) (D_800C35A0 + 0x20))) >= 8) & (s0 < 8)) || ((s0 >= 8) && ((*((u16 *) (D_800C35A0 + 0x20))) < 8)))
      {
        func_8008A104(D_800C3508, ((*((s16 *) (D_800C3508 + 2))) == s7) ? (s2) : (s1), 0, 0);
        ((u8 *) func_800592AC(s0))[0x41] = 0;
      }
      else
        if ((*((s16 *) (D_800C3508 + 2))) == s7)
      {
        if (*((u16 *) ((D_800AE850 + 0x7dc0) + s5)))
        {
          func_8008A0D8(D_800C3508, s2, 0);
          {
            u8 *q = func_800592AC(s0);
            q[0xf] = s6;
            q[0x10] = s6;
            q[0x11] = s6;
          }
        }
        else
          if (s3 < 0)
        {
          s3 = s0;
        }
        else
        {
        }
      }
      else
      {
        s3 = (((*((u16 *) (D_800C35A0 + 0x20))) < 8) ^ 1) << 3;
      }
      s2++;
      s5 += 2;
      s1++;
      s0++;
      s4 += 0x2c4;
    }
    while (s0 < ((s32) (*((u16 *) (D_800C02AE + 0x1037a)))));
  }
  {
    u8 *p = D_800C3508;
    u8 *q;
    ((*((u8 **) (D_800C3508 + 0x10))) + ((*((s16 *) (p + 2))) * 0x14))[0xe] = ((*((u8 **) (D_800C3508 + 0x10))) + ((*((s16 *) (p + 2))) * 0x14))[0xd] + s3;
    if ((*((s16 *) (D_800C3508 + 2))) == 2)
    {
      func_80062304();
      if (!s3)
      {
        func_8005A6E0(0x1c);
        result = 0x1b;
      }
      else
      {
        func_8005A6E0(0x1b);
        result = 0x1c;
      }
    }
    else
      if (!s3)
    {
      func_8005A6E0(0x13);
      result = 0x12;
    }
    else
    {
      func_8005A6E0(0x12);
      result = 0x13;
    }
  }
  func_8005A6BC(result);
  *((s32 *) (D_800AE850 + 0x1cf8)) = s3;
  record = *((CarRecord *) (((char *) (*((u8 **) (D_800C02AE + 0x1039a)))) + (s3 * 0x2c4)));
  func_80061740(record);
  if ((*((s16 *) (D_800C3508 + 2))) == 3)
  {
    D_800A16D4 = 0;
    func_80057B40(0x22, 3, 0, 0);
  }
}

