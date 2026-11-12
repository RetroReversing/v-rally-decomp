/* Sets the select-screen defaults in gSelectState: two u8 fields to 1 and 2, and copies the s32 at +0x290 into +0x294. */
extern void *gSelectState;

void selectStateSetDefaults(void) {
    *(s8 *)((char *)gSelectState + 0x29A) = 1;
    *(s8 *)((char *)gSelectState + 0x2BA) = 2;
    *(s32 *)((char *)gSelectState + 0x294) = (s32)*(s32 *)((char *)gSelectState + 0x290);
}
