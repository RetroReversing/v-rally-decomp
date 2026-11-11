s32 osPiGetCmdQueue();
s32 osSendMesg();
s32 osJamMesg();
extern s32 __osPiInitialized;

/* Fills in a PI DMA request message (type, priority, device and DRAM addresses, size, handle) and
 * queues it on the PI command queue: a jam for high-priority requests (priority 1), a send
 * otherwise. Direction 0 is a read from the cartridge, anything else a write. Returns -1 when the
 * PI manager is not initialised. */
s32 osPiStartDma(u8 *mb, s32 priority, s32 direction, s32 devAddr, s32 dramAddr, s32 size, s32 handle) {
    s16 v;

    if (__osPiInitialized == 0) {
        return -1;
    }
    v = 0xC;
    if (direction == 0) {
        v = 0xB;
    }
    *(s16 *)mb = v;
    *(s8 *)(mb + 2) = priority;
    *(s32 *)(mb + 4) = handle;
    *(s32 *)(mb + 8) = dramAddr;
    *(s32 *)(mb + 0xC) = devAddr;
    *(s32 *)(mb + 0x10) = size;
    *(s32 *)(mb + 0x14) = 0;
    if (priority != 1) {
        return osSendMesg(osPiGetCmdQueue(dramAddr), mb, 0);
    }
    return osJamMesg(osPiGetCmdQueue(dramAddr), mb, 0);
}
