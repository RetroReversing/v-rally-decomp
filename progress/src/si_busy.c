int si_busy(void) { return (*(volatile unsigned int *)0xA4800018 & 3) != 0; }
