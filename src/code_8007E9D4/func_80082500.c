#include "common.h"

s32 func_80082350();

void *func_80082500(void *arg0, s32 arg1) {
    u32 off;
    s32 n;
    s32 *p;
    void *r;

    if (func_80082350(arg1, arg0) != 0) {
        return arg0;
    }
    n = *(s32 *)((char *)arg0 + 0x10);
    if (n > 0) {
        off = n << 2;
        p = (s32 *)(off + (u32)arg0);
        do {
            r = func_80082500((void *)p[5], arg1);
            if (r != NULL) {
                return r;
            }
            n--;
            p--;
        } while (n > 0);
    }
    return NULL;
}
