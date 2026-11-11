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
extern void track_sample_lookup(Node *, s32, s32 *);
extern s32 gSnapIndex;
extern MinT D_8009EB90[];
extern Pct D_8009F510[];
extern Cfg *gRecords;

/* Fills the per-car position report: current checkpoint node and index, the target
 * time (scaled by the difficulty percentage when flag is 0, clamped to the table minimum),
 * the distance to that checkpoint, the rate of gain, and how many nodes behind the
 * leader are flagged. */
void func_800344F0(Out *out, Car *car) {
    s32 pos[3];
    Node *first;
    s32 flag;
    s32 count;
    s32 idx;
    Node *cur;
    s32 now;
    Node *node;
    s32 steps;
    s32 t;
    s32 dist_units;

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
        out->time = t - t * D_8009F510[gRecords->sel].pct / 100;
    }
    if (out->time < D_8009EB90[gSnapIndex].min) {
        out->time = D_8009EB90[gSnapIndex].min;
    }
    out->dist = 0;
    node = first;
    steps = 0;
    while (node != cur) {
        if (node->next == NULL) break;
        node = node->next;
        steps++;
    }
    if (steps < 4) {
        track_sample_lookup(cur, idx, pos);
        pos[0] -= car->pos->x;
        pos[2] -= car->pos->z;
        func_8002E778(pos, pos);
        out->dist = func_8002D2A0(pos[0] + pos[2]);
    } else {
        out->dist = 65000;
    }
    steps = now - out->time;
    dist_units = out->dist / 128;
    dist_units += !dist_units;
    out->rate = steps / dist_units;
    node = first;
    steps = 0;
    while (node != cur) {
        if (!(node->flags & 0x800)) break;
        node = node->next;
        steps++;
    }
    out->cnt = steps;
}
