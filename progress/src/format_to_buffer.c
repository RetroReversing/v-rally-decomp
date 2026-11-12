extern char gGameState[];
#ifdef PORT
s32 format_vargs(char *, const char *, va_list);
#else
s32 format_vargs(char *, s32, s32 *);
#endif
/* sprintf-style formatter: writes the formatted text into dst through the shared print state, then NUL-terminates it. */
void format_to_buffer(char *dst, const char *fmt, ...) {
    /* print state: remaining-count = -1 (unbounded), buffer start and cursor = dst */
    *(s32 *)(gGameState+0x6B10)=-1;
    *(char **)(gGameState+0x6B1C)=dst;
    *(char **)(gGameState+0x6B18)=dst;
#ifdef PORT
    {
        va_list ap;
        va_start(ap, fmt);
        dst+=format_vargs(dst,fmt,ap);
        va_end(ap);
    }
#else
    {
        s32 *ap;
        ap=(s32 *)__builtin_next_arg(fmt);
        dst+=format_vargs(dst,(s32)fmt,ap);
    }
#endif
    *dst=0;
}
