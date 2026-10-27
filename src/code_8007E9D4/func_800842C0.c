#include "common.h"

s32 func_8007EE9C(void *);
s32 func_800842C0(s32 arg0) {
    register s32 next;
    void *p = (void *)arg0;
    if (p != 0) {
        do {
            p = (void *)((u8 *)p - 8);
            next = *(s32 *)((u8 *)p + 4);
            func_8007EE9C(p);
            p = (void *)next;
        } while (p != 0);
    }
    return 0;
}
