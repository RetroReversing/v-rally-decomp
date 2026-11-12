typedef struct RObj { char pad0[4]; struct RObj *next; char pad8[0x14 - 8]; s32 flags; char pad18[0x48 - 0x18]; s32 *pos; char pad4C[0x6C - 0x4C]; struct { s32 *times; s32 pad; s32 place; } *res; } RObj;
typedef struct REntry { char name[4]; s32 total; s32 diff; s32 rate; u8 pos; u8 idx; u8 b; u8 pad; RObj *obj; } REntry;
typedef struct RPlayer { char name[4]; s32 time; s32 pad; s32 c; char pad2[2]; u8 d; } RPlayer;
typedef struct RName { char name[10]; u16 v; char pad[0x28 - 12]; } RName;
typedef struct RCfg { char pad0[0xE]; u16 mode; char pad10[7]; u8 c17; char pad18[6]; u16 cls; char pad20[2]; u16 sel; char pad24[0x32 - 0x24]; u8 order[0x12]; RName names[4]; } RCfg;
typedef struct RRec { s32 time; u8 c4; u8 pad5; char name[4]; u8 cA; char padB[0x40 - 0xB]; } RRec;
typedef struct RData { char pad0[0x2C]; RRec recs[8]; s32 vals[8]; } RData;

extern RData *func_80041564(void);
extern void func_80045404(s32, RData *, s32, REntry *, s32, s32);
extern void strCpy(char *, char *);
extern s32 gRecordTimeScale;
extern u8 gCurCount;
extern s32 D_800B55FC[][8];
extern s32 D_800B560C[][8];
extern RObj **gCarList;
extern RCfg *gRecords;
extern REntry gResultsTable[4];
extern RPlayer D_800C7FF0;
s32 abs(s32);

/* Fills gResultsTable for the finished race, one entry per car in finish
 * order: total and rate from the lap times, the car's name, and the diff to
 * the leader. Also adds the class totals and the bonus for a tied last place,
 * and copies the local player's record into D_800C7FF0. */
void func_80073708(void) {
    RData *race_data;
    RObj *car_obj;
    u8 i;
    u8 j;
    s32 *time_p;
    s32 total;
    s32 place;
    RCfg *cfg;
    s32 n;
    u8 k;
    s32 pick_val;
    s32 *tb;

    race_data = func_80041564();
    car_obj = *gCarList;
    i = 0;
    while (car_obj != NULL) {
        tb = D_800B55FC[0];
        j = 0;
        total = 0;
        n = gCurCount - 1;
        time_p = car_obj->res->times + 1;
        while (j < n) {
            j++;
            total += *time_p++;
        }
        place = car_obj->res->place - 1;
        cfg = gRecords;
        gResultsTable[(u8)place].obj = car_obj;
        strCpy(gResultsTable[(u8)place].name, cfg->names[cfg->order[i]].name);
        pick_val = gRecords->names[gRecords->order[i]].v;
        gResultsTable[(u8)place].idx = i;
        gResultsTable[(u8)place].total = total;
        gResultsTable[(u8)place].b = pick_val;
        if (total != 0) {
            gResultsTable[(u8)place].rate = (u32)(race_data->vals[gRecords->sel] * gRecordTimeScale * 3600) / (u32)(total * 1000); } else {
            gResultsTable[(u8)place].rate = 0;
        }
        {
        RCfg *c2 = gRecords;
        if (c2->cls != 5) {
            *(s32 *)((u8 *)(tb + c2->cls) + (i << 5)) += total;
            if (total != 0) {
                s32 *tb2 = tb + 4;
                *(s32 *)((u8 *)(tb2 + c2->cls) + (i << 5)) += race_data->vals[c2->sel];
            }
        }
        }
        gResultsTable[(u8)place].pos = *car_obj->pos;
        if (gResultsTable[(u8)place].pos < 4 && gResultsTable[(u8)place].total != 0 && !(car_obj->flags & 0x200)) {
            func_80045404(total, race_data, gResultsTable[(u8)place].b, &gResultsTable[(u8)place], gRecords->c17, gResultsTable[(u8)place].rate);
        }
        car_obj = car_obj->next;
        i++;
    }
    for (k = 0; k < 4; k++) {
        if (gResultsTable[k].total != 0) {
            gResultsTable[k].diff = abs(gResultsTable[k].total - gResultsTable[0].total); } else {
            gResultsTable[k].diff = 0;
        }
    }
    if (gRecords->mode == 2 && (u32)gResultsTable[3].total < (u32)gResultsTable[2].total) {
        if (gRecords->cls != 5) {
            s32 *tb3 = D_800B55FC[0];
            *(s32 *)((u8 *)(tb3 + gRecords->cls) + (gResultsTable[3].idx << 5)) += 15000;
            gResultsTable[3].total = 0;
            gResultsTable[3].rate = 0;
            gResultsTable[3].diff = 0;
        }
    }
    strCpy(D_800C7FF0.name, race_data->recs[gRecords->sel].name);
    D_800C7FF0.time = race_data->recs[gRecords->sel].time;
    D_800C7FF0.c = race_data->recs[gRecords->sel].cA;
    D_800C7FF0.d = race_data->recs[gRecords->sel].c4;
}
