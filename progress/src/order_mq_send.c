s32 osSendMesg();
extern char gOrderState[];

/* Sends msg to the order-state entry at index + base_index (0x5C-byte records past gOrderState + 0x5924), blocking. */ void order_mq_send(s32 index, s32 base_index, s32 msg) {
    osSendMesg(((index + base_index) * 0x5C) + (gOrderState + 0x5924), msg, 1);
}
