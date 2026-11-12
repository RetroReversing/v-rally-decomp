/* Returns the field at offset 0x6 minus the field at offset 0x7A of obj. */
s32 func_80006050(void *obj) {
    return *(u16 *)((s8 *)obj + 6) - *(u16 *)((s8 *)obj + 0x7A);
}
