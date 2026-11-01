#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Node
{
  u8 p0[8];
  s16 unk8;
  u16 unkA;
  u8 pC[0x40];
  s32 unk4C;
  u8 p50[8];
  struct Node *unk58;
  struct Node *unk5C;
  u8 p60[0x28];
  u16 unk88;
  u16 unk8A;
  u16 unk8C;
} Node;
s32 func_8004E5B0(Node *, u16 *);
s32 func_8004ECA8(u16 *, u16 *);
void func_8004ED08(Node *, s32, u16, u16, s32, s32, s32);
extern u8 D_800ADFE1;
void func_8004EF40(Node *arg0)
{
  u16 a[4];
  u16 b[4];
  s32 one;
  s32 six;
  u16 *bp;
  s32 temp_v0;
  s32 var_a1;
  s32 var_s2;
  s32 var_s4;
  s32 var_t0;
  u16 temp_a0_2;
  u16 temp_a0_3;
  u16 temp_a0_4;
  s32 temp_v0_3;
  u16 temp_v1_2;
  u16 var_v0;
  u32 var_v1;
  Node *temp_a0;
  Node *temp_s3;
  Node *temp_v0_2;
  Node *temp_v0_4;
  Node *temp_v1;
  Node *var_s0;
  Node *var_s1;
  var_s4 = 0;

  if (arg0->unk58 != 0)
  {
    var_s1 = arg0;
  }
  else
  {
    var_s1 = arg0->unk5C;
  }
  bp = b;
  one = 1;
  six = 6;
  do {
  var_s0 = var_s1->unk58;

  temp_v0 = func_8004E5B0(var_s1, &a[0]);
  var_s2 = 0;
  temp_s3 = var_s1;
  if (a[1] != 0)
  {
    if (!(temp_v0 & 0xFF))
    {
      temp_a0 = var_s1->unk5C;
      if (temp_a0 != NULL)
      {
        func_8004E5B0(temp_a0, bp);
        if (func_8004ECA8(&a[0], bp) != 0)
        {
          temp_a0_2 = var_s1->unk8C;
          var_s2 = 1;
          if ((temp_a0_2 != 0x1C) & (temp_a0_2 != 0x14))
          {
            goto block_21;
          }
          {
            if (temp_a0_2 == 0x1C)
            {
              a[0] = one;
              b[0] = one;
              a[1] = 2;
              b[1] = one;
            }
            else
            {
              a[0] = 0;
              b[0] = 0;
              var_s2 = 5;
              if (var_s1->unkA & 0x100)
              {
                a[1] = one;
                b[1] = 2;
              }
              else
              {
                a[1] = 2;
                b[1] = one;
              }
            }
          }
        }
        else
          if (((a[3] == 0) && (b[3] != 0)) && (a[1] == b[1]))
        {
          if (a[0] != 2)
          {
            a[0] = a[0] + 1;
          }
          block_21:
          temp_v0_2 = var_s1->unk5C;

          if (temp_v0_2 != NULL)
          {
            var_s1 = temp_v0_2;
          }
        }
      }
    }
    if (var_s4 != 0)
    {
      if ((D_800ADFE1 != 0) || (var_s0->unk8 >= 2))
      {
        var_s0 = var_s0->unk58;
      }
      var_t0 = ((u32)(var_s0->unk88 - 4) * var_s0->unk8A) + var_s0->unk4C;
    }
    else if (a[3] == 0)
    {
      var_t0 = var_s0->unk4C + (((var_s0->unk88 / 3) & 0xFFFF) * var_s0->unk8A);
    }
    else
    {
      var_t0 = ((u32)(var_s0->unk88 >> 2) * var_s0->unk8A) + var_s0->unk4C;
    }
    temp_v1 = temp_s3->unk5C;
    if (temp_v1 != NULL)
    {
      var_a1 = 1;
      if (a[0] == 0)
      {
        temp_a0_3 = temp_s3->unk8C;
        if (((temp_a0_3 == temp_v1->unk8C) & (var_s2 != 0)) && ((((u32) (temp_a0_3 - 0x1D)) < 2U) || (((u32) (temp_a0_3 - 0x12)) < 2U)))
        {
          var_a1 = 0;
        }
      }
      if (var_a1 != 0)
      {
        if (temp_s3->unkA & 0x20)
        {
          var_s2 = 2;
          b[1] = six;
          b[0] = six;
        }
        temp_v1_2 = temp_s3->unkA;
        if (!(temp_v1_2 & 0x10))
        {
          if (temp_v1_2 & 0x80)
          {
            temp_v0_3 = a[1];
            temp_a0_4 = a[0];
            var_s2 = 2;
            a[1] = 9;
            a[0] = six;
            b[1] = temp_v0_3;
            b[0] = temp_a0_4;
          }
        }
        func_8004ED08(var_s0, var_s2, a[1], a[0], (s32) b[1], (s32) b[0], var_t0);
        var_s4 = 0;
      }
    }
  }
  else
  {
    var_s4 += 1;
  }
  temp_v0_4 = var_s1->unk5C;
  if (temp_v0_4 != NULL)
  {
    var_s1 = temp_v0_4;
  }
  } while ((var_s1 != arg0) && (var_s1->unk5C != 0));
}

