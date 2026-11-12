extern char *fmt_buf_pos;
extern char *D_800ADEFC;
extern s32 D_800ADEF4;
extern s32 fmt_buf_left;
s32 str_last_char();
s32 print_putc();

/* Resets the output cursor fmt_buf_pos and writes arg0 after the text in D_800ADEFC. In mode 2 the text
 * is handed to str_last_char whole; otherwise each character goes through print_putc. The byte
 * after the text is then the marker 0x7F, followed by arg0. */
void print_flush_buffer(s32 arg0)
{
    char *ch;
    char *text;
    u8 c;

    *fmt_buf_pos = 0;
    if (D_800ADEF4 == 2)
    {
        fmt_buf_pos = D_800ADEFC;
        str_last_char(D_800ADEFC);
    }
    else
    {
        text = D_800ADEFC;
        fmt_buf_pos = text;
        ch = text;
        c = *(u8 *) ch;
        if (*ch != 0)
        {
            do
            {
                ch += 1;
                print_putc((s8) c);
                c = *(u8 *) ch;
            }
            while (*ch != 0);
        }
    }
    fmt_buf_left = 0x7F;
    fmt_buf_pos = fmt_buf_pos + 1;
    *(fmt_buf_pos - 1) = arg0;
}
