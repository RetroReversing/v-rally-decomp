void func_8001D1A4(void);
extern s32 stream_state;

/* Runs the step func_8001D1A4 when the stream state field at 0x32AA is 3. */
void func_8001D178(void) {
    if (*(s32 *)((s8 *)&stream_state + 0x32AA) == 3) {
        func_8001D1A4();
    }
}
