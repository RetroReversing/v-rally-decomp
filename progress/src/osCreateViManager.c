typedef s32 OSPri;
typedef s32 OSId;

typedef union {
    struct {
        f32 f_odd;
        f32 f_even;
    } f;
    f64 d;
} __OSfp;

typedef struct {
    u64 at, v0, v1, a0, a1, a2, a3;
    u64 t0, t1, t2, t3, t4, t5, t6, t7;
    u64 s0, s1, s2, s3, s4, s5, s6, s7;
    u64 t8, t9;
    u64 gp, sp, s8, ra;
    u64 lo, hi;
    u32 sr, pc, cause, badvaddr, rcp;
    u32 fpcsr;
    __OSfp  fp0,  fp2,  fp4,  fp6,  fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;

typedef struct {
    u32 flag;
    u32 count;
    u64 time;
} __OSThreadprofile_s;

typedef struct OSThread_s {
    struct OSThread_s    *next;
    OSPri                 priority;
    struct OSThread_s   **queue;
    struct OSThread_s    *tlnext;
    u16                   state;
    u16                   flags;
    OSId                  id;
    int                   fp;
    __OSThreadprofile_s  *thprof;
    __OSThreadContext     context;
} OSThread;

extern void     osCreateThread(OSThread *, OSId, void (*)(void *), void *, void *, OSPri);
extern void     osStartThread(OSThread *);
extern void     osSetThreadPri(OSThread *, OSPri);
extern OSPri    func_800937D0(OSThread *);

typedef void *OSMesg;

typedef struct OSMesgQueue_s {
    OSThread    *mtqueue;
    OSThread    *fullqueue;
    s32          validCount;
    s32          first;
    s32          msgCount;
    OSMesg      *msg;
} OSMesgQueue;

extern void     osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
typedef u32 OSEvent;
extern void     osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);

typedef u32 OSIntMask;
extern u32      osDisableInt(void);
extern void     osRestoreInt(u32);

typedef struct {
    u16          type;
    u8           pri;
    u8           status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct {
    OSIoMesgHdr  hdr;
    void        *dramAddr;
    u32          devAddr;
    u32          size;
    void        *piHandle;
} OSIoMesg;

typedef struct {
    s32          active;
    OSThread    *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32         (*dma)(s32, u32, void *, u32);
    s32         (*edma)(void *, s32, u32, void *, u32);
} OSDevMgr;

extern void __osTimerServicesInit(void);
extern void func_80095B70(void);
extern void     osCreateViManager(OSPri);
extern void osCreateViManager(OSPri);

OSDevMgr __osViDevMgr = { 0 };

u32 __additional_scanline = 0;

static struct { OSThread thread; unsigned char gap[8]; } viThreadStorage;
static unsigned char viThreadStack[4096 ] __attribute__((aligned( 8 ))) ;
static OSMesgQueue viEventQueue __attribute__((aligned( 8 ))) ;
static OSMesg viEventBuf[5] __attribute__((aligned( 8 ))) ;
static OSIoMesg viRetraceMsg __attribute__((aligned( 8 ))) ;
static OSIoMesg viCounterMsg __attribute__((aligned( 8 ))) ;

static void viMgrMain(void* arg);

/* Creates the VI retrace manager thread once. It raises its own priority to
   pri if needed while the thread is set up, then restores it. */
void osCreateViManager(OSPri pri) {
    u32 saved_mask;
    OSPri old_pri;
    OSPri my_pri;

    if (__osViDevMgr.active) {
        return;
    }
    __osTimerServicesInit();

    __additional_scanline = 0;

    osCreateMesgQueue(&viEventQueue, viEventBuf, ((s32) (sizeof( viEventBuf ) / sizeof( viEventBuf [0]))) );
    viRetraceMsg.hdr.type = ((10)  + 3) ;
    viRetraceMsg.hdr.pri = 0 ;
    viRetraceMsg.hdr.retQueue = 0 ;
    viCounterMsg.hdr.type = ((10)  + 4) ;
    viCounterMsg.hdr.pri = 0 ;
    viCounterMsg.hdr.retQueue = 0 ;
    osSetEventMesg(7 , &viEventQueue, &viRetraceMsg);
    osSetEventMesg(3 , &viEventQueue, &viCounterMsg);
    old_pri = -1;
    my_pri = func_800937D0(0 );

    if (my_pri < pri) {
        old_pri = my_pri;
        osSetThreadPri(0 , pri);
    }

    saved_mask = osDisableInt();
    __osViDevMgr.active = 1 ;
    __osViDevMgr.thread = &viThreadStorage.thread;
    __osViDevMgr.cmdQueue = &viEventQueue;
    __osViDevMgr.evtQueue = &viEventQueue;
    __osViDevMgr.acsQueue = 0 ;
    __osViDevMgr.dma = 0 ;
    __osViDevMgr.edma = 0 ;
    osCreateThread(&viThreadStorage.thread, 0, viMgrMain, &__osViDevMgr, &viThreadStack[4096 ], pri);
    func_80095B70();
    osStartThread(&viThreadStorage.thread);
    osRestoreInt(saved_mask);

    if (old_pri != -1) {
        osSetThreadPri(0 , old_pri);
    }
}
