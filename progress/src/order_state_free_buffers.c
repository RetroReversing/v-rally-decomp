extern char gOrderState[];
void heapFreeBlock(void *block);

/* Frees the three heap buffers held in the order state block (offsets 0x8AC4, 0x8AC8, 0x8AB4). */
void order_state_free_buffers(void)
{
    heapFreeBlock(*((void **) (gOrderState + 0x8AC4)));
    heapFreeBlock(*((void **) (gOrderState + 0x8AC8)));
    heapFreeBlock(*((void **) (gOrderState + 0x8AB4)));
}
