extern s32 gGameState;
s32 print_flush_buffer(s32);
#ifdef PORT
s32 format_vargs(s32 *, const char *, va_list);
#else
s32 format_vargs(s32 *, s32, s32 *);
#endif

/* Formats a printf-style string into a 128-character stack buffer through the shared
 * formatter, then flushes the buffer with print_flush_buffer(0). Returns the formatter's count. */
#ifdef PORT
s32 debug_sprintf_128(const char *fmt, ...)
#else
s32 debug_sprintf_128(s32 fmt, ...)
#endif
{
    s32 buf[32];
    s32 count;
#ifndef PORT
    s32 *args;
#endif

    *(s32 *)((char *)&gGameState + 0x6B10) = 0x80;
    *(s32 *)((char *)&gGameState + 0x6B14) = 1;
    *(s32 **)((char *)&gGameState + 0x6B1C) = buf;
    *(s32 **)((char *)&gGameState + 0x6B18) = buf;
#ifdef PORT
    {
        va_list ap;
        va_start(ap, fmt);
        count = format_vargs(buf, fmt, ap);
        va_end(ap);
    }
#else
    args = (s32 *)__builtin_next_arg(fmt);
    count = format_vargs(buf, fmt, args);
#endif
    print_flush_buffer(0);
    return count;
}
