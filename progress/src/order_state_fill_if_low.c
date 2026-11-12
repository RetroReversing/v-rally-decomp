void func_8001D1A4();
extern char stream_state[];

/* Creates the next order-state node while the stream's counter at +0x32AA is below 2. */
void order_state_fill_if_low(void) {
    if (*(u32 *)(stream_state + 0x32AA) < 2U) {
        func_8001D1A4();
    }
}
