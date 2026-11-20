#include "decompdecomp_sync_d7c61faab5cad10e9d78.h"
#line 1 "func.c"
/* Returns the current CP0 Status register value. */
#ifdef PORT
unsigned int func_800937C0(void) { return 0; }
#else
unsigned int func_800937C0(void) { return __builtin_mips_read_status(); }
#endif

