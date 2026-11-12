typedef struct Record {
    s32 w[5];
    u16 count;
    u8 pad16[0x2BC - 0x16];
    u8 colors[8];
} Record;
typedef struct Disp {
    s16 x;
    u16 y;
    f32 f;
    u8 step;
} Disp;
typedef struct State {
    u8 pad00[0x20];
    u16 sel;
    u16 h22;
} State;
extern VRMenuManager *gLeague;
extern State *gRecords;
extern u8 D_800C352C[];
extern s32 D_800B3DA0;
extern u8 *gSelectState;
extern s32 *gStreamList;
extern Disp *gSelectBuffer;
extern f64 D_800A5698;
extern s32 D_800D05D8;
extern Record *gSlotTableB;
extern void func_8005937C(u8, u16);
extern void select_arm_if_clear(void);
extern void func_80061740(Record);
#ifdef PORT
extern void func_8006185C(void *, s32);
#else
extern void func_8006185C(s32, s32);
#endif
extern void menu_draw_text_objs(Record, s32);
extern void func_80062E68(void);
extern void func_8004D08C(s32, u8, s16, s16, f32, f32, u8, u8);
void *select_get_entry(u32);

/* Selects the record shown by the current menu item, updates the selection
 * state, and draws one colour bar per record field. Bars for fields that are
 * not yet unlocked (bit clear in D_800C352C[sel]) are drawn dimmed. */
void select_update_record_bars(void)
{
    VRMenuItem *item;
    s32 recIdx;
    u8 field;
    s32 mask;
    s32 selected;
    u8 alpha;
    Record record;
    f64 barWidth;

    item = &gLeague->items[gLeague->count];
    recIdx = item->value - item->pad00[13];
    if (!gSelectState[0x245]) {
        *(u16 *)((u8 *)gRecords + 0x20) = recIdx;
        func_8005937C(item->value, gSlotTableB[recIdx].count);
        if (recIdx != D_800B3DA0) {
            if (*gStreamList) {
                select_arm_if_clear();
            }
            if (!gSelectState[0x2BE]) {
                func_80061740(gSlotTableB[recIdx]);
                D_800B3DA0 = recIdx;
            }
        }
        gRecords->h22 = 0;
    } else {
#ifdef PORT
        func_8006185C(select_get_entry((u16)(gRecords->sel)), 0);
#else
        func_8006185C((s32)select_get_entry((u16)(gRecords->sel)), 0);
#endif
    }
    record = gSlotTableB[gRecords->sel];
    if (gLeague->count == 1 && gSelectState[0x245]) {
        func_80062E68();
    }
    menu_draw_text_objs(record, 1);
    if (!gSelectState[0x24D] && !gSelectState[0x2BE]) {
        field = 0;
        if (field < record.count) barWidth = D_800A5698;
        for (; field < record.count; field++) {
            selected = gRecords->sel;
            mask = 1 << field;
            if ((D_800C352C[selected] & mask) != mask) {
                if ((selected == 0 & field == 6) || (selected == 1 & field == 4) || (selected == 5 & field == 6) || (selected == 6 & field == 5)) {
                    alpha = 200;
                } else {
                    alpha = 130;
                }
                func_8004D08C(D_800D05D8, field, gSelectBuffer->x, gSelectBuffer->y + field * gSelectBuffer->step,
                              gSelectBuffer->f - barWidth, gSelectBuffer->f, record.colors[field], alpha);
            } else {
                func_8004D08C(D_800D05D8, field, gSelectBuffer->x, gSelectBuffer->y + field * gSelectBuffer->step,
                              gSelectBuffer->f - barWidth, gSelectBuffer->f, record.colors[field], 255);
            }
        }
    }
}