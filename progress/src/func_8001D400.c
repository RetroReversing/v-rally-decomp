void func_8001D458(void);
extern s32 stream_state;

/* Runs the step func_8001D458 when the stream state field at 0x32AA is 2. */
void func_8001D400(void) {
    if (*(s32 *)((s8 *)&stream_state + 0x32AA) == 2) {
        func_8001D458();
    }
}
