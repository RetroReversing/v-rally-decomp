void *select_get_entry(u32);
extern char gStreamState[];

/* Flags the sub-item at index `selected` of the active select entry as active, clears the rest. */
void select_set_active_sub(s32 slot, s32 selected)
{
    char *p;
    char *base;
    char *obj;
    char *cur;
    u32 i;
    u8 n;
    p = *(char **)(gStreamState + 0x325A);
    base = *(char **)(p + 0x10);
    obj = select_get_entry(slot - *(u8 *)(base + *(s16 *)(p + 2) * 0x14 + 0xD));
    n = *(u8 *)(obj + 0x4D);
    cur = *(char **)(obj + 0x28);
    i = 0;
    if (n != 0) {
        do {
            if ((i & 0xFF) == selected) {
                *(s8 *)(cur + 0x1B) = 1;
            } else {
                *(s8 *)(cur + 0x1B) = 0;
            }
            cur = *(char **)cur;
            i++;
        } while ((i & 0xFF) < n);
    }
}
