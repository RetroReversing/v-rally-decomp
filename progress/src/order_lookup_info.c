void *order_table_search(s32 table, s32 key);
extern u8 gOrderState[];
extern u8 gStreamState[];

/* Searches the order table in gOrderState for key. Stores the matched entry's
 * value at +0x10 in *out_value and sets *out_flag to 1 if the entry's u16 at +0x1A
 * is non-zero, else 0. Returns the sum of the table's +0x8AB0 word, the entry's
 * +0x1C word, and the entry's +0x28 word minus the stream state word at +0x308A. */
s32 order_lookup_info(s32 key, s32 *out_value, s8 *out_flag)
{
    s8 *entry;

    entry = order_table_search(*(s32 *)(gOrderState + 0x8AB8), key);
    *out_value = *(s32 *)(entry + 0x10);
    if (*(u16 *)(entry + 0x1A) == 0) {
        *out_flag = 0;
    } else {
        *out_flag = 1;
    }
    return *(s32 *)(gOrderState + 0x8AB0) + *(s32 *)(entry + 0x1C) + (*(s32 *)(entry + 0x28) - *(s32 *)(gStreamState + 0x308A));
}
