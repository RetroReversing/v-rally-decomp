#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
/* Follows the first-word link of a singly linked list 'steps' times and returns the node reached. */
void *func_8005A744(u32 steps, void *node)
{
    u32 before;
    goto check;
loop:
    node = *(void **)node;
check:
    before = steps;
    steps--;
    if (before)
    {
        goto loop;
    }
    return node;
}

