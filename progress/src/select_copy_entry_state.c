void *select_get_entry(u32);
extern char gStreamState[];

/* Copies the stored state of entry src (word at +0x28, flag byte at +0x4D) to
 * entry dst, with both indices shifted by the stream table's base offset. Sets
 * the flag byte at +0x4E on dst. */
void select_copy_entry_state(s32 src, s32 dst)
{
    void *select_state;
    s32 table_base;
    s32 base_offset;
    s32 dst_index;
    void *src_entry;
    void *dst_entry;
    u8 flag;

    select_state = *((void **) (gStreamState + 0x325A));
    table_base = *((s32 *) (((char *) select_state) + 0x10));
    base_offset = *((u8 *) ((table_base + ((*((s16 *) (((char *) select_state) + 2))) * 0x14)) + 0xD));
    dst_index = dst - base_offset;
    src_entry = select_get_entry(src - base_offset);
    dst_entry = select_get_entry(dst_index);
    *((s32 *) (((char *) dst_entry) + 0x28)) = *((s32 *) (((char *) src_entry) + 0x28));
    flag = *((u8 *) (((char *) src_entry) + 0x4D));
    *((u8 *) (((char *) dst_entry) + 0x4E)) = 1;
    *((u8 *) (((char *) dst_entry) + 0x4D)) = flag;
}
