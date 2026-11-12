/* Stores value in the first free entry of the object's 4-slot table at +0xA0 (free = -1) and marks the entry after it free. */
void obj_set_flag_slot(void *obj, s32 value) {
    s32 slot = 0;
    unsigned int free_marker;
    void *cursor;

    if (*(s32 *)((s8 *)obj + 0xA0) != -1) {
        free_marker = -1;
        cursor = obj;
        do {
            cursor = (s8 *)cursor + 4;
            slot += 1;
        } while (*(s32 *)((s8 *)cursor + 0xA0) != free_marker);
    }
    *(s32 *)((s8 *)((slot * 4) + obj) + 0xA0) = value;
    *(s32 *)((s8 *)((slot * 4) + obj) + 0xA4) = -1;
}
