typedef struct RObj { char pad0[4]; struct RObj *next; char pad8[0x14 - 8]; s32 flags; char pad18[0x48 - 0x18]; s32 *pos; char pad4C[0x6C - 0x4C]; struct { s32 *times; s32 pad; s32 place; } *res; } RObj;
typedef struct REntry { char name[4]; s32 total; s32 diff; s32 rate; u8 pos; u8 idx; u8 b; u8 pad; RObj *obj; } REntry;
typedef struct RPlayer { char name[4]; s32 time; s32 pad; s32 c; char pad2[2]; u8 d; } RPlayer;
typedef struct RName { char name[10]; u16 v; char pad[0x28 - 12]; } RName;
typedef struct RCfg { char pad0[0xE]; u16 mode; char pad10[7]; u8 c17; char pad18[6]; u16 cls; char pad20[2]; u16 sel; char pad24[0x32 - 0x24]; u8 order[0x12]; RName names[4]; } RCfg;
typedef struct RRec { s32 time; u8 c4; u8 pad5; char name[4]; u8 cA; char padB[0x40 - 0xB]; } RRec;
typedef struct RData { char pad0[0x2C]; RRec recs[8]; s32 vals[8]; } RData;

extern RData *func_80041564(void);
extern void func_80045404(s32, RData *, s32, REntry *, s32, s32);
extern void func_80098290(char *, char *);
extern s32 D_8009D540;
extern u8 D_800ADFE0;
extern s32 D_800B55FC[][8];
extern s32 D_800B560C[][8];
extern RObj **D_800B5C40;
extern RCfg *D_800C35A0;
extern REntry D_800C7F90[4];
extern RPlayer D_800C7FF0;

void func_80073708(void) {
    RData *data;
    RObj *obj;
    u8 i;
    u8 j;
    s32 *p;
    s32 sum;
    s32 place;
    RCfg *cfg;
    s32 n;
    u8 k;
    s32 d;

    data = func_80041564();
    obj = *D_800B5C40;
    i = 0;
    while (obj != NULL) {
        j = 0;
        sum = 0;
        n = D_800ADFE0 - 1;
        p = obj->res->times + 1;
        while (j < n) {
            j++;
            sum += *p++;
        }
        place = obj->res->place - 1;
        cfg = D_800C35A0;
        D_800C7F90[(u8)place].obj = obj;
        func_80098290(D_800C7F90[(u8)place].name, cfg->names[cfg->order[i]].name);
        d = D_800C35A0->names[D_800C35A0->order[i]].v;
        D_800C7F90[(u8)place].idx = i;
        D_800C7F90[(u8)place].total = sum;
        D_800C7F90[(u8)place].b = d;
        if (sum != 0) {
            D_800C7F90[(u8)place].rate = (u32)(data->vals[D_800C35A0->sel] * D_8009D540 * 3600) / (u32)(sum * 1000); } else {
            D_800C7F90[(u8)place].rate = 0;
        }
        cfg = D_800C35A0;
        if (cfg->cls != 5) {
            *(s32 *)((u8 *)&D_800B55FC[0][cfg->cls] + (i << 5)) += sum;
            if (sum != 0) {
                *(s32 *)((u8 *)&D_800B55FC[0][cfg->cls + 4] + (i << 5)) += data->vals[cfg->sel];
            }
        }
        D_800C7F90[(u8)place].pos = *obj->pos;
        if (D_800C7F90[(u8)place].pos < 4 && D_800C7F90[(u8)place].total != 0 && !(obj->flags & 0x200)) {
            func_80045404(sum, data, D_800C7F90[(u8)place].b, &D_800C7F90[(u8)place], D_800C35A0->c17, D_800C7F90[(u8)place].rate);
        }
        obj = obj->next;
        i++;
    }
    for (k = 0; k < 4; k++) {
        if (D_800C7F90[k].total != 0) {
            D_800C7F90[k].diff = abs(D_800C7F90[k].total - D_800C7F90[0].total); } else {
            D_800C7F90[k].diff = 0;
        }
    }
    if (D_800C35A0->mode == 2 && (u32)D_800C7F90[3].total < (u32)D_800C7F90[2].total) {
        if (D_800C35A0->cls != 5) {
            *(s32 *)((u8 *)&D_800B55FC[0][D_800C35A0->cls] + (D_800C7F90[3].idx << 5)) += 15000;
            D_800C7F90[3].total = 0;
            D_800C7F90[3].rate = 0;
            D_800C7F90[3].diff = 0;
        }
    }
    func_80098290(D_800C7FF0.name, data->recs[D_800C35A0->sel].name);
    D_800C7FF0.time = data->recs[D_800C35A0->sel].time;
    D_800C7FF0.c = data->recs[D_800C35A0->sel].cA;
    D_800C7FF0.d = data->recs[D_800C35A0->sel].c4;
}
