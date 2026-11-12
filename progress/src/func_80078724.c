s32 D_80078760();
void results_screen_draw();
extern char stream_state[];

/* Draws the results panel while the stream state byte at +0x7F4F is 5; otherwise runs the results-screen draw. */
void func_80078724(void) {
    if (*(u8 *)(stream_state + 0x7F4F) != 5) {
        results_screen_draw();
        return;
    }
    D_80078760();
}
