/* Returns the counter value word (offset 0x68) of the counter block that obj points to at offset 0x5C. */
s32 getCounterValue(void *obj) {
    return *(s32 *)((s8 *)*(void **)((s8 *)obj + 0x5C) + 0x68);
}
