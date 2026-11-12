/* Sets FPC CSR register and returns the old value */
#ifdef PORT
unsigned int __osSetFpcCsr(unsigned int value) { return value; }
#else
unsigned int __osSetFpcCsr(unsigned int value) { return __builtin_mips_exchange_fcsr(value); }
#endif
