s32 crc32_compute();
s32 func_80084AFC();
s32 func_80084B50();
s32 pfs_write_block();
extern s32 gRaceFlags;
extern char gOrderState[];
extern char stream_state[];

/* Saves the race data block to the controller pak unless flag 0x8000 is set.
 * The buffer holds a CRC-32 of the 0x1FC bytes after it, then 64 blocks of
 * 8 bytes are written one at a time. Returns the last write's result. */
s32 save_race_to_pak(void) {
    s32 result;
    s32 block;
    s32 ret;
    void *save;

    ret = gRaceFlags & 0x8000;
    if (ret == 0) {
        save = stream_state + 0x6E22;
        *(s32 *)(stream_state + 0x6E22) = crc32_compute(save + 4, 0x1FC);
        func_80084AFC();
        block = 0;
        do {
            result = pfs_write_block(gOrderState + 0x5A38, block & 0xFF, save + ((block & 0xFFFF) * 8));
            block += 1;
        } while ((u32) (block & 0xFFFF) < 0x40U);
        func_80084B50();
        ret = result;
    }
    return ret;
}
