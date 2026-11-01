#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern int D_800B6880;
extern unsigned int D_800AE44C;
extern float D_800C35E0;
extern signed char D_800C8120;
s32 func_8000E8B8();
s32 func_8001FEE8();
void *func_80022318();
s32 func_80022F78();
s32 func_80027C64();
s32 func_80027E8C();
s32 func_8002FE78();
s32 func_80038A8C();
void *func_8004240C();
s32 func_80042D20();
long func_80042F40();
s32 func_80043124();
s32 func_800446D0();
s32 func_800447A0();
s32 func_80076E7C();
s32 func_800804C4();
s32 func_80080514();
s32 func_80085778();
s32 func_80086854();
s32 func_80086A34();
s32 func_80086DE8();
extern s32 D_8009D538;
extern void *D_800C35A0;
extern s32 D_8009F640;
extern s32 D_800A0200;
extern char D_800A4DF4[];
extern char D_800A4DFC[];
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_8002291C;
extern s32 func_8004E18C;
typedef struct { unsigned char pad_0[4]; void * field_4; unsigned char pad_8[12]; int field_14; unsigned char pad_18[48]; void * field_48; unsigned char pad_4C[32]; void * field_6C; } __repair_record_var_s2;
void func_80043150(void *arg0, void *arg1)
{
  s32 temp_a0;
  s32 var_a0_2;
  s32 var_a1;
  s32 var_s3;
  s32 var_s5;
  u32 temp_v1_3;
  u32 temp_v1_5;
  char *new_var2;
  s32 var_s1;
  u32 temp_a0_2;
  u8 temp_v0_2;
  int new_var;
  u8 temp_v0_3;
  u8 temp_v1;
  u8 temp_v1_2;
  u8 var_s4;
  void *temp_a2;
  void *temp_v0;
  void *temp_v0_10;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_7;
  void *temp_v0_8;
  void *temp_v0_9;
  void *temp_v1_4;
  void *var_a0;
  void *var_s0;
  void *var_s2;
  var_s2 = arg0;
  var_s0 = arg1;
  temp_a2 = ((__repair_record_var_s2*)var_s2)->field_6C;
  var_s4 = *((u8 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xF));
  var_s5 = *((s32 *) (((char *) temp_a2) + 0x10));
  func_80085778(*((u8 *) (((char *) (((__repair_record_var_s2*)var_s2)->field_48)) + 3)), 1);
  if (D_800B6880 != 1)
  {
    if (!((((__repair_record_var_s2*)var_s2)->field_14) & 0x200))
    {
      temp_v0 = func_8004240C((var_s4 * 2) + 2);
      *((void **) (D_800C02AE + 0x7CD6)) = temp_v0;
      func_800447A0(temp_v0);
    }
    func_80027E8C(var_s2, *((s32 *) (((char *) (((__repair_record_var_s2*)var_s2)->field_48)) + 0)), var_s0);
    ((__repair_record_var_s2*)var_s2)->field_14 |= 0x200;
    var_a1 = func_8001FEE8(var_s2);
    if (var_a1 < 0)
    {
      *((s8 *) (((char *) var_s0) + 5)) = 0;
      *((s8 *) (((char *) var_s0) + 4)) = 0;
      temp_v0_2 = (*((u8 *) (((char *) var_s0) + 1))) | 0x10;
      *((u8 *) (((char *) var_s0) + 1)) = temp_v0_2;
      temp_v1 = ((*((u8 *) (((char *) var_s0) + 2))) | (~temp_v0_2)) | 0x10;
      *((u8 *) (((char *) var_s0) + 2)) = temp_v1;
      *((s8 *) (((char *) var_s0) + 3)) = (s8) ((*((u8 *) (((char *) var_s0) + 1))) & temp_v1);
    }
    else
    {
      *((s8 *) (((char *) var_s0) + 4)) = 0;
      *((u8 *) (((char *) var_s0) + 5)) = 0x80;
    }
    if ((((u32) (var_a1 + 5)) < 0xBU) & (var_s5 == 0))
    {
      *((s8 *) (((char *) var_s0) + 5)) = 0;
      temp_v1_2 = (*((u8 *) (((char *) var_s0) + 1))) & 0xEF;
      *((u8 *) (((char *) var_s0) + 1)) = temp_v1_2;
      temp_v0_3 = ((*((u8 *) (((char *) var_s0) + 2))) | (~temp_v1_2)) | 0x10;
      *((u8 *) (((char *) var_s0) + 2)) = temp_v0_3;
      *((s8 *) (((char *) var_s0) + 3)) = (s8) ((*((u8 *) (((char *) var_s0) + 1))) & temp_v0_3);
      var_s0 = *(*((void ***) (D_800AE850 + 0x73F0)));
      var_s1 = *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE));
      var_s3 = 0;
      if (var_s0 != NULL)
      {
        do
        {
          if ((*(*((s32 **) (((char *) var_s0) + 0x48)))) < 4)
          {
            var_a1 = func_8001FEE8(var_s0, var_a1);
            if (((!((*((s32 *) (((char *) var_s0) + 0x14))) & 0x100)) && (((u32) (var_a1 + 5)) < 0xBU)) && ((*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x6C)))) + 0x10))) == 0))
            {
              var_s3 += 1;
              var_s1 -= 1;
            }
            if (((u16) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE)))) >= 2U)
            {
              {
                s32 flags = (*((s32 *) (((char *) var_s0) + 0x14))) & 0x100;
                var_s1 -= flags != 0;
              }
            }
          }
          var_s0 = *((void **) (((char *) var_s0) + 4));
        }
        while (var_s0 != NULL);
      }
      if (var_s1 == 0)
      {
        temp_v1_3 = *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE));
        if ((temp_v1_3 >= 2U) && ((var_s3 & 0xFFFF) != temp_v1_3))
        {
          func_80042F40();
          D_800B6880 = 0;
          func_80085778(0U, 0x1000);
          func_80085778(0U, 0x8000);
        }
        else
        {
          if (((u32) D_800AE44C) < 2U)
          {
            if ((*((s32 *) (((char *) (((__repair_record_var_s2*)var_s2)->field_48)) + 0))) < 4)
            {
              var_a0 = *(*((void ***) (D_800AE850 + 0x72FC)));
              if (var_a0 != NULL)
              {
                loop_23:
                if ((*((s32 *) (((char *) var_a0) + 0x24))) != var_s2)
                {
                  var_a0 = *((void **) (((char *) var_a0) + 4));
                  if (var_a0 != NULL)
                  {
                    goto loop_23;
                  }
                }

              }
              temp_v0_4 = func_80022318(var_a0 + 0x28, &D_800A4DFC);
              {
                s32 two = 2;
                if (temp_v0_4 != NULL)
                {
                  temp_v1_4 = *((void **) (((char *) temp_v0_4) + 0x10));
                  if ((*((s32 *) (((char *) temp_v1_4) + 8))) != two)
                  {
                    *((s32 *) (((char *) temp_v1_4) + 8)) = two;
                  }
                }
              }
            }
            if (D_800AE44C == 0)
            {
              func_80038A8C(0x10);
              if (!(D_8009F640 & 0x20))
              {
                D_8009F640 |= 0x20;
                func_80086A34(1);
                func_80086854(D_800C02AE + 0x10122);
                func_80086DE8((s32) (D_800C35E0 * 80.0f));
              }
            }
          }
          new_var2 = ((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E;
          ((__repair_record_var_s2*)var_s2)->field_14 |= 0x80;
          temp_a0_2 = D_800AE44C + 1;
          D_800AE44C = temp_a0_2;
          if (temp_a0_2 == (((struct { u8 pad[0xE]; u16 e; } *) (*((void **) (D_800C02AE + 0x32F2))))->e * 0x4B))
          {
            temp_v1_5 = *((u16 *) new_var2);
            D_8009D538 &= ~1;
            if ((temp_v1_5 != 0) & (temp_v1_5 != 5))
            {
              if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x36))) != 0)
              {
                var_a0_2 = var_s4 * 2;
                if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE))) == 1)
                {
                  {
                    s32 i = 0;
                    do
                    {
                      func_80085778(i & 0xFF, 1);
                      i++;
                    }
                    while (((u32) (i & 0xFFFF)) < ((u16) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE)))));
                  }
                  D_8009D538 |= 0x80;
                  temp_v0_5 = func_8004240C((var_s4 * 2) + 2);
                  *((void **) (D_800C02AE + 0x7CD6)) = temp_v0_5;
                  func_800446D0(temp_v0_5);
                }
                else
                {
                  goto block_39;
                }
              }
              else
              {
                var_a0_2 = var_s4 * 2;
                block_39:
                temp_v0_6 = func_8004240C(var_a0_2 + 2);
                { extern void *D_800C7F84; D_800C7F84 = temp_v0_6; }
                func_800447A0(temp_v0_6);
                func_80043124(var_s2);
                func_8002FE78();
                D_8009D538 |= 1;
                temp_v0_7 = func_8004240C((((struct { u8 pad[0xE]; u16 e; } *) (*((void **) (D_800C02AE + 0x32F2))))->e * 2) | 1);
                *((void **) (D_800C02AE + 0x7CD6)) = temp_v0_7;
                ((struct { u8 pad[8]; s32 v; } *) (*((void **) (((char *) func_80022318(temp_v0_7 + 0x28, &D_800A4DF4)) + 0x10))))->v = 1;
                temp_v0_8 = func_8004240C((((struct { u8 pad[0xE]; u16 e; } *) D_800C35A0)->e * 2) + 2);
                *((void **) (D_800C02AE + 0x7CD6)) = temp_v0_8;
                func_8000E8B8(((struct { u8 pad[0x178]; s32 x; } *) temp_v0_8)->x);
                { extern void *D_800C7F84; func_80076E7C(D_800C7F84); }
                var_s2 = *(*((void ***) (D_800AE850 + 0x73F0)));
                if (var_s2 != NULL)
                {
                  do
                  {
                    *((s32 *) (((char *) (((__repair_record_var_s2*)var_s2)->field_48)) + 0x20)) = 8;
                    ((__repair_record_var_s2*)var_s2)->field_14 |= 0x10;
                    var_s2 = ((__repair_record_var_s2*)var_s2)->field_4;
                  }
                  while (var_s2 != NULL);
                }
                D_800B6880 = 2;
                D_8009D538 |= 0xA00;
              }
            }
            else
            {
              func_80043124(var_s2, *((void **) (D_800C02AE + 0x32F2)));
            }
          }
        }
      }
    }
  }
  else
  {
    temp_v0_9 = func_8004240C((var_s4 * 2) + 2);
    *((void **) (D_800C02AE + 0x7CD6)) = temp_v0_9;
    func_800447A0(temp_v0_9);
    func_80043124(var_s2);
    D_800B6880 = 5;
    D_800C8120 = 0;
  }
  if (var_s5 != 0)
  {
    D_800AE44C = 0U;
    ((__repair_record_var_s2*)var_s2)->field_14 &= ~0x200;
    if (D_800B6880 != 1)
    {
      *((s32 *) (((char *) (((__repair_record_var_s2*)var_s2)->field_48)) + 0x20)) = (s32) (func_80027C64(*((u16 *) (((char *) (((__repair_record_var_s2*)var_s2)->field_48)) + 2))) & 0xFFFF);
    }
  }
  if (D_800A0200 != 0)
  {
    temp_v0_10 = func_8004240C((var_s4 * 2) + 2);
    *((void **) (D_800C02AE + 0x7CD6)) = temp_v0_10;
    new_var = 0x73F0;
    func_800447A0(temp_v0_10);
    func_80042D20();
    func_80022F78(*((void ***) (D_800AE850 + new_var)));
    func_80080514(*((void ***) (D_800AE850 + new_var)), &func_8002291C, 0x10);
    func_800804C4(*((void ***) (D_800AE850 + 0x72FC)), &func_8004E18C);
    D_800A0200 = 0;
  }
}

