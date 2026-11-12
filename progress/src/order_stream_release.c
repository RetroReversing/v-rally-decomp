/* Frees the stream object and releases the stream entry in gOrderState, then clears the entry slot. */
extern char gOrderState[];
s32 stream_obj_free(s32);
s32 streamReleaseEntry(s32);

void order_stream_release(void) {
    stream_obj_free(*(s32 *)(gOrderState + 0x1D00));
    streamReleaseEntry(*(s32 *)(gOrderState + 0x1200));
    *(s32 *)(gOrderState + 0x1200) = 0;
}
