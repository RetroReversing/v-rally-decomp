#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
void *select_get_entry(u32);

/* Stores value into the byte at offset 0x42 of the select entry for index. */
void func_8005A764(char value, int unused, int index)
{
  ((u8 *)select_get_entry(index))[0x42] = value;
}

