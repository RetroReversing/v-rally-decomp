/* Returns the CPU Count register, which ticks at half the CPU clock. */
#ifdef PORT
/* No CP0 Count register on a PC: the port reports a fixed 0 (a stub). */
unsigned int osGetCount(void) { return 0; }
#else
unsigned int osGetCount(void) { return __builtin_mips_read_count(); }
#endif
