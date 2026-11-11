#define FIELD(expr, type_ptr, off) (*(type_ptr)((s8 *)(expr) + (off)))
s32 sort_split_times();
s32 store_split_deltas();
s32 save_race_to_pak();
s32 copyStringAligned();
extern s32 gRecordTimeScale;
extern char gOrderState[];
extern char gStreamState[];
extern void *gRecords;
extern char D_800C3780[];
extern char g_split_times[];
extern char D_800C375C[];

/* Refreshes the record entries shown after a race: for each record it copies the name and
 * timing data into its track's entry in D_800C3780, works out the average speed (km/h,
 * scaled by gRecordTimeScale), applies the first-split adjustment, then sorts the track's
 * split times. Finally it runs the two follow-up updates. */
void update_record_entries(void) {
    char *slot_rec;
    s32 slot;
    s32 time_a;
    s32 time_b;
    s32 slot_off;
    s32 time_c;
    s32 group_off;
    s32 total_time;
    s32 total_dist;
    s32 i;
    u16 track;
    u32 t_first;
    u32 t_first_alt;
    void *recs;
    void *slot_time;
    void *entry;
    void *times;
    void *track_state;

    recs = gRecords; times = gOrderState + 0x7DB0;
    i = 0;
    if (FIELD(recs, u16 *, 0xE) != 0) {
        do {
            track = FIELD(recs, u16 *, 0x20);
            slot = i & 0xFF;
            slot_off = slot * 4;
            entry = (void *)((track << 6) + (s32)D_800C3780);
            FIELD(entry, s32 *, 0) = (s32)FIELD((void *)((track * 0x10) + (s32)times + slot_off), s32 *, 0x58);
            slot_rec = (char *)(((FIELD((recs + slot), u8 *, 0x32) * 0x28) + recs));

            FIELD(entry, s8 *, 4) = (s8)FIELD(slot_rec, u16 *, 0x4E);
            FIELD(entry, s8 *, 5) = (s8)FIELD(gRecords, u16 *, 0x16);
            copyStringAligned((s32)entry + 6, (s32)(gRecords + ((FIELD((gRecords + slot), u8 *, 0x32) * 0x28) + 0x44)));
            total_dist = 0;
            total_time = 0;
            slot_time = (void *)(slot_off + (s32)times);

            track_state = (void *)(*(s32 *)(gStreamState + 0x10386 + (FIELD(gRecords, u16 *, 0x1E) * 4)) + (FIELD(gRecords, u16 *, 0x20) * 0x2C4));
            time_a = FIELD(slot_time, s32 *, 0x118);
            if (time_a != 0) {
                total_dist = FIELD(track_state, s32 *, 0x22C);
                total_time = time_a;
            }
            time_b = FIELD(slot_time, s32 *, 0x128);
            if (time_b != 0) {
                total_time += time_b;
                total_dist += FIELD(track_state, s32 *, 0x230);
            }
            time_c = FIELD(slot_time, s32 *, 0x138);
            if (time_c != 0) {
                total_time += time_c;
                total_dist += FIELD(track_state, s32 *, 0x234);
            }
            { u32 avg_kmh = (u32)(total_dist * gRecordTimeScale * 0xE10) / (u32)(total_time * 0x3E8);
            FIELD(entry, s8 *, 0xB) = 0;
            FIELD(entry, s8 *, 0xC) = 1;
            FIELD(entry, s8 *, 0xA) = avg_kmh; }
            if (FIELD(gRecords, u16 *, 0x2C) & 0x4000) {
                group_off = FIELD(gRecords, u16 *, 0x20) << 6;
                if (*(u8 *)(D_800C375C + group_off) != 0) {
                    t_first = *(u32 *)(g_split_times + group_off);
                    if (t_first >= 0x33U) {
                        FIELD(entry, s32 *, 0) = (s32)(t_first - 3);
                    }
                } else {
                    t_first_alt = *(u32 *)(g_split_times + group_off);
                    if (t_first_alt >= 0x33U) {
                        FIELD(entry, s32 *, 0) = (s32)(t_first_alt - 0xA);
                    }
                }
            }
            sort_split_times((FIELD(gRecords, u16 *, 0x20) << 6) + (s32)(g_split_times));
            i += 1;
            recs = gRecords;
        } while ((u32)(i & 0xFF) < (u16)FIELD(gRecords, u16 *, 0xE));
    }
    store_split_deltas();
    save_race_to_pak();
}
