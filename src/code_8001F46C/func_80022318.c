#include "common.h"

s32 func_8001B730(void *a0);
s32 func_80098180(void *a0, void *a1);
s32 func_80098290(void *a0);

void *func_80022318(void **arg0) {
    s32 buf[4];
    void *node;

    func_80098290(buf);
    func_8001B730(buf);
    node = *arg0;
    if (node != NULL) {
        do {
            if (func_80098180(*(void **)((u8 *)node + 0xC), buf) == 0) {
                return node;
            }
            node = *(void **)((u8 *)node + 4);
        } while (node != NULL);
    }
    return NULL;
}
