void func_8005A6E0(u32);
void text_obj_set_enabled(u32);

/* Clears the text objects first..first+count-1 (through func_8005A6E0), then
 * calls text_obj_set_enabled for the object at first+offset. */
void func_8005A3BC(int first, int count, int offset) {
    int i;
    for (i = 0; i < count; i++) {
        func_8005A6E0(first + i);
    }
    text_obj_set_enabled(first + offset);
}
