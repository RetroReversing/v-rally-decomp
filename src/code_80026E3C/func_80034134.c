#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { s16 vx, vy, vz, pad; } SVec;
typedef struct { s32 vx, vy, vz, pad; } LVec;
s32 func_8001FEDC();
s32 func_8002D2A0();
s32 func_8002E778();
extern char D_800AE850[];

typedef struct Car {
    char pad0[4];
    struct Car *next;
    char pad8[0x50];
    char *pos;      /* 0x58 */
    char pad5C[4];
    char *info;     /* 0x60 */
    char pad64[0x1C];
    char *body;     /* 0x80 */
    char pad84[8];
    s32 *team;     /* 0x8C */
} Car;

typedef struct {
    s32 count;
    s32 id[4];
    s32 v14[4];
    s32 v24[4];
    s32 v34[4];
    s32 v44[4];
    s32 v54[4];
    s32 v64[4];
    Car *car[4];
    s32 n84;
    s32 a88[4];
    s32 n98;
    s32 a9C[4];
    s32 aAC[4];
} Out;

#define W(p, o) (*(s32 *)((char *)(p) + (o)))

void func_80034134(Out *out, Car *self)
{
    SVec a, b, c, d;
    LVec v;
    Car *car;
    s32 myRank;
    s32 myVal;
    s32 myTeam;
    s32 i;
    s32 cross1, cross2, dot;

    car = **(Car ***)(D_800AE850 + 0x73F0);
    myRank = W(self->info, 0x17C);
    myVal = W(self->info, 0x14);
    i = 0;
    myTeam = *self->team;
    out->n84 = 0;
    out->n98 = 0;
    out->count = 0;
    while (car != NULL) {
        if (car != self) {
            out->id[i] = *car->team;
            out->v14[i] = W(car->info, 0x14);
            out->v24[i] = W(car->info, 0x28);
            out->v34[i] = W(car->info, 0x30);
            if (out->id[i] == myTeam || out->id[i] == W(myTeam, 0x5C)) {
            a.vx = W(self->body, 0x2B8) - W(self->body, 0x2CC);
            a.vz = W(self->body, 0x2C0) - W(self->body, 0x2D4);
            b.vx = W(self->body, 0x240) - W(self->body, 0x254);
            b.vz = W(self->body, 0x248) - W(self->body, 0x25C);
            c.vx = W(car->body, 0x254) - W(self->body, 0x2CC);
            c.vz = W(car->body, 0x25C) - W(self->body, 0x2D4);
            d.vx = W(car->body, 0x2CC) - W(self->body, 0x254);
            d.vz = W(car->body, 0x2D4) - W(self->body, 0x25C);
            cross1 = a.vx * c.vz - a.vz * c.vx;
            cross2 = b.vx * d.vz - b.vz * d.vx;
            dot = a.vx * c.vx + a.vz * c.vz;
            if (out->v24[i] >= myVal || out->id[i] == W(myTeam, 0x5C)) {
            out->v44[i] = func_8001FEDC(car);
            out->v64[i] = W(car->info, 0x17C);
            out->car[i] = car;
            v.vx = W(self->pos, 0xC) - W(car->pos, 0xC);
            v.vz = W(self->pos, 0x14) - W(car->pos, 0x14);
            func_8002E778(&v, &v);
            out->v54[i] = func_8002D2A0(v.vx + v.vz);
            if (((cross1 < 0) & (cross2 < 0)) && out->v64[i] < myRank + 20 && myRank - 20 < out->v64[i]) {
                out->a88[out->n84] = i;
                out->n84++;
            }
            if (((0 < cross1) & (cross2 < 0)) && out->v64[i] < myRank + 25 && myRank - 25 < out->v64[i]) {
                out->a9C[out->n98] = i;
                if (dot < 0) {
                    out->aAC[out->n98] = 0;
                } else {
                    out->aAC[out->n98] = 1;
                }
                out->n98++;
            }
            i++;
            out->count++;
            }
            }
        }
        car = car->next;
    }
}

