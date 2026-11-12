void order_state_init();
void stream_init_head_node();
void stream_alloc_record();
void streamCtlReset();
extern char gOrderState[];
extern char stream_state[];

/* Re-initialises the order and stream state, then clears the 16-bit fields at
 * stream_state+0x6C62 and gOrderState+0x7302. */
void func_80040770(void) {
    order_state_init();
    stream_init_head_node();
    stream_alloc_record();
    streamCtlReset();
    *(s16 *)(stream_state + 0x6C62) = 0;
    *(s16 *)(gOrderState + 0x7302) = 0;
}
