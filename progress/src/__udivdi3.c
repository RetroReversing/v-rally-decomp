extern unsigned long long func_8009A074(unsigned long long,unsigned long long);
extern unsigned long long func_80099F78(unsigned long long,unsigned long long);
/* 64-bit unsigned divide helper (libgcc __udivdi3): uses the wide-divisor path when the high word of divisor is set, else the narrow path. */
unsigned long long __udivdi3(unsigned long long dividend, unsigned long long divisor) { if (divisor >> 32) return func_80099F78(dividend,divisor); return func_8009A074(dividend,divisor); }
