/* Object state: buffer pointers f0, f18, f24, f28 and the per-object counters. */
typedef struct Sub80020428
{
  s32 *f0;
  s32 f4;
  s32 f8;
  s32 fC;
  s32 f10;
  void *f14;
  s32 *f18;
  s32 f1C;
  s32 f20;
  s32 *f24;
  s32 *f28;
  s32 f2C;
} Sub80020428;
typedef struct Obj80020428
{
  u8 pad[0x40];
  Sub80020428 *f40;
} Obj80020428;
typedef struct Cfg80020428
{
  u8 pad[0xE];
  u16 mode;
  u8 pad10[0xE];
  u16 f1E;
} Cfg80020428;
typedef struct Res80020428
{
  u8 pad[0x12];
  u16 f12;
} Res80020428;
extern u8 gCurCount;
extern u16 D_800ADFE4;
extern Cfg80020428 *gRecords;
extern s32 D_8009D534;
Res80020428 *func_80041564(void);
s32 *poolAlloc(s32, s32);

/* Sets up obj's state: allocates the buffers (sized from gRecords' mode and flags) and
 * zeroes the counters, then fills the first buffer and the mode-sized pair with defaults. */
void init_obj_state(Obj80020428 *obj)
{
  Res80020428 *res;
  s32 *pa;
  s32 *pb;
  s32 count;
  u32 i;
  res = func_80041564();
  if (gRecords->f1E != 0)
    obj->f40->f0 = poolAlloc(1, (gCurCount + 1) * 4);
  else
    obj->f40->f0 = poolAlloc(1, 0x10);
  switch (gRecords->mode)
  {
  case 1:
    obj->f40->f24 = poolAlloc(1, 0x1C);
    obj->f40->f28 = poolAlloc(1, 0x1C);
    break;
  case 2:
    obj->f40->f24 = poolAlloc(1, 0x10);
    obj->f40->f28 = poolAlloc(1, 0x10);
    break;
  case 3:
  case 4:
    obj->f40->f24 = poolAlloc(1, 4);
    obj->f40->f28 = poolAlloc(1, 4);
    break;
  }
  obj->f40->f2C = 0;
  obj->f40->f14 = res;
  obj->f40->f4 = 0;
  obj->f40->f8 = 1;
  obj->f40->fC = 0;
  obj->f40->f10 = D_800ADFE4;
  obj->f40->f20 = 0;
  if (res->f12 == 0)
    obj->f40->f18 = poolAlloc(1, 4);
  else
    obj->f40->f18 = poolAlloc(1, res->f12 * 4);
  pa = obj->f40->f24;
  pb = obj->f40->f28;
  count = 0;
  switch (gRecords->mode)
  {
  case 1:
    count = 6;
    break;
  case 2:
    count = 3;
    break;
  case 3:
  case 4:
    count = 1;
    break;
  }
  while (count--)
  {
    *pa++ = D_8009D534;
    *pb++ = 0;
  }
  pa = obj->f40->f0;
  if (gRecords->f1E != 0)
  {
    u8 *bp = &gCurCount;
    for (count = 0; count < (u32)(*bp + 1); count++)
      *pa++ = 0;
  }
  else
  {
    for (count = 0; count < 4U; count++)
      *pa++ = 0;
  }
}
