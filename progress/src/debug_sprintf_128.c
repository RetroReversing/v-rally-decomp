extern s32 D_800A73E0;
s32 print_flush_buffer(s32);
s32 func_8009912C(s32 *, s32, s32 *);

/* Formats a printf-style string into a 128-character stack buffer through the shared
 * formatter, then flushes the buffer with print_flush_buffer(0). Returns the formatter's count. */
s32 debug_sprintf_128(s32 fmt, ...)
{
    s32 buf[32];
    s32 count;
    s32 *args;

    *(s32 *)((char *)&D_800A73E0 + 0x6B10) = 0x80;
    *(s32 *)((char *)&D_800A73E0 + 0x6B14) = 1;
    *(s32 **)((char *)&D_800A73E0 + 0x6B1C) = buf;
    *(s32 **)((char *)&D_800A73E0 + 0x6B18) = buf;
    args = (s32 *)__builtin_next_arg(fmt);
    count = func_8009912C(buf, fmt, args);
    print_flush_buffer(0);
    return count;
}
