extern char D_800A73E0[];
s32 func_8009912C(char *, s32, s32 *);
/* sprintf-style formatter: writes the formatted text into dst through the shared print state, then NUL-terminates it. */
void format_to_buffer(char *dst, const char *fmt, ...) {
    s32 *ap;
    /* print state: remaining-count = -1 (unbounded), buffer start and cursor = dst */
    *(s32 *)(D_800A73E0+0x6B10)=-1;
    *(char **)(D_800A73E0+0x6B1C)=dst;
    *(char **)(D_800A73E0+0x6B18)=dst;
    ap=(s32 *)__builtin_next_arg(fmt);
    dst+=func_8009912C(dst,(s32)fmt,ap);
    *dst=0;
}
