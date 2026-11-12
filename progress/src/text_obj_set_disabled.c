void *textObjGet(u32 index);

/* Clears the +0x1A flag byte of text object `index` (looked up with textObjGet). */
void text_obj_set_disabled(u32 index) {
    ((s8 *)textObjGet(index))[0x1A] = 0;
}
