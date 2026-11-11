typedef struct OSMesgQueue_s OSMesgQueue;
typedef void *OSMesg;

typedef struct {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;

typedef struct {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;

typedef struct {
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;

typedef struct {
    f32 factor;
    u16 offset;
    u32 scale;
} __OSViScale;

typedef struct {
    u16 state;
    u16 retraceCount;
    void *framep;
    OSViMode *modep;
    u32 control;
    OSMesgQueue *msgq;
    OSMesg msg;
    __OSViScale x;
    __OSViScale y;
} __OSViContext;

extern __OSViContext *__osViCurr;
u32 osDisableInt(void);
void osRestoreInt(u32);

/* Turns VI special features on or off (bit set = on, bit clear = off) in the current
   VI context's control word, then marks the context as changed. Interrupts are
   disabled while the context is edited. */
void osViSetSpecialFeatures(u32 func) {
    register u32 saveMask;

    saveMask = osDisableInt();

    if ((func & 0x0001) != 0) {
        __osViCurr->control |= 0x00008;
    }

    if ((func & 0x0002) != 0) {
        __osViCurr->control &= ~0x00008;
    }

    if ((func & 0x0004) != 0) {
        __osViCurr->control |= 0x00004;
    }

    if ((func & 0x0008) != 0) {
        __osViCurr->control &= ~0x00004;
    }

    if ((func & 0x0010) != 0) {
        __osViCurr->control |= 0x00010;
    }

    if ((func & 0x0020) != 0) {
        __osViCurr->control &= ~0x00010;
    }

    if ((func & 0x0040) != 0) {
        __osViCurr->control |= 0x10000;
        __osViCurr->control &= ~0x00300;
    }

    if ((func & 0x0080) != 0) {
        __osViCurr->control &= ~0x10000;
        __osViCurr->control |= __osViCurr->modep->comRegs.ctrl & 0x00300;
    }

    __osViCurr->state |= 0x08;

    osRestoreInt(saveMask);
}
