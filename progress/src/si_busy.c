/* Returns non-zero while the SI controller has a DMA or IO operation in progress (SI_STATUS bits 0-1). */ int si_busy(void) { return (*(volatile unsigned int *)0xA4800018 & 3) != 0; }
