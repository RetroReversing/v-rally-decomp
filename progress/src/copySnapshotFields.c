extern void *gSnapshotBlock;

/* Copies four one-byte fields from src (offsets 0x90, 0xDC, 0x128, 0x174) into the
 * snapshot block at 0x90..0x93, when the block exists. */
void copySnapshotFields(void *src) {
    if (gSnapshotBlock != NULL) {
        *(s8 *)((s8 *)gSnapshotBlock + 0x90) = (s8) *(s32 *)((s8 *)src + 0x90);
        *(s8 *)((s8 *)gSnapshotBlock + 0x91) = (s8) *(s32 *)((s8 *)src + 0xDC);
        *(s8 *)((s8 *)gSnapshotBlock + 0x92) = (s8) *(s32 *)((s8 *)src + 0x128);
        *(s8 *)((s8 *)gSnapshotBlock + 0x93) = (s8) *(s32 *)((s8 *)src + 0x174);
    }
}
