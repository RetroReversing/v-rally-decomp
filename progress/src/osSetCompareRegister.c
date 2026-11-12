/* Set the MIPS compare register to the specified value */
#ifdef PORT
/* No CP0 Compare register on a PC: the write is dropped (a stub). */
void osSetCompareRegister(unsigned int compareValue) { (void)compareValue; }
#else
void osSetCompareRegister(unsigned int compareValue) { __builtin_mips_write_compare(compareValue); }
#endif
