/* Recomputes the object's limit at +0x50: INT_MAX when the flag at +0x92 is 0x7FFF,
 * otherwise a base at +0x3C (or +0x38) moved by the step at +0xAA (or +0xAC), in 256ths.
 * Then sets the flag at +0xBB and copies two status bytes into +0xBC and +0xBD. */
void func_80089298(char *obj)
{
    u16 step;

    if (*(u16 *)(obj + 0x92) != 0x7FFF) {
        step = *(u16 *)(obj + 0xAA);
        if (step != 0) {
            *(s32 *)(obj + 0x50) = *(s32 *)(obj + 0x3C) + (step << 8);
        } else {
            *(s32 *)(obj + 0x50) = *(s32 *)(obj + 0x38) - (*(u16 *)(obj + 0xAC) << 8);
        }
    } else {
        *(s32 *)(obj + 0x50) = 0x7FFFFFFF;
    }
    *(s8 *)(obj + 0xBB) = 1;
    *(u8 *)(obj + 0xBC) = *(u8 *)(obj + 0xB8);
    *(u8 *)(obj + 0xBD) = *(u8 *)(obj + 0xB7);
}
