#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct {
    u16 type;
    u8 status;
    u8 errno;
} ContStat;

typedef struct {
    s32 port;
    s32 state;
    volatile s32 unk8;
    u8 pad[0xC];
} RmbState;

typedef struct {
    s32 unk0;
    s32 count;
    u8 pad8[4];
    ContStat stat[4];
    u8 pad1C[0x170];
    u8 pfs[4][0x68];
    RmbState rmb[4];
    RmbState *list[4];
} PakCtx;

extern PakCtx *D_800A1B70;
extern u8 D_800AE850[];
void func_800863B0(s32 arg0, s32 arg1);
s32 osPfsIsPlug(void *queue, u8 *pattern);
s32 osMotorInit(void *queue, void *pfs, s32 channel);
s32 osPfsInitPak(void *queue, void *pfs, s32 channel);

void func_80086138(s32 port, u8 mask) {
    u8 pattern = 0;
    PakCtx *c = D_800A1B70;
    void *queue;

    c->rmb[port].state = 0;
    if (!((mask >> port) & 1))
        return;
    c->list[c->count] = &c->rmb[port];
    c->rmb[port].port = port;
    if (!(c->stat[port].type & 4))
        return;
    if (!(c->stat[port].status & 1))
        return;
    queue = D_800AE850 + 0x5A38;
    osPfsIsPlug(queue, &pattern);
    if (!((pattern >> port) & 1))
        return;
    if (osMotorInit(queue, D_800A1B70->pfs[port], port) == 0) {
        func_800863B0(port, 0);
        D_800A1B70->rmb[port].state = 1;
        D_800A1B70->rmb[port].unk8 = 0;
        return;
    }
    if (osPfsInitPak(queue, D_800A1B70->pfs[port], port) == 0) {
        D_800A1B70->rmb[port].state = 2;
        return;
    }
    D_800A1B70->rmb[port].state = 3;
}

