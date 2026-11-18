extern char gStreamState[];
s32 pool_alloc_cleared_node(void);
void order_records_init(void);

/* Stores a freshly allocated, cleared pool node in gStreamState at 0x80C6, then sets up the order records. */
void stream_state_init(void)
{
    *(s32 *) (gStreamState + 0x80C6) = pool_alloc_cleared_node();
    order_records_init();
}
