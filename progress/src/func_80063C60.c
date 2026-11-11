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

/* Scans the bit table D_800C352C for the next set bit, walking down from the saved bit index in
 * gRecords[0x23] and across the slot-table entries. If a bit is found, stores it as the current
 * slot and calls select_set_active_sub with it. Always returns 0. */
s32 func_80063C60(s32 arg0)
{
    St *st;
    s8 found = -1;
    s8 bit;
    s8 tries;
    s32 mask;
    u16 id;
    Obj *base = gSlotTableB;

    bit = ((u8 *)gRecords)[0x23];
    tries = 0;
    if (base[gRecords->id].count - 1 > 0) {
        st = gRecords;
        do {
            if (bit > 0) {
                bit--;
            } else {
                bit = ((u8 *)&base[st->id])[0x15] - 1;
            }
            id = st->id;
            mask = 1 << bit;
            if ((D_800C352C[id] & mask) == mask) {
                found = bit;
                break;
            }
            tries++;
            base = gSlotTableB;
        } while (tries < base[id].count - 1);
    }
    if (found != -1) {
        gRecords->cur = found;
        select_set_active_sub(arg0, found);
    }
    return 0;
}
