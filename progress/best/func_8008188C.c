extern void *D_800B7334;
extern s32 D_800B7320;
extern s32 D_800B731C;
extern s32 D_800B0BA8;
extern s32 D_800B7300;
extern s32 D_800B7308;
typedef struct VRTransferArgs
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
} VRTransferArgs;
extern VRTransferArgs D_800B0BAC;
s32 func_80081040(s32, s32, s32, s32, VRTransferArgs);
void *func_800817A0(s32, s32);
void func_80081C30(void);
void func_80081D50(s32);
typedef struct VRLoadState
{
  s32 x0;
  s32 x4;
  s32 x8;
  u8 padC[0x10];
  s32 x1C;
  u8 pad20[0x10];
  u16 x30;
  u16 x32;
  s32 x34;
  s32 x38;
  u8 pad3C[0x24];
  s32 x60;
} VRLoadState;
extern VRLoadState D_800C3338[];
typedef struct VREntry
{
  u8 pad0[0x10];
  s32 x10;
  s32 x14;
  u16 x18;
  u16 x1A;
  s32 x1C;
  s32 x20;
  s32 x24;
  s32 x28;
} VREntry;
static __inline__ VRLoadState *getState(void *q)
{
  VRLoadState *p;
  int k = 0;
  if (q)
    p = D_800C3338;
  else
    p = D_800C3338 + k;
  return p;
}
s32 func_8008188C(s32 arg0, s32 arg1)
{
  VREntry *e;
  VRLoadState *s;
  e = func_800817A0(D_800B7308, arg0);
 do { func_80081040(D_800B7300 + e->x1C, (s = getState(e))->x0, 0x2000, D_800B0BA8, D_800B0BAC); s->x38 = e->x10; s->x34 = e->x14; s->x32 = e->x1A; s->x30 = e->x18; s->x4 = e->x28; s->x8 = e->x24; D_800B731C = e->x14; ((s32 *) D_800B7334)[0] = e->x20; ((s32 *) D_800B7334)[1] = e->x14; D_800B7320 = e->x10; } while (0);
  s->x1C = e->x1C;
  func_80081D50(arg1);
  func_80081C30();
  return s->x60;
}
