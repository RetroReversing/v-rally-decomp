extern char stream_state[];
s32 pool_alloc_cleared_node(void);

/* Allocates the stream head node and stores its pointer at stream_state+0x6C5E. */
void stream_init_head_node(void) {
    *(s32 *)(stream_state + 0x6C5E) = pool_alloc_cleared_node();
}
