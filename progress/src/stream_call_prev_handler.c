extern void (*gPrevStreamHandler)(void);

/* Calls the stream handler that was installed before the current one. */
void stream_call_prev_handler(void) {
    gPrevStreamHandler();
}
