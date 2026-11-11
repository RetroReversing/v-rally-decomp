/* Inserts node into a doubly linked list. list[0] is the head and list[1] the tail;
   node[0] is the prev link and node[1] the next link. Nodes are kept in descending
   order of the s16 key at +8: the node goes before the first node whose key is lower,
   or at the tail if there is none. Sets the key and clears the s16 flag at +0xA. */
void sorted_list_insert(s32 *node, s32 *list, s16 key)
{
    s32 *cur;
    u16 want;

    want = key;
    cur = (s32 *)list[0];
    while (cur != NULL) {
        if (*(s16 *)(cur + 2) < want) {
            break;
        }
        cur = (s32 *)cur[1];
    }
    if (cur != NULL) {
        node[1] = (s32)cur;
        node[0] = cur[0];
        cur[0] = (s32)node;
        if ((s32)cur == list[0]) {
            list[0] = (s32)node;
        }
    } else {
        node[1] = 0;
        node[0] = list[1];
        if (list[1] != 0) {
            ((s32 *)list[1])[1] = (s32)node;
        }
        list[1] = (s32)node;
        if (list[0] == 0) {
            list[0] = (s32)node;
        }
    }
    *(s16 *)(node + 2) = key;
    *(s16 *)((u8 *)node + 0xA) = 0;
}
