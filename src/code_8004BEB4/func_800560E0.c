#include "snapshot29_0433f7af8f6d.h"

typedef struct 
{
  s32 a;
  s16 b;
  s16 c;
  s32 d;
  s32 e[4];
} FuncBlk;
typedef struct 
{
  u8 pad[0x64];
  u16 count;
  u8 pad2[2];
  u8 *records;
} FuncArg0;
extern u8 D_800A1310[];
extern s32 func_8007EAA0(s32, s32);
extern void func_80056FE4(s32 *);
extern void func_80056AB8(s32, s32 *, s32);
extern void *func_80006008(s32);
extern void func_80006014(s32, void *);
extern void func_8007EE9C(s32);
void func_800560E0(FuncArg0 *arg0, s32 arg1)
{
  FuncBlk blk;
  u32 *p;
  s32 sum = 0;
  s32 i = 0;
  s32 count = arg0->count;
  u8 *rec = arg0->records;
  if (count)
  {
    do
    {
      sum += *((u16 *) (rec + 4));
      i++;
      rec += 8;
    }
    while (i < count);
  }
  i = func_8007EAA0(1, sum * 0x22);
  blk.a = i;
  blk.b = sum;
  blk.c = 0;
  rec = arg0->records;
  i = 0;
  blk.d = blk.a;
  if (count)
  {
    do
    {
      ((void (*)(s32 *, u8 *)) (*((s32 *) (D_800A1310 + ((*((u16 *) (rec + 6))) << 2)))))(&blk.d, rec);
      rec += 8;
      i++;
    }
    while (i < count);
  }
  func_80056FE4(&blk.a);
  func_80056AB8(arg1, &blk.a, *((s32 *) (((u8 *) arg0) + 0x50)));
  if (arg0->records && arg0->records)
  {
  }
  p = func_80006008(arg1);
  p[0] = 0xDF000000;
  p[1] = 0;
  func_80006014(arg1, p + 2);
  func_8007EE9C(blk.a);
}
