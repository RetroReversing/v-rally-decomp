s32 stream_buffer_init();
s32 func_8007F910();
s32 func_8007F984();
s32 func_8007F9AC();
s32 func_8007F9D4();
s32 func_8007F9FC();

/* Runs the stream buffer setup steps in order and returns the OR of their results; nonzero means
   a step failed. */
s32 stream_buffers_ready(void) {
    s32 status;

    status = stream_buffer_init();
    status = status | func_8007F910();
    status = status | func_8007F984();
    status = status | func_8007F9AC();
    status = status | func_8007F9D4();
    return status | func_8007F9FC();
}
