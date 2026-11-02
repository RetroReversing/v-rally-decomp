#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct {
    s16 x, y, z;
    s16 px, py, pz;
    u8 decay;
    u8 pad[7];
} Particle;

typedef struct {
    f32 x, y, z;
} Pos12;

typedef struct {
    u8 pad0[8];
    s32 count;
    u8 pad1[0xC];
    Pos12 pos[1];
} SmokeTable;

typedef struct {
    u8 pad[0xD8];
    f32 vx;
    f32 pad2;
    f32 vz;
    u8 pad3[0x34];
    f32 x;
    f32 y;
    f32 z;
} Car;

extern s32 func_8002D2C8(s32, s32);
extern void func_8002E148(s16 *, s32 *);
extern void func_8002E514(s32 *, s16 *, Particle *);
extern s32 func_80098090(void);
extern SmokeTable *D_800C811C;
extern Car *D_800C7F84;

void func_8003647C(Particle *p, u8 idx)
{
s32 __repair_call_arithmetic;
    s16 vec[4];
    s16 rot[4];
    s32 mtx[8];
    f32 dx, dz;
    s32 angle;
    s32 n;
    s32 r;

    dx = (s16)(s32)(D_800C811C->pos[idx].x - D_800C7F84->x);
    dz = (s16)(s32)(D_800C811C->pos[idx].z - D_800C7F84->z);
    if (abs((s32)dx) > 1000 || abs((s32)dz) > 1000) {
        dx = dz = 0.0f;
    }
    dx += 4.0f;
    dz += 2.0f;
    angle = -func_8002D2C8((s32)(D_800C7F84->vz * 4096.0f), (s32)(D_800C7F84->vx * -4096.0f));
    rot[0] = 0;
    rot[2] = 0;
    vec[2] = 0;
    n = D_800C811C->count;
    while (n-- != 0) {
        if (p->y == 1001) {
            vec[0] = func_80098090() % 4095 + 0x200;
            vec[1] = -(func_80098090() % 511);
__repair_call_arithmetic = angle - 0x200;

            rot[1] = __repair_call_arithmetic + func_80098090() % 1023;
            func_8002E148(rot, mtx);
            func_8002E514(mtx, vec, p);
        }
        p->px = p->x;
        p->pz = p->z;
        p->x = p->x + dx;
        p->y += 0x41;
        p->z = p->z + dz;
        p->py = p->y - p->decay;
        p++;
    }
}

