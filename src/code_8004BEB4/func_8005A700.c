#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
/* Sets the +0x41 flag byte of the select list's head node (the node at select_get_entry(index)) to 1. */
extern void *select_get_entry(u32 index);

void func_8005A700(u32 index) {
    ((s8 *)select_get_entry(index))[0x41] = 1;
}

