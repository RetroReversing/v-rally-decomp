/* Inserts node into a doubly linked list. list[0] is the head and list[1] the tail;
   node[0] is the prev link and node[1] the next link. Nodes are kept in descending
   order of the s16 key at +8: the node goes before the first node whose key is lower,
   or at the tail if there is none. Sets the key and clears the s16 flag at +0xA. */
void sorted_list_insert(AddrWord *node, AddrWord *list, s16 key)
{
    AddrWord *cur;
    u16 want;

    want = key;
    cur = (AddrWord *)list[0];
    while (cur != NULL) {
        if (*(s16 *)((u8 *)cur + 8) < want) {
            break;
        }
        cur = (AddrWord *)cur[1];
    }
    if (cur != NULL) {
        node[1] = (AddrWord)cur;
        node[0] = cur[0];
        cur[0] = (AddrWord)node;
        if ((AddrWord)cur == list[0]) {
            list[0] = (AddrWord)node;
        }
    } else {
        node[1] = 0;
        node[0] = list[1];
        if (list[1] != 0) {
            ((AddrWord *)list[1])[1] = (AddrWord)node;
        }
        list[1] = (AddrWord)node;
        if (list[0] == 0) {
            list[0] = (AddrWord)node;
        }
    }
    *(s16 *)((u8 *)node + 8) = key;
    *(s16 *)((u8 *)node + 0xA) = 0;
}
