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
extern u8 D_800ADFE0;
extern u16 D_800ADFE4;
extern Cfg80020428 *D_800C35A0;
extern s32 D_8009D534;
Res80020428 *func_80041564(void);
s32 *func_8007EAA0(s32, s32);
void func_80020428(Obj80020428 *arg0)
{
  Res80020428 *res;
  s32 *a;
  s32 *b;
  s32 n;
  u32 i;
  res = func_80041564();
  if (D_800C35A0->f1E != 0)
    arg0->f40->f0 = func_8007EAA0(1, (D_800ADFE0 + 1) * 4);
  else
    arg0->f40->f0 = func_8007EAA0(1, 0x10);
  switch (D_800C35A0->mode)
  {
  case 1:
    arg0->f40->f24 = func_8007EAA0(1, 0x1C);
    arg0->f40->f28 = func_8007EAA0(1, 0x1C);
    break;
  case 2:
    arg0->f40->f24 = func_8007EAA0(1, 0x10);
    arg0->f40->f28 = func_8007EAA0(1, 0x10);
    break;
  case 3:
  case 4:
    arg0->f40->f24 = func_8007EAA0(1, 4);
    arg0->f40->f28 = func_8007EAA0(1, 4);
    break;
  }
  arg0->f40->f2C = 0;
  arg0->f40->f14 = res;
  arg0->f40->f4 = 0;
  arg0->f40->f8 = 1;
  arg0->f40->fC = 0;
  arg0->f40->f10 = D_800ADFE4;
  arg0->f40->f20 = 0;
  if (res->f12 == 0)
    arg0->f40->f18 = func_8007EAA0(1, 4);
  else
    arg0->f40->f18 = func_8007EAA0(1, res->f12 * 4);
  a = arg0->f40->f24;
  b = arg0->f40->f28;
  n = 0;
  switch (D_800C35A0->mode)
  {
  case 1:
    n = 6;
    break;
  case 2:
    n = 3;
    break;
  case 3:
  case 4:
    n = 1;
    break;
  }
  while (n--)
  {
    *a++ = D_8009D534;
    *b++ = 0;
  }
  a = arg0->f40->f0;
  if (D_800C35A0->f1E != 0)
  {
    u8 *bp = &D_800ADFE0;
    for (n = 0; n < (u32)(*bp + 1); n++)
      *a++ = 0;
  }
  else
  {
    for (n = 0; n < 4U; n++)
      *a++ = 0;
  }
}
