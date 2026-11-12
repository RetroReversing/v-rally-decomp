/* Marks the byte at offset 0xAF of obj as 1 and returns the value passed in. */
s32 func_80087CC4(void *obj, s32 value) {
    *(s8 *)((s8 *)obj + 0xAF) = 1;
    return value;
}
