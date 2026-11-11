/* Sets the defaults in the sub-state block at obj+0x44 (flags at +0 and +4 set to 1, counters at
 * +8, +0xC, +0x20, +0x24 cleared, +0x28 set to -1) and clears the word at +0x38 of the block at obj+0x9C. */
void initObjectSubState(void *obj) {
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x44) + 0x28) = -1;
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x44) + 0) = 1;
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x44) + 4) = 1;
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x44) + 8) = 0;
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x44) + 0xC) = 0;
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x44) + 0x20) = 0;
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x44) + 0x24) = 0;
    *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x9C) + 0x38) = 0;
}
