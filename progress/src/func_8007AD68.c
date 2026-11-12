typedef void (*Callback)(void);
typedef struct { u8 pad[0x2c]; s32 state; } Object;
typedef struct { s32 pad; Object *obj; s32 pad8; } Slot;
typedef struct { u8 pad[8]; Slot *slots; u8 pad2[8]; } Team;
typedef struct { u8 pad[3]; u8 current; u8 pad4[12]; Team *teams; } League;
void func_800407D0(void);
void select_set_text_default(void *);
s32 select_copy_entry_label(s32, s32);
void glyph_record_pack(u8);
void UpdateSelectedEntry(void);
extern void *gSelectState;
extern u8 D_800A5FB8[];
extern u8 D_800A5FC4[];
extern u8 D_800A5FD0[];
extern u8 *gRecords;
extern League *gLeague;
extern void InitRaceHud(void);
extern void select_update_record_bars(void);
extern void league_season_setup(void);
extern void func_80065860(void);
extern void finish_race_results(void);
extern void best_times_select_update(void);
extern void func_8007A29C(void);
extern void func_8007A9A8(void);
extern void func_8007AA94(void);

/* Moves the results screen on to the next slot. While slots remain it arms the
 * next step's callbacks and marks the slot; after the last slot it resets the
 * selection and shows the end-of-results message for the record's mode.
 * Returns 0 when there is nothing to show. */
s32 func_8007AD68(s32 stepParam, s32 slot) {
    char *recordStat; s8 selected;
    u16 mode;
    u16 mode2;
    u8 teamIdx;

    (*(s8 *)((char *)(gSelectState) + 0x245)) = 0;
    UpdateSelectedEntry();
  recordStat = (char *) ((gRecords + ((gRecords + ((s8) ((u8 *)gSelectState)[0x228]))[0x32] * 0x28)) + 0x4E);
  *((s16 *) recordStat) = ((u8 *)gSelectState)[0x237];
    glyph_record_pack((u8) (*(s8 *)((char *)(gSelectState) + 0x228)));
    selected = (*(s8 *)((char *)(gSelectState) + 0x228));
    teamIdx = gLeague->current;
    if (selected >= ((*(u16 *)((char *)(gRecords) + 0xE)) - 1)) {
        goto block_11;
    }
    ++((u8 *)gSelectState)[0x228];
    select_copy_entry_label(stepParam, slot);
    { u8 *state = (u8 *)gSelectState; u8 *record = gRecords;
    *((Callback *)(state + 0x288)) = func_8007A29C;
    *((Callback *)(state + 0x28C)) = func_8007A9A8;
    *((Callback *)(state + 0x290)) = func_8007AA94;
    mode = *((u16 *)(record + 0x1E)); }
    switch (mode) {
case 1: case 2: case 3: case 4:
    gLeague->teams[teamIdx].slots[slot].obj->state = 5;
break;
case 0:
    gLeague->teams[teamIdx].slots[slot].obj->state = 5;
break;
case 5:
    gLeague->teams[teamIdx].slots[slot].obj->state = 7;
break;
default: return 0;
} goto block_22;
block_11:
    (*(s8 *)((char *)(gSelectState) + 0x228)) = 0;
    (*(s8 *)((char *)(gSelectState) + 0x22B)) = -1;
    mode2 = (*(u16 *)((char *)(gRecords) + 0x1E));
    switch (mode2) {
case 1: case 2: case 3: case 4: goto block_19;
case 0: goto block_20;
case 5: goto block_21;
default: return 0;
}
block_19:
    gLeague->teams[teamIdx].slots[slot].obj->state = 2;
    select_set_text_default(D_800A5FB8);
    (*(Callback *)((char *)gSelectState + 0x288)) = &league_season_setup;
    (*(Callback *)((char *)gSelectState + 0x28C)) = &func_80065860;
    goto block_22;
block_20:
    gLeague->teams[teamIdx].slots[slot].obj->state = 2;
    select_set_text_default(D_800A5FC4);
    (*(Callback *)((char *)gSelectState + 0x288)) = &InitRaceHud;
    (*(Callback *)((char *)gSelectState + 0x28C)) = &select_update_record_bars;
    goto block_22;
block_21:
    gLeague->teams[teamIdx].slots[slot].obj->state = 3;
    select_set_text_default(D_800A5FD0);
    (*(Callback *)((char *)gSelectState + 0x288)) = &finish_race_results;
    (*(Callback *)((char *)gSelectState + 0x28C)) = &best_times_select_update;
    func_800407D0();
block_22:
    return 0;
}
