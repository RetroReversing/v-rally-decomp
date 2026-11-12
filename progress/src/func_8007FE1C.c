extern void *osRecvMesg(void *, void **, s32);
extern void msg_list_send_all(void *, void **);
extern void *func_8007F73C(s32, s32);
extern void func_8008DD00(void *);
extern void osSpTaskStartGo(void *);
extern void osSendMesg(void *, void *, s32);
extern u8 gOrderState[];
extern u8 D_800B4568[];
extern u8 stream_state[];

/* Task loop: waits on the request queue for the next task, runs its handler from the
 * handler table, starts it on the RSP, then waits for completion and sends it on. */
void func_8007FE1C(void *queue) {
    void *task;
    void *msg;
    u8 *state;
    u8 *handlers;
    u8 *ucode;

    msg = NULL;
    state = gOrderState + 0x1D10;
    handlers = stream_state + 0x7D8A;
    ucode = D_800B4568;
    for (;;) {
        osRecvMesg(queue + 0x14, &task, 1);
        if (*(void **)(state + 0x55C) != NULL) {
            *(void **)(state + 0x560) = task;
            osRecvMesg(state + 0x10, &msg, 1);
            *(void **)(state + 0x560) = NULL;
        }
        msg_list_send_all(queue, &task);
        ((void (*)(void *))*(void **)(handlers + *(u16 *)(queue + 0xE) * 4))(task);
        *(void **)(state + 0x558) = task;
        *(u8 **)((u8 *)task + 0x40) = ucode;
        func_8008DD00(task);
        osSpTaskStartGo(task);
        msg = func_8007F73C(0x22, 2);
        ((void (*)(void *))*(void **)(handlers + 0x90))(task);
        *(void **)(state + 0x558) = NULL;
        msg = func_8007F73C(0x22, 3);
        ((void (*)(void))*(void **)(handlers + 0x94))();
        osSendMesg(*(void **)((u8 *)task + 0x40), *(void **)((u8 *)task + 0x44), 0);
    }
}
