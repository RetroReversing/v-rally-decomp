extern char gStreamState[];
typedef struct { u8 pad00[0x20]; u16 flags; } VRStreamDev;
#define VR_STREAM_PAUSED 0x40

/* Pauses (arg1 != 0) or resumes the stream device at gStreamState+0x7CD6. On resume, a device that was paused flags the stream object at arg0 as paused-requested (0x2) and clears its pause bit. */
void setStreamPaused(void *arg0, s32 arg1) {
    u16 flags;
    VRStreamDev *dev;

    if (arg1 != 0) {
        dev = *(VRStreamDev **)(gStreamState + 0x7CD6);
        flags = dev->flags;
        flags |= VR_STREAM_PAUSED;
        goto block_4;
    }
    dev = *(VRStreamDev **)(gStreamState + 0x7CD6);
    flags = dev->flags;
    flags &= VR_STREAM_PAUSED;
    if (flags != 0) {
        flags = *(u16 *)((char *)arg0 + 0x68);
        flags |= 2;
        *(u16 *)((char *)arg0 + 0x68) = flags;
        flags = dev->flags;
        flags &= 0xFFBF;
block_4:
        dev->flags = flags;
    }
}
