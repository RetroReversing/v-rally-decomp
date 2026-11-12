extern char gOrderState[];
void osSendMesg(char *a, int b, int c);
/* Posts a zero-valued blocking message to the order state's message queue. */
void order_post_wakeup(void) { osSendMesg(gOrderState + 0x87A8, 0, 0); }