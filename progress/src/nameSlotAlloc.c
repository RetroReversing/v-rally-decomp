extern int gNameSlotCount;
extern int gNameSlots;
void *copyStringAligned();

/* Takes the next free name slot (0x468 bytes each), copies the name into it and clears its two flag words. Returns the slot. */
void *nameSlotAlloc(s32 name) {
    s32 temp_v1;
    void *temp_s0;
    void *temp_v0;

    temp_v1 = gNameSlotCount;
    gNameSlotCount = (s32) (temp_v1 + 1);
    temp_s0 = (void *) (gNameSlots + (temp_v1 * 0x468));
    copyStringAligned(temp_s0, name);
    temp_v0 = temp_s0;
    *(s32 *)((char *)temp_v0 + 0x10) = 0;
    *(s32 *)((char *)temp_v0 + 0x7C) = 0;
    return temp_v0;
}
