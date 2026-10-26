#include "common.h"

f32 __cosf(f32);
extern f32 D_800A1878;
extern f32 D_800A187C;
extern s16 D_800A18A4;
extern s16 D_800A18A6;
extern s16 D_800A18A8;
extern s16 D_800A18AC;
extern s16 D_800A18AE;
extern s16 D_800A18B0;
extern s16 D_800A18B4;
extern s16 D_800A18B6;
extern s16 D_800A18B8;
extern s16 D_800A18BC;
extern s16 D_800A18BE;
extern s16 D_800A18C0;
extern s32 D_800A18C4;
extern s32 D_800A18C8;
extern f64 D_800A48D0;

void func_8001F518(void *arg0)
{
  f64 temp_fs0;
  s32 temp_v1;
  s32 new_var;
  s32 temp_a;

  D_800A18A4 = 0;
  D_800A18A6 = *((s32 *) (((char *) arg0) + 0x90));
  temp_a = *((s32 *) (((char *) arg0) + 0xDC));
  D_800A18AC = 0;
  D_800A18A8 = temp_a;
  D_800A18AE = *((s32 *) (((char *) arg0) + 0x128));
  temp_a = *((s32 *) (((char *) arg0) + 0x174));
  D_800A18B4 = 0;
  D_800A18B0 = temp_a;
  D_800A18B6 = *((s32 *) (((char *) arg0) + 0x1C0));
  temp_a = *((s32 *) (((char *) arg0) + 0x20C));
  D_800A18BC = 0;
  D_800A18B8 = temp_a;
  D_800A18BE = *((s32 *) (((char *) arg0) + 0x258));
  D_800A18C0 = *((s32 *) (((char *) arg0) + 0x2A4));
  temp_fs0 = D_800A48D0;
  temp_v1 = *((s32 *) (((char *) arg0) + 0x2F0));
  new_var = *((s32 *) (((char *) arg0) + 0x33C));
  D_800A18C4 = temp_v1;
  D_800A18C8 = new_var;
  D_800A1878 = __cosf((f32) (((f64) temp_v1) * temp_fs0));
  D_800A187C = __cosf((f32) (((f64) D_800A18C8) * temp_fs0));
}
