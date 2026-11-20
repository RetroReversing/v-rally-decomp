#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
/* Sets the enable byte (+0x1A) of the text object with the given index. */
void *textObjGet(u32);

void func_8005A6BC(u32 index)
{
    *(s8 *)((s8 *)textObjGet(index) + 0x1A) = 1;
}

