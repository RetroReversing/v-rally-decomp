/* Writes value to the RSP status register (SP_STATUS at 0xA4040010). */
void sp_status_write(unsigned int value) {
    *(volatile unsigned int *)0xA4040010 = value;
}
