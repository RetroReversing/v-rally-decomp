extern char gStreamList[];
s32 pool_alloc_cleared_node(void);
extern char D_8009A552[];

/* Allocates the stream head node and stores its pointer at ((char *)&gStreamList) (the stream state). */
void func_8004C794(void)
{
    *(s32 *)(((char *)&gStreamList)) = pool_alloc_cleared_node();
}
