void *find_object_by_id();

/* Stores value at offset 0x24 of the object with the given id. Returns 1 if the object exists, 0 if not. */
s32 set_object_field_by_id(s32 value, s32 id) {
    void *obj;

    obj = find_object_by_id(id);
    if (obj != NULL) {
        *(s32 *)((char *)obj + 0x24) = value;
        return 1;
    }
    return 0;
}
