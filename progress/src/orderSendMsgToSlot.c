s32 osSendMesg();
extern char gOrderState[];

/* Posts msg to the message queue of the order slot at (base + offset) * 0x5C inside gOrderState. */ void orderSendMsgToSlot(s32 base, s32 offset, s32 msg) {
    osSendMesg(((base + offset) * 0x5C) + (gOrderState + 0x5924), msg, 0);
}
