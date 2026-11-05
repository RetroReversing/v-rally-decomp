#include "decompdecomp_snapshot_8005a744.h"
#line 1 "func.c"
void *func_8005A744(u32 count, void *head) { u32 before; goto check; loop: head=*(void **)head; check: before=count; count--; if(before) goto loop; return head; }

