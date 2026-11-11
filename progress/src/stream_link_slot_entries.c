extern char gOrderState[];
extern char gStreamState[];
s32 find_object_by_id();

/* Links the two objects for slot (slot - 1) * 2 and (slot - 1) * 2 + 2 to the list node
 * that matches list_index. The node is searched for only when the stream state reports
 * entries (entry_count != 0). */
s32 stream_link_slot_entries(s32 slot, s32 list_index, s32 unused, s32 first_index)
{
    char pad[8];
    s32 *found;
    s32 *node;
    s32 key_a;
    s32 obj_a;
    s32 has_entries;
    s32 key_b;
    s32 index;
    s32 keep_going;
    u8 entry_count;

    found = NULL;
    entry_count = ((u8 *) *(void **) (gStreamState + 0x32F2))[0xF];
    node = *(s32 **) (*(void **) (gOrderState + 0x73F0));
    has_entries = entry_count != 0;
    if (entry_count) {
        index = 1;
        list_index &= 0xFF;
        do {
            if (index == list_index) {
                found = node;
            }
            node = *(s32 **) ((char *) node + 4);
            keep_going = (u32) found < 1;
            keep_going = has_entries & (u8) keep_going;
        } while (keep_going);
        first_index = index;
    }
    key_a = (slot - 1) * 2;
    obj_a = find_object_by_id(key_a | 1, list_index, has_entries, first_index);
    key_b = key_a + 2;
    key_a = obj_a;
    obj_a = find_object_by_id(key_b);
    *(s32 **) ((char *) key_a + 0x24) = found;
    *(s32 **) ((char *) obj_a + 0x24) = found;
    return 1;
}
