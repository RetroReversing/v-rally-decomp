extern char gStreamState[];

/* Walks the linked list of sound/sprite nodes starting at *list. Each node with flag bit 1 set runs its hook
 * (at +0x30) and, unless flag bit 2 is also set, sends its parameters (+0x10..+0x24, u16 at +0x1C) through its
 * handler at +0x2C, using the device word at gStreamState+0x7CD6 -> +0x178. */
void func_8004C5BC(void **list) {
    s32 (*hook)(void *);
    s32 (*send)(s32, s32, s32, s32, s32, u16);
    void *node, *next, *global;
    node = *list;
    global = *(void **)(gStreamState + 0x7CD6);
    if(node == 0) return;
    do {
        next = *(void **)((u8 *)node + 4);
        if (*(s32 *)((u8 *)node + 0xC) & 1) {
            hook = *(s32 (**)(void *))((u8 *)node + 0x30);
            if (hook != 0) hook(node);
            if ((*(s32 *)((u8 *)node + 0xC) & 2) == 0) {
                (*(s32 (**)(s32, s32, s32, s32, s32, u16))((u8 *)node + 0x2C))(*(s32 *)((u8 *)global + 0x178), *(s32 *)((u8 *)node + 0x24),
                     *(s32 *)((u8 *)node + 0x10), *(s32 *)((u8 *)node + 0x14),
                     *(s32 *)((u8 *)node + 0x20), (u32)*(u16 *)((u8 *)node + 0x1C));
            }
        }
        node = next;
    } while(node);
}
