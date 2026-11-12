extern s32 gSnapIndex;

/* Stores the s32 value at offset 0x90 of obj into gSnapIndex. */
void func_8002FF94(void *obj) {
    gSnapIndex = *(s32 *)((u8 *)obj + 0x90);
}
