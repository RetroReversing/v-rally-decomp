void *select_get_entry(u32);

/* Walks entries from end-1 down to start+offset. Each entry takes the value of the
   entry `offset` places before it, and that value is also written to every node in
   the entry's child list (count at +0x4C, nodes linked through their first word). */
void select_propagate_values(s32 start, u32 offset, u32 end) {
    u32 i;
    u32 limit = start + offset;
    void *p;
    void *node;
    u16 v;
    i = end - 1;
    while ((u16)i >= start + offset) {
            void *previous = select_get_entry((u16)i - offset);
            p = select_get_entry((u16)i);
            node = *(void **)((u8 *)p + 0x28);
            { u32 j = 0;
            v = *(u16 *)((u8 *)previous + 0xC);
            if (*(u8 *)((u8 *)p + 0x4C) != 0) {
                do {
                    *(u16 *)((u8 *)node + 8) = v;
                    node = *(void **)node;
                    j++;
                } while ((u16)j < *(u8 *)((u8 *)p + 0x4C));
            }
            }
            i--;
            *(u16 *)((u8 *)p + 0xC) = v;
    }
}
