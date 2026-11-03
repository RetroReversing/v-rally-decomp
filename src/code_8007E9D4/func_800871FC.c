#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  s32 data;
  s16 size;
} Arg1;
typedef struct 
{
  s32 x0;
  s16 size;
  s16 pad6;
  s32 x8;
  s32 xC;
  s32 x10;
  s32 x14;
  s32 x18;
  s32 x1C;
  s32 x20;
  s32 x24;
  s32 x28;
  s32 x2C;
  s32 x30;
  s32 x34;
  s32 x38;
  s32 x3C;
  s32 x40;
  s32 x44;
  s32 x48;
  void *p4C;
  s16 n50;
  s16 n52;
} Arg0;
extern u32 D_800A1BAC;
extern s32 D_800A73E0[];
extern s32 D_800AE850[];
extern s32 D_800C8320;
extern s32 D_80001D10;
extern s32 D_80001DE0;
extern s32 D_8009AAB0;
void func_80087114(void);
s32 osVirtualToPhysical(s32);
void func_8008A6D0(s32, s32);
u32 func_8008A590(void);
s32 alAudioFrame(s32, s32 *, s32, s16);
void func_8007F6E0(s32);
void osSetThreadPri(s32, s32);
void func_8007F798(s32, s32, void *);
static inline s32 *getSlot(void)
{
  return &D_800AE850[(0x2278 / 4) + D_800A1BAC % 3];
}
s32 func_800871FC(Arg0 *a, Arg1 *b)
{
  Arg0 *new_var4;
  s32 *new_var2;
  s32 samples[2];
  u8 *new_var5;
  int new_var;
  s16 count;
  s32 phys;
  s32 wrote;
  s32 *slot;
  s16 new_var3;
  s32 frame;
  s32 idx;
  new_var4 = a;
  func_80087114();
  phys = osVirtualToPhysical(a->x0);
  if (b != NULL)
  {
    new_var3 = b->size;
    func_8008A6D0(b->data, 2 * (2 * new_var3));
  }
  count = (s16) (((D_800A73E0[0x4570 / 4] - (func_8008A590() >> 2)) + 0x100) & 0xFFF0);
  a->size = count;
  new_var2 = &D_800A73E0[0x4574 / 4];
  if (((u32) count) < ((u32) (*new_var2)))
  {
    a->size = (s16) (*new_var2);
  }
  slot = &D_800AE850[(0x2278 / 4) + D_800A1BAC % 3];
  wrote = alAudioFrame(*slot, samples, phys, a->size);
  if (samples[0] == 0)
  {
    return 0;
  }
  {
    a->p4C = ((u8 *) a) + 0x58;
    a->n50 = 4;
    a->n52 = 0;
    slot = getSlot();
    a->x38 = *slot;
    frame = *slot;
    new_var5 = (u8 *) (&D_80001D10);
    a->x8 = 2;
    a->x14 = (s32) (((u8 *) (&D_80001DE0)) - new_var5);
    new_var4->x18 = (s32) (new_var5 + 0xd0);
    a->x20 = (s32) (&D_8009AAB0);
    a->x10 = (s32) (&D_80001D10);
    a->xC = 0;
    a->x24 = 0x800;
    a->x28 = 0;
    a->x2C = 0;
    a->x30 = 0;
    a->x34 = 0;
    a->x40 = 0;
    a->x44 = 0;
    a->x3C = ((wrote - frame) >> 3) << 3;
    func_8007F6E0(*(s32 *)0x800C8320);
    osSetThreadPri(D_800AE850[0x2290 / 4], 6);
    func_8007F798(0x26, 0, ((u8 *) a) + 8);
    D_800A1BAC++;
    return 1;
  }
  return 0;
}

