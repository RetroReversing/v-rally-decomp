extern char stream_state[];
void msg_list_send_all();
void osRecvMesg();

/* Message loop: waits on the queue at obj+0x14, calls the handler for the message type at
   obj+0xE (from the stream_state handler table), then forwards the message to the list at obj.
   Never returns. */
void msg_dispatch_loop(char *obj) {
    s32 msg;

    for (;;) {
        osRecvMesg(obj + 0x14, &msg, 1);
        (*(void (**)())(stream_state + 0x7D8A + *(u16 *)(obj + 0xE) * 4))();
        msg_list_send_all(obj, &msg);
    }
}
