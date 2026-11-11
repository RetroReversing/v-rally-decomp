extern char gStreamState[];
typedef struct { s16 modeA, modeB, modeC, modeD, posE, posF, posG; u8 pad0E[2]; s32 tail; } VRStreamCtl;

/* Resets the stream control block at gStreamState+0x329A to its default modes and zeroes its counters. */
void streamCtlReset(void) {
    VRStreamCtl *ctl = (VRStreamCtl *)(gStreamState + 0x329A);
    ctl->modeA = 4;
    ctl->modeB = 4;
    ctl->modeC = 2;
    ctl->modeD = 5;
    ctl->posG = 0;
    ctl->posE = 0;
    ctl->posF = 0;
    ctl->tail = 0;
}
