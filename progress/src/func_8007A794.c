s32 streamReleaseEntry();
extern void *gSelectState;

/* Releases the stream entry stored at gSelectState+0x1E4, if any, and clears the slot. */
void func_8007A794(void) {
    s32 entry;

    entry = *(s32 *)((char *)gSelectState + 0x1E4);
    if (entry != 0) {
        streamReleaseEntry(entry);
        *(s32 *)((char *)gSelectState + 0x1E4) = 0;
    }
}
