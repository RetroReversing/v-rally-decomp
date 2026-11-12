void text_obj_set_disabled(u32);
void text_obj_set_enabled(u32);

/* Clears the text objects first..first+count-1 (through text_obj_set_disabled), then
 * calls text_obj_set_enabled for the object at first+offset. */
void func_8005A3BC(int first, int count, int offset) {
    int i;
    for (i = 0; i < count; i++) {
        text_obj_set_disabled(first + i);
    }
    text_obj_set_enabled(first + offset);
}
