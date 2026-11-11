s32 create_thread_on_ctx(void *, s32, s32, void *);
void *poolAllocNode(void *, s32);
void osCreateMesgQueue(void *, void *, s32);
s32 osSetIntState(s32);
extern u8 gOrderState[];
extern void msg_dispatch_loop;
extern void func_8007F490;
extern void GfxTaskThread;
extern void func_8007FE1C;

/* Allocates a message queue with msg_count slots for task slot (base + offset) and starts its
   thread if the slot has none yet. The thread entry depends on the task id. Returns the
   allocated block. */
void *taskOpen(s32 base, s32 offset, s32 msg_count) {
    void *var_a0;
    s32 var_a2;
    s32 saved_intr;
    u32 task_id;
    void *slot;
    void *block;

    saved_intr = osSetIntState(1);
    task_id = base + offset;
    slot = (void *)((u8 *)gOrderState + 0x5910 + task_id * 0x5C);
    block = poolAllocNode(slot, (msg_count * 4) + 0x28);
    osCreateMesgQueue((void *)((u8 *)block + 0x10), (void *)((u8 *)block + 0x28), msg_count);
    *(u16 *)((u8 *)block + 0xC) = (u16)task_id;
    *(s16 *)((u8 *)block + 0xE) = 0;
    if ((*(s32 *)((u8 *)slot + 0) == *(s32 *)((u8 *)slot + 4)) && (*(s32 *)((u8 *)slot + 0x10) == 0)) {
        switch (task_id) {
        case 10U:
            *(s32 *)((u8 *)slot + 0x10) = create_thread_on_ctx(&func_8007FE1C, 0x400, 0x71, slot);
            break;
        case 38U:
            *(s32 *)((u8 *)slot + 0x10) = create_thread_on_ctx(&GfxTaskThread, 0x400, 0x73, slot);
            break;
        case 34U:
            *(s32 *)((u8 *)slot + 0x10) = create_thread_on_ctx(&func_8007F490, 0x400, 0x7F, slot);
            break;
        default:
            *(s32 *)((u8 *)slot + 0x10) = create_thread_on_ctx(&msg_dispatch_loop, 0x400, 0x78, slot);
            break;
        }
    }
    osSetIntState(saved_intr);
    return block;
}
