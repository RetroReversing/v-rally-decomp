/* Returns the current CP0 Status register value. */
#ifdef PORT
unsigned int cpuGetStatus(void) { return 0; }
#else
unsigned int cpuGetStatus(void) { return __builtin_mips_read_status(); }
#endif
