extern s32 func_8006786C(s32, s32); extern s32 strCmp(u8 *, u8 *); extern s32 gRecordTimeScale; extern u8 *gSelectState; extern u8 *gRecords; extern s16 *gLeague; extern s16 D_800C6F12;

/* Name-entry letter picker: the stick moves the current letter (A-Z, wrapping),
   which is written at offset 3 of the entry. Once two letters are set, checks
   the name against the four league records; a match leaves the entry for a
   retry, no match clears league slot 1 and resets the league. */
s32 func_800676A0(void)
{
    u8 *entry = gSelectState + 0x280;
    u8 i;
    if (*(s8 *)entry > 0) {
        entry[1]++;
        if ((s8)entry[1] == 0x1a) entry[1] = 0;
    } else if (*(s8 *)entry < 0) {
        entry[1]--;
        if ((s8)entry[1] < 0) entry[1] = 0x19;
    }
    entry[0] = 0;
    (entry + entry[2])[3] = entry[1] + 0x41;
    if (entry[2] == 2) {
        i = 0;
        do {
            if (strCmp(gRecords + (((((i << 2) + i)) << 3) + 0x44), entry + 3) == 0) break;
            i++;
        } while (i < 4);
        if (i == 4) {
            gLeague[1] = 0;
            func_8006786C(0, 0);
        } else {
            D_800C6F12 = gRecordTimeScale * 2;
        }
        return 0;
    }
    entry[2]++;
    return 0;
}
