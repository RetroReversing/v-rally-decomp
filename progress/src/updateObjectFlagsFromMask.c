typedef struct {
    s32 pad0[5];
    s32 flags;
    s32 pad1[12];
    s32 *countPtr;
} ObjFlags;

/* Clears the mask bits in obj->flags when the object's counter is below 4, otherwise sets them. */
void updateObjectFlagsFromMask(ObjFlags *obj, s32 mask) {
    if (*obj->countPtr < 4) {
        obj->flags = obj->flags & ~(mask & 0xFFFF);
        return;
    }
    obj->flags = obj->flags | (mask & 0xFFFF);
}
