extern char *D_800ADEF8;
extern char *D_800ADEFC;
extern s32 D_800ADEF4;
extern s32 D_800ADEF0;
s32 str_last_char();
s32 func_8009A630();

/* Resets the output cursor D_800ADEF8 and writes arg0 after the text in D_800ADEFC. In mode 2 the text
 * is handed to str_last_char whole; otherwise each character goes through func_8009A630. The byte
 * after the text is then the marker 0x7F, followed by arg0. */
void print_flush_buffer(s32 arg0)
{
    char *ch;
    char *text;
    u8 c;

    *D_800ADEF8 = 0;
    if (D_800ADEF4 == 2)
    {
        D_800ADEF8 = D_800ADEFC;
        str_last_char(D_800ADEFC);
    }
    else
    {
        text = D_800ADEFC;
        D_800ADEF8 = text;
        ch = text;
        c = *(u8 *) ch;
        if (*ch != 0)
        {
            do
            {
                ch += 1;
                func_8009A630((s8) c);
                c = *(u8 *) ch;
            }
            while (*ch != 0);
        }
    }
    D_800ADEF0 = 0x7F;
    D_800ADEF8 = D_800ADEF8 + 1;
    *(D_800ADEF8 - 1) = arg0;
}
