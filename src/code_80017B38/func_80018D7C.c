#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Ent
{
  u8 *p0;
  u16 f4;
  u16 f6;
} Ent;
extern u8 D_8009BBBC;
extern s16 D_8009C254[][4][7];
extern s32 D_8009C2C4[];
extern u16 D_800B5B50;
extern s32 D_800B5B44;
extern u8 *D_800C6ED8;
extern u8 D_800C7926;
extern u8 *D_800C7F84;
u8 *func_80018C04(void *, void *, void *);
void func_8000DBC0(s32);
void func_8007EE9C(s32);
void func_80018D7C(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3)
{
  int __repair_literal;
  u8 *s3;
  u8 *s0;
  s32 s1;
  u8 *new_var;
  s32 v;
  u8 *t;
  s3 = func_80018C04(D_800C6ED8, D_800C7F84 + 0x38, *((void **) (arg1 + 0x14)));
  if (s3 == NULL)
  {
    t = *((u8 **) (arg1 + 0x14));
    if (t != NULL)
      s3 = t;
    else
      s3 = *(*((u8 ***) (&D_800C6ED8)));
  }
  if ((*((u8 **) (arg1 + 0x14))) == NULL)
  {
    *((u8 **) (arg1 + 0x14)) = s3;
  }
  if (D_8009BBBC != 0)
  {
    if ((*((u8 **) (arg1 + 0x14))) != s3)
    {
      s1 = (*((s32 *) (*((u8 **) (arg1 + 0x14)) + 0x28))) - 1;
      while (s1 >= 0)
      {
        s0 = *((u8 **) ((*((u8 **) ((*((u8 **) (arg1 + 0x14))) + 0x2C))) + (s1 * 8)));
        if ((*((s32 *) (s0 + 0x38))) != 0)
        {
          func_8007EE9C(*((s32 *) (s0 + 0x38)));
          *((s32 *) (s0 + 0x38)) = 0;
        }
        s1--;
      }

      func_8000DBC0(D_800B5B44);
      *((u8 **) (arg1 + 0x14)) = s3;
      return;
    }
  }
  if (s3 != NULL)
  {
    *((s16 *) (arg1 + 0x18)) = 1;
    *((u16 *) (arg1 + 0x1C)) = 0;
    s1 = (*((s32 *) (s3 + 0x28))) + (-1);
    while (s1 >= 0)
    {
      Ent *rec = (Ent *) ((*((u8 **) (s3 + 0x2C))) + (s1 * 8));
      if ((s1 != 0) && (rec->f4 == 0))
      {
        rec->f4 = 4;
      }
      v = D_8009C254[D_800B5B50][D_800C7926][rec->f4];
      if (v >= 0)
      {
        new_var = rec->p0;
        __repair_literal = 4;
        *((u16 *) (arg1 + 0x1C)) |= ((s32 (*)(u8 *, s32, u8 *, s32)) (*((s32 *) ((((char *) D_8009C254) + 0x70) + (rec->f6 * __repair_literal)))))(new_var, rec->f4, arg2, arg3);
      }
      s1--;
    }

  }
  *((u8 **) (arg1 + 0x14)) = s3;
}

