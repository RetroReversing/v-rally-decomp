extern u8 stream_state[];
extern u8 D_800A4E40[];

void *poolAllocListNode(s32, s32);
s32 resolve_path(void *);
s32 getTexturePack(void *, s32);

/* Allocates a 0x50-byte node from the pool at stream_state+0x7672, resolves
 * the path in D_800A4E40, and stores the texture pack for `obj` in node+0xC. */
void stream_obj_attach_texture_pack(void *obj) {
    void *node;

    node = poolAllocListNode(*(s32 *) (stream_state + 0x7672), 0x50);
    resolve_path(D_800A4E40);
    *(s32 *) ((u8 *) node + 0xC) = getTexturePack(obj, 0);
}
