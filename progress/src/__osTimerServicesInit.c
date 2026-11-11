extern VRTimer *__osTimerList;
extern u8 gOrderState;

/* Initialises the timer services: clears two state words in gOrderState and makes the timer list head an empty ring (points to itself, zero interval/value/queue/message). */
void __osTimerServicesInit(void){
    VRTimer *head = __osTimerList;
    *(u64 *)((u8 *)&gOrderState + 0x7918) = 0;
    *(s32 *)((u8 *)&gOrderState + 4) = 0;
    *(s32 *)((u8 *)&gOrderState + 0x2528) = 0;
    head->value = 0;
    head->interval = 0;
    head->prev = head;
    head->next = head;
    head->mq = 0;
    head->msg = 0;
}
