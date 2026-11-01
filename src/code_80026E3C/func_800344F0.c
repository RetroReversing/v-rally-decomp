#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct NInfo { char pad0[0x18]; u16 time; u8 idx; } NInfo;
typedef struct Node { char pad0[0xA]; u16 flags; char pad1[0x58 - 0xC]; struct Node *last; struct Node *next; char pad2[0x78 - 0x60]; NInfo *info; } Node;
typedef struct CState { char pad0[0x2C]; s32 count; char pad1[0x150 - 0x30]; Node *cur; s32 idx; char pad2[0x170 - 0x158]; s32 flag; } CState;
typedef struct CTrack { char pad0[0x2C]; Node *first; } CTrack;
typedef struct CPos { char pad0[0x2CC]; s32 x; s32 y; s32 z; } CPos;
typedef struct Car { char pad0[0x60]; CState *state; char pad1[0x80 - 0x64]; CPos *pos; char pad2[0x8C - 0x84]; CTrack *track; } Car;
typedef struct Out { Node *first; Node *cur; s32 idx; s32 count; u32 time; s32 dist; s32 cnt; s32 rate; } Out;
typedef struct Pct { s32 pct; char pad[0x2C]; } Pct;
typedef struct MinT { u32 min; char pad[0x14]; } MinT;
typedef struct Cfg { char pad0[0x16]; u16 sel; } Cfg;

extern s32 func_8001FEDC(Car *);
extern s32 func_8002D2A0(s32);
extern void func_8002E778(s32 *, s32 *);
extern void func_800306A8(Node *, s32, s32 *);
extern s32 D_8009EB80;
extern MinT D_8009EB90[];
extern Pct D_8009F510[];
extern Cfg *D_800C35A0;

void func_800344F0(Out *out, Car *car) {
    s32 v[3];
    Node *first;
    s32 flag;
    s32 count;
    s32 idx;
    Node *cur;
    s32 now;
    Node *n;
    s32 i;
    s32 t;
    s32 d;

    first = car->track->first;
    flag = car->state->flag;
    count = car->state->count;
    out->first = first;
    out->count = count;
    idx = car->state->idx;
    cur = car->state->cur;
    now = func_8001FEDC(car);
    if (cur == first->last || ((cur == first) & (idx < count))) {
        if (cur->next != NULL) {
            cur = cur->next;
            while (cur->info->time == 12000) {
                cur = cur->next;
            }
        }
        idx = cur->info->idx;
        car->state->idx = idx;
        car->state->cur = cur;
    }
    out->cur = cur;
    out->idx = idx;
    t = cur->info->time;
    out->time = t;
    if (flag == 0) {
        out->time = t - t * D_8009F510[D_800C35A0->sel].pct / 100;
    }
    if (out->time < D_8009EB90[D_8009EB80].min) {
        out->time = D_8009EB90[D_8009EB80].min;
    }
    out->dist = 0;
    n = first;
    i = 0;
    while (n != cur) {
        if (n->next == NULL) break;
        n = n->next;
        i++;
    }
    if (i < 4) {
        func_800306A8(cur, idx, v);
        v[0] -= car->pos->x;
        v[2] -= car->pos->z;
        func_8002E778(v, v);
        out->dist = func_8002D2A0(v[0] + v[2]);
    } else {
        out->dist = 65000;
    }
    i = now - out->time;
    d = out->dist / 128;
    d += !d;
    out->rate = i / d;
    n = first;
    i = 0;
    while (n != cur) {
        if (!(n->flags & 0x800)) break;
        n = n->next;
        i++;
    }
    out->cnt = i;
}

