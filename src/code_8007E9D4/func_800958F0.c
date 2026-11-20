#include "decompdecomp_sync_6700660849154e9b2c27.h"
#line 1 "func.c"
/* Set the MIPS compare register to the specified value */
#ifdef PORT
/* No CP0 Compare register on a PC: the write is dropped (a stub). */
void func_800958F0(unsigned int compareValue) { (void)compareValue; }
#else
void func_800958F0(unsigned int compareValue) { __builtin_mips_write_compare(compareValue); }
#endif

