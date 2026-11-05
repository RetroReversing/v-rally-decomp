#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
char *func_8002B180(char *p, char *end)
{
    s32 c;

    while (({ s32 t=p<end; if (!t) return end; t; })) {
        top:
        c = *p;
        if (c == '\r') {
            do {
                while (*p++ != '\r') {
                    if (!(p < end)) break;
                }
                if (p == end) break;
                p++;
            } while (*p == '\r');
            continue;
        }
        if (c == '#' || (c == '/' && p + 1 < end && p[1] == c)) {
            do {
                while (*p++ != '\r') {
                    if (!(p < end)) break;
                }
                if (p == end) break;
                p++;
            } while (*p == '\r');
            continue;
        }
        {
            s32 c2 = *p;
            if (c2 == ' ' || c2 == '\t' || c2 == ',') {
                c2 = *p;
                while (c2 == ' ' || c2 == '\t' || c2 == ',') {
                    if (!(p < end)) break;
                    c2 = *++p;
                }
            } else {
                return p;
            }
        }
    }
    return end;
}

