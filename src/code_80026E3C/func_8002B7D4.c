#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
static __inline__ s32 __repair_inline(s32 a) { return a; }
typedef struct { s32 x, y, z, w; } V4;
typedef struct { s16 x, y, z; } P3;
typedef struct {
    u8 pad0[0x24];
    s32 x;
    s32 y;
    s32 z;
    u8 pad30[0x4C - 0x30];
    s32 base;
    u8 pad50[4];
    P3 *pts;
    u8 pad58[0x8A - 0x58];
    u16 n;
} Track;
extern void func_8002D6E0(V4 *, V4 *);

void func_8002B7D4(u8 *arg0)
{
    V4 pos;
    V4 dir;
    V4 rel;
    Track *t;
    u8 *p58;
    s32 idx;
    s32 a;
    s32 b;
    s32 s;
    s32 d;

    t = **(Track ***)(arg0 + 0x8C);
    p58 = *(u8 **)(arg0 + 0x58);
    idx = __repair_inline(**(s32 **)(arg0 + 0x60));
    idx = idx * t->n + t->base;
    pos.x = *(s32 *)(p58 + 0xC);
    pos.z = *(s32 *)(*(u8 **)(arg0 + 0x58) + 0x14);
    pos.x -= t->x;
    pos.z -= t->z;
    b = idx - 2;
    a = idx + 2;
    dir.x = t->pts[a].x - t->pts[b].x;
    dir.z = t->pts[a].z - t->pts[b].z;
    rel.x = pos.x - t->pts[b].x;
    rel.z = pos.z - t->pts[b].z;
    s = dir.x * rel.x + dir.z * rel.z;
    func_8002D6E0(&dir, &dir);
    d = dir.x + dir.z;
    s = s * 100 / d;
    *(s32 *)(*(u8 **)(arg0 + 0x60) + 0x17C) = s;
}

