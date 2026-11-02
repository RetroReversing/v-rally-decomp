#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
s32 func_800153E4();
s32 func_80022184(void *);
s32 func_800221D4(void *, s32 *);
s32 memset(void *, s32, s32);
extern s32 D_8009BBA4;
extern s16 D_8009BBB4;
extern s16 D_8009BBB6;
extern s32 *D_8009BBB8;
extern s16 D_8009CEBC;
extern s32 D_8009E250;
extern s32 D_8009E254;
extern s32 D_8009E258;
extern s32 D_8009FF30;
extern f32 D_800A1878;
extern f32 D_800A187C;
extern s32 D_800A1884;
extern s32 D_800A188C;
extern s32 D_800A1894;
extern s32 D_800A189C;
extern s32 D_800A18A4;
extern s32 D_800A18AC;
extern s32 D_800A18B4;
extern s32 D_800A18BC;
extern s32 D_800A18C4;
extern s32 D_800A18C8;
extern f64 D_800A4178;
extern s32 D_800A73E0;
extern s32 D_800AE850;
extern s32 D_800C02AE;
extern s32 func_80015E4C;
extern s32 func_8001B880;
typedef struct { u8 pad[0xE]; u16 mode; u8 pad10[2]; u16 x12; u8 pad14[0xA]; u16 x1E; u8 pad20[0xC]; u16 x2C; } R15780;
typedef struct { u8 p0[2]; s8 state; u8 p3[2]; s8 x5; u8 p6[2]; u16 x8; s8 xA; u8 pB; } S7676;
#define G(t, base, off) (*(t *) ((char *) &base + (off)))
#define RACE (*(R15780 **) ((char *) &D_800C02AE + 0x32F2))
#define ST ((S7676 *) ((char *) &D_800C02AE + 0x7676))
struct Copy12 { s32 a; s32 b; s32 c; } __attribute__((packed));
struct Copy6 { s32 a; s16 b; } __attribute__((packed, aligned(2)));

void func_80015780(s32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4, s32 arg5)
{
  s32 *temp_v1;
  f64 temp_fs0;
  void *temp_s0;
  temp_s0 = (char *) &D_800AE850 + 0x7368;
  if (func_80022184(temp_s0) == 0)
  {
    func_800221D4(temp_s0, &func_8001B880);
    D_8009BBB4 = arg5;
    G(s32, D_800A73E0, 0x6BD0) = 0x1000;
    G(s16, D_800A73E0, 0x6BEE) = arg3;
    func_800153E4();
    G(struct Copy12, D_800C02AE, 0x7676) = *(struct Copy12 *) &D_8009BBA4;
    D_8009CEBC = 4;
    if (arg0 == 0)
    {
      if ((RACE->x2C & 1) || (RACE->x1E == 7))
      {
        ST->state = 0;
        if (G(u8, D_800A73E0, 0x6C02))
          ST->x8 = 0x8000;
        else
          ST->x8 = 0x4000;
      }
      else if (RACE->mode == 1)
      {
        ST->state = 0;
        if (G(u8, D_800A73E0, 0x6C02))
          ST->x8 = 0x8000;
        else
          ST->x8 = 0x4000;
      }
      else
      {
        ST->xA = 1;
        if (RACE->mode == 2)
        {
          ST->x5 = RACE->x12;
          if (RACE->x12)
          {
            ST->state = 2;
            ST->x8 = 0xC000;
          }
          else
          {
            ST->state = 1;
            ST->x8 = 0xC000;
            G(s16, D_800A73E0, 0x6BEE) = (arg3 * 2) / 3;
          }
        }
        else
        {
          ST->state = 3;
          ST->x8 = 0xF400;
        }
      }
    }
    else
    {
      G(s32, D_800AE850, 0x72F4) = 0;
      ST->state = 0;
      ST->x8 = 0xC000;
    }
    G(s16, D_800A73E0, 0x6BE6) = 0xFF;
    G(s16, D_800A73E0, 0x6BE8) = 0xFF;
    G(s16, D_800A73E0, 0x6BEA) = 0xFF;
    G(s16, D_800A73E0, 0x6BEC) = 0xFF;
  }
  D_8009E250 = 2;
  D_8009E254 = 2;
  D_8009FF30 = 0;
  D_8009E258 = 7;
  memset((u8 *) &D_800C02AE + 0x5A4A, 0, 0x24);
  *(struct Copy6 *) &D_800A18A4 = *(struct Copy6 *) &D_800A1884;
  *(struct Copy6 *) &D_800A18AC = *(struct Copy6 *) &D_800A188C;
  temp_fs0 = D_800A4178;
  temp_v1 = G(s32 *, D_800C02AE, 0x7DA6);
  *(struct Copy6 *) &D_800A18B4 = *(struct Copy6 *) &D_800A1894;
  *(struct Copy6 *) &D_800A18BC = *(struct Copy6 *) &D_800A189C;
  G(s16, D_800AE850, 0x7300) = 0;
  G(s32 *, D_800C02AE, 0x7DA6) = &func_80015E4C;
  G(s32, D_800AE850, 0x82AC) = 0;
  D_8009BBB8 = temp_v1;
  D_800A1878 = __cosf((f32) (((f64) D_800A18C4) * temp_fs0));
  D_800A187C = __cosf((f32) (((f64) D_800A18C8) * temp_fs0));
  D_8009BBB6 = 0xA;
}

