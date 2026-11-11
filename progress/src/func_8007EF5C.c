extern s32 gHeapBusy, gHeapCallerRa;
extern void (*heapPanicFn)(s32), (*heapReentryFn)(s32);
extern s32 gHeapBlocks[];
typedef struct Dispatch { s32 pad[2]; s32 (*call)(s32); } Dispatch;
extern Dispatch *D_800C5BB0[];

/* Calls the handler for id (a table index, or a direct pointer when the high half is set),
 * flagging the dispatcher as busy and recording the caller's return address while it runs.
 * A null target goes to heapPanicFn and returns 0. */
s32 func_8007EF5C(s32 id) {
    volatile s32 handlerSlot; s32 result = 0; s32 entry; s32 body;
    if (gHeapBusy == 1) heapReentryFn(gHeapCallerRa - 4);
    gHeapBusy = 1; do { gHeapCallerRa = (s32) __builtin_mips_live_return_address(); } while (0);
    if (!(id & 0xffff0000)) { entry = gHeapBlocks[id]; handlerSlot = id; } else { entry = id; handlerSlot = 1; }
    if (entry == 0) { heapPanicFn(gHeapCallerRa - 4); body = 0; } else body = entry - 8;
    if (body) result = D_800C5BB0[handlerSlot]->call(body + 8);
    gHeapBusy = 0; return result;
}
