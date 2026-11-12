/* Clears the flag byte at 0xCF of obj, then returns arg (pass-through). */
s32 func_80087DD8(void *obj, s32 arg) {
    *(s8 *)((s8 *)obj + 0xCF) = 0;
    return arg;
}
