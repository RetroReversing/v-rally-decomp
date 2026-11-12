extern void *gSelectState;

/* Copies the select-state byte from obj+0xDC and sets the select-state timer at 0x222:
 * 0 if obj has its flag at 0x90 set, otherwise 0xC0. */
void func_80058190(void *obj) {
    if (*(s32 *)((char *)obj + 0x90) != 0) {
        *(s16 *)((char *)gSelectState + 0x222) = 0;
    } else {
        *(s16 *)((char *)gSelectState + 0x222) = 0xC0;
    }
    *(s8 *)((char *)gSelectState + 0x24C) = (s8)*(s32 *)((char *)obj + 0xDC);
}
