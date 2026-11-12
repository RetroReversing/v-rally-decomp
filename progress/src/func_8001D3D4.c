void func_8001D458(void);
extern s32 stream_state;

/* Runs the step func_8001D458 when the stream state field at 0x32AA is below 2. */
void func_8001D3D4(void) {
    if ((u32)*(u32 *)((s8 *)&stream_state + 0x32AA) < 2U) {
        func_8001D458();
    }
}
