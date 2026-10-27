#include "common.h"

typedef struct Copy40 { s32 w[10]; } Copy40;
typedef struct Words
{
  s32 w0;
  s32 w1;
  s32 w2;
  s32 w3;
} Words;
typedef struct HeaderView
{
  u8 pad[0x1A];
  u16 mode1A;
  u8 gap[2];
  u16 mode1E;
} HeaderView;
s32 func_80022A98();
s32 func_8007B204(void *);
extern void ** volatile D_800B5C40;
extern void * volatile D_800C35A0;
void func_8004F57C(void *arg0)
{
  s32 tail1;
  s32 tail0;
  s32 tail2;
  s32 tail3;
  s32 tail4;
  s32 tail5;
  s32 w0;
  s32 w1;
  s32 w2;
  s32 w3;
  s32 x0;
  s32 x1;
  s32 x2;
  s32 y0;
  s32 y1;
  s32 y2;
  s32 y3;
  s32 lastval;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_s0;
  s32 var_s0;
  s32 var_s0_2;
  s32 var_s3;
  s32 var_s3_2;
  u16 temp_a0;
  s32 temp_v1;
  void *temp_s1;
  void *temp_s1_2;
  void *temp_s1_3;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *initial;
  void *base;
  void *end2;
  void *end3;
  void *var_a2;
  void *var_a2_2;
  void *var_a2_3;
  void *var_a3;
  void *var_a3_2;
  void *var_a3_3;
  void *var_s2;
  void *var_s2_2;
  void *var_s2_3;
  initial = D_800C35A0;
  temp_v1 = *((u8 *) (((char *) arg0) + 0x114));
  if (((HeaderView *) initial)->mode1E == 0)
  {
    temp_s0 = temp_v1 & 0xFF;
    if (((HeaderView *) initial)->mode1A != 0)
    {
      register void *end;
      var_s2 = *D_800B5C40;
      if (temp_s0 == 1)
      {
        var_s2 = *((void **) (((char *) var_s2) + 4));
        var_s2 = *((void **) (((char *) var_s2) + 4));
      }
      temp_s1 = arg0 + (temp_s0 * 0x44);
      func_80022A98(var_s2, *((s32 *) (((char *) temp_s1) + 0)));
      base = D_800C35A0;
      *((s16 *) (((char *) temp_s1) + 0xE)) = 0;
      var_a3_2 = temp_s1 + 0x1C;
      temp_v0_3 = (void *) (((*((u8 *) (((char *) (base + temp_s0)) + 0x32))) * 0x28) + ((u32) base));
      *(Copy40 *)(temp_s1 + 0x1C) = *(Copy40 *)(temp_v0_3 + 0x44);
      *((s32 *) (((char *) temp_s1) + 0x18)) = (s32) (*(*((s32 **) (((char *) var_s2) + 0x88))));
      func_8007B204(var_s2);
      *((u16 *) (((char *) temp_s1) + 8)) = (u16) (((*((u16 *) (((char *) temp_s1) + 8))) | 0x200) & 0xFBFF);
      return;
    }
    temp_a0 = (u8)(s8)temp_v1;
    if (temp_a0 != 0)
    {
      return;
    }
    {
      var_s2_2 = *D_800B5C40;
      var_s3 = 0;
      if (((u32) (temp_a0 & 0xFF)) < ((u16) (*((u16 *) (((char *) arg0) + 0x110)))))
      {
        do
        {
          var_s0 = var_s3 & 0xFF;
          temp_s1_2 = arg0 + (var_s0 * 0x44);
          func_80022A98(var_s2_2, *((s32 *) (((char *) temp_s1_2) + 0)));
          base = D_800C35A0;
          *((s16 *) (((char *) temp_s1_2) + 0xC)) = 0;
          *((s16 *) (((char *) temp_s1_2) + 0xE)) = 0;
          var_a3_3 = temp_s1_2 + 0x1C;
          temp_v0_2 = (void *)(((*((u8 *) (((char *) (base + var_s0)) + 0x32))) * 0x28) + (u32)base);
          *(Copy40 *)(temp_s1_2 + 0x1C) = *(Copy40 *)(temp_v0_2 + 0x44);
          *((s32 *) (((char *) temp_s1_2) + 0x18)) = (s32) (*(*((s32 **) (((char *) var_s2_2) + 0x88))));
          func_8007B204(var_s2_2);
          var_s3 += 1;
          *((s16 *) (((char *) temp_s1_2) + 0xA)) = 1;
          *((u16 *) (((char *) temp_s1_2) + 8)) = (u16) (((*((u16 *) (((char *) temp_s1_2) + 8))) | 0x200) & 0xFBFF);
          var_s2_2 = *((void **) (((char *) var_s2_2) + 4));

        }
        while (((u32) (var_s3 & 0xFF)) < ((u16) (*((u16 *) (((char *) arg0) + 0x110)))));
      }
    }
  }
  else
  {
    var_s3 = 0;
    if (temp_v1 == 0)
    {
      var_s2 = *D_800B5C40;
      do
      {
        var_s0_2 = var_s3 & 0xFF;
        temp_s1 = arg0 + (var_s0_2 * 0x44);
        *((s16 *) (((char *) temp_s1) + 0xC)) = 0;
        *((s16 *) (((char *) temp_s1) + 0xE)) = 0;
        func_80022A98(var_s2, *((s32 *) (((char *) temp_s1) + 0)));
        var_a3 = temp_s1 + 0x1C;
        base = D_800C35A0;
        temp_v0 = (void *)(((*((u8 *) (((char *) (base + var_s0_2)) + 0x32))) * 0x28) + (u32)base);
        *(Copy40 *)(temp_s1 + 0x1C) = *(Copy40 *)(temp_v0 + 0x44);
        lastval = (s32) (*(*((s32 **) (((char *) var_s2) + 0x88))));
        var_s3 += 1;
        *((s16 *) (((char *) temp_s1) + 0xA)) = 1;
        *((u16 *) (((char *) temp_s1) + 8)) = (u16) (((*((u16 *) (((char *) temp_s1) + 8))) | 0x200) & 0xFBFF);
        *((s32 *) (((char *) temp_s1) + 0x18)) = lastval;
        var_s2 = *((void **) (((char *) var_s2) + 4));
      }
      while (((u32) (var_s3 & 0xFF)) < 4U);
    }
  }
}
