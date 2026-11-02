#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct RRec { s32 time; u8 c4; u8 pad5; char name[4]; u8 cA; char padB[0x40 - 0xB]; } RRec;
typedef struct RData { char pad0[0x2C]; RRec recs[8]; s32 vals[8]; } RData;
typedef struct RRes { char pad0[0x14]; RData *data; char pad18[0x24 - 0x18]; s32 *times; s32 *vals; } RRes;
typedef struct RCar { char pad0[4]; struct RCar *next; char pad8[0x6C - 8]; RRes *res; } RCar;
typedef struct REntry { char name[4]; s32 total; s32 diff; s32 rate; u8 pos; u8 idx; u8 b; u8 pad; RCar *obj; } REntry;
typedef struct RName { char name[10]; u16 v; char pad[0x28 - 12]; } RName;
typedef struct RCfg { char pad0[0xE]; u16 mode; char pad10[0x1A - 0x10]; u16 flag1A; char pad1C[0x22 - 0x1C]; u16 sel; char pad24[0x32 - 0x24]; u8 order[0x12]; RName names[4]; } RCfg;

extern void func_80041564(void);
extern void func_80098290(char *, char *);
extern RCar **D_800B5C40;
extern RCfg *D_800C35A0;
extern REntry D_800C7F90[7];

void func_800746C0(void) {
    RCar *car;
    s32 *times;
    s32 *vals;
    RData *data;
    u8 i;
    u32 n;

    car = *D_800B5C40;
    func_80041564();
    switch (D_800C35A0->mode) {
    case 1:
        i = 0;
        times = car->res->times;
        vals = car->res->vals;
        do {
            D_800C7F90[i].obj = car;
            func_80098290(D_800C7F90[i].name, D_800C35A0->names[D_800C35A0->order[0]].name);
            D_800C7F90[i].rate = vals[i];
            D_800C7F90[i].total = times[i];
            D_800C7F90[i].b = D_800C35A0->names[D_800C35A0->order[0]].v;
            data = car->res->data;
            D_800C7F90[i].diff = abs(D_800C7F90[i].total - data->recs[D_800C35A0->sel].time);
            if (D_800C7F90[i].total == 15000) {
                D_800C7F90[i].total = 0;
                D_800C7F90[i].rate = 0;
                D_800C7F90[i].diff = 0;
            }
            i++;
        } while ((n = i) < 6);
        break;
    case 2:
        i = 0;
        times = car->res->times;
        vals = car->res->vals;
        do {
            D_800C7F90[i].obj = car;
            func_80098290(D_800C7F90[i].name, D_800C35A0->names[D_800C35A0->order[0]].name);
            D_800C7F90[i].rate = vals[i];
            D_800C7F90[i].total = times[i];
            D_800C7F90[i].b = D_800C35A0->names[D_800C35A0->order[0]].v;
            data = car->res->data;
            D_800C7F90[i].diff = abs(D_800C7F90[i].total - data->recs[D_800C35A0->sel].time);
            D_800C7F90[4].b = data->recs[D_800C35A0->sel].c4;
            if (D_800C7F90[i].total == 15000) {
                D_800C7F90[i].total = 0;
                D_800C7F90[i].rate = 0;
                D_800C7F90[i].diff = 0;
            }
            i++;
        } while (i < 3);
        if (D_800C35A0->flag1A) car = car->next;
        car = car->next;
        i = 3;
        times = car->res->times;
        vals = car->res->vals;
        do {
            D_800C7F90[i].obj = car;
            func_80098290(D_800C7F90[i].name, D_800C35A0->names[D_800C35A0->order[1]].name);
            D_800C7F90[i].rate = vals[i - 3];
            D_800C7F90[i].total = times[i - 3];
            D_800C7F90[i].b = D_800C35A0->names[D_800C35A0->order[1]].v;
            data = car->res->data;
            D_800C7F90[i].diff = abs(D_800C7F90[i].total - data->recs[D_800C35A0->sel].time);
            if (D_800C7F90[i].total == 15000) {
                D_800C7F90[i].total = 0;
                D_800C7F90[i].rate = 0;
                D_800C7F90[i].diff = 0;
            }
            i++;
        } while ((n = i) < 6);
        break;
    default:
        return;
    }
    func_80098290(D_800C7F90[n].name, data->recs[D_800C35A0->sel].name);
    D_800C7F90[n].obj = car;
    D_800C7F90[n].total = data->recs[D_800C35A0->sel].time;
    D_800C7F90[n].rate = data->recs[D_800C35A0->sel].cA;
    D_800C7F90[n].b = data->recs[D_800C35A0->sel].c4;
}

