extern u8 D_8009BA34;
extern u8 D_800ADFEC[];
extern u8 *D_800AE004;

/* For each node in the manager's node list, collects the 0x34-byte entries that
   fall inside its bounding box (x in 34..3C, z in 44..48) into the node's list at
   +0x7C, linked through +0x24. Then counts the nodes that got no entries into
   D_8009BA34. */
void func_80012F7C(void *obj) {
    u8 *node;
    u8 *mgr;
    u8 *table;
    u8 *count_src;
    u8 *list_head;
    u8 *entry;
    u8 *entries;
    u8 *first_hit;
    u16 i;
    u16 any_flag;
    s32 more;

    mgr = *(u8 **)((u8 *)obj + 0x8C);
    table = D_800AE004;
    count_src = D_800ADFEC;
    D_8009BA34 = 0;
    list_head = *(u8 **)(mgr + 0x28);
    any_flag = 0;
    if (table == NULL) goto reset;
    {
        entries = *(u8 **)table;
        node = list_head;
        while (1) {
            if (node == NULL) {
                any_flag = 0;
                break;
            }
            for (i = 0; i < *(u16 *)(*(u8 **)(count_src + 0x18) + 4); i++) {
#ifdef PORT
                entry = entries + i * 0x34;
#else
                entry = (u8 *)(i * 0x34);
                entry += (u32)entries;
#endif
                if (*(s32 *)(entry + 0xC) > *(s32 *)(node + 0x34) &&
                    *(s32 *)(entry + 0xC) < *(s32 *)(node + 0x3C) &&
                    *(s32 *)(entry + 0x14) > *(s32 *)(node + 0x44) &&
                    *(s32 *)(entry + 0x14) < *(s32 *)(node + 0x48)) {
                    if (*(u8 **)(node + 0x7C) == NULL) {
                        *(u8 **)(node + 0x7C) = entry;
                    } else {
                        *(u8 **)(*(u8 **)(node + 0x7C) + 0x24) = entry;
                        *(u8 **)(*(u8 **)(*(u8 **)(node + 0x7C) + 0x24) + 0x24) = NULL;
                    }
                }
            }
            if (any_flag == 0) {
                any_flag = 1;
            }
            first_hit = *(u8 **)(node + 0x7C);
            if (first_hit != NULL && *(u8 **)(first_hit + 0x24) == NULL) {
                *(u8 **)(first_hit + 0x24) = first_hit;
            }
            node = *(u8 **)(node + 0x5C);
            { s32 flag = any_flag ^ 1; s32 different = list_head != node; more = different | flag; }
            if (more == 0) {
                break;
            }
        }
reset:
        any_flag = 0;
    }
    D_8009BA34 = 0;
    node = list_head;
    while (1) {
        if (node == NULL) break;
        if (*(u8 **)(node + 0x7C) == NULL) {
            D_8009BA34++;
        }
        if (any_flag == 0) {
            any_flag = 1;
        }
        node = *(u8 **)(node + 0x5C);
        { s32 flag = any_flag ^ 1; s32 different = list_head != node; more = different | flag; }
        if (more == 0) {
            break;
        }
    }
}
