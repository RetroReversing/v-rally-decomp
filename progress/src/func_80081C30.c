extern u8 stream_state[];
s32 order_sync_stream_pos(void);
s32 order_stream_next_byte(void);
void func_80083B40(void);
void huftFreeTables(void);
void func_80081D8C(void);

/* Stream read/transfer entry point: clears the three stream counters, runs the setup in
 * order_sync_stream_pos, then dispatches on the stream mode (labels follow jtbl_800A6CC8). Mode 0
 * copies bytes until the -1 end marker; mode 8 runs two helpers; modes 1-6 just finish; mode 7 and
 * modes above 8 fail. Returns 0 on success, -1 on failure. */
s32 func_80081C30(void) {
    u32 ch;
    u8 **dst;
    s32 *remaining;
    *(s32 *)(stream_state + 0x309A) = 0;
    *(s32 *)(stream_state + 0x3096) = 0;
    *(s32 *)(stream_state + 0x309E) = 0;
    order_sync_stream_pos();
    switch (*(u16 *)(stream_state + 0x30BC)) {
    case 0:
        { u8 **p = (u8 **)(stream_state + 0x30F2); remaining = (s32 *)((u8 *)p - 0x60); dst = p; }
        *dst = *(u8 **)(stream_state + 0x30EA);
        for (;;) {
            if (--*remaining >= 0) {
                u8 *src = *(u8 **)(remaining - 1);
                *(u8 **)(remaining - 1) = src + 1;
                ch = *src; } else { ch = order_stream_next_byte(); }
            if (ch == -1) break;
            *(*dst)++ = ch;
        }
        func_80081D8C();
        return 0;
    case 8:
        func_80083B40(); huftFreeTables(); goto done;
    case 1: case 2: case 3: case 4: case 5: case 6: goto done;
    case 7: goto fail;
    default: goto fail;
    }
fail: func_80081D8C(); return -1;
done: func_80081D8C(); return 0;
}
