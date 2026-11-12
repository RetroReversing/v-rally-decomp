typedef struct RRec { s32 time; u8 c4; u8 pad5; char name[4]; u8 cA; char padB[0x40 - 0xB]; } RRec;
typedef struct RData { char pad0[0x2C]; RRec recs[8]; s32 vals[8]; } RData;
typedef struct RRes { char pad0[0x14]; RData *data; char pad18[0x24 - 0x18]; s32 *times; s32 *vals; } RRes;
typedef struct RCar { char pad0[4]; struct RCar *next; char pad8[0x6C - 8]; RRes *res; } RCar;
typedef struct REntry { char name[4]; s32 total; s32 diff; s32 rate; u8 pos; u8 idx; u8 b; u8 pad; RCar *obj; } REntry;
typedef struct RName { char name[10]; u16 v; char pad[0x28 - 12]; } RName;
typedef struct RCfg { char pad0[0xE]; u16 mode; char pad10[0x1A - 0x10]; u16 flag1A; char pad1C[0x22 - 0x1C]; u16 sel; char pad24[0x32 - 0x24]; u8 order[0x12]; RName names[4]; } RCfg;

extern void func_80041564(void);
extern void strCpy(char *, char *);
extern RCar **gCarList;
extern RCfg *gRecords;
extern REntry gResultsTable[7];
s32 abs(s32);

/* Fills the race results table (gResultsTable) for the current car's result
 * screen. Mode 1 lists six rows from the car's times/rates; mode 2 lists three
 * rows from this car and three from the next car; the final entry is the
 * player's own record. A time of 15000 means "no time" and is zeroed. */
void results_table_fill(void) {
    RCar *car;
    s32 *times;
    s32 *vals;
    RData *data;
    u8 i;
    u32 n;

    car = *gCarList;
    func_80041564();
    switch (gRecords->mode) {
    case 1:
        i = 0;
        times = car->res->times;
        vals = car->res->vals;
        do {
            gResultsTable[i].obj = car;
            strCpy(gResultsTable[i].name, gRecords->names[gRecords->order[0]].name);
            gResultsTable[i].rate = vals[i];
            gResultsTable[i].total = times[i];
            gResultsTable[i].b = gRecords->names[gRecords->order[0]].v;
            data = car->res->data;
            gResultsTable[i].diff = abs(gResultsTable[i].total - data->recs[gRecords->sel].time);
            if (gResultsTable[i].total == 15000) {
                gResultsTable[i].total = 0;
                gResultsTable[i].rate = 0;
                gResultsTable[i].diff = 0;
            }
            i++;
        } while ((n = i) < 6);
        break;
    case 2:
        i = 0;
        times = car->res->times;
        vals = car->res->vals;
        do {
            gResultsTable[i].obj = car;
            strCpy(gResultsTable[i].name, gRecords->names[gRecords->order[0]].name);
            gResultsTable[i].rate = vals[i];
            gResultsTable[i].total = times[i];
            gResultsTable[i].b = gRecords->names[gRecords->order[0]].v;
            data = car->res->data;
            gResultsTable[i].diff = abs(gResultsTable[i].total - data->recs[gRecords->sel].time);
            gResultsTable[4].b = data->recs[gRecords->sel].c4;
            if (gResultsTable[i].total == 15000) {
                gResultsTable[i].total = 0;
                gResultsTable[i].rate = 0;
                gResultsTable[i].diff = 0;
            }
            i++;
        } while (i < 3);
        if (gRecords->flag1A) car = car->next;
        car = car->next;
        i = 3;
        times = car->res->times;
        vals = car->res->vals;
        do {
            gResultsTable[i].obj = car;
            strCpy(gResultsTable[i].name, gRecords->names[gRecords->order[1]].name);
            gResultsTable[i].rate = vals[i - 3];
            gResultsTable[i].total = times[i - 3];
            gResultsTable[i].b = gRecords->names[gRecords->order[1]].v;
            data = car->res->data;
            gResultsTable[i].diff = abs(gResultsTable[i].total - data->recs[gRecords->sel].time);
            if (gResultsTable[i].total == 15000) {
                gResultsTable[i].total = 0;
                gResultsTable[i].rate = 0;
                gResultsTable[i].diff = 0;
            }
            i++;
        } while ((n = i) < 6);
        break;
    default:
        return;
    }
    strCpy(gResultsTable[n].name, data->recs[gRecords->sel].name);
    gResultsTable[n].obj = car;
    gResultsTable[n].total = data->recs[gRecords->sel].time;
    gResultsTable[n].rate = data->recs[gRecords->sel].cA;
    gResultsTable[n].b = data->recs[gRecords->sel].c4;
}
