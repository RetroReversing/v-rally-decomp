void *select_get_entry(u32);
extern char stream_state[];

/* Walks the entries of the selected slot's object (linked list at +0x28, count at
 * +0x4D) and marks the entry whose index equals arg1 with flag 1 at +0x1A; the others get 0. */
void slotSetSelected(s32 slot, s32 selected_index)
{
    char *p;
    char *base;
    char *obj;
    char *cur;
    u32 i;
    u8 cnt;

    p = *((char **) (stream_state + 0x325A));
    base = *((char **) (p + 0x10));
    obj = select_get_entry(slot - *((u8 *) (base + *((s16 *) (p + 2)) * 0x14 + 0xD)));
    cnt = *((u8 *) (obj + 0x4D));
    cur = *((char **) (obj + 0x28));
    i = 0;
    if (cnt != 0) {
        do {
            if ((i & 0xFF) == selected_index) {
                *((s8 *) (cur + 0x1A)) = 1;
            } else {
                *((s8 *) (cur + 0x1A)) = 0;
            }
            cur = *((char **) cur);
            i++;
        } while ((i & 0xFF) < cnt);
    }
}
