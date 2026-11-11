void *select_get_entry(u32);
void *textObjGet(u32);
void *list_advance(u32, void *);
extern void *gSelectState;

/* Sets the flag byte of one selection entry: the value goes into the +0x1A field of
 * every node in the entry's first list (count at +9) and the +0x41 field of every node
 * in the second list (count at +6), then into the entry's own +0xA byte. */
void func_800580D0(s32 index, s8 value)
{
    s32 n;
    s32 n2;
    void *entry;
    void *node;
    void *node2;

    entry = list_advance(index & 0xFF, *(void **)((s8 *)gSelectState + 0x24));
    if (*(s8 *)((s8 *)entry + 9) != 0) {
        node = textObjGet((u8)(*(u8 *)((s8 *)entry + 8)));
        n = 0;
        if (*(s8 *)((s8 *)entry + 9) > 0) {
            do {
                *(s8 *)((s8 *)node + 0x1A) = value;
                node = *(void **)((s8 *)node + 0);
                n += 1;
            } while ((n & 0xFF) < *(s8 *)((s8 *)entry + 9));
        }
    }
    node2 = select_get_entry((u16)(*(u16 *)((s8 *)entry + 4)));
    n2 = 0;
    if (*(u16 *)((s8 *)entry + 6) != 0) {
        do {
            *(s8 *)((s8 *)node2 + 0x41) = value;
            node2 = *(void **)((s8 *)node2 + 0);
            n2 += 1;
        } while ((u32) (n2 & 0xFF) < (u16) *(u16 *)((s8 *)entry + 6));
    }
    *(s8 *)((s8 *)entry + 0xA) = value;
}
