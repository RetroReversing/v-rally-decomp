extern s32 gGameState;
s32 print_flush_buffer(s32);
#ifdef PORT
s32 format_vargs(int, const char *, va_list);
#else
s32 format_vargs(s32 *, s32, s32 *);
#endif

/* printf-style formatting into a 128-byte buffer in the print state block
   (gGameState): sets the buffer size, mode 2 and the buffer pointers, formats
   the arguments through format_vargs, then flushes with print_flush_buffer. */
#ifdef PORT
s32 debug_printf(const char *fmt, ...)
#else
s32 debug_printf(s32 fmt, ...)
#endif
{
    s32 buf[32];
    s32 ret;
    #ifdef PORT
    va_list ap;
#else
    s32 *args;
#endif

    *(s32 *)((char *)&gGameState + 0x6B10) = 0x80;
    *(s32 *)((char *)&gGameState + 0x6B14) = 2;
    *(s32 **)((char *)&gGameState + 0x6B1C) = buf;
    *(s32 **)((char *)&gGameState + 0x6B18) = buf;
    #ifdef PORT
    va_start(ap, fmt);
    ret = format_vargs((int)(uintptr_t)buf, fmt, ap);
    va_end(ap);
#else
    args = (s32 *)__builtin_next_arg(fmt);
        ret = format_vargs(buf, fmt, args);
#endif
    print_flush_buffer(0);
    return ret;
}
