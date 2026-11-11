extern u8 D_800AFA49;
extern void *gLeague;
extern s32 D_800C8118;

typedef struct VRLeagueEntry { u8 pad00[0x10]; s32 value; } VRLeagueEntry;
typedef struct VRLeague { u8 pad00[2]; s16 index; s16 timer; u8 pad06[10]; VRLeagueEntry *entries; } VRLeague;

/* Counts D_800C8118 down one frame at a time. When it reaches zero it is set to -1 and the league timer is
 * cleared. Then the current league entry (at index * 0x14 into the entry table) gets value 1 if D_800AFA49 is 1,
 * else 0x32. */
void func_8005D8B0(void) {
    if (D_800C8118 > 0) {
        D_800C8118 -= 1;
        return;
    }
    if (D_800C8118 == 0) {
        D_800C8118 = -1;
        ((VRLeague *) gLeague)->timer = 0;
    }
    if (D_800AFA49 == 1) {
        ((VRLeagueEntry *) ((s32) ((VRLeague *) gLeague)->entries + ((VRLeague *) gLeague)->index * 0x14))->value = (s32) D_800AFA49;
        return;
    }
    ((VRLeagueEntry *) ((s32) ((VRLeague *) gLeague)->entries + ((VRLeague *) gLeague)->index * 0x14))->value = 0x32;
}
