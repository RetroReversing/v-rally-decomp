/* Clears the byte at offset 0xCE of obj and returns value unchanged. */
s32 func_80087DBC(void *obj, s32 value) {
    *(s8 *)((s8 *)obj + 0xCE) = 0;
    return value;
}
