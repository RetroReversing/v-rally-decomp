s32 stream_set_objects(s32, void **, void **);
s32 func_80005824(s32, f32, s32);
void **func_80005CB8(u16, u16, u16, s32, s32);

/* Sets up an object's two pooled lists when its first count (0x186) is non-zero. Each list is created
 * from the same type and counts, and points at the object's embedded node at +0x10. The object is then
 * registered with stream_set_objects and, when its scale at 0x18C is set, that scale is applied. */
void func_800421A4(void *obj) {
    f32 scale;
    u16 count;
    void **listA;
    void **listB;
    void *node;

    count = *(u16 *)((u8 *)obj + 0x186);
    if (count != 0) {
        listA = func_80005CB8(*(u16 *)((u8 *)obj + 0x184), count, *(u16 *)((u8 *)obj + 0x188), 1, 6);
        node = (u8 *)obj + 0x10;
        *listA = node;
        listB = func_80005CB8(*(u16 *)((u8 *)obj + 0x184), *(u16 *)((u8 *)obj + 0x186), *(u16 *)((u8 *)obj + 0x188), 1, 6);
        *listB = node;
        stream_set_objects(*(s32 *)((u8 *)obj + 0x178), listA, listB);
        scale = *(f32 *)((u8 *)obj + 0x18C);
        if (scale != 0.0f) {
            func_80005824(*(s32 *)((u8 *)obj + 0x178), scale, *(s32 *)((u8 *)obj + 0x190));
        }
    }
}
