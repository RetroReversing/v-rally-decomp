void *textObjGet(u32);

/* Reads two 16-bit fields (offsets 6 and 8) of the text object with the given id. */
void func_8005A5D4(s32 id, u16 *outA, u16 *outB) {
    void *obj;

    obj = textObjGet(id);
    *outA = *(u16 *)((s8 *)obj + 6);
    *outB = *(u16 *)((s8 *)obj + 8);
}
