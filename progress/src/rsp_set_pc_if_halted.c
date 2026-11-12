/* Sets the RSP program counter (SP_PC) to pc, but only while the RSP is halted (SP_STATUS bit 0); returns -1 otherwise. */
s32 rsp_set_pc_if_halted(s32 pc) {
    s32 ret;

    if (*(vu32 *)0xA4040010 & 1) {
        *(vs32 *)0xA4080000 = pc;
        ret = 0;
    } else {
        ret = -1;
    }
    return ret;
}
