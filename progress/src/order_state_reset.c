extern char gOrderState[];
void order_state_free_buffers(void);
void streamFreeBuffers(void);

/* Frees the order buffers and the stream buffers, then clears the two saved pointers in the order state. */
void order_state_reset(void)
{
    order_state_free_buffers();
    streamFreeBuffers();
    *((s32 *) (gOrderState + 0x8ABC)) = 0;
    *((s32 *) (gOrderState + 0x8AC0)) = 0;
}
