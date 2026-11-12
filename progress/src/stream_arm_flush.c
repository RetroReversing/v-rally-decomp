s32 flag_set_then_call();
s32 poolAllocHeadNode();
extern char gOrderState[];
extern int gStreamHeadNode;
extern s32 stream_flush_if_pending;

/* Allocates the stream head node and arms the deferred flush: flag_set_then_call sets the
 * pending flag at gOrderState+0x7380 and registers stream_flush_if_pending to run when it is handled. */
void stream_arm_flush(void) {
    gStreamHeadNode = poolAllocHeadNode();
    flag_set_then_call(gOrderState + 0x7380, &stream_flush_if_pending);
}
