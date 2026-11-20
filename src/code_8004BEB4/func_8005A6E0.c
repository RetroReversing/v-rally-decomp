#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
void *textObjGet(u32 index);

/* Clears the +0x1A flag byte of text object `index` (looked up with textObjGet). */
void func_8005A6E0(u32 index) {
    ((s8 *)textObjGet(index))[0x1A] = 0;
}

