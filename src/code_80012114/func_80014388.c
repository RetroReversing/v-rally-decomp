#include "common.h"

extern char D_800B5C80[];
extern s32 D_800B681C;
extern u32 D_800B727C;
extern s32 *D_800C7304;
extern s32 D_800C7930;
extern void *D_800C80C8;
extern void *D_800C80CC;
extern void *D_800C8060;
extern void *D_800C8058;
extern void *D_8009BB14;
extern void *D_8009BB18;
extern void *D_8009BB1C;
extern void *D_8009BB24;
u64 osGetTime(void *);
u64 func_8009A2B0(u64, u64);
void func_800141D0(void);
void func_80014288(void);
void func_80014130(void);
void func_80013FD0(void);
void func_80014388(void)
{
  u32 idx;
  u64 ret;
  s32 *rec;
  char *base;
  s32 *new_var;
  void *a2;
  void *a3;
  void *t0;
  void *t1;
  base = D_800B5C80;
  D_800C7930++;
  idx = *((u32 *) 0x800b727c);
  D_800B681C = (s32) ((idx * 0x118) + base);
  D_800B727C = 1;
  D_800B727C = (idx + D_800B727C) & 3;
  rec = (s32 *) (base + (D_800B727C * 0x118));
  D_800C7304 = rec;
  rec[1] = 0;
  rec[0] = 0;
  ret = osGetTime(base);
  ret = func_8009A2B0(ret << 6, 0xBB8);
  new_var = D_800C7304;
  a2 = D_800C80C8;
  a3 = D_800C80CC;
  t0 = D_800C8060;
  t1 = D_800C8058;
  D_800C80C8 = func_800141D0;
  D_800C80CC = func_80014288;
  D_800C8060 = func_80014130;
  D_800C8058 = func_80013FD0;
  *((u64 *) (((char *) new_var) + 8)) = ret;
  D_8009BB14 = a2;
  D_8009BB18 = a3;
  D_8009BB1C = t0;
  D_8009BB24 = t1;
}
