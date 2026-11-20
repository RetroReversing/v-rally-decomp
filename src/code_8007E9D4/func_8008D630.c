#include "decompdecomp_sync_5587969387644355bbe3.h"
#line 1 "func.c"
/* Sets FPC CSR register and returns the old value */
#ifdef PORT
unsigned int func_8008D630(unsigned int value) { return value; }
#else
unsigned int func_8008D630(unsigned int value) { return __builtin_mips_exchange_fcsr(value); }
#endif

