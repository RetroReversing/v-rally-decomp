char *func_8002B180(char *p, char *end);

#define SKIP_LINE(p, end) \
    do { \
        while (*p++ != '\r') { \
            if (!(p < end)) break; \
        } \
        if (p == end) break; \
        p++; \
    } while (*p == '\r')

static inline s32 str_differs(char *a, char *b)
{
    while (*a == *b && *a != 0 && *b != 0) {
        a++;
        b++;
    }
    {
        s32 r = 1;
        if (*a == 0) r = *b != 0;
        return r;
    }
}

/* Scans a CR-separated text block for the section header "[name]". On a match
 * returns a pointer to the first line after the header and sets *found to 1;
 * otherwise returns NULL with *found set to 0. The header's ']' is overwritten
 * with a NUL terminator. */
char *func_8002B344(char *text, char *end, char *name, s8 *found)
{
    char *close;

    do {
        do {
            text = func_8002B180(text, end);
            if (!(text < end)) break;
            if (*text == '[') break;
            SKIP_LINE(text, end);
        } while (text < end);
        if (!(text < end)) break;
        text++;
        close = text;
        while (*close != ']' && close < end) close++;
        if (!(text < end)) break;
        *close = 0;
        if (!str_differs(text, name)) {
            *found = 1;
            SKIP_LINE(text, end);
            return text;
        }
        SKIP_LINE(text, end);
    } while (text < end);
    *found = 0;
    return 0;
}
