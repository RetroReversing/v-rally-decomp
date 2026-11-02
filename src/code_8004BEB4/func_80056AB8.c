#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 w[4]; s16 h; } Elem6;
typedef struct { u32 a:1; u32 b:4; u32 c:1; u32 rest:26; } Flags56;
typedef struct { u8 pad[0x84]; Flags56 f; } Obj56;
typedef struct { u8 *items; u16 count; } List56;
void func_80009C90(Obj56 *, s32);
void func_800566B4(void *arg0, u8 *arg1, Elem6 *arg2);
void func_80056884(void *arg0, u8 *arg1, Elem6 *arg2);
void func_80056AB8(Obj56 *arg0, List56 *arg1, Elem6 *arg2)
{
  u8 *p;
  s32 i;
  s32 n;
  p = arg1->items;
  n = arg1->count;
  arg0->f.b = 1;
  *(u32 *)&arg0->f = (*(u32 *)&arg0->f & 0xFBFFFFFF) | 0x04000000;
  func_80009C90(arg0, 1);
  for (i = 0; i < n; i++)
  {
    switch (p[3])
    {
      case 6:
        func_800566B4(arg0, p, arg2);
        break;
      case 10:
        func_80056884(arg0, p, arg2);
        break;
    }
    p += 0x22;
  }
}
