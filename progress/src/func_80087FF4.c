/* Clears the s32 at offset 0x7C of obj and returns the value passed in. */
s32 func_80087FF4(void *obj, s32 value) {
    *(s32 *)((s8 *)obj + 0x7C) = 0;
    return value;
}
