/* Stores value at offset 0x2C of obj. */
void func_80005830(void *obj, s32 value) {
    *(s32 *)((s8 *)obj + 0x2C) = value;
}
