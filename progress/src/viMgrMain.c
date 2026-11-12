typedef struct OSMesgQueue_s OSMesgQueue;
typedef void *OSMesg;

typedef struct {
    u16 state;
    u16 retraceCount;
    void *framep;
    void *modep;
    u32 control;
    OSMesgQueue *msgq;
    OSMesg msg;
} __OSViContext;

typedef struct {
    s32 active;
    void *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
} OSDevMgr;

extern u16 D_800ACCB0; extern u32 D_800B0D78,D_800AE854; extern u64 D_800B6168;
void *vi_get_pending(void); void vi_apply_context(void); u32 osGetCount(void); void __osTimerInterrupt(void); void osRecvMesg(OSMesgQueue *,void*,s32);void osSendMesg(OSMesgQueue *,OSMesg,s32);

/* VI manager thread. Blocks on the event queue; each VI retrace (message 13)
   applies the pending context and counts down the frame countdown D_800ACCB0,
   notifying the current context's queue when it reaches zero. Timer messages
   (14) go to the OS timer code. */
void viMgrMain(void *mgr_arg){
 OSDevMgr *mgr;
 u16 *msg=NULL; s32 first=0; u32 count; __OSViContext *ctx; OSDevMgr *q;
 mgr = mgr_arg;
 D_800ACCB0 = ((__OSViContext *)vi_get_pending())->retraceCount; if(!D_800ACCB0)D_800ACCB0=1;
 first=0;
 q=mgr;
 for(;;){osRecvMesg(q->evtQueue,&msg,1);switch(*msg){case 13:
 vi_apply_context(); if(--D_800ACCB0==0){ctx=vi_get_pending();if(ctx->msgq)osSendMesg(ctx->msgq,ctx->msg,0);D_800ACCB0=ctx->retraceCount;}
 D_800B0D78++;if(first){first=0;count=osGetCount();D_800B6168=count;}
 count=D_800AE854;D_800AE854=osGetCount();count=D_800AE854-count;D_800B6168+=count;break;
 case 14:__osTimerInterrupt();break;}}}
