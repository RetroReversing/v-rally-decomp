/* Sets the s16 field at offset 0x14 of obj to value. */
void func_800056F4(void *obj, s16 value) {
    *(s16 *)((s8 *)obj + 0x14) = value;
}
