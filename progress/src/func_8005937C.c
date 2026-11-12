void *select_get_entry(u32);
extern char stream_state[];

/* Sets up the select entry at `slot` (relative to the stream's first slot) with `count` sub-items:
 * stores the count at +0x4D, marks it ready at +0x4E, and clears the active flag (+0x1B) on every
 * sub-item in the linked list at +0x28. */
void func_8005937C(s32 slot, s32 count)
{
    s32 i;
    char *p;
    char *cur;
    char *obj;
    char *base;
    p = *(char **)(stream_state + 0x325A);
    base = *(char **)(p + 0x10);
    slot -= *(u8 *)(base + *(s16 *)(p + 2) * 0x14 + 0xD);
    obj = select_get_entry(slot);
    *((s8 *)obj + 0x4D) = count;
    *((s8 *)obj + 0x4E) = 1;
    cur = *(char **)(obj + 0x28);
    i = 0;
    if (count > 0) {
        do {
            *((s8 *)cur + 0x1B) = 0;
            cur = *(char **)cur;
            i++;
        } while ((i & 0xFF) < count);
    }
}
