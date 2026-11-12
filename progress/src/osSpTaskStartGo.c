s32 sp_status_busy(void);
void sp_status_write(u32 value);

/* Starts the RSP: waits until it is no longer halted or busy, then writes 0x125 to SP_STATUS. */
void osSpTaskStartGo(void) {
    do {

    } while (sp_status_busy() != 0);
    sp_status_write(0x125);
}
