s32 copyStringAligned(void *, s32);
extern void *gSelectState;

/* Copies `text` into the select state's text buffer at +0x2A1, marks it dirty (+0x29C) and
 * clears the three handler slots at +0x288, +0x28C and +0x290. */
void selectSetText(s32 text) {
    *(s8 *)((u8 *)gSelectState + 0x29C) = 1;
    copyStringAligned((u8 *)gSelectState + 0x2A1, text);
    *(s32 *)((u8 *)gSelectState + 0x288) = 0;
    *(s32 *)((u8 *)gSelectState + 0x28C) = 0;
    *(s32 *)((u8 *)gSelectState + 0x290) = 0;
}
