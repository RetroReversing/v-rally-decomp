typedef struct Item {
    s32 w[4];
} Item;
typedef struct Group {
    Item item[4];
} Group;
typedef struct Record {
    s32 w[5];
    u16 count;
    u8 pad16[0x2C - 0x16];
    Group groups[10];
    u8 pad2AC[0x18];
} Record;
typedef struct Slot {
    u8 pad00[0x28];
} Slot;
typedef struct Game {
    u8 pad00[0x1E];
    u16 mode;
    u16 sel;
    u16 sub;
    u8 pad24[0x44 - 0x24];
    Slot slots[4];
} Game;
extern Game *gRecords;
extern Record *gSlotTableB[5];
extern Group g_split_times[12];
extern Group D_800C3650[4];
extern Item D_800C3A50[];
extern s8 D_800A16F0;
extern u8 D_800A57C0[];
extern s32 func_8006F820(void *, s32);
extern void rebuildSplitTimes(void *);
extern long func_8006DDD8(void);
extern void pack_tile_rows(void);
extern void store_split_deltas(void);
extern void update_split_deltas(void);
extern void func_8006CB9C(void);
extern void UpdateChannelDeltas(void);
extern void func_8006F4A8(u8);
extern void func_8006EE3C(u8);
extern void func_8006F0E0(u8);
extern s32 save_race_to_pak(void);
extern s32 text_load_and_parse(u8 *, u8 *);
extern void func_8006F8E0(void);
extern void clearRaceData(void);
extern void func_8005508C(void);

#define GROUP(p, j) ((Group *)((u8 *)(p) + ((j) * 0x40 + 0x2C)))

void func_8006D564(s32 arg0)
{
    Record *r;
    Group *g;
    u8 i;
    u8 j;
    u8 *p;
    u8 k;
    u8 mode;
    u8 sel;
    u8 sub;

    mode = gRecords->mode;
    sel = gRecords->sel;
    sub = gRecords->sub;
    for (i = 0; i < 8; i++) {
        r = &gSlotTableB[0][i];
        for (j = 0; j < r->count; j++) {
            k = 0;
            g = GROUP(r, j);
            for (; k < 3; k++) {
                func_8006F820(&g->item[k], (u8)arg0);
            }
            gRecords->mode = 0;
            gRecords->sel = i;
            gRecords->sub = j;
            func_8006DDD8();
        }
    }
    for (j = 0; j < 4; j++) {
        r = gSlotTableB[1];
        k = 0;
        p = (u8 *)GROUP(r, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], (u8)arg0);
        }
        gRecords->mode = 1;
        gRecords->sel = 0;
        gRecords->sub = j;
        pack_tile_rows();
    }
    for (j = 0; j < 5; j++) {
        r = gSlotTableB[2];
        k = 0;
        p = (u8 *)GROUP(r, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], (u8)arg0);
        }
        gRecords->mode = 2;
        gRecords->sel = 0;
        gRecords->sub = j;
        pack_tile_rows();
    }
    for (j = 0; j < 6; j++) {
        p = (u8 *)gSlotTableB[3];
        k = 0;
        p = (u8 *)GROUP(p, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], (u8)arg0);
        }
        gRecords->mode = 3;
        gRecords->sel = 0;
        gRecords->sub = j;
        pack_tile_rows();
    }
    for (j = 0; j < 3; j++) {
        p = (u8 *)gSlotTableB[4];
        k = 0;
        p = (u8 *)GROUP(p, j);
        for (; k < 3; k++) {
            func_8006F820(&((Group *)p)->item[k], (u8)arg0);
        }
        gRecords->mode = 4;
        gRecords->sel = 0;
        gRecords->sub = j;
        pack_tile_rows();
    }
    for (i = 0; i < 12; i++) {
        for (k = 0; k < 3; k++) {
            func_8006F820(&g_split_times[i].item[k], (u8)arg0);
        }
        gRecords->sel = i;
        store_split_deltas();
    }
    for (i = 0; i < 4; i++) {
        for (k = 0; k < 3; k++) {
            func_8006F820(&D_800C3650[i].item[k], (u8)arg0);
        }
        update_split_deltas();
    }
    for (k = 0; k < 3; k++) {
        func_8006F820(&D_800C3A50[k], (u8)arg0);
        func_8006CB9C();
        func_8006F820(&D_800C3A50[k + 12], (u8)arg0);
        UpdateChannelDeltas();
    }
    gRecords->mode = mode;
    gRecords->sel = sel;
    gRecords->sub = sub;
    func_8006F4A8(arg0);
    func_8006EE3C(arg0);
    gRecords->slots[(u8)arg0].pad00[0] = 0x5B;
    func_8006F0E0(arg0);
    save_race_to_pak();
    D_800A16F0 = j = 0;
    text_load_and_parse(D_800A57C0, 0);
    func_8006F8E0();

    mode = gRecords->mode;
    sel = gRecords->sel;
    sub = gRecords->sub;
    for (i = 0; i < 8; i++) {
        p = (u8 *)&gSlotTableB[0][i];
        for (j = 0; j < ((Record *)p)->count; j++) {
            gRecords->mode = 0;
            gRecords->sel = i;
            gRecords->sub = j;
            rebuildSplitTimes(GROUP(p, j));
            func_8006DDD8();
        }
    }
    for (j = 0; j < 4; j++) {
        gRecords->mode = 1;
        gRecords->sel = 0;
        gRecords->sub = j;
        p = (u8 *)gSlotTableB[1];
        rebuildSplitTimes(GROUP(p, j));
        pack_tile_rows();
    }
    for (j = 0; j < 5; j++) {
        gRecords->mode = 2;
        gRecords->sel = 0;
        gRecords->sub = j;
        p = (u8 *)gSlotTableB[2];
        rebuildSplitTimes(GROUP(p, j));
        pack_tile_rows();
    }
    for (j = 0; j < 6; j++) {
        gRecords->mode = 3;
        gRecords->sel = 0;
        gRecords->sub = j;
        p = (u8 *)gSlotTableB[3];
        rebuildSplitTimes(GROUP(p, j));
        pack_tile_rows();
    }
    for (j = 0; j < 3; j++) {
        gRecords->mode = 4;
        gRecords->sel = 0;
        gRecords->sub = j;
        p = (u8 *)gSlotTableB[4];
        rebuildSplitTimes(GROUP(p, j));
        pack_tile_rows();
    }
    for (i = 0; i < 12; i++) {
        gRecords->sel = i;
        rebuildSplitTimes(&g_split_times[i]);
        store_split_deltas();
    }
    for (i = 0; i < 4; i++) {
        rebuildSplitTimes(&D_800C3650[i]);
        update_split_deltas();
    }
    rebuildSplitTimes((Group *)D_800C3A50);
    func_8006CB9C();
    rebuildSplitTimes((Group *)&D_800C3A50[12]);
    UpdateChannelDeltas();
    gRecords->mode = mode;
    gRecords->sel = sel;
    gRecords->sub = sub;
    clearRaceData();
    func_8005508C();
}
