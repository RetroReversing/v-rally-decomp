s32 findAndReserveObj(s32, u16, void *);
s32 fillEntryFromTrackRecord(s32, s32);

/* Reserves a free entry from this slot's pool on the board and fills it from the track record. */
void fill_leaderboard_entry(s32 record, s32 board, s32 slot)
{
    void *slotCounts;

#ifdef PORT
    slotCounts = (void *)((uintptr_t)board + (uintptr_t)(slot * 2));
    fillEntryFromTrackRecord(record, findAndReserveObj(*(s32 *)((u8 *)((uintptr_t)board + (uintptr_t)(slot * 4)) + 0x54),
#else
    slotCounts = (void *)((slot * 2) + board);
    fillEntryFromTrackRecord(record, findAndReserveObj(*(s32 *)(((s8 *)((slot * 4) + board)) + 0x54),
#endif
 *(u16 *)(((s8 *)slotCounts) + 0x3E), slotCounts));
}
