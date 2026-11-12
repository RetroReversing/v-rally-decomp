/* Clears the s16 at offset 0x84 and sets the s16 at 0x86 to 150 (0x96). */
void func_80012294(void *obj) {
    *(s16 *)((s8 *)obj + 0x84) = 0;
    *(s16 *)((s8 *)obj + 0x86) = 0x96;
}
