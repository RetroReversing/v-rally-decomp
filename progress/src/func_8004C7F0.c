s32 getTexturePack(s32, s32);
void *poolAllocListNode(s32, s32);
extern s32 D_800A11B0;

/* Allocates a 16-byte list node from the pool at D_800A11B0 and stores the texture pack
 * handle for id at its +0xC field (the entry that stream_list_destroy releases). */
void func_8004C7F0(s32 id) {
    void *node;

    node = poolAllocListNode(D_800A11B0, 0x10);
    *(s32 *)((char *)node + 0xC) = getTexturePack(id, 0);
}
