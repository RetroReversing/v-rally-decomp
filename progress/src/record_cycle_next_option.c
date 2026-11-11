typedef struct {
    u8 pad0[0x14];
    u16 count;
    u8 pad16[0x2C4 - 0x16];
} Obj;
typedef struct {
    u8 pad0[0x20];
    u16 id;
    s16 cur;
} St;
extern u8 D_800C352C[];
extern St *gRecords;
extern Obj *gSlotTableB;
void select_set_active_sub(s32, u16);

/* Moves the current record's option to the next bit (wrapping) whose flag is set in
 * D_800C352C for its id, giving up after one full pass. If one is found, stores it as
 * cur and calls select_set_active_sub with it. Returns 0. */
s32 record_cycle_next_option(s32 owner)
{
    St *rec;
    s8 chosen = -1;
    s8 bitIdx;
    s8 attempts;
    s32 bitMask;
    u16 optId;
    s32 offset;
    Obj *slotTable = gSlotTableB;

    bitIdx = ((u8 *)gRecords)[0x23];
    attempts = 0;
    if (slotTable[gRecords->id].count - 1 > 0) {
        rec = gRecords;
        offset = rec->id * sizeof(Obj);
        do {
            if (bitIdx < ((Obj *)(offset + (s32)slotTable))->count - 1) {
                bitIdx++;
            } else {
                bitIdx = 0;
            }
            optId = rec->id;
            bitMask = 1 << bitIdx;
            if ((D_800C352C[optId] & bitMask) == bitMask) {
                chosen = bitIdx;
                break;
            }
            attempts++;
            slotTable = gSlotTableB;
        } while (attempts < slotTable[optId].count - 1);
    }
    if (chosen != -1) {
        gRecords->cur = chosen;
        select_set_active_sub(owner, chosen);
    }
    return 0;
}
