#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
void *poolAlloc(s32, s32, ...);
s32 memset(void *, s32, u32);
void listAppendNode(void *, void *);

/* Allocates a zeroed node of `size` bytes from pool 6 and appends it to the list. */
void *func_800802A0(void *list, s32 size) {
    void *node;
    node = (void *)poolAlloc(6, size);
    memset(node, 0, (u32)size);
    listAppendNode(node, list);
    return node;
}

