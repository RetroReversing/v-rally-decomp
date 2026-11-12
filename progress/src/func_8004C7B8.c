s32 stream_release_list(s32);
s32 heapReleaseBlock(s32);
extern s32 gStreamList;

/* Releases the stream list and its heap block, then clears the handle. */
void func_8004C7B8(void) {
    stream_release_list(gStreamList);
    heapReleaseBlock(gStreamList);
    gStreamList = 0;
}
