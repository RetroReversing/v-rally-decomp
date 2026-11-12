s32 taskRecvMsg(void *task);
extern s32 gOrderState;

/* Receives the next message for the order task whose pointer is stored at gOrderState+0x58F4. */
void order_recv_msg(void) {
    taskRecvMsg(*(void **)((u8 *)&gOrderState + 0x58F4));
}
