/* Runs the per-frame car update, but only while the stream's state word at 0xE is below 3. */
extern char stream_state[];
void func_8002F7D8(void);

void race_update_cars_gated(void)
{
    if (*(u16 *)((s8 *)*(void **)(stream_state + 0x32F2) + 0xE) < 3U) {
        func_8002F7D8();
    }
}
