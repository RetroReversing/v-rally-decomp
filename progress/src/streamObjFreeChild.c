s32 streamObjDestroy(s32);

/* Destroys the child stream object stored at +0x178 of obj, if there is one. */
void streamObjFreeChild(void *obj) {
    s32 child;

    child = *(s32 *)((s8 *)obj + 0x178);
    if (child != 0) {
        streamObjDestroy(child);
    }
}
