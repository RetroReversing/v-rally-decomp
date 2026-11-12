extern void order_ticker_init(void);
extern s32 stream_init_pools(void);

/* Initialises the order ticker, then the stream pools. */
void order_stream_init(void) {
    order_ticker_init();
    stream_init_pools();
}
