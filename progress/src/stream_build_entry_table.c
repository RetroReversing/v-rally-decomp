extern u8 stream_state[];
extern u8 gOrderState[];
void stream_locate_header(void);
void stream_select_entry(s32 index);
void stream_load_entry(s32 index);
s32 stream_store_entry_fields(void);
void stream_build_path_tree(void);
void *poolAlloc(s32, s32);

/* Builds the stream entry table. Reads the entry count from stream_state, allocates
 * count 8-byte entries from `pool`, and fills each one in turn. Then it loads each
 * entry's header and adds it to the path tree. */
void stream_build_entry_table(s32 pool) {
    s32 pad[2];
    s32 count;
    s32 i;
    s32 j;
    u16 remaining;

    stream_locate_header();
    remaining = *(u16 *)((s8 *)&stream_state + 0x30DE);
    count = remaining & 0xFFFF;
    *(void **)((s8 *)&gOrderState + 0x8AE0) = poolAlloc(pool, count * 8);
    i = pool - pool;
    if (count != 0) {
        remaining -= 1;
        do {
            stream_select_entry(i);
            i += 1;
            stream_store_entry_fields();
            if (!(remaining & 0xFFFF)) break;
            remaining -= 1;
        } while (1);
    }
    j = 0;
    if (i > 0) {
        do {
            stream_load_entry(j);
            j += 1;
            stream_build_path_tree();
        } while (j < i);
    }
}
