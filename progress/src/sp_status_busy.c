/* Returns nonzero while the RSP DMA or I/O path is busy (SP_STATUS bits 0x1C). */ int sp_status_busy(void) { return (*(volatile unsigned int *)0xA4040010 & 0x1C) != 0; }
