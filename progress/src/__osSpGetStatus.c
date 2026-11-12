/* Reads the RSP status register (SP_STATUS at 0xA4040010). */
u32 __osSpGetStatus(void) { return *(vu32 *)0xA4040010; }
