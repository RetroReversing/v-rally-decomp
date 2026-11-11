typedef struct StreamSlotParams { u8 pad00[6]; u16 flags; u8 pad08[4]; s8 volume; s8 pan; u8 rate; u8 reserved; } StreamSlotParams;

/* If the slot at `index` in the table at owner+0x70 is marked pending (flags bit 0),
 * clears the flag and stores the four parameter bytes into it. */
void streamSlotSetParams(void *owner, s32 index, s8 volume, s8 pan, u8 rate, u8 reserved) {
    s32 offset;
    StreamSlotParams *slot;
    u16 flags;

    offset = (index & 0xFFFF) * 0x10;
    slot = (StreamSlotParams *)(offset + *(s32 *)((u8 *)owner + 0x70));
    flags = slot->flags;
    if (flags & 1) {
        slot->flags = (u16)(flags & 0xFFFE);
        ((StreamSlotParams *)(offset + *(s32 *)((u8 *)owner + 0x70)))->volume = volume;
        ((StreamSlotParams *)(offset + *(s32 *)((u8 *)owner + 0x70)))->pan = pan;
        ((StreamSlotParams *)(offset + *(s32 *)((u8 *)owner + 0x70)))->rate = rate;
        ((StreamSlotParams *)(offset + *(s32 *)((u8 *)owner + 0x70)))->reserved = reserved;
    }
}
