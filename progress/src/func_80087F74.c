/* Clears the byte at +0xC6 of obj and returns value unchanged. */ s32 func_80087F74(void *obj, s32 value) {
    *(u8 *)((u8 *)obj + 0xC6) = 0;
    return value;
}
