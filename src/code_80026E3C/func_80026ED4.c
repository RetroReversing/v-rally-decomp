#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
static inline f32 quarter(f32 x) { return x*0.25f; }
static inline s32 id_field(s32 x){return x;}
static inline s32 lower_check(s32 a,s32 b) { return a < b; }
#define sp18 slot18[0]
#define sp1C slot18[1]
#define sp20 slot18[2]
#define sp24 slot18[3]
#define sp28 slot28[0]
#define sp2C slot28[1]
#define sp30 slot28[2]
#define sp34 slot28[3]
#define sp38 slot38[0]
#define sp3C slot38[1]
#define sp40 slot38[2]
#define sp44 slot38[3]
#define sp48 slot48[0]
#define sp4C slot48[1]
#define sp50 slot48[2]
#define sp54 slot48[3]
#define sp58 slot58[0]
#define sp5C slot58[1]
#define sp60 slot58[2]
#define sp64 slot58[3]
#define sp68 slot68[0]
#define sp6C slot68[1]
#define sp70 slot68[2]
#define sp74 slot68[3]
#define sp78 slot78[0]
#define sp7C slot78[1]
#define sp80 slot78[2]
#define sp84 slot78[3]
#define sp88 slot88[0]
#define sp8C slot88[1]
#define sp90 slot88[2]
#define sp94 slot88[3]
#define sp98 slot98[0]
#define sp9C slot98[1]
#define spA0 slot98[2]
#define spA4 slot98[3]
#define spA8 slota8[0]
s32 func_8002D2A0(s32);
s32 func_8002D4E0(void *, s32 *, s32, s32, s32 *);
s32 func_8002D594(s32 *, s32 *, s32 *);
s32 func_8002D6E0(void *, void *);
s32 func_8002D740(void *, void *, void *);
s32 func_8002D8A0(void *, void *, void *);
s32 func_8002DA98(void *, void *);
extern void **D_8009BB10;
extern char D_800AE850[];
extern s32 D_800B6B00;
extern char D_800C02AE[];
extern s32 D_800C8370;
void func_80026ED4(void **arg0)
{
  s32 slot18[4];
  s32 slot28[4];
  s32 slot38[4];
  s32 slot48[4];
  s32 slot58[4];
  s32 slot68[4];
  s32 slot78[4];
 s32 *p78;
  s32 slot88[4];
  s32 slot98[4];
  s32 slota8[8];
  f32 *temp_s0_3;
  f32 *temp_v1_13;
  f32 *var_a0_3;
  f32 *var_a3;
  f32 temp_fv0;
  s32 var_v0_5;
  s32 temp_a0_2;
  s32 temp_a0_7;
  s32 temp_a0_3;
  s32 temp_a3;
  s32 oldY;
 s32 y_force;
  s32 oldZ;
  s32 temp_t1;
  s32 temp_t2;
  s32 temp_t3;
  s32 temp_v0_2;
  s32 temp_v0_3;
  s32 temp_v0_4;
  s32 temp_v1;
  s32 temp_v1_10;
  char *new_var;
  s32 temp_v1_11;
  s32 temp_v1_2;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a1;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_a2_3;
  s32 var_a2_4;
  s32 var_t4;
 s32 dt;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v1;
  s32 var_v1_2;
  s32 *new_var2;
  s32 var_v1_3;
  s32 var_v1_4;
  s32 var_v1_5;
 s32 matrix_offset;
 s32 matrix_base;
  void *temp_a0;
  void *temp_a0_4;
  void *temp_a0_5;
  void *temp_a0_6;
  void *temp_a0_8;
  void *temp_a0_9;
  void *temp_a1;
  void *temp_a1_2;
  void *temp_a1_3;
  void *temp_a1_4;
  void *temp_a1_5;
  void *temp_a1_6;
  void *temp_a2;
  void *temp_a2_2;
  void *temp_a2_3;
  void *temp_s0;
  void *temp_s0_2;
  void *temp_v0;
  void *temp_v1_12;
  void *temp_v1_14;
  void *temp_v1_3;
  void *temp_v1_6;
  void *temp_v1_7;
  void *temp_v1_8;
  void *temp_v1_9;
  void *var_s1;
  var_s1 = *arg0;
  if (var_s1 != NULL)
  {
    do
    {
      if (D_800B6B00 == 1)
      {
        temp_a0 = *((char **) (((char *) var_s1) + 0x8C));
        *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x30)))) + 0x58)) = (s32) (quarter(((((((f32) (*((s16 *) (((char *) temp_a0) + 0xB6)))) + ((f32) (*((s16 *) (((char *) temp_a0) + 0xCA))))) + ((f32) (*((s16 *) (((char *) temp_a0) + 0xDE))))) + ((f32) (*((s16 *) (((char *) temp_a0) + 0xF2))))))) - ((f32) ((*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x80)))) + 0x4))) + 0x14)));
        *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x10)) = (s32) (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x30)))) + 0x58)));
        *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xEC)) = (s32) ((*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x30)))) + 0x58))) * 0x10);
        *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xC4)) = (s32) ((*((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x30)))) + 0x46))) * 4);
        *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xD8)) = (s32) ((*((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x30)))) + 0x48))) * 4);
        *((s32 *) (((char *) var_s1) + 0x14)) &= ~0x1000;
        *((s32 *) (((char *) var_s1) + 0x14)) &= ~0x2000;
      }
      func_8002DA98((*((char **) (((char *) var_s1) + 0x5C))) + 0x40, &spA8);
      func_8002D8A0((*((char **) (((char *) var_s1) + 0x5C))) + 0x40, (*((char **) (((char *) var_s1) + 0x58))) + 0x5C, &sp58);
      temp_v1 = *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x84)))) + 0x44)); var_a2 = ((s32) (temp_v1 * sp58)) >> 0xC;
      var_t4 = ((s32) (temp_v1 * sp60)) >> 0xC;
      temp_a0_2 = (((s32) (temp_v1 * sp5C)) >> 0xC) + 0x500;
      if ((*((s32 *) (((char *) var_s1) + 0x14))) & 0x10)
      {
        var_a2 = 0;
        var_t4 = 0;
      }
      temp_v0 = *((char **) (((char *) var_s1) + 0x58));
      dt = D_800C8370;
      temp_v1_2 = id_field(*((s32 *) (((char *) temp_v0) + 0x34)));
      temp_t1 = id_field(*((s32 *) (((char *) temp_v0) + 0x20)));
      oldY = id_field(*((s32 *) (((char *) temp_v0) + 0x38)));
      temp_t2 = id_field(*((s32 *) (((char *) temp_v0) + 0x24)));
      oldZ = id_field(*((s32 *) (((char *) temp_v0) + 0x3C)));
      temp_t3 = id_field(*((s32 *) (((char *) temp_v0) + 0x28)));
      *((s32 *) (((char *) temp_v0) + 0x34)) = var_a2;
      *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x38)) = temp_a0_2;
      *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x3C)) = var_t4;
      temp_a2 = *((char **) (((char *) var_s1) + 0x58));
      temp_t1 = temp_t1 + (((s32) ((var_a2 + temp_v1_2) * dt)) >> 5);
      y_force = temp_a0_2 + oldY;
      *((s32 *) (((char *) temp_a2) + 0xE8)) = (s32) ((*((s32 *) (((char *) temp_a2) + 0xE8))) + (((temp_t1 + (*((s32 *) (((char *) temp_a2) + 0x20)))) * dt) / 1600));
      temp_a2_2 = *((char **) (((char *) var_s1) + 0x58));
      temp_t2 = temp_t2 + (((s32) (y_force * dt)) >> 5);
      *((s32 *) (((char *) temp_a2_2) + 0xEC)) = (s32) ((*((s32 *) (((char *) temp_a2_2) + 0xEC))) + (((temp_t2 + (*((s32 *) (((char *) temp_a2_2) + 0x24)))) * dt) / 1600));
      temp_a1 = *((char **) (((char *) var_s1) + 0x58));
      temp_a3 = ((s32) ((var_t4 + oldZ) * dt)) >> 5;
      temp_t3 = temp_t3 + temp_a3;
      *((s32 *) (((char *) temp_a1) + 0xF0)) = (s32) ((*((s32 *) (((char *) temp_a1) + 0xF0))) + (((temp_t3 + (*((s32 *) (((char *) temp_a1) + 0x28)))) * dt) / 1600));
      *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x20)) = temp_t1;
      *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x24)) = temp_t2;
      *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x28)) = temp_t3;
      temp_v1_3 = *((char **) (((char *) var_s1) + 0x58));
      temp_a0_3 = *((s32 *) (((char *) temp_v1_3) + 0x20));
      temp_a1_2 = temp_v1_3 + 0x20;
      if ((temp_a0_3 < 0x190) && lower_check(-0x190, temp_a0_3))
      {
        *((s32 *) (((char *) temp_v1_3) + 0x20)) = 0;
      }
      temp_v1_4 = *((s32 *) (((char *) temp_a1_2) + 0x4));
      if ((temp_v1_4 < 0x190) && lower_check(-0x190, temp_v1_4))
      {
        *((s32 *) (((char *) temp_a1_2) + 0x4)) = 0;
      }
      temp_v1_5 = *((s32 *) (((char *) temp_a1_2) + 0x8));
      if ((temp_v1_5 < 0x190) && lower_check(-0x190, temp_v1_5))
      {
        *((s32 *) (((char *) temp_a1_2) + 0x8)) = 0;
      }
      temp_v1_6 = *((char **) (((char *) var_s1) + 0x58));
      *((s32 *) (((char *) temp_v1_6) + 0xC)) = (s32) (((s32) (*((s32 *) (((char *) temp_v1_6) + 0xE8)))) >> 4);
      temp_v1_7 = *((char **) (((char *) var_s1) + 0x58));
      *((s32 *) (((char *) temp_v1_7) + 0x10)) = (s32) (((s32) (*((s32 *) (((char *) temp_v1_7) + 0xEC)))) >> 4);
      temp_v1_8 = *((char **) (((char *) var_s1) + 0x58));
      *((s32 *) (((char *) temp_v1_8) + 0x14)) = (s32) (((s32) (*((s32 *) (((char *) temp_v1_8) + 0xF0)))) >> 4);
      temp_a1_3 = *((char **) (((char *) var_s1) + 0x58));
      func_8002D740(temp_a1_3 + 0x48, temp_a1_3 + 0x5C, &sp98);
      sp88 = (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x70))) - sp98;
      sp8C = (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x74))) - sp9C;
      sp90 = (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x78))) - spA0;
      func_8002D8A0((*((char **) (((char *) var_s1) + 0x84))) + 0x20, &sp88, &sp18);
      temp_a0_4 = *((char **) (((char *) var_s1) + 0x58));
      *((s32 *) (((char *) temp_a0_4) + 0x98)) = (s32) ((*((s32 *) (((char *) temp_a0_4) + 0x98))) + (((s32) ((sp18 + (*((s32 *) (((char *) temp_a0_4) + 0x84)))) * D_800C8370)) >> 8));
      temp_a0_5 = *((char **) (((char *) var_s1) + 0x58));
      *((s32 *) (((char *) temp_a0_5) + 0x9C)) = (s32) ((*((s32 *) (((char *) temp_a0_5) + 0x9C))) + (((s32) ((sp1C + (*((s32 *) (((char *) temp_a0_5) + 0x88)))) * D_800C8370)) >> 8));
      temp_a0_6 = *((char **) (((char *) var_s1) + 0x58));
      *((s32 *) (((char *) temp_a0_6) + 0xA0)) = (s32) ((*((s32 *) (((char *) temp_a0_6) + 0xA0))) + (((s32) ((sp20 + (*((s32 *) (((char *) temp_a0_6) + 0x8C)))) * D_800C8370)) >> 8));
      *((char **) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x84)) = sp18;
      *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x88)) = sp1C;
      *((char **) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x8C)) = sp20;
      temp_v1_9 = *((char **) (((char *) var_s1) + 0x58));
      temp_a0_7 = *((s32 *) (((char *) temp_v1_9) + 0x98));
      temp_a1_4 = temp_v1_9 + 0x98;
      if ((temp_a0_7 < 2) && lower_check(-2, temp_a0_7))
      {
        *((s32 *) (((char *) temp_v1_9) + 0x98)) = 0;
      }
      temp_v1_10 = *((s32 *) (((char *) temp_a1_4) + 0x4));
      if ((temp_v1_10 < 2) && lower_check(-2, temp_v1_10))
      {
        *((s32 *) (((char *) temp_a1_4) + 0x4)) = 0;
      }
      temp_v1_11 = *((s32 *) (((char *) temp_a1_4) + 0x8));
      if ((temp_v1_11 < 2) && lower_check(-2, temp_v1_11))
      {
        *((s32 *) (((char *) temp_a1_4) + 0x8)) = 0;
      }
      if ((*((s32 *) (((char *) var_s1) + 0x14))) & 0x10)
      {
        *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x9C)) = 0;
      }
      temp_v1_12 = *((char **) (((char *) var_s1) + 0x58));
      if (((u32) ((*((s32 *) (((char *) temp_v1_12) + 0x9C))) + 4)) < 9U)
      {
        *((s32 *) (((char *) temp_v1_12) + 0x9C)) = 0;
      }
      temp_a1_5 = *((char **) (((char *) var_s1) + 0x58));
      p78=&sp68; func_8002D594(temp_a1_5 + 0xC0, temp_a1_5 + 0xD4, p78); p78=0;
      sp68 /= 16384;
      sp6C /= 16384;
      sp70 /= 16384;
      temp_a0_8 = *((char **) (((char *) var_s1) + 0x58));
      func_8002D4E0(temp_a0_8 + 0xD4, &sp68, *((s32 *) (((char *) temp_a0_8) + 0xA0)), -(*((s32 *) (((char *) temp_a0_8) + 0x9C))), &sp28);
      temp_a0_9 = *((char **) (((char *) var_s1) + 0x58));
      func_8002D4E0(temp_a0_9 + 0xC0, &sp68, -(*((s32 *) (((char *) temp_a0_9) + 0xA0))), *((s32 *) (((char *) temp_a0_9) + 0x98)), &sp38);
      if (((sp28 != 0) || (sp2C != 0)) || (sp30 != 0))
      {
        func_8002D4E0((*((char **) (((char *) var_s1) + 0x58))) + 0xC0, &sp28, 0x1000, 0x400, &sp68);
        temp_s0 = *((char **) (((char *) var_s1) + 0x58));
        func_8002D6E0(&sp68, temp_s0 + 0xC0);
        temp_v0_2 = func_8002D2A0(((*((s32 *) (((char *) temp_s0) + 0xC0))) + (*((s32 *) (((char *) temp_s0) + 0xC4)))) + (*((s32 *) (((char *) temp_s0) + 0xC8))));
        if (temp_v0_2 != 0)
        {
          *((s32 *) (((char *) temp_s0) + 0xC0)) = (s32) (((s32) (sp68 << 0xE)) / temp_v0_2);
          temp_a0_3 = temp_v0_2;
          *((s32 *) (((char *) temp_s0) + 0xC4)) = (s32) (((s32) (sp6C << 0xE)) / temp_a0_3);
          *((s32 *) (((char *) temp_s0) + 0xC8)) = (s32) (((s32) (sp70 << 0xE)) / temp_a0_3);
        }
        else
        {
          *((s32 *) (((char *) temp_s0) + 0xC0)) = 0;
          *((s32 *) (((char *) temp_s0) + 0xC4)) = 0;
          *((s32 *) (((char *) temp_s0) + 0xC8)) = 0;
        }
      }
      if ((sp38 || sp3C) || sp40)
      {
        func_8002D4E0((*((char **) (((char *) var_s1) + 0x58))) + 0xD4, &sp38, 0x1000, 0x400, &sp88);
        p78=&sp78;
func_8002D594((*((char **) (((char *) var_s1) + 0x58))) + 0xC0, &sp88, p78);
 p78=0;
        sp78 /= 16384;
        sp7C /= 16384;
        sp80 /= 16384;
        func_8002D6E0(&sp78, &sp48);
        temp_v0_4 = func_8002D2A0((sp48 + sp4C) + sp50);
        if (temp_v0_4 != 0)
        {
          sp48 = ((s32) (sp78 << 0xE)) / temp_v0_4;
          sp4C = ((s32) (sp7C << 0xE)) / temp_v0_4;
          sp50 = ((s32) (sp80 << 0xE)) / temp_v0_4;
        }
        else
        {
          sp48 = 0;
          sp4C = 0;
          sp50 = 0;
        }
        temp_s0_2 = *((char **) (((char *) var_s1) + 0x58));
        func_8002D594(&sp48, temp_s0_2 + 0xC0, temp_s0_2 + 0xD4);
        var_v0_4 = *((s32 *) (((char *) temp_s0_2) + 0xD4));
        *((s32 *) (((char *) temp_s0_2) + 0xD4)) = var_v0_4 / 16384;
        var_a0_2 = *((s32 *) (((char *) temp_s0_2) + 0xD8));
        *((s32 *) (((char *) temp_s0_2) + 0xD8)) = var_a0_2 / 16384;
        var_v1_4 = *((s32 *) (((char *) temp_s0_2) + 0xDC));
        *((s32 *) (((char *) temp_s0_2) + 0xDC)) = var_v1_4 / 16384;
      }
      else
      {
        temp_a1_6 = *((char **) (((char *) var_s1) + 0x58));
        func_8002D594(temp_a1_6 + 0xC0, temp_a1_6 + 0xD4, &sp78);
        do
        {
        }
        while (0);
        sp78 /= 16384;
        sp7C /= 16384;
        sp80 /= 16384;
        func_8002D6E0(&sp78, &sp48);
        temp_v0_3 = func_8002D2A0((sp48 + sp4C) + sp50);
        if (temp_v0_3 != 0)
        {
          sp48 = ((s32) (sp78 << 0xE)) / temp_v0_3;
          sp4C = ((s32) (sp7C << 0xE)) / temp_v0_3;
          sp50 = ((s32) (sp80 << 0xE)) / temp_v0_3;
        }
        else
        {
          sp48 = 0;
          sp4C = 0;
          sp50 = 0;
        }
      }
      temp_v1_13 = *((char **) (((char *) var_s1) + 0x5C));
      matrix_base = (s32)((s32) (((char *) temp_v1_13) + 0x40));
      var_v0_5 = *((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xC2));
      if (var_v0_5 < 0)
      {
        var_v0_5 += 3;
      }
      *((s16 *) (((char *) temp_v1_13) + 0x40)) = (s16) (var_v0_5 >> 2);
      *((s16 *) (((char *) temp_v1_13) + 0x46)) = (s16) (((s16) (*((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xC6)))) / 4);
      *((s16 *) (((char *) temp_v1_13) + 0x4C)) = (s16) (((s16) (*((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xCA)))) / 4);
      *((s16 *) (((char *) temp_v1_13) + 0x42)) = (s16) (((s16) (*((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xD6)))) / 4);
      *((s16 *) (((char *) temp_v1_13) + 0x48)) = (s16) (((s16) (*((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xDA)))) / 4);
      *((s16 *) (((char *) temp_v1_13) + 0x4E)) = (s16) (((s16) (*((s16 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xDE)))) / 4);
      *((s16 *) (((char *) temp_v1_13) + 0x44)) = (s16) ((*((s16 *) (((char *) (&sp48)) + 2))) / 4);
      *((s16 *) (((char *) temp_v1_13) + 0x4A)) = (s16) ((*((s16 *) (((char *) (&sp4C)) + 2))) / 4);
      *((s16 *) (((char *) temp_v1_13) + 0x50)) = (s16) ((*((s16 *) (((char *) (&sp50)) + 2))) / 4);
      temp_s0_3 = *((char **) (((char *) var_s1) + 0x5C));
      var_a2_4 = 0;
      var_a3 = temp_s0_3;
      for (;var_a2_4<3;) {
      var_a1 = 0;

      matrix_offset = var_a2_4 * 2;
      var_a0_3 = var_a3;
      var_v1_5 = (s32) matrix_base;
      loop_79:
      temp_fv0 = ((f32) (*((s16 *) (matrix_offset + var_v1_5)))) * (1.0f/4096.0f);

      var_v1_5 += 6;
      var_a1 += 1;
      *var_a0_3 = temp_fv0;
      var_a0_3 += 1;
      if (var_a1 < 3)
      {
        goto loop_79;
      }
      var_a2_4 += 1;
      var_a3 += 4;
      }
      temp_v1_14 = *((char **) (((char *) var_s1) + 0x58));
      *((s16 *) (((char *) temp_v1_14) + 0xFC)) = (s16) (*((s32 *) (((char *) temp_v1_14) + 0xC0)));
      new_var = (char *) var_s1;
      *((s16 *) (((char *) temp_v1_14) + 0x102)) = (s16) (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xC4)));
      *((s16 *) (((char *) temp_v1_14) + 0x108)) = (s16) (*((s32 *) (((char *) (*((char **) (new_var + 0x58)))) + 0xC8)));
      *((s16 *) (((char *) temp_v1_14) + 0xFE)) = (s16) (*((s32 *) (((char *) (*((char **) (new_var + 0x58)))) + 0xD4)));
      *((s16 *) (((char *) temp_v1_14) + 0x104)) = (s16) (*((s32 *) (((char *) (*((char **) (new_var + 0x58)))) + 0xD8)));
      *((s16 *) (((char *) temp_v1_14) + 0x10A)) = (s16) (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xDC)));
      *((s16 *) (((char *) temp_v1_14) + 0x100)) = (s16) sp48;
      *((s16 *) (((char *) temp_v1_14) + 0x106)) = (s16) sp4C;
      *((s16 *) (((char *) temp_v1_14) + 0x10C)) = (s16) sp50;
      temp_a2_3 = *((char **) (new_var + 0x58));
      func_8002D8A0((*((char **) (new_var + 0x5C))) + 0x40, temp_a2_3 + 0x98, temp_a2_3 + 0xAC);
      *((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x5C)))) + 0x54)) = (s32) (*((s32 *) (((char *) (*((char **) (new_var + 0x58)))) + 0xC)));
      *((char **) (((char *) (*((char **) (new_var + 0x5C)))) + 0x58)) = (s32) (*((s32 *) (((char *) (*((char **) (new_var + 0x58)))) + 0x10)));
      *((char **) (((char *) (*((char **) (new_var + 0x5C)))) + 0x5C)) = (s32) (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x14)));
      *((f32 *) (((char *) temp_s0_3) + 0x30)) = (f32) (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0xC)));
      *((f32 *) (((char *) temp_s0_3) + 0x34)) = (f32) (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x10)));
      *((f32 *) (((char *) temp_s0_3) + 0x38)) = (f32) (*((s32 *) (((char *) (*((char **) (((char *) var_s1) + 0x58)))) + 0x14)));
      *((f32 *) (((char *) temp_s0_3) + 0x3C)) = 1.0f;
      *((f32 *) (((char *) temp_s0_3) + 0xC)) = 0;
      *((f32 *) (((char *) temp_s0_3) + 0x1C)) = 0;
      *((f32 *) (((char *) temp_s0_3) + 0x2C)) = 0;
      var_s1 = *((s32 *) (((char *) var_s1) + 0x4));
    }
    while (var_s1 != NULL);
  }
  D_8009BB10 = arg0;
  D_800B6B00 = (s32) (D_800B6B00 + 1);
}

