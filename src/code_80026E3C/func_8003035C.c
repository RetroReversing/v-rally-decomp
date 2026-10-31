#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u16 x; u16 y; u16 z; } V303;
typedef struct { s16 x; s16 y; s16 z; s16 pad; } SV303;
typedef struct
{
  u8 pad[0x4C];
  s32 base;
  u32 pad50;
  V303 *table;
  u8 pad58[0x32];
  u16 stride;
} O303;
s32 func_8002D2A0(s32);
s32 func_8003035C(O303 *o, s32 row, V303 *pos)
{
  SV303 a;
  SV303 b;
  SV303 c;
  s32 n;
  s32 d;
  s32 e;
  n = row * o->stride + o->base;
  c.x = o->table[n - 2].x - o->table[n].x;
  c.z = o->table[n - 2].z - o->table[n].z;
  a.x = pos->x - o->table[n].x;
  a.z = pos->z - o->table[n].z;
  if (c.x * a.x + c.z * a.z > 0)
  {
    a.x = o->table[n - 2].x - o->table[n].x;
    a.z = o->table[n - 2].z - o->table[n].z;
    b.x = pos->x - o->table[n].x;
    b.z = pos->z - o->table[n].z;
    d = func_8002D2A0(a.x * a.x + a.z * a.z);
    e = func_8002D2A0(b.x * b.x + b.z * b.z);
    d = e * 1000 / d;
    d = 500 - d / 2;
  }
  else
  {
    a.x = o->table[n + 2].x - o->table[n].x;
    a.z = o->table[n + 2].z - o->table[n].z;
    b.x = pos->x - o->table[n].x;
    b.z = pos->z - o->table[n].z;
    d = func_8002D2A0(a.x * a.x + a.z * a.z);
    e = func_8002D2A0(b.x * b.x + b.z * b.z);
    d = e * 1000 / d;
    d = d / 2 + 500;
  }
  return d;
}
