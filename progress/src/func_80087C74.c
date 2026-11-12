/* Clears the flag byte at 0xCD and the word at 0x64 of obj, then returns arg (pass-through). */
s32 func_80087C74(void *obj, s32 arg) {
    *(s8 *)((s8 *)obj + 0xCD) = 0;
    *(s32 *)((s8 *)obj + 0x64) = 0;
    return arg;
}
