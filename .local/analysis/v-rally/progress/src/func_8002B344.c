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

char *func_8002B344(char *p, char *end, char *name, s8 *found)
{
    char *q;

    do {
        do {
            p = func_8002B180(p, end);
            if (!(p < end)) break;
            if (*p == '[') break;
            SKIP_LINE(p, end);
        } while (p < end);
        if (!(p < end)) break;
        p++;
        q = p;
        while (*q != ']' && q < end) q++;
        if (!(p < end)) break;
        *q = 0;
        if (!str_differs(p, name)) {
            *found = 1;
            SKIP_LINE(p, end);
            return p;
        }
        SKIP_LINE(p, end);
    } while (p < end);
    *found = 0;
    return 0;
}
