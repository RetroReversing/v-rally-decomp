extern u8 gStreamState[];
extern u8 D_800A4E40[];

void *poolAllocListNode(s32, s32);
s32 resolve_path(void *);
s32 getTexturePack(void *, s32);

/* Allocates a 0x50-byte node from the pool at gStreamState+0x7672, resolves
 * the path in D_800A4E40, and stores the texture pack for `obj` in node+0xC. */
void func_80047CC0(void *obj) {
    void *node;

    node = poolAllocListNode(*(s32 *) (gStreamState + 0x7672), 0x50);
    resolve_path(D_800A4E40);
    *(s32 *) ((u8 *) node + 0xC) = getTexturePack(obj, 0);
}
