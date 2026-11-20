#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
void strCpy();

/* Copy a label string into the item's label field at offset 0x10. */
void func_800424A4(void *item_ptr, void *src_label) {
    strCpy((unsigned char *)item_ptr + 0x10, src_label);
}

