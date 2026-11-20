#include "decompdecomp_sync_609e936c2b660ff12377.h"
#line 1 "func.c"
/* Writes the CP0 status register through the compiler's status-write builtin. */ void func_8008D6E0(int status) {
#ifdef PORT
    (void) status;
#else
    __builtin_mips_write_status_return_spacing(status);
#endif
}

