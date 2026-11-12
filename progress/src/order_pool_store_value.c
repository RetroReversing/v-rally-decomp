/* Allocates a 0x10-byte node from the pool at gOrderState+0x2370 and stores arg0 in its +0xC word. */
extern char gOrderState[];
void *poolAllocNode(s32, s32);

void order_pool_store_value(s32 arg0) {
    *(s32 *)((char *)poolAllocNode(*(s32 *)(gOrderState + 0x2370), 0x10) + 0xC) = arg0;
}
