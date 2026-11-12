extern void *gSelectState;

/* Steps the select screen index at +0x22F up by one, stopping at the limit stored at +0x230. */
s32 select_bump_index(void) {
    u8 index;

    index = *(u8 *)((s8 *)gSelectState + 0x22F);
    if (index < (u8) *(u8 *)((s8 *)gSelectState + 0x230)) {
        *(u8 *)((s8 *)gSelectState + 0x22F) = (u8) (index + 1);
    }
    return 0;
}
