void *select_get_entry(u32);
extern void *gSelectState;

/* Sets the select state's flag at +0x24E, then writes a code to field +8 of
 * entry 0: 0x1AB if the flag at +0x228 is set, otherwise 0x1A4. */
void func_80069648(void) {
    s16 code;
    void *entry;

    *(s8 *)((u8 *)gSelectState + 0x24E) = 1;
    entry = select_get_entry(0);
    code = 0x1A4;
    if (*(s8 *)((u8 *)gSelectState + 0x228) != 0) {
        code = 0x1AB;
    }
    *(s16 *)((u8 *)entry + 8) = code;
}
