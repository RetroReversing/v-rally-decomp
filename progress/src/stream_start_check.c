s32 stream_buffers_ready();
s32 func_8007FA70();
s32 func_80080070();
s32 func_80081030();

/* Runs the stream prep step, then returns 1 only when the stream buffers are ready
 * and the second check passes. */
s32 stream_start_check(void) {
    s32 result;

    func_80080070();
    result = 0;
    if (stream_buffers_ready() != 0) {
        result = 0;
        if (func_8007FA70() != 0) {
            result = func_80081030() != 0;
        }
    }
    return result;
}
