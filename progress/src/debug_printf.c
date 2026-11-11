extern s32 D_800A73E0;
s32 print_flush_buffer(s32);
s32 func_8009912C(s32 *, s32, s32 *);

/* printf-style formatting into a 128-byte buffer in the print state block
   (D_800A73E0): sets the buffer size, mode 2 and the buffer pointers, formats
   the arguments through func_8009912C, then flushes with print_flush_buffer. */
s32 debug_printf(s32 fmt, ...)
{
    s32 buf[32];
    s32 ret;
    s32 *args;

    *(s32 *)((char *)&D_800A73E0 + 0x6B10) = 0x80;
    *(s32 *)((char *)&D_800A73E0 + 0x6B14) = 2;
    *(s32 **)((char *)&D_800A73E0 + 0x6B1C) = buf;
    *(s32 **)((char *)&D_800A73E0 + 0x6B18) = buf;
    args = (s32 *)__builtin_next_arg(fmt);
    ret = func_8009912C(buf, fmt, args);
    print_flush_buffer(0);
    return ret;
}
