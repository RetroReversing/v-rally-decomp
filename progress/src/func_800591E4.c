#define FIELD(expr, type, offset) (*(type *)((s8 *)(expr) + (offset)))
extern s32 func_80059154(s32);
extern s32 select_clear_slots();
extern s32 heapFreeBlock(void *);

/* Frees a list object and everything it owns. The object holds a u16 group count at +0 and
 * a pointer to the groups at +0x10 (0x14 bytes each). A group has its item count at +8,
 * an item array at +4 (0xC bytes each, with a block at +0 and a flag at +4) and a block
 * at +0 freed when its flag at +0xB is set. */
void func_800591E4(void *list) {
    s32 groupCount;
    s32 itemCount;
    void *item;
    void *group;
    void *groups;

    select_clear_slots();
    groupCount = FIELD(list, u16, 0);
    groups = FIELD(list, void *, 0x10);
    if (groupCount != 0) {
        group = (s8 *)groups + 4;
        do {
            itemCount = FIELD(group, u8, 8);
            if (itemCount != 0) {
                item = (s8 *)FIELD(group, void *, 4) + 4;
                do {
                    itemCount -= 1;
                    if (FIELD(item, u8, 4) != 0) {
                        heapFreeBlock(FIELD(item, void *, 0));
                    }
                    item = (s8 *)item + 0xC;
                } while (itemCount != 0);
                heapFreeBlock(FIELD(group, void *, 4));
            }
            groupCount -= 1;
            if (FIELD(group, u8, 0xB) != 0) {
                heapFreeBlock(FIELD(group, void *, 0));
            }
            group = (s8 *)group + 0x14;
        } while (groupCount != 0);
        groups = FIELD(list, void *, 0x10);
    }
    heapFreeBlock(groups);
    heapFreeBlock(list);
    func_80059154(0);
}
