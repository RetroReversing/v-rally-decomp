#include "decompdecomp_sync_22b16d56d88b95a7fc91.h"
#line 1 "func.c"
/* Returns the CPU Count register, which ticks at half the CPU clock. */
#ifdef PORT
/* No CP0 Count register on a PC: the port reports a fixed 0 (a stub). */
unsigned int func_800937B0(void) { return 0; }
#else
unsigned int func_800937B0(void) { return __builtin_mips_read_count(); }
#endif

