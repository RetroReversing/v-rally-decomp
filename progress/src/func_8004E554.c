typedef struct StreamSlot { u8 pad00[2]; u16 state; u8 pad04[2]; u16 flag; } StreamSlot;

/* Advances a two-state slot: states 1 and 2 alternate, and the flag toggles
 * between 0 and 1 unless it is already 2. */
void func_8004E554(StreamSlot *slot) {
    s32 state;
    u16 flag;
    u16 next;
    u16 cur;

    cur = slot->state;
    next = cur - 1;
    state = cur & 0xFFFF;
    if ((u32) (next & 0xFFFF) < 2U) {
        if (state == 1) {
            slot->state = (u16) (cur + 1);
        } else if (state == 2) {
            slot->state = next;
        }
        flag = slot->flag;
        if ((flag & 0xFFFF) != 2) {
            slot->flag = (u16) (1 - flag);
        }
    }
}
