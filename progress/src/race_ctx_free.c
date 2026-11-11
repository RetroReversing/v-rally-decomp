s32 stream_obj_free(s32);
s32 func_8004C7B8();
s32 func_800578E0(s32);
void heapFreeBlock(void *);
s32 heap_free_stub(s32);
extern void *gRaceCtx;
extern s32 gStreamState;

/* Frees the race context: its two owned blocks (+0 and +4), the block itself,
 * then the stream object at gStreamState+0x807A, and clears gRaceCtx. */
void race_ctx_free(void) {
    heap_free_stub(*(s32 *)((s8 *)gRaceCtx + 0));
    stream_obj_free(*(s32 *)((s8 *)gRaceCtx + 4));
    heapFreeBlock(gRaceCtx);
    gRaceCtx = NULL;
    func_800578E0(*(s32 *)((s8 *)&gStreamState + 0x807A));
    func_8004C7B8();
}
