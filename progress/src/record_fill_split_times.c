typedef struct SplitTime { s32 time; u8 c4; u8 pad5; char name[3]; u8 pad9; u8 speed; u8 padB; u8 valid; u8 padD[3]; } SplitTime;
typedef struct RecordGlyph { u16 w0; u16 w2; char pad[10]; } RecordGlyph;
typedef struct RecordSeries { char pad0[0x14]; u16 n; char pad16[0x22C - 0x16]; s32 vals[8]; char pad24C[0x2C4 - 0x24C]; } RecordSeries;

extern void record_put_glyphs(s32,s32,s32,s32);
extern s32 gRecordTimeScale;
extern s32 gSplitBaseTimes[];
extern SplitTime g_split_times[][4];
extern RecordGlyph gRecordGlyphs[];
extern u8 gSplitRecordIds[];
extern RecordSeries *D_800D0648;

/* Fills the three split-time entries of one track from its split record ids:
 * decodes the glyph name, the time and the average speed, and draws the glyphs. */
void record_fill_split_times(u8 track) {
    u8 slot;
    s32 split;
    u32 entry;
    RecordGlyph *glyph;
    u16 *tbl;
    s32 total;
    u8 v;

    for (slot = 0; slot < 3; slot++) {
        split = slot;
        tbl = (u16 *)gSplitRecordIds;
        entry = tbl[track * 3 + split + 0xAD];
        if (entry != 0xFFFF) {
            glyph = &gRecordGlyphs[entry >> 14];
            record_put_glyphs((u8)(split), 22,(u8)(track),(u8)(track));
            g_split_times[track][split].name[0] = ((glyph->w0 >> 10) & 0x1F) + 'A';
            g_split_times[track][split].name[1] = ((glyph->w0 >> 5) & 0x1F) + 'A';
            {
                s32 w0_lo = ((u8 *)glyph)[1];
                entry &= 0x3FFF;
                g_split_times[track][split].valid = 1;
                g_split_times[track][split].name[2] = (w0_lo & 0x1F) + 'A';
            }
            if (entry & 1) entry = -entry;
            entry = gSplitBaseTimes[track] - entry;
            g_split_times[track][split].time = entry;
            g_split_times[track][split].c4 = (glyph->w2 >> 12) + (glyph->w0 >> 15) * 16;
            total = 0;
            for (v = 0; v < D_800D0648[track].n; v++) {
                total += D_800D0648[track].vals[v];
            }
            g_split_times[track][slot].speed = (u32)(total * gRecordTimeScale * 3600) / (u32)(entry * 1000);
        }
    }
}
