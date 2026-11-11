void *list_find_node(void **, u8 *);
void func_800804C4(void *, void (*)(void *));
extern u8 D_800A4F20[];
extern u8 D_800A4F28[];
extern void func_8004E094(void *);

/* Resets the two stream nodes of the object at arg0+0x28. The first node's list gets
 * func_8004E094 called on each entry. The second node's sub-object gets its +0x08 word
 * cleared, +0x30 set to 1, +0x60 cleared, +0x6A set to 0x1000 and bit 1 set at +0x68. */
void func_8004E18C(s32 arg0) {
    s32 listHead;
    void *node;
    void *node2;
    void *subObj;
    void *obj;

    listHead = arg0 + 0x28;
    node = list_find_node((void **)(listHead), D_800A4F20);
    if (node != NULL) {
        func_800804C4(*(void **)((s8 *)node + 0x10), &func_8004E094);
    }
    node2 = list_find_node((void **)(listHead), D_800A4F28);
    if (node2 != NULL) {
        subObj = *(void **)((s8 *)node2 + 0x10);
        obj = *(void **)((s8 *)subObj + 0);
        *(s32 *)((s8 *)subObj + 8) = 0;
        *(s32 *)((s8 *)obj + 0x30) = 1;
        *(s32 *)((s8 *)obj + 0x60) = 0;
        *(s16 *)((s8 *)obj + 0x6A) = 0x1000;
        *(u16 *)((s8 *)obj + 0x68) = (u16)(*(u16 *)((s8 *)obj + 0x68) | 1);
    }
}
